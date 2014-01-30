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
//---- Fin modif

namespace Ui {
class MainWindow;
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

    //---- Partie Modifié le 30/01/2014
    void nouvelleConnexion();
    void deconnexionClient();
    //---- Fin modif

private:
    Ui::MainWindow *ui;
    //---- Partie Modifié le 30/01/2014
    QLabel *etatServeur;
    QTcpServer *serveur; // Represente le serveur sur le reseau
    QList<QTcpSocket *> clients; // Gere un tableau contenant la liste des clients
    //---- Fin modif
};

#endif // MAINWINDOW_H
