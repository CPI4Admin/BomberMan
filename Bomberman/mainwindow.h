#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//---- Partie Modifié le 30/01/2014
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QFile>
#include <QTextEdit>
#include <QString>
#include <QTextStream>
#include <QInputDialog>
//---- Fin modif

namespace Ui {
class MainWindow;
class Statistics;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT       

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void BeginPartySolo();
    void BeginPartyMulti();
    void LoadPartySolo();
    void LoadPartyMulti();
    void SavePartySolo();
    void Quit();
    void GameControls();
    void DisplaySetting();
    void AudioSetting();
    void Help();
    void Credits();
    void nouvelleConnexion();
    void deconnexionClient();
    void Statistics();

private:
    Ui::MainWindow *ui;
    //---- Partie Modifié le 30/01/2014
    QLabel *etatServeur;
    QTcpServer *serveur; // Represente le serveur sur le reseau
    QList<QTcpSocket *> clients; // Gere un tableau contenant la liste des clients
    //---- Fin modif
};

#endif // MAINWINDOW_H
