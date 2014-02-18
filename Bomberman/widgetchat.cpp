#include "widgetchat.h"
#include "ui_widgetchat.h"

widgetChat::widgetChat(QWidget *parent,QList<QString> *listJoueur) :
    QWidget(parent),
    ui(new Ui::widgetChat)
{
    ui->setupUi(this);
    connect(ui->btQuitterChat,SIGNAL(clicked()),this,SLOT(close()));
    //TODO; Parcourir la liste des joueur et remplir la liste view avec celle ci

    //TODO; connect le bouton a envoyer
}

widgetChat::~widgetChat()
{
    delete ui;

}

void widgetChat::RecevoirMessage(QString msg, QString JoueurQuiLaEnvoyer)
{
    EcrireMessage(msg,JoueurQuiLaEnvoyer);
}


 void widgetChat::EcrireMessage(QString msg, QString JoueurQuiLaEnvoyer)
 {
     //TODO:Ecrire le message dans lhistorique sous forme "Nomdujoueur : message"
 }


 void widgetChat::EnvoyerMessage()
 {
     // Envoyer le message

     // Ecrire dans lhistorique
     EcrireMessage(ui->saisiMessage->text(),"Moi");

 }
