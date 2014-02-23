/********************************************************************************
** Form generated from reading UI file 'launchmultigame.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAUNCHMULTIGAME_H
#define UI_LAUNCHMULTIGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_LaunchMultiGame
{
public:
    QRadioButton *rB_Heberger;
    QRadioButton *rB_Rejoindre;
    QLineEdit *txt_IP;
    QLineEdit *txt_Port;
    QPushButton *bt_Fermer;
    QPushButton *bt_OK;

    void setupUi(QDialog *LaunchMultiGame)
    {
        if (LaunchMultiGame->objectName().isEmpty())
            LaunchMultiGame->setObjectName(QStringLiteral("LaunchMultiGame"));
        LaunchMultiGame->resize(322, 112);
        rB_Heberger = new QRadioButton(LaunchMultiGame);
        rB_Heberger->setObjectName(QStringLiteral("rB_Heberger"));
        rB_Heberger->setGeometry(QRect(10, 20, 141, 17));
        rB_Rejoindre = new QRadioButton(LaunchMultiGame);
        rB_Rejoindre->setObjectName(QStringLiteral("rB_Rejoindre"));
        rB_Rejoindre->setGeometry(QRect(10, 50, 131, 17));
        txt_IP = new QLineEdit(LaunchMultiGame);
        txt_IP->setObjectName(QStringLiteral("txt_IP"));
        txt_IP->setGeometry(QRect(140, 50, 113, 20));
        txt_Port = new QLineEdit(LaunchMultiGame);
        txt_Port->setObjectName(QStringLiteral("txt_Port"));
        txt_Port->setGeometry(QRect(260, 50, 51, 20));
        bt_Fermer = new QPushButton(LaunchMultiGame);
        bt_Fermer->setObjectName(QStringLiteral("bt_Fermer"));
        bt_Fermer->setGeometry(QRect(90, 80, 75, 23));
        bt_OK = new QPushButton(LaunchMultiGame);
        bt_OK->setObjectName(QStringLiteral("bt_OK"));
        bt_OK->setGeometry(QRect(170, 80, 75, 23));

        retranslateUi(LaunchMultiGame);

        QMetaObject::connectSlotsByName(LaunchMultiGame);
    } // setupUi

    void retranslateUi(QDialog *LaunchMultiGame)
    {
        LaunchMultiGame->setWindowTitle(QApplication::translate("LaunchMultiGame", "Dialog", 0));
        rB_Heberger->setText(QApplication::translate("LaunchMultiGame", "H\303\251berger une partie", 0));
        rB_Rejoindre->setText(QApplication::translate("LaunchMultiGame", "Rejoindre une partie", 0));
        bt_Fermer->setText(QApplication::translate("LaunchMultiGame", "Fermer", 0));
        bt_OK->setText(QApplication::translate("LaunchMultiGame", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class LaunchMultiGame: public Ui_LaunchMultiGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAUNCHMULTIGAME_H
