#include "bmnetwork.h"

BmNetwork::BmNetwork(const QHostAddress &aHostAddress)
    : QObject()
    , mHostAddress( aHostAddress )
{
}

BmNetwork::~BmNetwork()
{
}

const QHostAddress& BmNetwork::getHostAddress() const
{
    return mHostAddress;
}

