#ifndef FRMMODIFMDP_H
#define FRMMODIFMDP_H

#include <QDialog>

namespace Ui {
class frmModifMdp;
}

class frmModifMdp : public QDialog
{
    Q_OBJECT

public:
    explicit frmModifMdp(QWidget *parent = 0);
    ~frmModifMdp();

private:
    Ui::frmModifMdp *ui;
    bool Verif();

private slots:
    void ModifierMotDePasse();

};

#endif // FRMMODIFMDP_H
