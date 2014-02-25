#include "networkserver.h"


NetworkServer::NetworkServer(QObject *parent) :
    QTcpServer(parent)
{
}

bool NetworkServer::StartServer()
{
    return listen(QHostAddress::Any, 60000); // Demarrage du serveur sur toutes les IP disponibles et sur le port 60000
}

bool NetworkServer::StopServer()
{
    close(); // Arrêt du serveur.
    return true;

}

bool NetworkServer::QuitServer()
{
    close(); // Arrêt du serveur avant fermeture de la fenêtre du serveur.
    return true;

}

void NetworkServer::NewConnection()
{
    QTcpSocket *socket = server->nextPendingConnection(); // Gestion des connections clients et de port dans un tableau.
    socket->disconnect();


}

void NetworkServer::DisConnection()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender()); //On determine quel client se deconnecte.
    if (socket == 0) // Si par hasard on n'a pas trouve le client a l'origine du signal, on arrete la methode
        return;

    clients.removeOne(socket);

    socket->deleteLater();
}
