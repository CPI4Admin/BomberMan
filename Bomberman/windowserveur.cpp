#include "windowserveur.h"
#include <QMessageBox>

windowserveur::windowserveur(QWidget *parent) :
    QTcpServer(parent)
{
    //ui->setupUi(this);
}

windowserveur::~windowserveur()
{
    //delete ui;
}

void windowserveur::DemarrerServeur()
{
        //etatServeur = new QLabel;
        // changer text label
        //ui->labelStatutServeur->setText("Le serveur est démarré.");

        if (!listen(QHostAddress::Any, 60000)) // Demarrage du serveur sur toutes les IP disponibles et sur le port 60000
        {
            // Si le serveur n'a pas ete demarre correctement
            //todo: Retourner une erreur
           // ui->labelStatutServeurErreur->setText(tr("Le serveur est déja demarré. Raison :<br />") + serveur->errorString());

        }else
        {
            // TODO: Retourner un signal bien déroulé

            // changer text label
            //ui->labelStatutServeur->setText("Le serveur à été demarré sur le port 60 000 <strong>") ;//+ QString::number(serveur->serverPort());

        }
}


void windowserveur::ArreterServeur()
{
    // changer text label
    //ui->labelStatutServeur->setText("Le serveur est arreté.");
    close();

    // RETOURNER UNE ALERTE !
}
void windowserveur::nouvelleConnexion()
{
    //** Gestion des connections clients et de port dans un tableau
    QTcpSocket *nouveauClient = nextPendingConnection();
    clients << nouveauClient;

}

void windowserveur::deconnexionClient()
{
     //** On determine quel client se deconnecte
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (socket == 0) // Si par hasard on n'a pas trouve le client a l'origine du signal, on arrete la methode
        return;

    clients.removeOne(socket);

    socket->deleteLater();
}


