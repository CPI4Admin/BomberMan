#include "bmnetworktcp.h"

BmNetworkTCP::BmNetworkTCP( int aPort )
    : BmNetwork()
    , mPort( aPort )
{
}

BmNetworkTCP::BmNetworkTCP( const QHostAddress& aHostAddress, int aPort )
    : BmNetwork( aHostAddress )
    , mPort( aPort )
{
}

BmNetworkTCP::~BmNetworkTCP()
{

}

int BmNetworkTCP::getPort() const
{
    return mPort;
}
