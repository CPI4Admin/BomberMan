#include "frmconnexion.h"
#include "ui_frmconnexion.h"
#include "currentProfile.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QIODevice>

frmConnexion::frmConnexion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmConnexion)
{
    ui->setupUi(this);

    connect(ui->btConnexion,SIGNAL(clicked()),this,SLOT(ConnexionProfil()));
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
        msg.exec();
    }else if(ui->txtPseudo->text() == "")
    {
        msg.setText("Vous devez impérativement rentrer un pseudo.");
        msg.exec();
    }
    else
    {
        /*TODO: Lire le fichier profiles.csv*/
        QFile profiles(QApplication::applicationDirPath() + "/profiles.csv");
        QString pseudo = ui->txtPseudo->text();
        QString motdepasse = ui->txtPassword->text();
        int nbConnexion, nbPartie, nbVictoire, nbDefaite;

        bool trouve = false;

        if(profiles.exists())
        {
            if(profiles.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                QTextStream flux(&profiles);
                while(!flux.atEnd() && !trouve)
                {
                    QString line = flux.readLine();
                    QStringList detailsLine = line.split(";");
                    if(detailsLine[0] == pseudo && detailsLine[1] == motdepasse)
                    {
                        trouve = true;
                        nbConnexion = detailsLine[2].toInt();
                        nbPartie = detailsLine[3].toInt();
                        nbVictoire= detailsLine[4].toInt();
                        nbDefaite = detailsLine[5].toInt();
                    }
                }

                if(trouve)
                {
                    currentProfile::getInstance(pseudo,motdepasse,nbConnexion, nbPartie, nbVictoire, nbDefaite);

                    msg.setText("Connecté au profil: " + currentProfile::getInstance()->getPseudo());
                    msg.exec();
                    emit connexionOk();
                    this->close();
                }
                else
                {
                    msg.setText("Données d'identifications incorrectes.");
                    msg.exec();
                }
            }
            else
            {
                msg.setText("Problème d'accès au fichier profiles.csv");
                msg.exec();
            }
        }
        else
        {
            if (profiles.open(QIODevice::Append | QIODevice::Text))
            {
                QTextStream flux(&profiles);
                QString contenu = flux.readAll();
                QString texte = pseudo+ ";" + motdepasse+ ";0;0;0;0";
                flux << texte;

                profiles.close();

                currentProfile::getInstance(pseudo,motdepasse,0,0,0,0);

                msg.setText("Le fichier profiles.csv et le profil utilisateur " + currentProfile::getInstance()->getPseudo() +" ont été crée.\n Connecté au profil: " + currentProfile::getInstance()->getPseudo());
                msg.exec();
                emit connexionOk();
                this->close();
            }

        }
    }
}

void frmConnexion::CreationProfil()
{
    QMessageBox msg;
    if(ui->txtPassword->text() == "")
    {
        msg.setText("Vous devez impérativement rentrer un mot de passe.");
        msg.exec();
    }else if(ui->txtPseudo->text() == "")
    {
        msg.setText("Vous devez impérativement rentrer un pseudo.");
        msg.exec();
    }
    else
    {
        /*TODO: Ecrire le fichier profiles.csv*/

        QString pseudo = ui->txtPseudo->text();
        QString motdepasse = ui->txtPassword->text();

        QFile profiles(QApplication::applicationDirPath() +"/profiles.csv");
        if (profiles.open(QIODevice::Append | QIODevice::Text))
        {
            QTextStream flux(&profiles);
            QString contenu = flux.readAll();
            QString texte = contenu + "\n" + pseudo+ ";" + motdepasse+ ";0;0;0;0";
            flux << texte;

            profiles.close();

            currentProfile::getInstance(pseudo,motdepasse,0,0,0,0);

            msg.setText("Connecté au profil: " + currentProfile::getInstance()->getPseudo());
            msg.exec();
            emit connexionOk();
            this->close();
        }
        else
        {
            msg.setText("Problème d'accès au fichier profiles.csv.");
            msg.exec();
        }

    }
}
