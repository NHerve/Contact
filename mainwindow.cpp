#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QDebug>
#include <QInputDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    chargerContact();
    afficheContact();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::chargerContact()
{
    qDebug()<<"MainWindow::chargerContact()";

    QSqlQuery reqContact("select idContact, prenom, nom, mail, numPortable from contact;");
    while(reqContact.next())
    {
        int idContact= reqContact.value(0).toInt();
        QString prenomContact = reqContact.value(1).toString();
        QString nomContact = reqContact.value(2).toString();
        QString mailContact = reqContact.value(3).toString();
        QString numPortableContact = reqContact.value(4).toString();

        Contact newContact(idContact,nomContact,prenomContact,mailContact,numPortableContact);

        vectContact.push_back(newContact);
    }

}

//--------------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_pushButtonAddContact_clicked()
{
    qDebug()<<"MainWindow::on_pushButtonAddContact_clicked()"<<endl;

    DialogAddContact newContact;

    if(newContact.exec() == QDialog::Accepted)
    {
        QString prenomContact = newContact.getPrenom();
        QString nomContact = newContact.getNom();
        QString mailContact = newContact.getMail();
        QString numPortableContact = newContact.getNumPort();
        if(numPortableContact.length()<10)
        {
            ui->statusBar->showMessage(tr("le numero de portable a etait mal saisie"),2100);
        }else
        {
            //*****************************************************************************************************
            //pour tout les contact
            int idMax=0;
            for(int cpt=0;cpt<vectContact.size();cpt++)
            {
                //si l'id est plus grande on la stock dans une variable
                if (idMax<vectContact[cpt].getId())
                {
                    idMax=vectContact[cpt].getId();
                }
            }

            //*****************************************************************************************************
            int idContact=idMax+1;

            Contact newContact(idContact,nomContact,prenomContact,mailContact,numPortableContact);

            vectContact.push_back(newContact);

            QString addContact("insert into contact values(");
            addContact+=QString::number(idContact);
            addContact+=",'";
            addContact+=prenomContact;
            addContact+="','";
            addContact+=nomContact;
            addContact+="','";
            addContact+=mailContact;
            addContact+="','";
            addContact+=numPortableContact;
            addContact+="');";

            QSqlQuery reqAddContact;
            reqAddContact.exec(addContact);

            afficheContact();
        }
    }
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::afficheContact()
{
    qDebug()<<"void MainWindow::afficheContact()"<<endl;

    ui->tableWidgetContact->setRowCount(0);
    ui->tableWidgetContact->setRowCount(vectContact.size());
    for(unsigned int leCpt=0;leCpt<vectContact.size();leCpt++)
    {

        QString lIdContact = QString::number(vectContact[leCpt].getId());
        QTableWidgetItem *itemIdContact=new QTableWidgetItem(lIdContact);

        QString lePrenomContact = vectContact[leCpt].getPrenom();
        QTableWidgetItem *itemPrenomContact=new QTableWidgetItem(lePrenomContact);

        QString leNomContact = vectContact[leCpt].getNom();
        QTableWidgetItem *itemNomContact=new QTableWidgetItem(leNomContact);

        QString leMailContact = vectContact[leCpt].getMail();
        QTableWidgetItem *itemMailContact=new QTableWidgetItem(leMailContact);

        QString leNumContact = vectContact[leCpt].getNumPortable();
        QTableWidgetItem *itemNumContact=new QTableWidgetItem(leNumContact);

        ui->tableWidgetContact->setItem(leCpt,0,itemIdContact);
        ui->tableWidgetContact->setItem(leCpt,1,itemPrenomContact);
        ui->tableWidgetContact->setItem(leCpt,2,itemNomContact);
        ui->tableWidgetContact->setItem(leCpt,3,itemMailContact);
        ui->tableWidgetContact->setItem(leCpt,4,itemNumContact);

        ui->statusBar->showMessage(tr("contact afficher"),2100);

    }

}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------

void MainWindow::on_pushButtonDelContact_clicked()
{
    qDebug()<<"MainWindow::on_pushButtonDelContact_clicked()"<<endl;

    int ret = QMessageBox::question(this,tr("GestContact"),tr("voulez vous supprimmer le contact ?"),
                                    QMessageBox::Yes | QMessageBox::No,QMessageBox::No);
    if(ret == QMessageBox::Yes)
    {

        QString idContact = QString::number(vectContact[ui->tableWidgetContact->currentRow()].getId());
        int test = ui->tableWidgetContact->currentRow();
        ui->tableWidgetContact->removeRow(ui->tableWidgetContact->currentRow());

        QString delContact("delete from contact where idContact=");
        delContact+=idContact;
        delContact+=";";

        QSqlQuery reqDelContact;
        reqDelContact.exec(delContact);

        vectContact.remove(test);

        afficheContact();
        ui->statusBar->showMessage(tr("contact supprimer"),2100);

    }
}

void MainWindow::on_pushButtonUpdate_clicked()
{

    qDebug()<<"MainWindow::on_pushButtonUpdate_clicked()"<<endl;

    DialogUpdateContact upDateContact(vectContact[ui->tableWidgetContact->currentRow()].getNom(),
                                      vectContact[ui->tableWidgetContact->currentRow()].getPrenom(),
                                      vectContact[ui->tableWidgetContact->currentRow()].getMail(),
                                      vectContact[ui->tableWidgetContact->currentRow()].getNumPortable());


    if(upDateContact.exec()==QDialog::Accepted)
    {
        int ret = QMessageBox::question(this,tr("GestContact"),tr("voulez vous modifier le contact ?"),
                                        QMessageBox::Yes | QMessageBox::No,QMessageBox::Yes);
        if(ret == QMessageBox::Yes)
        {
            QString prenomContactUp = upDateContact.getPrenomUp();
            QString nomContactUp = upDateContact.getNomUp();
            QString mailContactUp = upDateContact.getMailUp();
            QString numPortableContactUp = upDateContact.getNumPortUp();

            QString reqUpdate="update contact set ";


            if(!(prenomContactUp==vectContact[ui->tableWidgetContact->currentRow()].getPrenom()))
            {
                //modification dans le vecteur
                vectContact[ui->tableWidgetContact->currentRow()].setPrenom(prenomContactUp);

            }

            if(!(nomContactUp==vectContact[ui->tableWidgetContact->currentRow()].getNom()))
            {
                //modification dans le vecteur
                vectContact[ui->tableWidgetContact->currentRow()].setNom(nomContactUp);
            }

            if(!(mailContactUp==vectContact[ui->tableWidgetContact->currentRow()].getMail()))
            {
                //modification dans le vecteur
                vectContact[ui->tableWidgetContact->currentRow()].setMail(mailContactUp);
            }

            if(!(numPortableContactUp==vectContact[ui->tableWidgetContact->currentRow()].getNumPortable()))
            {
                //modification dans le vecteur
                vectContact[ui->tableWidgetContact->currentRow()].setNumPortable(numPortableContactUp);
            }
            //modification dans la bdd
            //reqUpdate="update contact set prenom='";//***********************************************************met ca dans les if
            reqUpdate+=vectContact[ui->tableWidgetContact->currentRow()].getPrenom();
            reqUpdate+="',nom='";
            reqUpdate+=vectContact[ui->tableWidgetContact->currentRow()].getNom();
            reqUpdate+="',mail='";
            reqUpdate+=vectContact[ui->tableWidgetContact->currentRow()].getMail();
            reqUpdate+="',numPortable='";
            reqUpdate+=vectContact[ui->tableWidgetContact->currentRow()].getNumPortable();
            reqUpdate+="' where id=";
            reqUpdate+=QString::number(vectContact[ui->tableWidgetContact->currentRow()].getId());
            reqUpdate+=";";
            QSqlQuery laReqUpdate;
            laReqUpdate.exec(reqUpdate);
        }
    }

    afficheContact();

}
