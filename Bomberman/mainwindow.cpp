#include "mainwindow.h"
#include "paramwindows.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QDialog>
#include "windowstatistics.h"
#include "createpartymultigamer.h"
#include "launchsologame.h"
#include "widgetchat.h"
#include "joinparty.h"
#include "frmconnexion.h"
#include "help.h"
#include <QAction>
#include "currentProfile.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Maximize the window
    showMaximized();

    // Play welcome sound
    QSound::play(":/sons/welcome");

    //Show welcome message
    ui->statusBar->showMessage("Non connecté - Bienvenue sur BOMBERMAN.", 15000);
    frmConnexion* frmConnect = new frmConnexion();
    frmConnect->show();


    // Linking buttons to action triggered
    connect(ui->actionDemarrerPartieSolo,SIGNAL(triggered()),this,SLOT(BeginPartySolo()));
    connect(ui->actionDemarrerPartieMulti,SIGNAL(triggered()),this,SLOT(BeginPartyMulti()));
    connect(ui->actionChargerPartieSolo,SIGNAL(triggered()),this,SLOT(LoadPartySolo()));
    connect(ui->actionChargerPartieMulti,SIGNAL(triggered()),this,SLOT(LoadPartyMulti()));
    connect(ui->actionSauvegarderPartieSolo,SIGNAL(triggered()),this,SLOT(SavePartySolo()));
    connect(ui->actionQuitter,SIGNAL(triggered()),this,SLOT(Quit()));
    connect(ui->actionCommandes_de_jeu,SIGNAL(triggered()),this,SLOT(GameControls()));
    connect(ui->actionAffichage,SIGNAL(triggered()),this,SLOT(DisplaySetting()));
    connect(ui->actionAudio,SIGNAL(triggered()),this,SLOT(AudioSetting()));
    connect(ui->actionAide,SIGNAL(triggered()),this,SLOT(Help()));
    connect(ui->actionA_propos,SIGNAL(triggered()),this,SLOT(Credits()));
    connect(ui->actionAffichageStatistics,SIGNAL(triggered()),this,SLOT(Statistics()));
    connect(frmConnect,SIGNAL(connexionOk()),this,SLOT(UtilisateurConnecte()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::BeginPartySolo()
{
    /*QMessageBox msg;
    msg.setText("Vous venez de lancer une partie solo.");
    msg.exec();*/

    LaunchSoloGame* formsologame = new LaunchSoloGame(this);
    formsologame->show();
    ui->statusBar->showMessage("Lancez une nouvelle partie solo.", 15000);
}

void MainWindow::UtilisateurConnecte()
{
    currentProfile* user  = currentProfile::getInstance();
    ui->statusBar->showMessage("Connecté - Bienvenue sur BOMBERMAN " + user->getPseudo() + ".", 15000);
}

void MainWindow::BeginPartyMulti()
{

    createpartymultigamer* CreatePartyMultiGamer;
    CreatePartyMultiGamer = new createpartymultigamer(this);
    CreatePartyMultiGamer->exec();


    //Test du module chat
    //Ajout du widgetChat

    QList<QString> *listJoueur = new QList<QString>();
    listJoueur->insert(0,"toto");
    widgetChat *Chat = new widgetChat(this,listJoueur);
    Chat->setGeometry(10,40,590,500);
    Chat->show();


    ui->statusBar->showMessage("Vous avez lancé la partie multijoueur.", 15000);
}

void MainWindow::LoadPartySolo()
{   
    // Ouverture du dossier parent de la solution et filtre sur les fichiers de type texte pour sélection fichier à ouvrir
    QString fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Fichiers texte (*.txt)");

    // Message d'information provisoire indiquant le chemin d'accès au fichier à ouvrir
    // QMessageBox::information(this, "Fichier", "Vous avez ouvert le fichier :\n" + fichier);

    // on déclare la variable de type fichier, puis on l'ouvre en mode "lecture seule"
    QFile fichierACharger(fichier);

    if (fichierACharger.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream flux (&fichierACharger);

        QString ligne;

        // On parcours ensuite le fichier ligne par ligne en y appliquant un traitement : ici affichage d'une messageBox
        while(! flux.atEnd())
        {
            ligne = flux.readLine();

            QMessageBox msg;
            msg.setText(ligne);
            msg.exec();
        }
    }
}

void MainWindow::LoadPartyMulti()
{
    /*QMessageBox msg;
    msg.setText("Vous venez de charger une partie multi.");
    msg.exec();
    ui->statusBar->showMessage("Vous avez chargé une partie multijoueur.", 15000);*/

    JoinParty* JoinPartyMulti;
    JoinPartyMulti = new JoinParty(this);
//JoinPartyMulti->setGeometry(50,100,200,190);
    JoinPartyMulti->show();
}

void MainWindow::SavePartySolo()
{
    // On ouvre une boite de dialogue permettant la sauvegarde d'un fichier
    QString path = QFileDialog::getSaveFileName(this, "Enregistrer un fichier", QString("*.txt"), "Fichiers texte (*.txt);; Tous les fichiers (*.*)");

    // On crée le fichier ou écrase un existant
    QFile file(path);

    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        out << "J'ai sauvegardé le fichier " + path;

        file.close();

        ui->statusBar->showMessage("Partie sauvegardée : " + path, 15000);
    }
}

void MainWindow::Quit()
{
    QSound::play(":/sons/goodbye");

    if (QMessageBox::Yes == QMessageBox(QMessageBox::Warning, "Confirmation de sortie.", "Êtes-vous sûr de vouloir quitter BomberMan ?", QMessageBox::Yes|QMessageBox::No).exec())
    {
        exit(true);
    }
}


void MainWindow::GameControls()
{
    ParamWindows* paramForm;
    paramForm = new ParamWindows(this, 2);
    paramForm->show();
}

void MainWindow::DisplaySetting()
{
    ParamWindows* paramForm;
    paramForm = new ParamWindows(this, 1);
    paramForm->show();
}

void MainWindow::AudioSetting()
{
    ParamWindows* paramForm;
    paramForm = new ParamWindows(this, 0);
    paramForm->show();
}

void MainWindow::Help()
{

    help* helpWindow = new help(this);

    // helpWindow->show(); // Roman : 30/05/2014 : Mis en commentaire car s'ouvre déjà deans la classe help

    ui->statusBar->showMessage("Vous venez de fermer la fenêtre d'Aide.", 15000);

 }

void MainWindow::Credits()
{
    /*QMessageBox msg;
    msg.setText("Vous venez d'ouvrir les configurations audio.");
    msg.exec();*/

    QMessageBox::about(this, tr("BomberMAN"),
                 tr("The <b>BomberMAN</b>  is a strategic, maze-based video game franchise originally developed by Hudson Soft. The original game was published in 1983 and new games have been published at irregular intervals ever since.                Several titles in the 2000s were published by fellow Japanese game company Konami, who gained full control of the franchise when they purchased and absorbed Hudson in 2012. Today, Bomberman has featured in over 70 different games on numerous platforms (including all Nintendo platforms save for the 3DS and Wii U), as well as several anime and manga.His franchise is one of the most commercially successful of all time.    <br><b>Realised by the Dream-Team : </b></br> <br>Petra Kratochvilova</br> <br>Thibaud Cutullic</br><br>Yoann Solacroup</br><br>Yann Damon</br><br>Gregoire Quincy</br><br>Roman Logvinov</br><br>Damien Moro</br>"));
}

void MainWindow::Statistics()
{
    windowstatistics* Stats;
    Stats = new windowstatistics(this);
    Stats->setGeometry(50,100,490,190);
    Stats->exec();
    ui->statusBar->showMessage("Vous avez consulté les statistics.", 15000);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event && event->key() == Qt::Key_F1) {
        Help();// Ouvre la fenêtre d'aide
 }
}


//Cela fonction mais lance la fenetre 3 fois
/*bool MainWindow::event(QEvent *event)//Test lancement fenetre Aide en appuant la touche "F1"
{
    QKeyEvent* kevent = static_cast<QKeyEvent*>(event);
    if(kevent && kevent ->key() == Qt::Key_F1)
        Help();
    return true;

}
*/

