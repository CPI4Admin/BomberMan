#include "joinparty.h"
#include "ui_joinparty.h"

    #include "bmnetworktcpclient.h"
    #include "bytebuffer.h"
    #include "bmmessage.h"
    #include "bmerrormanager.h"
    #include <QtNetwork>
    #include <QByteArray>
    #include <QCoreApplication>
    #include <QDataStream>
    #include <QDateTime>
    #include <QMessageBox>
    #include <QTcpSocket>
    #include <QAbstractSocket>


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

    // Cela fonctionne, j'arrive à me connecter sur le serveur
    QTcpSocket* socket;
    socket = new QTcpSocket(this);
    socket->abort();
    socket->connectToHost(ui->lineEditIPServer->text(), ui->spinBoxPortListen->value());

    if (socket->state() == QAbstractSocket::UnconnectedState )
        BmErrorManager::pushMessage( tr("Erreur de connection !!").arg(sock->errorString()),
                                 BmErrorManager::DEBUG_MESSAGE);


    //cela ne fonctionne pas, je ne comprends pas l'erreur lié au nombre de para en sortie de compilation
    //BmNetworkTCPClient::connectedTo(ui->lineEditIPServer->text(), ui->spinBoxPortListen->value());
    //BmNetworkTCPClient::mSocket->connectToHost(ui->lineEditIPServer->text(), ui->spinBoxPortListen->value());

}
