#ifndef BMNETWORK_H
#define BMNETWORK_H

#include <QtNetwork/QHostAddress>

class BmNetwork : public QObject
{
    Q_OBJECT

private:
    QHostAddress mHostAddress;

public:
    BmNetwork( const QHostAddress& aHostAddress = QHostAddress::Any);

    virtual ~BmNetwork();

    const QHostAddress& getHostAddress() const;
};

#endif // BMNETWORK_H
