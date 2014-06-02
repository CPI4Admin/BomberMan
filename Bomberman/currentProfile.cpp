#include "currentProfile.h"

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
