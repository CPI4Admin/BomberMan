#ifndef WIDGETCHAT_H
#define WIDGETCHAT_H

#include <QWidget>
#include "networkclient.h"
#include "networkserver.h"

namespace Ui {
class widgetChat;
}

class widgetChat : public QWidget
{

public:
    explicit widgetChat(QWidget *parent = 0, NetworkServer *server = new NetworkServer());
    ~widgetChat();

    void WriteMessages(QString msg, QString JoueurQuiLaEnvoye);

public slots:
    void GetMessages(QString msg, QString JoueurQuiLaEnvoye);
    void SendMessages();

private:
    Ui::widgetChat *ui;
    QList<NetworkClient*> ListClient;
    NetworkServer *Server;

private slots:

};

#endif // WIDGETCHAT_H
