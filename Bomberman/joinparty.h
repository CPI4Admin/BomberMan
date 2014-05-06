#ifndef JOINPARTY_H
#define JOINPARTY_H

#include <QMainWindow>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QTextEdit>
#include <QDialog>
#include <QMessageBox>

    #include "bmnetworktcpclient.h"

class BmNetworkTCPClient;

namespace Ui {
class JoinParty;
}

class JoinParty : public QDialog
{
    Q_OBJECT

public:
    explicit JoinParty(QWidget *parent = 0);
    ~JoinParty();
private:
    Ui::JoinParty *ui;
    BmNetworkTCPClient* socket;

private slots:
    void connectParty();
    void showError();

};

#endif // JOINPARTY_H
