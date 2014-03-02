#ifndef NETWORKSERVER_H
#define NETWORKSERVER_H

#include "mainwindow.h"

#include <QTcpServer>
#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QLabel>
#include "networkclient.h"

class NetworkServer : public QTcpServer
{
    Q_OBJECT

public:
    explicit NetworkServer(QObject *parent = 0);

    bool StartServer();
    bool StopServer();
    bool QuitServer();

    QList<NetworkClient *> clients; // Gere un tableau contenant la liste des clients.

private:

signals:

public slots:

private slots:

    void NewConnection();
    void DisConnection();



};

#endif // NETWORKSERVER_H
