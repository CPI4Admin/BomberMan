#include "frmconnexion.h"
#include "ui_frmconnexion.h"
#include "currentProfile.h"
#include <QMessageBox>

frmConnexion::frmConnexion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmConnexion)
{
    ui->setupUi(this);

    connect(ui->btBox,SIGNAL(accepted()),this,SLOT(ConnexionProfil()));
    connect(ui->btBox,SIGNAL(rejected()),this,SLOT(close()));
    connect(ui->btCreation,SIGNAL(clicked()),this, SLOT(CreationProfil()));
}

frmConnexion::~frmConnexion()
{
    delete ui;
}

void frmConnexion::ConnexionProfil()
{
    QMessageBox msg;
    if(ui->txtPassword->text() == "")
    {
        msg.setText("Vous devez impérativement rentrer un mot de passe.");
        msg.show();
    }else if(ui->txtPseudo->text() == "")
    {
        msg.setText("Vous devez impérativement rentrer un pseudo.");
        msg.show();
    }
    else
    {
        /*TODO: Lire le fichier profiles.csv*/

        QString pseudo = ui->txtPseudo->text();
        QString motdepasse = ui->txtPassword->text();

        currentProfile::getInstance(pseudo,motdepasse,0,0,0,0);

        msg.setText("Connecté au profil :" + currentProfile::getInstance()->pseudo);
        msg.show();
    }
}

void frmConnexion::CreationProfil()
{

}
