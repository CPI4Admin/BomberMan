#ifndef BMNETWORKTCP_H
#define BMNETWORKTCP_H

#include "bmnetwork.h"

class BmMessage;

class BmNetworkTCP : public BmNetwork
{
private:
    int mPort;

public:
    BmNetworkTCP( int aPort );
    BmNetworkTCP( const QHostAddress& aHostAddress, int aPort );

    virtual ~BmNetworkTCP();

    int getPort() const;
    virtual bool isConnected() const = 0;
    virtual unsigned long ping() = 0;
    virtual int receivedBytes() = 0;
    virtual int sentBytes() = 0;

protected:
    virtual void connectTo() = 0;
    virtual BmMessage* receive() = 0;
    virtual void send( BmMessage* aMessage ) = 0;

};

#endif // BMNETWORKTCP_H
