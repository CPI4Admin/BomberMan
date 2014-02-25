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

    void WriteMessages(QString msg, QString JoueurQuiLaEnvoye);

public slots:
    void GetMessages(QString msg, QString JoueurQuiLaEnvoye);

private:
    Ui::widgetChat *ui;

private slots:
    void SendMessages();
};

#endif // WIDGETCHAT_H
