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
    socket(0)
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
    // Je crée ma Bm..Socket en me basant sur les infos de la gui
    socket = new BmNetworkTCPClient(QHostAddress( ui->lineEditIPServer->text() ), ui->spinBoxPortListen->value(), false);
    // Je connecte ma Bm..Socket pour récupérer les erreurs lorsqu'elles arrivent
    connect( socket, SIGNAL(connectionError()), this, SLOT(showError()) );
    // Je connecte ma Bm..Socket
    socket->start();
}

void JoinParty::showError()
{
    // Cette methode est appelée lorsque le signal connectionError() est envoyé
    // depuis la classe BmNetworkTCPClient
    // A partir d'ici, on peut afficher le message d'erreur notifiant l'utilisateur
    // du probleme de connexion

    // Je récupère la dernière erreur générée
    BmError* error = BmErrorManager::getInstance()->popError();
    // Je récupère le message
    QString msg = error->getMessage();
}
