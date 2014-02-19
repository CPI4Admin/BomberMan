#include "networkserver.h"
#include <QTcpSocket>
NetworkServer::NetworkServer(QObject *parent) :
    QTcpServer(parent)
{
}

bool NetworkServer::StartServeur()
{
    if (!listen(QHostAddress::Any, 60000)) // Demarrage du serveur sur toutes les IP disponibles et sur le port 60000
    {
        return false;

    }else
    {

        return true;
    }
}

void NetworkServer::nouvelleConnexion()
{
    //** Gestion des connections clients et de port dans un tableau
    QTcpSocket *nouveauClient = this->nextPendingConnection();
    clients << nouveauClient;

}

void NetworkServer::deconnexionClient()
{
     //** On determine quel client se deconnecte
     QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (socket == 0) // Si par hasard on n'a pas trouve le client a l'origine du signal, on arrete la methode
        return;

    clients.removeOne(socket);

    socket->deleteLater();
}
