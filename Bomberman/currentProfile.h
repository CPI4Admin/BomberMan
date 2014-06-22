#ifndef CURRENTPROFILE_H
#define CURRENTPROFILE_H

#include <QString>

class currentProfile
{
public:
    static currentProfile* getInstance(QString,QString,int,int,int,int);
    static currentProfile* getInstance();
    QString getPseudo();
    QString getMotDePasse();
    int getNbVictoire();
    int getNbPartie();
    int getNbDefaite();
    int getNbConnexion();

    void setMotDePasse(QString value);
    void setNbVictoire(int value);
    void setNbPartie(int value);
    void setNbDefaite(int value);
    void setNbConnexion(int value);

    void MAJProfil();

private:
    currentProfile(QString _pseudo,QString _motdepasse,int _nbConnexion,int _nbPartie,int _nbVictoire,int _nbDefaite);
    static currentProfile* instance;
    QString pseudo;
    QString motDePasse;
    int nbVictoire;
    int nbPartie;
    int nbDefaite;
    int nbConnexion;
};

#endif // CURRENTPROFILE_H
