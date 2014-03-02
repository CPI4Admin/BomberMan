/********************************************************************************
** Form generated from reading UI file 'widgetchat.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETCHAT_H
#define UI_WIDGETCHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widgetChat
{
public:
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_1;
    QLineEdit *saisiMessage;
    QPushButton *btSendMessages;
    QPushButton *btQuitterChat;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_1;
    QLabel *label_3;
    QPlainTextEdit *affichageMessages;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_1;
    QListView *listJoueurs;

    void setupUi(QWidget *widgetChat)
    {
        if (widgetChat->objectName().isEmpty())
            widgetChat->setObjectName(QStringLiteral("widgetChat"));
        widgetChat->resize(592, 370);
        widgetChat->setBaseSize(QSize(0, 0));
        horizontalLayoutWidget_2 = new QWidget(widgetChat);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 330, 571, 31));
        horizontalLayout_1 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_1->setObjectName(QStringLiteral("horizontalLayout_1"));
        horizontalLayout_1->setContentsMargins(0, 0, 0, 0);
        saisiMessage = new QLineEdit(horizontalLayoutWidget_2);
        saisiMessage->setObjectName(QStringLiteral("saisiMessage"));

        horizontalLayout_1->addWidget(saisiMessage);

        btSendMessages = new QPushButton(horizontalLayoutWidget_2);
        btSendMessages->setObjectName(QStringLiteral("btSendMessages"));

        horizontalLayout_1->addWidget(btSendMessages);

        btQuitterChat = new QPushButton(horizontalLayoutWidget_2);
        btQuitterChat->setObjectName(QStringLiteral("btQuitterChat"));

        horizontalLayout_1->addWidget(btQuitterChat);

        verticalLayoutWidget = new QWidget(widgetChat);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 411, 321));
        verticalLayout_1 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_1->setObjectName(QStringLiteral("verticalLayout_1"));
        verticalLayout_1->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_1->addWidget(label_3);

        affichageMessages = new QPlainTextEdit(verticalLayoutWidget);
        affichageMessages->setObjectName(QStringLiteral("affichageMessages"));
        affichageMessages->setEnabled(false);

        verticalLayout_1->addWidget(affichageMessages);

        verticalLayoutWidget_2 = new QWidget(widgetChat);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(430, 10, 151, 321));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_1 = new QLabel(verticalLayoutWidget_2);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setLayoutDirection(Qt::LeftToRight);
        label_1->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_1);

        listJoueurs = new QListView(verticalLayoutWidget_2);
        listJoueurs->setObjectName(QStringLiteral("listJoueurs"));

        verticalLayout_2->addWidget(listJoueurs);


        retranslateUi(widgetChat);

        QMetaObject::connectSlotsByName(widgetChat);
    } // setupUi

    void retranslateUi(QWidget *widgetChat)
    {
        widgetChat->setWindowTitle(QApplication::translate("widgetChat", "Form", 0));
        btSendMessages->setText(QApplication::translate("widgetChat", "Envoyer", 0));
        btQuitterChat->setText(QApplication::translate("widgetChat", "Quitter", 0));
        label_3->setText(QApplication::translate("widgetChat", "Historique du chat", 0));
        label_1->setText(QApplication::translate("widgetChat", "Joueur sur le chat", 0));
    } // retranslateUi

};

namespace Ui {
    class widgetChat: public Ui_widgetChat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETCHAT_H
