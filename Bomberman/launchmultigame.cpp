#include "launchmultigame.h"
#include "ui_launchmultigame.h"
#include "windowserveur.h"
#include <QMessageBox>

LaunchMultiGame::LaunchMultiGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LaunchMultiGame)
{
    ui->setupUi(this);
    connect(ui->bt_OK,SIGNAL(clicked()),this,SLOT(LancerPartie()));
    connect(ui->bt_Fermer,SIGNAL(clicked()), this, SLOT(close()));
}

LaunchMultiGame::~LaunchMultiGame()
{
    delete ui;
}

void LaunchMultiGame::LancerPartie()
{
    if(ui->rB_Heberger->isChecked())
    {
        windowserveur* server = new windowserveur();
        server->DemarrerServeur();

        QMessageBox msg;
        msg.setText("Vous venez de démarrer une parite multi-joueur en tant que joueur hôte.");
        msg.exec();

        //TODO: Modifier affichage

    }
    else if(ui->rB_Rejoindre->isChecked())
    {
        // TODO: Tester si les txt sont bien rempli

        // TODO: Se connecter en tant que client à un server

        // TODO: Modifier l'affichage
        resize(300,115);
        //Afficher le chat


        QMessageBox msg;
        msg.setText("Vous venez de rejoindre une parite multi-joueur.");
        msg.exec();
    }
}
