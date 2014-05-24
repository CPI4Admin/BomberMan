#ifndef CURRENTPROFILE_H
#define CURRENTPROFILE_H

#include <QString>

class currentProfile
{
public:
    static currentProfile* getInstance(QString,QString,int,int,int,int);
    static currentProfile* getInstance();
    QString pseudo;
    QString motDePasse;
    int nbVictoire;
    int nbPartie;
    int nbDefaite;
    int nbConnexion;

private:
    currentProfile(QString _pseudo,QString _motdepasse,int _nbConnexion,int _nbPartie,int _nbVictoire,int _nbDefaite);
    static currentProfile* instance;
};

#endif // CURRENTPROFILE_H
