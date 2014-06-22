#include "currentProfile.h"
#include <QCryptographicHash>
#include <QFile>
#include <QTextStream>
#include <QApplication>

currentProfile* currentProfile::instance = 0;

currentProfile::currentProfile(QString _pseudo,QString _motdepasse,int _nbConnexion,int _nbPartie,int _nbVictoire,int _nbDefaite)
{
    pseudo = _pseudo;
    motDePasse = _motdepasse;
    nbConnexion = _nbConnexion;
    nbDefaite = _nbDefaite;
    nbVictoire = _nbVictoire;
    nbPartie = _nbPartie;
}

currentProfile* currentProfile::getInstance(QString _pseudo,QString _motdepasse,int _nbConnexion,int _nbPartie,int _nbVictoire,int _nbDefaite)
{
    if (!instance)
        instance = new currentProfile(_pseudo,_motdepasse,_nbConnexion,_nbPartie,_nbVictoire,_nbDefaite);

    return instance;
}

currentProfile* currentProfile::getInstance()
{
    if (!instance)
        return NULL;
    else
        return instance;
}

QString currentProfile::getPseudo()
{
    return pseudo;
}

QString currentProfile::getMotDePasse()
{
    return motDePasse;
}

int currentProfile::getNbConnexion()
{
    return nbConnexion;
}

int currentProfile::getNbVictoire()
{
    return nbVictoire;
}

int currentProfile::getNbDefaite()
{
    return nbDefaite;
}

int currentProfile::getNbPartie()
{
    return nbPartie;
}

void currentProfile::MAJProfil()
{
    QFile profiles(QApplication::applicationDirPath() + "/profiles.csv");

    QString texte = pseudo+ ";" + motDePasse + ";" + QString::number(nbConnexion) + ";" + QString::number(nbPartie) + ";" + QString::number(nbVictoire) + ";" + QString::number(nbDefaite);

    bool trouve = false;
    QString lineTrouve;

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
                    lineTrouve = line;
                    trouve = true;
                }
            }
        }
        profiles.close();

        if(trouve)
        {
            if(profiles.open(QIODevice::ReadWrite | QIODevice::Text))
            {
                QTextStream flux(&profiles);
                QString fileStr = flux.readAll();
                fileStr.replace(lineTrouve, texte);
                profiles.resize(0);
                QTextStream (&profiles) << fileStr;
            }
            profiles.close();
        }
    }
}

void currentProfile::setMotDePasse(QString value)
{
        motDePasse = value;
        MAJProfil();
}

void currentProfile::setNbConnexion(int value)
{
    if (value =! NULL)
    {
        nbConnexion = value;
        MAJProfil();
    }
}

void currentProfile::setNbVictoire(int value)
{
    if (value =! NULL)
    {
        nbVictoire = value;
        MAJProfil();
    }
}

void currentProfile::setNbDefaite(int value)
{
    if (value =! NULL)
    {
        nbDefaite = value;
        MAJProfil();
    }
}

void currentProfile::setNbPartie(int value)
{
    if (value =! NULL)
    {
        nbPartie = value;
        MAJProfil();
    }
}
