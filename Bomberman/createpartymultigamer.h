#ifndef CREATEPARTYMULTIGAMER_H
#define CREATEPARTYMULTIGAMER_H

#include <QMainWindow>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QFile>
#include <QTextEdit>
#include <QString>
#include <QTextStream>
#include <QInputDialog>
#include <QDialog>

class BmNetworkTCPServer;

namespace Ui {
class createpartymultigamer;
}

class createpartymultigamer : public QDialog
{
    Q_OBJECT

public:
    explicit createpartymultigamer(QWidget *parent = 0);
    ~createpartymultigamer();

private:
   Ui::createpartymultigamer *ui;
    BmNetworkTCPServer* server;

private slots:
    void StartServer();
    void StopServer();
    void QuitServer();

};

#endif // CREATEPARTYMULTIGAMER_H
