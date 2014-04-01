#ifndef LAUNCHSOLOGAME_H
#define LAUNCHSOLOGAME_H

#include <QDialog>

namespace Ui {
class LaunchSoloGame;
}

class LaunchSoloGame : public QDialog
{
    Q_OBJECT

public:
    explicit LaunchSoloGame(QWidget *parent = 0);
    ~LaunchSoloGame();


private slots:
//    void on_scrollLevel_destroyed();
    void LancerPartieSolo();


private:
    Ui::LaunchSoloGame *ui;
        void FillMap();

private slots:
    void ChangeMap();

private slots:
    void SetDiff();

};

#endif // LAUNCHSOLOGAME_H
