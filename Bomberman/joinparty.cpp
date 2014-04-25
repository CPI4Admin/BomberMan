#include "joinparty.h"
#include "ui_joinparty.h"
#include "bmnetworktcpclient.h"
#include <QMessageBox>
#include "bmerrormanager.h"
#include "BmError.h"

JoinParty::JoinParty(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JoinParty)
{
    ui->setupUi(this);

    connect(ui->btJointParty,SIGNAL(clicked()),this, SLOT(ConnectParty()));
    connect(ui->btQuitParty,SIGNAL(clicked()),this,SLOT(close()));
}

JoinParty::~JoinParty()
{
    delete ui;
}

void JoinParty::ConnectParty()
{
    const QHostAddress host =  QHostAddress(ui->lineEditIPServer->text());
    int Port = ui->spinBoxPortListen->value();
    BmNetworkTCPClient* monClient = new BmNetworkTCPClient(host,Port,true);
    if(monClient->isConnected())
    {
        QMessageBox msg;
        msg.setText("Vous êtez connecté à la partie !!");
        msg.exec();
    }
    else
    {
        //QString errors;

        //for(std::list<BmError *>::iterator it = BmErrorManager::getInstance()->getErrors().begin(); it != BmErrorManager::getInstance()->getErrors().end(); it++)
        //{
            /* TODO : Parcours de la liste d'erreur*/
        //}


        QMessageBox msg;
        //msg.setText(errors);
        msg.setText("Vous n'êtez pas connecté !!");
        msg.exec();
    }


    /*
    close();

    QMessageBox msg;
    msg.setText("Vous êtez connecté à la partie !!");
    msg.exec();*/
}
