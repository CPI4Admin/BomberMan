#ifndef NETWORKSERVER_H
#define NETWORKSERVER_H

#include "mainwindow.h"

#include <QTcpServer>
#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QLabel>

class NetworkServer : public QTcpServer
{
    Q_OBJECT

public:
    explicit NetworkServer(QObject *parent = 0);

    bool StartServer();
    bool StopServer();
    bool QuitServer();

private:

    QList<QTcpSocket *> clients; // Gere un tableau contenant la liste des clients.
    QTcpServer *server;


signals:

public slots:

private slots:

    void NewConnection();
    void DisConnection();



};

#endif // NETWORKSERVER_H
