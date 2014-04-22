#ifndef NETWORKCLIENT_H
#define NETWORKCLIENT_H

#include <QTcpSocket>

class NetworkClient : public QObject
{
public:
    NetworkClient();

public slots :
    void receiveIP(QString IP2);
    void receiveMessage(Message msg)

private slots :
    void connectionOK();
    void readMessage();
signals:
    void MessageReceived(Message msg);
    void connectionOkSignal();
private:
    QString IP;
    int port;
    QTcpSocket socket;
};

#endif // NETWORKCLIENT_H
