#include "bmnetworktcpserver.h"
#include "bmerrormanager.h"
#include "bmnetworktcpclient.h"
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>

BmNetworkTCPServer::BmNetworkTCPServer( int aPort )
    : BmNetworkTCP( aPort )
{
    mSocket = new QTcpServer( this );
    QObject::connect( mSocket, SIGNAL(newConnection()), this, SLOT(handleConnection()) );
}

BmNetworkTCPServer::~BmNetworkTCPServer()
{
    delete mSocket;
    mSocket = NULL;
}

void BmNetworkTCPServer::close ()
{
    disconnectFrom();
    mSocket->close();
}

//---------------------------------------------------------------------//
void BmNetworkTCPServer::errorManagement( QAbstractSocket::SocketError socketError )
{
    switch (socketError)
    {
        case QAbstractSocket::RemoteHostClosedError:
        {
            QTcpSocket* socket = dynamic_cast<QTcpSocket*>(sender());
            if ( socket )
            {
                QString sockAddr = socket->peerAddress().toString();
                BmErrorManager::pushMessage( tr("The remote host %1 closed the connection.").arg(sockAddr),
                                             BmErrorManager::WARNING_MESSAGE );
              }
            else
            {
                BmErrorManager::pushMessage( tr("The remote host closed the connection."), BmErrorManager::WARNING_MESSAGE );
            }
            break;
        }
        case QAbstractSocket::SocketAccessError:
            BmErrorManager::pushMessage( tr("The socket operation failed because the application lacked the required privileges."),
                                         BmErrorManager::CRITICAL_MESSAGE );
            BmErrorManager::pushMessage( tr("Error in BmNetworkTCPServer::errorManagement: %1.").arg(mSocket->errorString()),
                                         BmErrorManager::DEBUG_MESSAGE );
            break;
        case QAbstractSocket::SocketResourceError:
            BmErrorManager::pushMessage( tr("The local system ran out of resources (e.g., too many sockets)."),
                                         BmErrorManager::CRITICAL_MESSAGE );
            BmErrorManager::pushMessage( tr("Error in BmNetworkTCPServer::errorManagement: %1.").arg(mSocket->errorString()),
                                         BmErrorManager::DEBUG_MESSAGE );
            break;
        case QAbstractSocket::UnsupportedSocketOperationError:
            BmErrorManager::pushMessage( tr("The requested socket operation is not supported by this operating system."),
                                         BmErrorManager::CRITICAL_MESSAGE );
            BmErrorManager::pushMessage( tr("Error in BmNetworkTCPServer::errorManagement: %1.").arg(mSocket->errorString()),
                                         BmErrorManager::DEBUG_MESSAGE );
            break;
        case QAbstractSocket::UnknownSocketError:
        default:
             BmErrorManager::pushMessage( tr("An unknown error occurred."), BmErrorManager::CRITICAL_MESSAGE );
             BmErrorManager::pushMessage( tr("Error in BmNetworkTCPServer::errorManagement: %1.").arg(mSocket->errorString()),
                                          BmErrorManager::DEBUG_MESSAGE );
         }
}

//---------------------------------------------------------------------//
void BmNetworkTCPServer::start()
{
    connectTo();
}

//---------------------------------------------------------------------//
void BmNetworkTCPServer::connectTo()
{
    bool succeed = mSocket->listen( QHostAddress::Any, getPort() ); // Accept connections from any client

    if( !succeed )
        errorManagement( mSocket->serverError() );
}

//---------------------------------------------------------------------//
void BmNetworkTCPServer::disconnectFrom()
{
    mConnected = false;
}

//---------------------------------------------------------------------//
void BmNetworkTCPServer::handleConnection()
{
    QTcpSocket* socket = mSocket->nextPendingConnection();
    QObject::connect( socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(errorManagement(QAbstractSocket::SocketError)) );
    QObject::connect( socket, SIGNAL(disconnected()), this, SLOT(lostConnection()) );

    BmNetworkTCPClient* stack =  new BmNetworkTCPClient( socket, true );
    mConnected = true;

    emit connectedTo( socket->peerAddress().toString() );
}

//---------------------------------------------------------------------//
bool BmNetworkTCPServer::isConnected() const
{
    return mConnected;
}

//---------------------------------------------------------------------//
void BmNetworkTCPServer::lostConnection()
{
    QTcpSocket* socket = dynamic_cast<QTcpSocket*>(sender());
    if ( socket )
    {
        emit disconnecting( socket->peerAddress().toString() );
        socket->deleteLater(); // The TCP socket must be deleted ASAP.
    }
}

//---------------------------------------------------------------------//
unsigned long BmNetworkTCPServer::ping()
{
    return 0;
}

//---------------------------------------------------------------------//
BmMessage* BmNetworkTCPServer::receive()
{
    return NULL;
}

//---------------------------------------------------------------------//
int BmNetworkTCPServer::receivedBytes()
{
    return 0;
}

//---------------------------------------------------------------------//
void BmNetworkTCPServer::send( BmMessage* aMessage )
{
}

//---------------------------------------------------------------------//
int BmNetworkTCPServer::sentBytes()
{
    return 0;
}
