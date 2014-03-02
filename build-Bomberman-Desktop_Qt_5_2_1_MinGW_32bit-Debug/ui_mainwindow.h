/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionDemarrerPartieSolo;
    QAction *actionSauvegarderPartieSolo;
    QAction *actionDemarrerPartieMulti;
    QAction *actionChargerPartieMulti;
    QAction *actionChargerPartieSolo;
    QAction *actionCommandes_de_jeu;
    QAction *actionAffichage;
    QAction *actionAudio;
    QAction *actionInformations;
    QAction *actionLeaderboard;
    QAction *actionQuitter;
    QAction *actionAide;
    QAction *actionA_propos;
    QAction *actionAffichageStatistics;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuNouvelle_Partie;
    QMenu *menuPartie_solo;
    QMenu *menuPartie_multi_joueur;
    QMenu *menuOptions;
    QMenu *menuProfil;
    QMenu *menu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(631, 378);
        actionDemarrerPartieSolo = new QAction(MainWindow);
        actionDemarrerPartieSolo->setObjectName(QStringLiteral("actionDemarrerPartieSolo"));
        actionSauvegarderPartieSolo = new QAction(MainWindow);
        actionSauvegarderPartieSolo->setObjectName(QStringLiteral("actionSauvegarderPartieSolo"));
        actionSauvegarderPartieSolo->setEnabled(true);
        actionDemarrerPartieMulti = new QAction(MainWindow);
        actionDemarrerPartieMulti->setObjectName(QStringLiteral("actionDemarrerPartieMulti"));
        actionChargerPartieMulti = new QAction(MainWindow);
        actionChargerPartieMulti->setObjectName(QStringLiteral("actionChargerPartieMulti"));
        actionChargerPartieSolo = new QAction(MainWindow);
        actionChargerPartieSolo->setObjectName(QStringLiteral("actionChargerPartieSolo"));
        actionCommandes_de_jeu = new QAction(MainWindow);
        actionCommandes_de_jeu->setObjectName(QStringLiteral("actionCommandes_de_jeu"));
        actionAffichage = new QAction(MainWindow);
        actionAffichage->setObjectName(QStringLiteral("actionAffichage"));
        actionAudio = new QAction(MainWindow);
        actionAudio->setObjectName(QStringLiteral("actionAudio"));
        actionInformations = new QAction(MainWindow);
        actionInformations->setObjectName(QStringLiteral("actionInformations"));
        actionLeaderboard = new QAction(MainWindow);
        actionLeaderboard->setObjectName(QStringLiteral("actionLeaderboard"));
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        actionAide = new QAction(MainWindow);
        actionAide->setObjectName(QStringLiteral("actionAide"));
        actionA_propos = new QAction(MainWindow);
        actionA_propos->setObjectName(QStringLiteral("actionA_propos"));
        actionAffichageStatistics = new QAction(MainWindow);
        actionAffichageStatistics->setObjectName(QStringLiteral("actionAffichageStatistics"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 631, 21));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        menuNouvelle_Partie = new QMenu(menuFichier);
        menuNouvelle_Partie->setObjectName(QStringLiteral("menuNouvelle_Partie"));
        menuPartie_solo = new QMenu(menuNouvelle_Partie);
        menuPartie_solo->setObjectName(QStringLiteral("menuPartie_solo"));
        menuPartie_multi_joueur = new QMenu(menuNouvelle_Partie);
        menuPartie_multi_joueur->setObjectName(QStringLiteral("menuPartie_multi_joueur"));
        menuOptions = new QMenu(menuFichier);
        menuOptions->setObjectName(QStringLiteral("menuOptions"));
        menuProfil = new QMenu(menuFichier);
        menuProfil->setObjectName(QStringLiteral("menuProfil"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menu->menuAction());
        menuFichier->addAction(menuNouvelle_Partie->menuAction());
        menuFichier->addAction(menuOptions->menuAction());
        menuFichier->addAction(menuProfil->menuAction());
        menuFichier->addAction(actionQuitter);
        menuNouvelle_Partie->addAction(menuPartie_solo->menuAction());
        menuNouvelle_Partie->addAction(menuPartie_multi_joueur->menuAction());
        menuPartie_solo->addAction(actionDemarrerPartieSolo);
        menuPartie_solo->addAction(actionSauvegarderPartieSolo);
        menuPartie_solo->addAction(actionChargerPartieSolo);
        menuPartie_multi_joueur->addAction(actionDemarrerPartieMulti);
        menuPartie_multi_joueur->addAction(actionChargerPartieMulti);
        menuOptions->addAction(actionCommandes_de_jeu);
        menuOptions->addAction(actionAffichage);
        menuOptions->addAction(actionAudio);
        menuProfil->addAction(actionInformations);
        menuProfil->addAction(actionLeaderboard);
        menuProfil->addAction(actionAffichageStatistics);
        menu->addAction(actionAide);
        menu->addAction(actionA_propos);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "BomberMan ", 0));
        actionDemarrerPartieSolo->setText(QApplication::translate("MainWindow", "D\303\251marrer partie", 0));
        actionSauvegarderPartieSolo->setText(QApplication::translate("MainWindow", "Sauvegarder partie", 0));
        actionDemarrerPartieMulti->setText(QApplication::translate("MainWindow", "D\303\251marrer partie", 0));
        actionChargerPartieMulti->setText(QApplication::translate("MainWindow", "Charger partie", 0));
        actionChargerPartieSolo->setText(QApplication::translate("MainWindow", "Charger partie", 0));
        actionCommandes_de_jeu->setText(QApplication::translate("MainWindow", "Commandes de jeu", 0));
        actionAffichage->setText(QApplication::translate("MainWindow", "Affichage", 0));
        actionAudio->setText(QApplication::translate("MainWindow", "Audio", 0));
        actionInformations->setText(QApplication::translate("MainWindow", "Informations", 0));
        actionLeaderboard->setText(QApplication::translate("MainWindow", "Leaderboard", 0));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0));
        actionAide->setText(QApplication::translate("MainWindow", "Aide", 0));
        actionA_propos->setText(QApplication::translate("MainWindow", "A propos", 0));
        actionAffichageStatistics->setText(QApplication::translate("MainWindow", "Satistics", 0));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Jeu", 0));
        menuNouvelle_Partie->setTitle(QApplication::translate("MainWindow", "Nouvelle Partie", 0));
        menuPartie_solo->setTitle(QApplication::translate("MainWindow", "Partie solo", 0));
        menuPartie_multi_joueur->setTitle(QApplication::translate("MainWindow", "Partie multi-joueur", 0));
        menuOptions->setTitle(QApplication::translate("MainWindow", "Options", 0));
        menuProfil->setTitle(QApplication::translate("MainWindow", "Profil", 0));
        menu->setTitle(QApplication::translate("MainWindow", "?", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
