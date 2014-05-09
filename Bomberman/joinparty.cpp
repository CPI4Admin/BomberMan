#include "joinparty.h"
#include "ui_joinparty.h"

#include "bmnetworktcpclient.h"
#include "bytebuffer.h"
#include "bmmessage.h"
#include "bmerrormanager.h"
#include "bmerror.h"

JoinParty::JoinParty(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JoinParty),
    mSocket(0)
{
    ui->setupUi(this);

    connect(ui->btJointParty,SIGNAL(clicked()),this, SLOT(connectParty()) );
    connect(ui->btQuitParty,SIGNAL(clicked()),this,SLOT(close()) );
}

JoinParty::~JoinParty()
{
    delete ui;
}

void JoinParty::connectParty()
{
    /* Création du socket client/serveur
    * récupère l'IP et le port saisie par le client */
    mSocket = new BmNetworkTCPClient(QHostAddress(ui->lineEditIPServer->text() ), ui->spinBoxPortListen->value(), false);
    connect(mSocket, SIGNAL(connectionError()), this, SLOT(showError()) );
    mSocket->start();
}
void JoinParty::showError()
{
    /* Méthode appelé au signal connectionError()
    * affichage des erreurs de connexion au client
    * récupération de la dernière erreur dans une QString msg */
    BmError* error = BmErrorManager::getInstance()->popError();
    QString msg = error->getMessage();
    ui->label_3->setText(error->getMessage());

}

