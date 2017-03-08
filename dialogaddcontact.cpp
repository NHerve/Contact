#include "dialogaddcontact.h"
#include "ui_dialogaddcontact.h"

DialogAddContact::DialogAddContact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddContact)
{
    ui->setupUi(this);
}

DialogAddContact::~DialogAddContact()
{
    delete ui;
}

QString DialogAddContact::getPrenom()
{
    return ui->lineEditPrenom->text();
}

QString DialogAddContact::getNom()
{
    return ui->lineEditNom->text();
}

QString DialogAddContact::getMail()
{
    return ui->lineEditMail->text();
}

QString DialogAddContact::getNumPort()
{
    return ui->lineEditNumPort->text();
}

