#include "dialogupdatecontact.h"
#include "ui_dialogupdatecontact.h"

DialogUpdateContact::DialogUpdateContact(QString leNom,QString lePrenom,QString leMail,QString leNum,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogUpdateContact)
{
    ui->setupUi(this);
    ui->lineEditNomUp->setText(leNom);
    ui->lineEditMailUp->setText(leMail);
    ui->lineEditNumPortUp->setText(leNum);
    ui->lineEditPrenomUp->setText(lePrenom);
}

DialogUpdateContact::~DialogUpdateContact()
{
    delete ui;
}

QString DialogUpdateContact::getPrenomUp()
{
    return ui->lineEditPrenomUp->text();
}

QString DialogUpdateContact::getNomUp()
{
    return ui->lineEditNomUp->text();
}

QString DialogUpdateContact::getMailUp()
{
    return ui->lineEditMailUp->text();
}

QString DialogUpdateContact::getNumPortUp()
{
    return ui->lineEditNumPortUp->text();
}
