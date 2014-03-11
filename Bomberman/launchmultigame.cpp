#include "launchmultigame.h"
#include "ui_launchmultigame.h"
#include "networkserver.h"
#include "networkclient.h"
#include "widgetchat.h"
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
        NetworkServer* server = new NetworkServer();
        server->StartServer();

        QMessageBox msg;
        msg.setText("Vous venez de démarrer une parite multi-joueur en tant que joueur hôte.");
        msg.exec();

        // TODO: Se connecter en tant que client au server.
        NetworkClient *monClient = new NetworkClient();


        //TODO: Modifier affichage
        ui->rB_Heberger->setVisible(false);
        ui->rB_Rejoindre->setVisible(false);
        ui->txt_IP->setVisible(false);
        ui->txt_Port->setVisible(false);
        resize(1200,800);

        widgetChat *Chat = new widgetChat(this, server);
        Chat->setGeometry(10,40,590,500);
        Chat->show();

        // TODO: Replacer les boutons
    }
    else if(ui->rB_Rejoindre->isChecked())
    {
        // TODO: Tester si les txt sont bien rempli

        // TODO: Se connecter en tant que client à un server

        // TODO: Modifier l'affichage
        resize(1200,800);
        //Afficher le chat


        QMessageBox msg;
        msg.setText("Vous venez de rejoindre une parite multi-joueur.");
        msg.exec();
    }
}
