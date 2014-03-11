#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
#include <Qdialog>
#include <QFileDialog>
#include <QAbstractSocket>

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
    void Statistics();

private:
    Ui::MainWindow *ui;

                                                                             //QTcpServer *server;
};
#endif //MAINWINDOW_H
