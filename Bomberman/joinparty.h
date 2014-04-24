#ifndef JOINPARTY_H
#define JOINPARTY_H

#include <QMainWindow>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QTextEdit>
#include <QDialog>
#include <QMessageBox>



namespace Ui {
class JoinParty;
}

class JoinParty : public QDialog
{
    Q_OBJECT

public:
    explicit JoinParty(QWidget *parent = 0);
    ~JoinParty();
private:
    Ui::JoinParty *ui;

private slots:
    void ConnectParty();

};

#endif // JOINPARTY_H
