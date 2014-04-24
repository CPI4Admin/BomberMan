#include "mainwindow.h"
#include <QApplication>
// I'm coming....
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
