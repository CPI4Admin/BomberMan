#ifndef BMERRORMANAGER_H
#define BMERRORMANAGER_H

#include <QObject>

class BmError;

class BmErrorManager : public QObject
{
    Q_OBJECT

private:
    std::list<BmError*> mErrors; /*!< The list of errors received by COCon server managed by this manager. */
    static BmErrorManager* mSelf; /*!< Singleton. */

public:
    /**
     * \enum LogTypes
     * \brief specifies the different types of logging messages
     */
    enum MessageType
    {
        CRITICAL_MESSAGE = 0, /**< Message issued for critical errors */
        DEBUG_MESSAGE, /**< Message issued for debug purposes */
        INFO_MESSAGE, /**< Message issued for information purposes */
        WARNING_MESSAGE /**< Message issued for warnings */
    };

    static void destroy();
    std::list<BmError*> getErrors() const;
    static BmErrorManager* getInstance();
    BmError* popError();
    void pushError( BmError* anError );
    static void pushMessage( const QString& aMessage, MessageType type = DEBUG_MESSAGE );

signals:
    /**
     *  This signal is emitted each time a new internal message is
     *  pushed in the incoming messages list
     *  Connect to this signal in order to process the message
     */
    void errorReceived();

protected:
    ~BmErrorManager();

private:
    BmErrorManager();
};

#endif // BMERRORMANAGER_H
