#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "contact.h"
#include <QMainWindow>
#include <QVector>
#include "dialogaddcontact.h"
#include "dialogupdatecontact.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QVector <Contact> vectContact;
    
    void chargerContact();
    void afficheContact();
private slots:
    void on_pushButtonAddContact_clicked();

    //void on_pushButtonActuContact_clicked();

    void on_pushButtonDelContact_clicked();

    void on_pushButtonUpdate_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
