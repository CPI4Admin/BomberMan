#ifndef BMNETWORKTCPSERVER_H
#define BMNETWORKTCPSERVER_H

#include "bmnetworktcp.h"

class QTcpServer;
class BmMessage;

class BmNetworkTCPServer : public BmNetworkTCP
{
    Q_OBJECT

private:
    QTcpServer* mSocket;
    bool mConnected; /*!< The connection indicator. */

public:
    BmNetworkTCPServer( int aPort = 60000 );
    virtual ~BmNetworkTCPServer();

    void close();
    virtual bool isConnected() const;
    virtual void start();

signals:
    /**
     *  This signal is emitted when this stack is successfully connected to a client
     *  The name of the client this stack is connected to is returned
     */
    void connectedTo( const QString& clientName );
    /**
     *  This signal is emitted when a client is disconnected from this stack
     *  The name of the disconnected client is returned
     */
    void disconnecting( const QString& clientName );

protected:
    virtual void connectTo();
    virtual void disconnectFrom();

private:
    virtual BmMessage* receive();
    virtual int receivedBytes();
    virtual unsigned long ping();
    virtual void send( BmMessage* aMessage );
    virtual int sentBytes();

private slots:
    void errorManagement( QAbstractSocket::SocketError socketError ); /*!< Manages the errors and throws exceptions. */
    void handleConnection(); /*!< Handles this stack connection. */
    void lostConnection(); /*!< Handles this stack clients disconnections. */
};

#endif // BMNETWORKTCPSERVER_H
