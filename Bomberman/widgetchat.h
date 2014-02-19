#ifndef WIDGETCHAT_H
#define WIDGETCHAT_H

#include <QWidget>

namespace Ui {
class widgetChat;
}

class widgetChat : public QWidget
{
    Q_OBJECT

public:
    explicit widgetChat(QWidget *parent = 0, QList<QString> *listJoueur = new QList<QString>());
    ~widgetChat();
    void EcrireMessage(QString msg, QString JoueurQuiLaEnvoyer);

public slots:
    void RecevoirMessage(QString msg, QString JoueurQuiLaEnvoyer);

private:
    Ui::widgetChat *ui;

private slots:
    void SendMessages();
};

#endif // WIDGETCHAT_H
