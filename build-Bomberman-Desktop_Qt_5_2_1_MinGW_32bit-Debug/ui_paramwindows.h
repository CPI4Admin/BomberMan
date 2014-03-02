/********************************************************************************
** Form generated from reading UI file 'paramwindows.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMWINDOWS_H
#define UI_PARAMWINDOWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ParamWindows
{
public:
    QTabWidget *tabWidget;
    QWidget *Audio;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_2;
    QSlider *sliderVolGen;
    QSlider *sliderVolMus;
    QSlider *sliderEffSon;
    QComboBox *cboPlaylist;
    QPushButton *btParcourir;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btParDefault;
    QSpacerItem *horizontalSpacer;
    QPushButton *btValider;
    QWidget *Affichage;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_6;
    QLabel *label_7;
    QVBoxLayout *verticalLayout;
    QComboBox *cboResolution;
    QSlider *sliderLuminosite;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btParDefault_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btValider_2;
    QWidget *Commande;
    QLabel *label_8;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_9;
    QVBoxLayout *verticalLayout_9;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_7;
    QLabel *label_17;
    QComboBox *cboJoueur;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *btParDefault_4;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btValider_4;

    void setupUi(QDialog *ParamWindows)
    {
        if (ParamWindows->objectName().isEmpty())
            ParamWindows->setObjectName(QStringLiteral("ParamWindows"));
        ParamWindows->resize(574, 379);
        tabWidget = new QTabWidget(ParamWindows);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 581, 381));
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tabWidget->setTabPosition(QTabWidget::West);
        Audio = new QWidget();
        Audio->setObjectName(QStringLiteral("Audio"));
        horizontalLayoutWidget = new QWidget(Audio);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 531, 291));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_3->addWidget(label_2);

        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_3->addWidget(label_3);

        label_4 = new QLabel(horizontalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_3->addWidget(label_4);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_3->addWidget(label);

        label_5 = new QLabel(horizontalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_3->addWidget(label_5);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        sliderVolGen = new QSlider(horizontalLayoutWidget);
        sliderVolGen->setObjectName(QStringLiteral("sliderVolGen"));
        sliderVolGen->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(sliderVolGen);

        sliderVolMus = new QSlider(horizontalLayoutWidget);
        sliderVolMus->setObjectName(QStringLiteral("sliderVolMus"));
        sliderVolMus->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(sliderVolMus);

        sliderEffSon = new QSlider(horizontalLayoutWidget);
        sliderEffSon->setObjectName(QStringLiteral("sliderEffSon"));
        sliderEffSon->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(sliderEffSon);

        cboPlaylist = new QComboBox(horizontalLayoutWidget);
        cboPlaylist->setObjectName(QStringLiteral("cboPlaylist"));

        verticalLayout_2->addWidget(cboPlaylist);

        btParcourir = new QPushButton(horizontalLayoutWidget);
        btParcourir->setObjectName(QStringLiteral("btParcourir"));

        verticalLayout_2->addWidget(btParcourir);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayoutWidget_2 = new QWidget(Audio);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 310, 531, 61));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        btParDefault = new QPushButton(horizontalLayoutWidget_2);
        btParDefault->setObjectName(QStringLiteral("btParDefault"));

        horizontalLayout_3->addWidget(btParDefault);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        btValider = new QPushButton(horizontalLayoutWidget_2);
        btValider->setObjectName(QStringLiteral("btValider"));

        horizontalLayout_3->addWidget(btValider);

        tabWidget->addTab(Audio, QString());
        Affichage = new QWidget();
        Affichage->setObjectName(QStringLiteral("Affichage"));
        horizontalLayoutWidget_3 = new QWidget(Affichage);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(10, 10, 531, 151));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_6 = new QLabel(horizontalLayoutWidget_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_4->addWidget(label_6);

        label_7 = new QLabel(horizontalLayoutWidget_3);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_4->addWidget(label_7);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        cboResolution = new QComboBox(horizontalLayoutWidget_3);
        cboResolution->setObjectName(QStringLiteral("cboResolution"));

        verticalLayout->addWidget(cboResolution);

        sliderLuminosite = new QSlider(horizontalLayoutWidget_3);
        sliderLuminosite->setObjectName(QStringLiteral("sliderLuminosite"));
        sliderLuminosite->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(sliderLuminosite);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalLayoutWidget_4 = new QWidget(Affichage);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(10, 170, 531, 61));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        btParDefault_2 = new QPushButton(horizontalLayoutWidget_4);
        btParDefault_2->setObjectName(QStringLiteral("btParDefault_2"));

        horizontalLayout_4->addWidget(btParDefault_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        btValider_2 = new QPushButton(horizontalLayoutWidget_4);
        btValider_2->setObjectName(QStringLiteral("btValider_2"));

        horizontalLayout_4->addWidget(btValider_2);

        tabWidget->addTab(Affichage, QString());
        Commande = new QWidget();
        Commande->setObjectName(QStringLiteral("Commande"));
        label_8 = new QLabel(Commande);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(80, 40, 131, 16));
        radioButton = new QRadioButton(Commande);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(240, 40, 82, 17));
        radioButton_2 = new QRadioButton(Commande);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(340, 40, 82, 17));
        horizontalLayoutWidget_5 = new QWidget(Commande);
        horizontalLayoutWidget_5->setObjectName(QStringLiteral("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(10, 60, 531, 251));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_10 = new QLabel(horizontalLayoutWidget_5);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_6->addWidget(label_10);

        label_11 = new QLabel(horizontalLayoutWidget_5);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout_6->addWidget(label_11);

        label_12 = new QLabel(horizontalLayoutWidget_5);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout_6->addWidget(label_12);

        label_9 = new QLabel(horizontalLayoutWidget_5);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_6->addWidget(label_9);


        horizontalLayout_5->addLayout(verticalLayout_6);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setSizeConstraint(QLayout::SetDefaultConstraint);
        lineEdit_4 = new QLineEdit(horizontalLayoutWidget_5);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        verticalLayout_9->addWidget(lineEdit_4);

        lineEdit_3 = new QLineEdit(horizontalLayoutWidget_5);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        verticalLayout_9->addWidget(lineEdit_3);

        lineEdit_2 = new QLineEdit(horizontalLayoutWidget_5);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        verticalLayout_9->addWidget(lineEdit_2);

        lineEdit = new QLineEdit(horizontalLayoutWidget_5);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout_9->addWidget(lineEdit);

        verticalLayout_9->setStretch(1, 12);
        verticalLayout_9->setStretch(2, 12);
        verticalLayout_9->setStretch(3, 12);

        horizontalLayout_5->addLayout(verticalLayout_9);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_13 = new QLabel(horizontalLayoutWidget_5);
        label_13->setObjectName(QStringLiteral("label_13"));

        verticalLayout_8->addWidget(label_13);

        label_14 = new QLabel(horizontalLayoutWidget_5);
        label_14->setObjectName(QStringLiteral("label_14"));

        verticalLayout_8->addWidget(label_14);

        label_15 = new QLabel(horizontalLayoutWidget_5);
        label_15->setObjectName(QStringLiteral("label_15"));

        verticalLayout_8->addWidget(label_15);

        label_16 = new QLabel(horizontalLayoutWidget_5);
        label_16->setObjectName(QStringLiteral("label_16"));

        verticalLayout_8->addWidget(label_16);


        horizontalLayout_5->addLayout(verticalLayout_8);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setSizeConstraint(QLayout::SetDefaultConstraint);
        lineEdit_8 = new QLineEdit(horizontalLayoutWidget_5);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));

        verticalLayout_5->addWidget(lineEdit_8);

        lineEdit_7 = new QLineEdit(horizontalLayoutWidget_5);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));

        verticalLayout_5->addWidget(lineEdit_7);


        horizontalLayout_5->addLayout(verticalLayout_5);

        label_17 = new QLabel(Commande);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(80, 20, 46, 13));
        cboJoueur = new QComboBox(Commande);
        cboJoueur->setObjectName(QStringLiteral("cboJoueur"));
        cboJoueur->setGeometry(QRect(240, 10, 161, 22));
        horizontalLayoutWidget_6 = new QWidget(Commande);
        horizontalLayoutWidget_6->setObjectName(QStringLiteral("horizontalLayoutWidget_6"));
        horizontalLayoutWidget_6->setGeometry(QRect(10, 310, 531, 61));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        btParDefault_4 = new QPushButton(horizontalLayoutWidget_6);
        btParDefault_4->setObjectName(QStringLiteral("btParDefault_4"));

        horizontalLayout_7->addWidget(btParDefault_4);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);

        btValider_4 = new QPushButton(horizontalLayoutWidget_6);
        btValider_4->setObjectName(QStringLiteral("btValider_4"));

        horizontalLayout_7->addWidget(btValider_4);

        tabWidget->addTab(Commande, QString());

        retranslateUi(ParamWindows);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ParamWindows);
    } // setupUi

    void retranslateUi(QDialog *ParamWindows)
    {
        ParamWindows->setWindowTitle(QApplication::translate("ParamWindows", "Dialog", 0));
        label_2->setText(QApplication::translate("ParamWindows", "Volume G\303\251n\303\251rale", 0));
        label_3->setText(QApplication::translate("ParamWindows", "Volume musique", 0));
        label_4->setText(QApplication::translate("ParamWindows", "Volume effets sonore", 0));
        label->setText(QApplication::translate("ParamWindows", "Liste de lecture musical", 0));
        label_5->setText(QApplication::translate("ParamWindows", "Ajouter une nouvelle liste de lecture", 0));
        btParcourir->setText(QApplication::translate("ParamWindows", "Parcourir", 0));
        btParDefault->setText(QApplication::translate("ParamWindows", "Par d\303\251fault", 0));
        btValider->setText(QApplication::translate("ParamWindows", "Valider", 0));
        tabWidget->setTabText(tabWidget->indexOf(Audio), QApplication::translate("ParamWindows", "Audio", 0));
        label_6->setText(QApplication::translate("ParamWindows", "R\303\251solution", 0));
        label_7->setText(QApplication::translate("ParamWindows", "Luminosit\303\251", 0));
        btParDefault_2->setText(QApplication::translate("ParamWindows", "Par d\303\251fault", 0));
        btValider_2->setText(QApplication::translate("ParamWindows", "Valider", 0));
        tabWidget->setTabText(tabWidget->indexOf(Affichage), QApplication::translate("ParamWindows", "Affichage", 0));
        label_8->setText(QApplication::translate("ParamWindows", "Mode de contr\303\264le", 0));
        radioButton->setText(QApplication::translate("ParamWindows", "Clavier", 0));
        radioButton_2->setText(QApplication::translate("ParamWindows", "Manette", 0));
        label_10->setText(QApplication::translate("ParamWindows", "Avancer", 0));
        label_11->setText(QApplication::translate("ParamWindows", "Reculer", 0));
        label_12->setText(QApplication::translate("ParamWindows", "Droite", 0));
        label_9->setText(QApplication::translate("ParamWindows", "Gauche", 0));
        label_13->setText(QApplication::translate("ParamWindows", "Poser une bombe", 0));
        label_14->setText(QApplication::translate("ParamWindows", "Mettre en pause", 0));
        label_15->setText(QString());
        label_16->setText(QString());
        label_17->setText(QApplication::translate("ParamWindows", "Joueur", 0));
        btParDefault_4->setText(QApplication::translate("ParamWindows", "Par d\303\251fault", 0));
        btValider_4->setText(QApplication::translate("ParamWindows", "Valider", 0));
        tabWidget->setTabText(tabWidget->indexOf(Commande), QApplication::translate("ParamWindows", "Commande", 0));
    } // retranslateUi

};

namespace Ui {
    class ParamWindows: public Ui_ParamWindows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMWINDOWS_H
