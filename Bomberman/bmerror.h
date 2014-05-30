#ifndef BMERROR_H
#define BMERROR_H

#include <QString>

class BmError
{
public:
    /**
     * \enum ErrorType
     * \brief specifies the different types of errors
     */
    enum ErrorType
    {
        CRITICAL = 0, /**< The error is critical and has an impact on the server behavior */
        DEBUG, /**< Debug is not an error and is just a debug indication (internal use only) */
        INFO, /**< Information. This is not a warning or an error */
        WARNING /**< Warning is not an error but deserves attention */
    };

private:
    QString mMessage; /*!< This error message. */
    ErrorType mType; /*!< This error type. */

public:
    BmError( const QString& aMessage, ErrorType aType );
    virtual ~BmError();

    const QString& getMessage() const;
    ErrorType getType() const;
};

#endif // BMERROR_H
