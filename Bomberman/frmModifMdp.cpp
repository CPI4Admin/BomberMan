#include "frmModifMdp.h"
#include "ui_frmModifMdp.h"

#include "currentProfile.h"
#include <QCryptographicHash>
#include <QMessageBox>

frmModifMdp::frmModifMdp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmModifMdp)
{
    ui->setupUi(this);

    ui->txtAncien->setEchoMode(QLineEdit::Password);
    ui->txtNouveau->setEchoMode(QLineEdit::Password);
    ui->txtConfirmation->setEchoMode(QLineEdit::Password);

    connect(ui->buttonBox, SIGNAL(rejected()),this,SLOT(close()));
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(ModifierMotDePasse()));
}

frmModifMdp::~frmModifMdp()
{
    delete ui;
}

void frmModifMdp::ModifierMotDePasse()
{
    if(this->Verif())
    {
        currentProfile *user = currentProfile::getInstance();

        QString chaine=ui->txtNouveau->text(); // On crée la chaine à hacher

        QByteArray ba =  QCryptographicHash::hash( QByteArray (QCryptographicHash::hash (QString("SEL_AVANT").toUtf8(), QCryptographicHash::Md5) + QCryptographicHash::hash (chaine.toUtf8(), QCryptographicHash::Md5) +  QCryptographicHash::hash( QString("SEL_APRES").toUtf8(), QCryptographicHash::Md5)), QCryptographicHash::Sha1); // on la hache
        QString motdepasse=ba.toHex(); // on convertit le hash en QString

        user->setMotDePasse(motdepasse);
    }
}

bool frmModifMdp::Verif()
{
    // TODO: La Vérif marche pas
    bool res = true;
    QString erreur;
    currentProfile *user = currentProfile::getInstance();

    QMessageBox msg;

    QString chaine=ui->txtAncien->text(); // On crée la chaine à hacher

    QByteArray ba =  QCryptographicHash::hash( QByteArray (
    QCryptographicHash::hash (QString("SEL_AVANT").toUtf8(), QCryptographicHash::Md5) + QCryptographicHash::hash (chaine.toUtf8(), QCryptographicHash::Md5) +  QCryptographicHash::hash( QString("SEL_APRES").toUtf8(), QCryptographicHash::Md5)), QCryptographicHash::Sha1); // on la hache

    QString motdepasse=ba.toHex(); // on convertit le hash en QString

    if(user->getMotDePasse() != motdepasse)
    {
        res = false;
        erreur = erreur + "Le mot de passe actuel enseigné n'est pas correct. /n";
    }

    if(ui->txtNouveau->text() != ui->txtConfirmation->text())
    {
        res = false;
        erreur = erreur + "La confirmation ne correspond pas au nouveau mot de passe. /n";
    }

    if (res = false)
    {
        msg.setText(erreur);
        msg.exec();
    }

    return res;
}
