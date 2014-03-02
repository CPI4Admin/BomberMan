/********************************************************************************
** Form generated from reading UI file 'windowserveur.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_windowserveur
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_1;
    QLabel *label_1;
    QLabel *label_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_1;
    QPushButton *btStartServer;
    QPushButton *btStopServer;
    QPushButton *btQuitterServer;

    void setupUi(QDialog *windowserveur)
    {
        if (windowserveur->objectName().isEmpty())
            windowserveur->setObjectName(QStringLiteral("windowserveur"));
        windowserveur->setWindowModality(Qt::NonModal);
        windowserveur->resize(411, 115);
        verticalLayoutWidget = new QWidget(windowserveur);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 0, 391, 71));
        verticalLayout_1 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_1->setObjectName(QStringLiteral("verticalLayout_1"));
        verticalLayout_1->setContentsMargins(0, 0, 0, 0);
        label_1 = new QLabel(verticalLayoutWidget);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setAlignment(Qt::AlignCenter);

        verticalLayout_1->addWidget(label_1);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_1->addWidget(label_2);

        horizontalLayoutWidget = new QWidget(windowserveur);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(50, 70, 301, 41));
        horizontalLayout_1 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_1->setObjectName(QStringLiteral("horizontalLayout_1"));
        horizontalLayout_1->setContentsMargins(0, 0, 0, 0);
        btStartServer = new QPushButton(horizontalLayoutWidget);
        btStartServer->setObjectName(QStringLiteral("btStartServer"));

        horizontalLayout_1->addWidget(btStartServer);

        btStopServer = new QPushButton(horizontalLayoutWidget);
        btStopServer->setObjectName(QStringLiteral("btStopServer"));

        horizontalLayout_1->addWidget(btStopServer);

        btQuitterServer = new QPushButton(horizontalLayoutWidget);
        btQuitterServer->setObjectName(QStringLiteral("btQuitterServer"));

        horizontalLayout_1->addWidget(btQuitterServer);


        retranslateUi(windowserveur);

        QMetaObject::connectSlotsByName(windowserveur);
    } // setupUi

    void retranslateUi(QDialog *windowserveur)
    {
        windowserveur->setWindowTitle(QApplication::translate("windowserveur", "Dialog", 0));
        label_1->setText(QApplication::translate("windowserveur", "Le serveur est arr\303\252t\303\251", 0));
        label_2->setText(QApplication::translate("windowserveur", "Aucune \303\251rreurs serveur", 0));
        btStartServer->setText(QApplication::translate("windowserveur", "Start", 0));
        btStopServer->setText(QApplication::translate("windowserveur", "Stop", 0));
        btQuitterServer->setText(QApplication::translate("windowserveur", "Quitter", 0));
    } // retranslateUi

};

namespace Ui {
    class windowserveur: public Ui_windowserveur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWSERVEUR_H
