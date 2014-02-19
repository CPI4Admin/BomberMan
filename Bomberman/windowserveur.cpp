#include "windowserveur.h"
#include "ui_windowserveur.h"
#include <QMessageBox>
#include <QTime>

windowserveur::windowserveur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::windowserveur)
{
    serveur = new NetworkServer(this);

    ui->setupUi(this);

    connect(ui->btStartServer,SIGNAL(clicked()),this, SLOT(StartServer()));
    connect(ui->btStopServer,SIGNAL(clicked()),this, SLOT(StopServer()));
    connect(ui->btQuitterServer,SIGNAL(clicked()),this,SLOT(close()));
}

windowserveur::~windowserveur()
{
    delete ui;
}

void windowserveur::StartServer()
{
        serveur = new NetworkServer(this);

        ui->label_1->setText("Le serveur est maintenant démarré." );

       // Test Erreur 01
       // Si le serveur n'est pas déja démarré
       if(serveur->StartServeur())
       {
           ui->label_1->setText("Le serveur a été demarré sur le port :<strong>" + QString::number(serveur->serverPort()));

       }else{
           // Si le serveur n'a pas ete demarre correctement
           ui->label_1->setText("Le serveur est déja demarré !!<strong>");
           ui->label_2->setText(serveur->errorString());
       }
}
void windowserveur::StopServer()
{
        // changer text label
        ui->label_1->setText("Le serveur est arreté.");
        serveur->deleteLater();
}



