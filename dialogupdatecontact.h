#ifndef DIALOGUPDATECONTACT_H
#define DIALOGUPDATECONTACT_H

#include <QDialog>

namespace Ui {
class DialogUpdateContact;
}

class DialogUpdateContact : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogUpdateContact(QString leNom,QString lePrenom,QString leMail,QString leNum,QWidget *parent = 0);
    ~DialogUpdateContact();
    QString getPrenomUp();
    QString getNomUp();
    QString getMailUp();
    QString getNumPortUp();
    
private:
    Ui::DialogUpdateContact *ui;
};

#endif // DIALOGUPDATECONTACT_H
