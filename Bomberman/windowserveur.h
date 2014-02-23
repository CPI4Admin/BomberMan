#ifndef WINDOWSERVEUR_H
#define WINDOWSERVEUR_H

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
#include <QDialog>

namespace Ui {
class windowserveur;
}

class windowserveur : public QTcpServer
{
    Q_OBJECT

public:
    explicit windowserveur(QWidget *parent = 0);
    ~windowserveur();
    void DemarrerServeur();
    void ArreterServeur();
    void nouvelleConnexion();
    void deconnexionClient();


private:
    QList<QTcpSocket *> clients; // Gere un tableau contenant la liste des clients
};

#endif // WINDOWSERVEUR_H
