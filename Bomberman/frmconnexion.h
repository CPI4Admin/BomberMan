#ifndef FRMCONNEXION_H
#define FRMCONNEXION_H

#include <QDialog>

namespace Ui {
class frmConnexion;
}

class frmConnexion : public QDialog
{
    Q_OBJECT

public:
    explicit frmConnexion(QWidget *parent = 0);
    ~frmConnexion();

signals:
    void connexionOk();

private slots:
    void ConnexionProfil();
    void CreationProfil();

private:
    Ui::frmConnexion *ui;
};

#endif // FRMCONNEXION_H
