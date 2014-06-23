#include "paramwindows.h"
#include "ui_paramwindows.h"


ParamWindows::ParamWindows(QWidget *parent, int modeOuverture) :
    QDialog(parent),
    ui(new Ui::ParamWindows)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(modeOuverture);
    FillCbResolution();
    FillCbPlaylist();
    connect(ui->cboResolution,SIGNAL(currentIndexChanged(int)),this,SLOT(ChangeResolution()));
    connect(ui->cboPlaylist,SIGNAL(currentIndexChanged(int)),this,SLOT(AddMusic()));
    connect(ui->btValider,SIGNAL(clicked()),this,SLOT(AddMusic()));

}

ParamWindows::~ParamWindows()
{
    delete ui;
}

void ParamWindows::FillCbResolution()
{
    ui->cboResolution->addItem("800x600");
    ui->cboResolution->addItem("1024x600");
    ui->cboResolution->addItem("1280x720");
    ui->cboResolution->addItem("1440x990");
    ui->cboResolution->addItem("1920x1080");
}

void ParamWindows::FillCbPlaylist()
{
    ui->cboPlaylist->addItem("Morceau 1");
    ui->cboPlaylist->addItem("Morceau 2");
    ui->cboPlaylist->addItem("Morceau 3");
}

void ParamWindows::ChangeResolution()
{
    //TODO: Changer la résolution en fonction de la selection
}
void ParamWindows::AddMusic()
{

}
