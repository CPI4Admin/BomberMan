#ifndef BMNETWORKTCPCLIENT_H
#define BMNETWORKTCPCLIENT_H

#include "bmnetworktcp.h"

class QTcpSocket;
class ByteBuffer;

class BmNetworkTCPClient : public BmNetworkTCP
{
    Q_OBJECT

private:
    volatile bool mBlockingLoop; /*!< Ping blocking handler. */
    bool mIsConnected; /*!< Connection status of the socket. */
    ByteBuffer* mBytes; /*!< Buffer sent at each ping request. */
    int mIncrement; /*!< Incremental variable used when receiving a ping back from the client. */
    int mMessageSize; /*!< The size of the message. */
    int mMessageSizeLeft; /*!< The bytes left for the complete message. */
    int mReceivedBytes; /*!< The number of received bytes. */
    int mSentBytes; /*!< The number of sent bytes. */
    QByteArray* mCurrentMessage; /*!< The current received message. */
    QTcpSocket* mSocket; /*!< The socket used by this TCP client stack. */
    unsigned long* mReceive; /*!< The receive time from ping request. */
    unsigned long* mSend; /*!< The send time from ping request. */

public:
    BmNetworkTCPClient(const QHostAddress& aHostAddress, int port, bool isConnected);
    BmNetworkTCPClient( QTcpSocket* aSocket, bool isConnected = false );
    virtual ~BmNetworkTCPClient();
    virtual bool isConnected() const;
    int receivedBytes();
    virtual unsigned long ping();
    virtual int sentBytes();
    virtual void start();

signals:
    void connectedTo( const QString& peerName );
    void disconnectedFrom( const QString& peerName );
    void connectionError();

protected:
    virtual void connectTo();
    virtual void disconnectFrom();
    virtual void send( BmMessage* aMessage );

protected slots:
    virtual BmMessage* receive();

private:
    void init(); /*!< Initializes this stack. */

private slots:
    void connectionSet(); /*!< Emits the signal connectedTo when this stack is actually connected. */
    void disconnected(); /*!< Emits the signal disconnectFrom() when this stack is actually disconnected. */
    void exceptionManagement( QAbstractSocket::SocketError socketError ); /*!< Manages the errors and throws exceptions. */
};

#endif // BMNETWORKTCPCLIENT_H
