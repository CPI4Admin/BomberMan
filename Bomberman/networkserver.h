#ifndef NETWORKSERVER_H
#define NETWORKSERVER_H

#include <QTcpServer>

class NetworkServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit NetworkServer(QObject *parent = 0);
    bool start();

signals:

public slots:

private slots:
    void nouvelleConnexion();
    void deconnexionClient();

private:
    QList<QTcpSocket *> clients; // Gere un tableau contenant la liste des clients


};

#endif // NETWORKSERVER_H
