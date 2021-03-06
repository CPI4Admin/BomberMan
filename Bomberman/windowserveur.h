#ifndef WINDOWSERVEUR_H
#define WINDOWSERVEUR_H

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
class windowserveur;
}

class windowserveur : public QDialog
{
    Q_OBJECT

public:
    explicit windowserveur(QWidget *parent = 0);
    ~windowserveur();

private:
    Ui::windowserveur *ui;
    BmNetworkTCPServer* server;

private slots:
    void StartServer();
    void StopServer();
    void QuitServer();

};

#endif // WINDOWSERVEUR_H
