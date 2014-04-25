#include "createpartymultigamer.h"
#include "ui_createpartymultigamer.h"
#include "bmnetworktcpserver.h"
#include "bmnetworktcpclient.h"

createpartymultigamer::createpartymultigamer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createpartymultigamer)
{

    server = new BmNetworkTCPServer();

    ui->setupUi(this);

    connect(ui->btStartServer,SIGNAL(clicked()),this, SLOT(StartServer()));
    connect(ui->btStopServer,SIGNAL(clicked()),this, SLOT(StopServer()));
    connect(ui->btQuitterServer,SIGNAL(clicked()),this,SLOT(QuitServer()));
}

createpartymultigamer::~createpartymultigamer()
{
    delete ui;
}

void createpartymultigamer::StartServer()
{
    server->start();

}

void createpartymultigamer::StopServer()
{

}

void createpartymultigamer::QuitServer()
{
}
