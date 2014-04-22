#include "networkclient.h"

NetworkClient::NetworkClient()
{
    port = 4000; //Pourquoi pas ?
    QObject::connect(&socket, SIGNAL(connected),this, SLOT(connectionOK())); // Le socket est conneter!
    QObject::connect(&socket,SIGNAL(readyRead()), this, SLOT(readMessage()));
}

void NetworkClient::receiveIP(QString IP2)
{
    IP = IP2;
    soc.connectToHost(IP, port);
}

void NetworkClient::receiveMessage(Message msg)
{
    /* TODO: Traitement du message */
}

void NetworkClient::connectionOK()
{
    emit connectionOkSignal();
}

void NetworkClient::readMessage()
{
    QString ligne;
    while(socket.canReadLine())
    {
        ligne = socket.readLine();
        /* TODO: Serialisation du message à partir de la ligne */
        Message = new Message();
        emit MessageReceived(Message);
    }
}
