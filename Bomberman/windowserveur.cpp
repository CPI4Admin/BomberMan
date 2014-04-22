#include "windowserveur.h"
#include "ui_windowserveur.h"

windowserveur::windowserveur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::windowserveur)
{

    server = new NetworkServer(this);

    ui->setupUi(this);

    connect(ui->btStartServer,SIGNAL(clicked()),this, SLOT(StartServer()));
    connect(ui->btStopServer,SIGNAL(clicked()),this, SLOT(StopServer()));
    connect(ui->btQuitterServer,SIGNAL(clicked()),this,SLOT(QuitServer()));
}

windowserveur::~windowserveur()
{
    delete ui;
}

void windowserveur::StartServer()
{
    // Test si le serveur ne démarre pas.
    if(!server->StartServer())
      {
        // Le serveur est déja démarré sur le port 60000 ou il ne peut pas démarrer.
        // Renvoi donc un message d'erreur.
        ui->label_1->setText("Le serveur est déja demarré !!<strong>");
        ui->label_2->setText("Le serveur est déja en écoute sur le port :" + QString::number(server->serverError()));

      }else{
            // Le serveur a bien démarré, affichage du port d'écoute pour les clients.
           ui->label_1->setText("Le serveur a été demarré sur le port :<strong>" + QString::number(server->serverPort()));
           ui->label_2->setText("");

            }

}
void windowserveur::StopServer()
{

    // Test si le serveur s'arrête correctement.
    if(!server->StopServer())
      {
        // Le serveur à un problème pour s'arrêter.
        // Renvoi donc un message d'erreur.
        ui->label_1->setText("Le serveur a un problème pour s'arrêter !!! <strong>");
        ui->label_2->setText(QString::number(server->serverError()));

      }else{
           // Le serveur va être arrêté.
           ui->label_1->setText("Le serveur est éteind");
           ui->label_2->setText("");
            }

}

void windowserveur::QuitServer()
{
    // Si je ferme la fenêtre du serveur sans fermer le serveur, il une erreur lors du rappel
    // de la fenêtre du serveur. Je n'arrive à récupérer la gestion du serveur en réouvrant la fenêtre
    // Test si le serveur s'arrête correctement.
    if(!server->StopServer())
      {
        // Le serveur à un problème pour s'arrêter.
        // Renvoi donc un message d'erreur.
        ui->label_1->setText("Le serveur a un problème pour s'arrêter !!! <strong>");
        ui->label_2->setText(QString::number(server->serverError()));

      }else{
           // Le serveur va être arrêté.
           ui->label_1->setText("Le serveur est éteind");
           ui->label_2->setText("");
           close();
            }
}
