#ifndef DIALOGADDCONTACT_H
#define DIALOGADDCONTACT_H

#include <QDialog>

namespace Ui {
class DialogAddContact;
}

class DialogAddContact : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogAddContact(QWidget *parent = 0);
    ~DialogAddContact();
    QString getPrenom();
    QString getNom();
    QString getMail();
    QString getNumPort();
    
private:
    Ui::DialogAddContact *ui;
};

#endif // DIALOGADDCONTACT_H
