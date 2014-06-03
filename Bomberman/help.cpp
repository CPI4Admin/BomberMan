#include "help.h"
#include <QPushButton>
#include <QMessageBox>

help::help(QWidget *parent)
{
    QFile fichier("../Bomberman/help.html");
    QMessageBox msgHelp;

    fichier.open(QIODevice::ReadOnly | QIODevice::Text);//Ouverture de fichier
        {
        QString texte = fichier.readAll();//conversion du fichier en String
        msgHelp.setGeometry(10,100,400,200);
        msgHelp.information(this, "Besoin d'aide? ", texte);

        boutonFermer = new QPushButton("Fermer"); //Bouton pour fermer ta fenetre d'aide

        connect(boutonFermer, SIGNAL(clicked()) ,this, SLOT(accept())); //Slot de fermeture avec le bouton        
        }
    fichier.close();//fermeture de fichier
}
