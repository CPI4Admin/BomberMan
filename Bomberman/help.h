#ifndef HELP_H
#define HELP_H


#include <QtGui>

#include <QDialog>


class help:public QDialog
{
public:
    help(QWidget *parent);
private:
    QPushButton*boutonFermer;
};

#endif // HELP_H
