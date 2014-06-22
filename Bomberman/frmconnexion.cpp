#include "frmconnexion.h"
#include "ui_frmconnexion.h"
#include "currentProfile.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QCryptographicHash>

frmConnexion::frmConnexion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmConnexion)
{
    ui->setupUi(this);

    ui->txtPassword->setEchoMode(QLineEdit::Password);

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
        int nbConnexion, nbPartie, nbVictoire, nbDefaite;

        QString chaine=ui->txtPassword->text(); // On crée la chaine à hacher

        QByteArray ba =  QCryptographicHash::hash( QByteArray (
        QCryptographicHash::hash (QString("SEL_AVANT").toUtf8(), QCryptographicHash::Md5) + QCryptographicHash::hash (chaine.toUtf8(), QCryptographicHash::Md5) +  QCryptographicHash::hash( QString("SEL_APRES").toUtf8(), QCryptographicHash::Md5)), QCryptographicHash::Sha1); // on la hache

        QString motdepasse=ba.toHex(); // on convertit le hash en QString

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
                    currentProfile *user = currentProfile::getInstance(pseudo,motdepasse,nbConnexion + 1, nbPartie, nbVictoire, nbDefaite);
                    user->MAJProfil();

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

                currentProfile *user = currentProfile::getInstance(pseudo,motdepasse,1,0,0,0);

                msg.setText("Le fichier profiles.csv et le profil utilisateur " + user->getPseudo() +" ont été crée.\n Connecté au profil: " + user->getPseudo());
                msg.exec();
                user->MAJProfil();

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

        QString chaine=ui->txtPassword->text(); // On crée la chaine à hacher
        QByteArray ba =  QCryptographicHash::hash( QByteArray (QCryptographicHash::hash (QString("SEL_AVANT").toUtf8(), QCryptographicHash::Md5) + QCryptographicHash::hash (chaine.toUtf8(), QCryptographicHash::Md5) +  QCryptographicHash::hash( QString("SEL_APRES").toUtf8(), QCryptographicHash::Md5)), QCryptographicHash::Sha1); // on la hache
        QString motdepasse=ba.toHex();

        QFile profiles(QApplication::applicationDirPath() +"/profiles.csv");

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
                    if(detailsLine[0] == pseudo)
                    {
                        trouve = true;
                    }
                }
                profiles.close();
            }
            if(!trouve)
            {
                if (profiles.open(QIODevice::Append | QIODevice::Text))
                {
                    QTextStream flux(&profiles);
                    QString contenu = flux.readAll();
                    QString texte = contenu + "\n" + pseudo+ ";" + motdepasse+ ";1;0;0;0";
                    flux << texte;

                    profiles.close();

                    currentProfile::getInstance(pseudo,motdepasse,1,0,0,0);

                    emit connexionOk();
                    this->close();
                }
            }
            else
            {
                    msg.setText("Ce pseudo existe déjà. Veuiller en choisir un autre.");
                    msg.exec();
            }
        }
        else
        {
            msg.setText("Problème d'accès au fichier profiles.csv.");
            msg.exec();
        }

    }
}
