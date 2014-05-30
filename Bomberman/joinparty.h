#ifndef JOINPARTY_H
#define JOINPARTY_H

#include "bmnetworktcpclient.h"

#include <QMainWindow>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QTextEdit>
#include <QDialog>
#include <QMessageBox>



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
    BmNetworkTCPClient* mSocket;

private slots:
    void connectParty();
    void showError();
    void connecToBis(const QString&);

};

#endif // JOINPARTY_H
