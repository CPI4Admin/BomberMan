/********************************************************************************
** Form generated from reading UI file 'launchsologame.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAUNCHSOLOGAME_H
#define UI_LAUNCHSOLOGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LaunchSoloGame
{
public:
    QPushButton *exit;
    QScrollArea *scrollArea;
    QWidget *scrollLevel;
    QRadioButton *diffNovice;
    QRadioButton *diffNormal;
    QRadioButton *diffVeteran;
    QCommandLinkButton *buttonStart;

    void setupUi(QDialog *LaunchSoloGame)
    {
        if (LaunchSoloGame->objectName().isEmpty())
            LaunchSoloGame->setObjectName(QStringLiteral("LaunchSoloGame"));
        LaunchSoloGame->resize(400, 300);
        exit = new QPushButton(LaunchSoloGame);
        exit->setObjectName(QStringLiteral("exit"));
        exit->setGeometry(QRect(310, 260, 75, 23));
        scrollArea = new QScrollArea(LaunchSoloGame);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(30, 40, 120, 31));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setWidgetResizable(true);
        scrollLevel = new QWidget();
        scrollLevel->setObjectName(QStringLiteral("scrollLevel"));
        scrollLevel->setGeometry(QRect(0, 0, 101, 29));
        scrollArea->setWidget(scrollLevel);
        diffNovice = new QRadioButton(LaunchSoloGame);
        diffNovice->setObjectName(QStringLiteral("diffNovice"));
        diffNovice->setGeometry(QRect(30, 150, 82, 21));
        diffNormal = new QRadioButton(LaunchSoloGame);
        diffNormal->setObjectName(QStringLiteral("diffNormal"));
        diffNormal->setGeometry(QRect(30, 180, 82, 17));
        diffVeteran = new QRadioButton(LaunchSoloGame);
        diffVeteran->setObjectName(QStringLiteral("diffVeteran"));
        diffVeteran->setGeometry(QRect(30, 210, 82, 17));
        buttonStart = new QCommandLinkButton(LaunchSoloGame);
        buttonStart->setObjectName(QStringLiteral("buttonStart"));
        buttonStart->setGeometry(QRect(20, 240, 172, 41));

        retranslateUi(LaunchSoloGame);

        QMetaObject::connectSlotsByName(LaunchSoloGame);
    } // setupUi

    void retranslateUi(QDialog *LaunchSoloGame)
    {
        LaunchSoloGame->setWindowTitle(QApplication::translate("LaunchSoloGame", "Dialog", 0));
#ifndef QT_NO_TOOLTIP
        LaunchSoloGame->setToolTip(QApplication::translate("LaunchSoloGame", "<html><head/><body><p>BONJOUR<br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_ACCESSIBILITY
        LaunchSoloGame->setAccessibleName(QApplication::translate("LaunchSoloGame", "<html><head/><body><p>Nouvel Partie</p></body></html>", 0));
#endif // QT_NO_ACCESSIBILITY
        exit->setText(QApplication::translate("LaunchSoloGame", "Quitter", 0));
        diffNovice->setText(QApplication::translate("LaunchSoloGame", "NOVICE", 0));
        diffNormal->setText(QApplication::translate("LaunchSoloGame", "NORMAL", 0));
        diffVeteran->setText(QApplication::translate("LaunchSoloGame", "VETERAN", 0));
        buttonStart->setText(QApplication::translate("LaunchSoloGame", "START !", 0));
    } // retranslateUi

};

namespace Ui {
    class LaunchSoloGame: public Ui_LaunchSoloGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAUNCHSOLOGAME_H
