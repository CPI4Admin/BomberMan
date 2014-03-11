#ifndef LAUNCHMULTIGAME_H
#define LAUNCHMULTIGAME_H

#include <QDialog>

namespace Ui {
class LaunchMultiGame;
}

class LaunchMultiGame : public QDialog
{
    Q_OBJECT

public:
    explicit LaunchMultiGame(QWidget *parent = 0);
    ~LaunchMultiGame();

private:
    Ui::LaunchMultiGame *ui;

private slots:
    void LancerPartie();
};

#endif // LAUNCHMULTIGAME_H
