#ifndef NETWORKCLIENT_H
#define NETWORKCLIENT_H

#include <QTcpSocket>

class NetworkClient
{
public:
    NetworkClient();
    QTcpSocket* socket;
};

#endif // NETWORKCLIENT_H
