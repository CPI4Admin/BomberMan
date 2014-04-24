#include "windowserveur.h"
#include "ui_windowserveur.h"
#include "bmnetworktcpserver.h"

windowserveur::windowserveur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::windowserveur)
{

    server = new BmNetworkTCPServer();

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
    server->start();
}

void windowserveur::StopServer()
{
}

void windowserveur::QuitServer()
{
}
