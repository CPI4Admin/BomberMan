#include "widgetchat.h"
#include "ui_widgetchat.h"
#include <QMessageBox>
widgetChat::widgetChat(QWidget *parent,QList<QString> *listJoueur) :
    QWidget(parent),
    ui(new Ui::widgetChat)
{
    ui->setupUi(this);
    connect(ui->btQuitterChat,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->btSendMessages,SIGNAL(clicked()),this,SLOT(SendMessages()));

    //Parcourir la liste des joueur et remplir la liste view avec celle ci
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
     //Ecrire le message dans l'historique sous forme "Nomdujoueur : message"
     ui->affichageMessages->insertPlainText(JoueurQuiLaEnvoyer + " : " + msg + "\n");
}

 void widgetChat::SendMessages()
{
    EcrireMessage(ui->saisiMessage->text(),"Moi");
    ui->saisiMessage->setText("");
}
