#include "bmnetworktcpclient.h"
#include "bytebuffer.h"
#include "bmmessage.h"
#include "bmerrormanager.h"

#include <QtNetwork/QTcpSocket>
#include <QByteArray>
#include <QCoreApplication>
#include <QDataStream>
#include <QDateTime>

BmNetworkTCPClient::BmNetworkTCPClient( const QHostAddress& aHostAddress, int aPort, bool isConnected )
    : BmNetworkTCP( aHostAddress, aPort )
{
    mSocket = new QTcpSocket( this );
    mIsConnected = false;
    init();
}

BmNetworkTCPClient::BmNetworkTCPClient( QTcpSocket* aSocket, bool isConnected )
: BmNetworkTCP( aSocket->peerAddress(), aSocket->peerPort() )
{
    mSocket = aSocket;
    mIsConnected = isConnected;
    init();
}

BmNetworkTCPClient::~BmNetworkTCPClient()
{
}

void BmNetworkTCPClient::connectionSet()
{
    mIsConnected = true;
    emit connectedTo( mSocket->peerName() );
}

void BmNetworkTCPClient::connectTo()
{
    if ( !isConnected() )
        mSocket->connectToHost( getHostAddress(), getPort() );
}

void BmNetworkTCPClient::disconnected()
{
    mIsConnected = false;
    emit disconnectedFrom( mSocket->peerName() );
}

void BmNetworkTCPClient::disconnectFrom()
{
    if ( isConnected() )
        mSocket->disconnectFromHost();  // Try to close the socket. If there is data pending to be written, it will wait until all data
                                        // has been written;
}

void BmNetworkTCPClient::exceptionManagement( QAbstractSocket::SocketError socketError )
{
    switch (socketError)
    {
         case QAbstractSocket::RemoteHostClosedError:
             BmErrorManager::pushMessage( tr("The remote host %1 closed the connection.").arg(mSocket->peerName()),
                                          BmErrorManager::WARNING_MESSAGE );
             break;
         case QAbstractSocket::HostNotFoundError:
             BmErrorManager::pushMessage( tr("The host address %1 was not found.").arg(mSocket->peerAddress().toString()),
                                          BmErrorManager::CRITICAL_MESSAGE );
             BmErrorManager::pushMessage( tr("Error in BmNetworkTCPClient: %1.").arg(mSocket->errorString()),
                                          BmErrorManager::DEBUG_MESSAGE );
             break;
         case QAbstractSocket::ConnectionRefusedError:
             BmErrorManager::pushMessage( tr("The connection was refused by the peer (or timedout)."),
                                          BmErrorManager::WARNING_MESSAGE );
             break;
         case QAbstractSocket::SocketAccessError:
             BmErrorManager::pushMessage( tr("The socket operation failed because the application lacked the required privileges."),
                                          BmErrorManager::CRITICAL_MESSAGE );
             BmErrorManager::pushMessage( tr("Error in BmNetworkTCPClient: %1.").arg(mSocket->errorString()),
                                          BmErrorManager::DEBUG_MESSAGE );
             break;
         case QAbstractSocket::SocketResourceError:
             BmErrorManager::pushMessage( tr("The local system ran out of resources (e.g., too many sockets)."),
                                          BmErrorManager::CRITICAL_MESSAGE );
             BmErrorManager::pushMessage( tr("Error in BmNetworkTCPClient: %1.").arg(mSocket->errorString()),
                                          BmErrorManager::DEBUG_MESSAGE );
             break;
         case QAbstractSocket::SocketTimeoutError:
             BmErrorManager::pushMessage( tr("The socket operation timed out."), BmErrorManager::WARNING_MESSAGE );
             break;
         case QAbstractSocket::UnsupportedSocketOperationError:
             BmErrorManager::pushMessage( tr("The requested socket operation is not supported by this operating system."),
                                          BmErrorManager::CRITICAL_MESSAGE );
             BmErrorManager::pushMessage( tr("Error in BmNetworkTCPClient: %1.").arg(mSocket->errorString()),
                                          BmErrorManager::DEBUG_MESSAGE );
             break;
         case QAbstractSocket::UnknownSocketError:
         default:
             BmErrorManager::pushMessage( tr("An unknown error occurred."), BmErrorManager::CRITICAL_MESSAGE );
             BmErrorManager::pushMessage( tr("Error in BmNetworkTCPClient: %1.").arg(mSocket->errorString()),
                                          BmErrorManager::DEBUG_MESSAGE );

         }
     emit connectionError(); // On emet une nouvelle erreur avec le signal connectionErro()
}

void BmNetworkTCPClient::init()
{
    mMessageSize = 0;
    mMessageSizeLeft = 0;
    mReceive = 0;
    mReceivedBytes = 0;
    mSentBytes = 0;

    QObject::connect( mSocket, SIGNAL(readyRead()), this, SLOT(receive()) ); // each time the socket receive a packet, receive() is called
    QObject::connect( mSocket, SIGNAL(connected()), this, SLOT(connectionSet()) );
    QObject::connect( mSocket, SIGNAL(disconnected()), this, SLOT(disconnected()) );
    QObject::connect( mSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(exceptionManagement(QAbstractSocket::SocketError)) );

    // No delay socket
    mSocket->setSocketOption( QTcpSocket::LowDelayOption, 1 );

    // Allocate the ping buffers
    mBytes = ByteBuffer::allocate( 32 );

    // Prepare ping block of 32 bytes (sizeof int + 28 bytes message)
    mBytes->putInt( 28 );
    QByteArray sArray( "ping", 4 );
    mBytes->put( &sArray );

    mReceive = new unsigned long[4];
    mSend = new unsigned long[4];
    for ( int i=0; i<4; i++ )
    {
        mReceive[i] = 0;
        mSend[i] = 0;
    }
}

bool BmNetworkTCPClient::isConnected() const
{
    return mIsConnected;
}

unsigned long BmNetworkTCPClient::ping()
{
    if ( !mIsConnected )
        return 0;

    unsigned long latency = 0;
    mIncrement = 0;
    // TODO add timeout

    // Send it
     int i;
    for ( i=0; i<4; i++ ) // Four times for a better estimation
    {
        mBlockingLoop = true;
        //QSleep::wait( ONE_SECOND ); // Non blocking for all ongoing processes and the GUI
        mSend[i] = QDateTime::currentMSecsSinceEpoch();
        mSocket->write( mBytes->array()->constData(), 32 );
        while ( mBlockingLoop )
            QCoreApplication::processEvents(); // Thus socket notifiers will be sent and processed
    }

    // Compute average latency
    for ( i=0; i<4; i++ )
    {
        //BmErrorManager::pushMessage( tr("BmNetworkTCPClient::ping mReceive: %1").arg(QString::number(mReceive[i])), BmErrorManager::DEBUG_MESSAGE );
        //BmErrorManager::pushMessage( tr("BmNetworkTCPClient::ping mSend: %1").arg(QString::number(mSend[i])), BmErrorManager::DEBUG_MESSAGE );
        latency += (mReceive[i] - mSend[i]);
        //BmErrorManager::pushMessage( tr("BmNetworkTCPClient::ping latency: %1").arg(QString::number(latency)), BmErrorManager::DEBUG_MESSAGE );
    }
    latency /= 4;

    return latency;
}

BmMessage* BmNetworkTCPClient::receive()
{
    if ( !mIsConnected )
        return NULL;

    static int t=0;
    while( true )
    {
        int bytesToWrite = mSocket->bytesAvailable();
        if( bytesToWrite <= 4 )
            return NULL;

        // Get the size of the bloc
        if( mMessageSizeLeft == 0 )
        {
            QDataStream in( mSocket );
            in >> mMessageSizeLeft;
            bytesToWrite -= 4;
            mMessageSize = 0;
            mCurrentMessage = new QByteArray();
            mCurrentMessage->resize( mMessageSizeLeft ); // prepare for receiving the data.
        }

        int maxBytesToWrite = (mMessageSizeLeft < bytesToWrite) ? mMessageSizeLeft : bytesToWrite;
        if( maxBytesToWrite > 0 )
        {
            mSocket->read( (char*) mCurrentMessage->constData() + mMessageSize, maxBytesToWrite );
            mMessageSize += maxBytesToWrite;
            mMessageSizeLeft -= maxBytesToWrite;
            if( mMessageSizeLeft == 0 )
            {
                if ( tr(mCurrentMessage->data()).contains("ping") )
                {
                    mReceive[mIncrement] = QDateTime::currentMSecsSinceEpoch();
                    mIncrement++;
                    mBlockingLoop = false;
                    delete mCurrentMessage;
                    return NULL;
                }
                mReceivedBytes += mCurrentMessage->size();
                BmMessage* message = new BmMessage( mCurrentMessage, /*getDevice()*/0 );
                t++;
            }
        }
    }
    return NULL;
}

int BmNetworkTCPClient::receivedBytes()
{
    return mReceivedBytes;
}

void BmNetworkTCPClient::send( BmMessage* aMessage )
{
    if ( aMessage && mIsConnected )
    {
        mSentBytes += aMessage->getData()->size();
        mSocket->write( *(aMessage->getData()) );
        mSocket->flush();
    }
}

int BmNetworkTCPClient::sentBytes()
{
    return mSentBytes;
}

void BmNetworkTCPClient::start()
{
    connectTo();
}
