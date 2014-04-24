#include "bmerrormanager.h"
#include "bmerror.h"

BmErrorManager* BmErrorManager::mSelf = 0;

//---------------------------------------------------------------------//
BmErrorManager::BmErrorManager()
: QObject()
{
}

//---------------------------------------------------------------------//
BmErrorManager::~BmErrorManager()
{
    // Clear the list
    if ( !mErrors.empty() )
    {
        for ( std::list<BmError*>::iterator iti = mErrors.begin(); iti != mErrors.end(); iti++ )
            delete (*iti);
        mErrors.clear();
    }
}

//---------------------------------------------------------------------//
void BmErrorManager::destroy()
{
    delete mSelf;
    mSelf = NULL;
}

//---------------------------------------------------------------------//
std::list<BmError*> BmErrorManager::getErrors() const
{
    return mErrors;
}

//---------------------------------------------------------------------//
BmErrorManager* BmErrorManager::getInstance()
{
    if (!mSelf)
        mSelf = new BmErrorManager();

    return mSelf;
}

//---------------------------------------------------------------------//
BmError* BmErrorManager::popError()
{
    if ( mErrors.empty() )
        return NULL;

    BmError* error = mErrors.front();
    mErrors.pop_front();
    return error;
}

//---------------------------------------------------------------------//
void BmErrorManager::pushError( BmError* anError )
{
    mErrors.push_back( anError );
    emit errorReceived();
}

//---------------------------------------------------------------------//
void BmErrorManager::pushMessage( const QString& aMessage, MessageType type )
{
    BmErrorManager* em = BmErrorManager::getInstance();
    BmError* message = new BmError( aMessage, BmError::ErrorType(type) );
    if ( type == DEBUG_MESSAGE )
    {
#ifdef _DEBUG_
        em->pushError( message ); // Only push debug messages when in debug mode
#endif
    }
    else
        em->pushError( message );
}
