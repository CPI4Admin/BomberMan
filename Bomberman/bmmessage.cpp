#include "bmmessage.h"

BmMessage::BmMessage( QByteArray* aData, int  )
{
}

BmMessage::~BmMessage()
{
}

QByteArray* BmMessage::getData()
{
    return mData;
}
