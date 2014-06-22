#include "windowstatistics.h"
#include "ui_windowstatistics.h"
#include "currentProfile.h"

windowstatistics::windowstatistics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::windowstatistics)
{
    ui->setupUi(this);
    connect(ui->btQuitter,SIGNAL(clicked()),this,SLOT(close()));

    currentProfile* user  = currentProfile::getInstance();
    ui->txtPartiesJouees->setText(QString::number(user->getNbPartie()));
    ui->txtPartiesGagnees->setText(QString::number(user->getNbVictoire()) + " / " + QString::number(user->getNbPartie()));
    ui->txtPartiesPerdues->setText(QString::number(user->getNbDefaite()) + " / " + QString::number(user->getNbPartie()));
}

windowstatistics::~windowstatistics()
{
   delete ui;
}
