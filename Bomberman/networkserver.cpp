#include "networkserver.h"


NetworkServer::NetworkServer(QObject *parent) :
    QTcpServer(parent)
{
    listen(QHostAddress::Any,4000);
    clients = new QList<NetworkClient *>();
}

void NetworkServer::newConnection(NetworkClient client)
{
    client.socket = server->nextPendingConnection(); // Gestion des connections clients et de port dans un tableau.
    clients.insert(client);
    QObject::connect(client, SIGNAL(readyRead()), this, SLOT(reading()));
    QObject::connect(client, SIGNAL(disconnect()), this, SLOT(disConnection()));
}

void NetworkServer::disConnection(NetworkClient client)
{
    clients.removeOne(client);
    client.socket->deleteLater();
}

void NetworkServer::reading()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket>(sender());

    if(socket == 0)
        return;

    QDataStream in(socket);
    /*
    if(sizeMessage == 0)
    {
        if(socket->bytesAvailable() < (int)sizeof(quint16))
            return;
    }
    */
    QString message;
    /* TODO: Dérialisation du message */
    Message = new Message();

    for(int i = 0; i < clients.size(); i++)
    {
        if (clients[i]->socket != &socket)
        {
            clients[i]->receiveMessage(message);
        }
    }
}
