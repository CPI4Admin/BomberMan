#include "bmerror.h"

BmError::BmError( const QString& aMessage, ErrorType aType )
{
    mMessage = aMessage;
    mType = aType;
}

BmError::~BmError()
{
    // Nothing to do
}

const QString& BmError::getMessage() const
{
    return mMessage;
}

BmError::ErrorType BmError::getType() const
{
    return mType;
}

