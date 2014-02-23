/********************************************************************************
** Form generated from reading UI file 'windowserveur.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWSERVEUR_H
#define UI_WINDOWSERVEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_windowserveur
{
public:
    QPushButton *pushButtonLancerServeur;
    QLabel *labelStatutServeur;
    QPushButton *pushButtonArreterServeur;
    QLabel *labelStatutServeurErreur;
    QPushButton *pushButtonFermer;

    void setupUi(QDialog *windowserveur)
    {
        if (windowserveur->objectName().isEmpty())
            windowserveur->setObjectName(QStringLiteral("windowserveur"));
        windowserveur->resize(343, 256);
        pushButtonLancerServeur = new QPushButton(windowserveur);
        pushButtonLancerServeur->setObjectName(QStringLiteral("pushButtonLancerServeur"));
        pushButtonLancerServeur->setGeometry(QRect(20, 180, 121, 23));
        labelStatutServeur = new QLabel(windowserveur);
        labelStatutServeur->setObjectName(QStringLiteral("labelStatutServeur"));
        labelStatutServeur->setGeometry(QRect(100, 30, 121, 16));
        pushButtonArreterServeur = new QPushButton(windowserveur);
        pushButtonArreterServeur->setObjectName(QStringLiteral("pushButtonArreterServeur"));
        pushButtonArreterServeur->setGeometry(QRect(200, 180, 111, 23));
        labelStatutServeurErreur = new QLabel(windowserveur);
        labelStatutServeurErreur->setObjectName(QStringLiteral("labelStatutServeurErreur"));
        labelStatutServeurErreur->setGeometry(QRect(10, 100, 321, 61));
        pushButtonFermer = new QPushButton(windowserveur);
        pushButtonFermer->setObjectName(QStringLiteral("pushButtonFermer"));
        pushButtonFermer->setGeometry(QRect(140, 230, 75, 23));

        retranslateUi(windowserveur);

        QMetaObject::connectSlotsByName(windowserveur);
    } // setupUi

    void retranslateUi(QDialog *windowserveur)
    {
        windowserveur->setWindowTitle(QApplication::translate("windowserveur", "Dialog", 0));
        pushButtonLancerServeur->setText(QApplication::translate("windowserveur", "D\303\251marrer le serveur", 0));
        labelStatutServeur->setText(QApplication::translate("windowserveur", "Le serveur est arr\303\252t\303\251", 0));
        pushButtonArreterServeur->setText(QApplication::translate("windowserveur", "Arreter le serveur", 0));
        labelStatutServeurErreur->setText(QString());
        pushButtonFermer->setText(QApplication::translate("windowserveur", "Fermer", 0));
    } // retranslateUi

};

namespace Ui {
    class windowserveur: public Ui_windowserveur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWSERVEUR_H
