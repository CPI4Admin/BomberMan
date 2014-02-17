/********************************************************************************
** Form generated from reading UI file 'windowstatistics.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_windowstatistics
{
public:
    QPushButton *pushButtonFermer;
    QPushButton *pushButtonReinitialiser;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *LayoutScores;
    QPlainTextEdit *plainTextEdit;
    QTextEdit *textEdit;

    void setupUi(QDialog *windowstatistics)
    {
        if (windowstatistics->objectName().isEmpty())
            windowstatistics->setObjectName(QStringLiteral("windowstatistics"));
        windowstatistics->resize(400, 159);
        pushButtonFermer = new QPushButton(windowstatistics);
        pushButtonFermer->setObjectName(QStringLiteral("pushButtonFermer"));
        pushButtonFermer->setGeometry(QRect(230, 130, 75, 23));
        pushButtonReinitialiser = new QPushButton(windowstatistics);
        pushButtonReinitialiser->setObjectName(QStringLiteral("pushButtonReinitialiser"));
        pushButtonReinitialiser->setGeometry(QRect(320, 130, 75, 23));
        verticalLayoutWidget = new QWidget(windowstatistics);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 160, 141));
        LayoutScores = new QVBoxLayout(verticalLayoutWidget);
        LayoutScores->setObjectName(QStringLiteral("LayoutScores"));
        LayoutScores->setContentsMargins(0, 0, 0, 0);
        plainTextEdit = new QPlainTextEdit(verticalLayoutWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        LayoutScores->addWidget(plainTextEdit);

        textEdit = new QTextEdit(windowstatistics);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(190, 10, 201, 111));

        retranslateUi(windowstatistics);

        QMetaObject::connectSlotsByName(windowstatistics);
    } // setupUi

    void retranslateUi(QDialog *windowstatistics)
    {
        windowstatistics->setWindowTitle(QApplication::translate("windowstatistics", "stat", 0));
        pushButtonFermer->setText(QApplication::translate("windowstatistics", "Fermer", 0));
        pushButtonReinitialiser->setText(QApplication::translate("windowstatistics", "R\303\251initialiser", 0));
        plainTextEdit->setPlainText(QApplication::translate("windowstatistics", "Meilleurs scores", 0));
        textEdit->setHtml(QApplication::translate("windowstatistics", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Nombre de parties jou\303\251es: 0</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Nombre de parties gagn\303\251es: 0</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Nombre de parties perdu: 0</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-"
                        "left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Nombre d'heures jou\303\251es: 0</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Nombre de bonus:0</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class windowstatistics: public Ui_windowstatistics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWSTATISTICS_H
