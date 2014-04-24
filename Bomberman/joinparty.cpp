#include "joinparty.h"
#include "ui_joinparty.h"

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
    close();

    QMessageBox msg;
    msg.setText("Vous êtez connecté à la partie !!");
    msg.exec();
}
