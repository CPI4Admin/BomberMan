#ifndef NETWORKSERVER_H
#define NETWORKSERVER_H

#include "mainwindow.h"
#include "networkclient.h"
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

private:
    QList<NetworkClient *> clients; // Gere un tableau contenant la liste des clients.

signals:
    void sendMessage(Message msg);
    void newConnectionSignal(NetworkClient);

private slots:
    void newConnection();
    void disConnection();
    void reading();

};

#endif // NETWORKSERVER_H
