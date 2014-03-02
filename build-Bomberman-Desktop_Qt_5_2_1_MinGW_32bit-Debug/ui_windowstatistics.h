/********************************************************************************
** Form generated from reading UI file 'windowstatistics.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWSTATISTICS_H
#define UI_WINDOWSTATISTICS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_windowstatistics
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_1;
    QPlainTextEdit *affichage_1;
    QSpacerItem *horizontalSpacer;
    QFormLayout *formLayout_1;
    QVBoxLayout *verticalLayout_1;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_1;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_2;
    QPushButton *btQuitter;
    QPushButton *btReset;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *windowstatistics)
    {
        if (windowstatistics->objectName().isEmpty())
            windowstatistics->setObjectName(QStringLiteral("windowstatistics"));
        windowstatistics->resize(469, 195);
        horizontalLayoutWidget = new QWidget(windowstatistics);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 451, 171));
        horizontalLayout_1 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_1->setObjectName(QStringLiteral("horizontalLayout_1"));
        horizontalLayout_1->setContentsMargins(0, 0, 0, 0);
        affichage_1 = new QPlainTextEdit(horizontalLayoutWidget);
        affichage_1->setObjectName(QStringLiteral("affichage_1"));
        affichage_1->setReadOnly(true);

        horizontalLayout_1->addWidget(affichage_1);

        horizontalSpacer = new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_1->addItem(horizontalSpacer);

        formLayout_1 = new QFormLayout();
        formLayout_1->setObjectName(QStringLiteral("formLayout_1"));
        formLayout_1->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        verticalLayout_1 = new QVBoxLayout();
        verticalLayout_1->setObjectName(QStringLiteral("verticalLayout_1"));
        label_1 = new QLabel(horizontalLayoutWidget);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_1->addWidget(label_1);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_1->addWidget(label_2);

        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_1->addWidget(label_3);

        label_4 = new QLabel(horizontalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_1->addWidget(label_4);


        formLayout_1->setLayout(0, QFormLayout::LabelRole, verticalLayout_1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lineEdit_3 = new QLineEdit(horizontalLayoutWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setReadOnly(true);

        verticalLayout_2->addWidget(lineEdit_3);

        lineEdit_1 = new QLineEdit(horizontalLayoutWidget);
        lineEdit_1->setObjectName(QStringLiteral("lineEdit_1"));
        lineEdit_1->setReadOnly(true);

        verticalLayout_2->addWidget(lineEdit_1);

        lineEdit_4 = new QLineEdit(horizontalLayoutWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setReadOnly(true);

        verticalLayout_2->addWidget(lineEdit_4);

        lineEdit_2 = new QLineEdit(horizontalLayoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setReadOnly(true);

        verticalLayout_2->addWidget(lineEdit_2);


        formLayout_1->setLayout(0, QFormLayout::FieldRole, verticalLayout_2);

        btQuitter = new QPushButton(horizontalLayoutWidget);
        btQuitter->setObjectName(QStringLiteral("btQuitter"));

        formLayout_1->setWidget(2, QFormLayout::LabelRole, btQuitter);

        btReset = new QPushButton(horizontalLayoutWidget);
        btReset->setObjectName(QStringLiteral("btReset"));

        formLayout_1->setWidget(2, QFormLayout::FieldRole, btReset);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_1->setItem(1, QFormLayout::SpanningRole, verticalSpacer);


        horizontalLayout_1->addLayout(formLayout_1);


        retranslateUi(windowstatistics);

        QMetaObject::connectSlotsByName(windowstatistics);
    } // setupUi

    void retranslateUi(QDialog *windowstatistics)
    {
        windowstatistics->setWindowTitle(QApplication::translate("windowstatistics", "stat", 0));
        affichage_1->setPlainText(QApplication::translate("windowstatistics", "Meilleurs scores", 0));
        label_1->setText(QApplication::translate("windowstatistics", "Parties jou\303\251es :", 0));
        label_2->setText(QApplication::translate("windowstatistics", "Parties gagn\303\251es :", 0));
        label_3->setText(QApplication::translate("windowstatistics", "Parties perdu :", 0));
        label_4->setText(QApplication::translate("windowstatistics", "Bonus :", 0));
        btQuitter->setText(QApplication::translate("windowstatistics", "Quitter", 0));
        btReset->setText(QApplication::translate("windowstatistics", "R\303\251initialiser", 0));
    } // retranslateUi

};

namespace Ui {
    class windowstatistics: public Ui_windowstatistics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWSTATISTICS_H
