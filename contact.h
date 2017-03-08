#ifndef CONTACT_H
#define CONTACT_H
#include <QString>

class Contact
{
public:
    Contact();
    Contact(int id,QString nom,QString prenom,QString mail,QString numPortable);

    int getId() const;
    void setId(int value);
    QString getNom() const;
    void setNom(const QString &value);
    QString getPrenom() const;
    void setPrenom(const QString &value);
    QString getMail() const;
    void setMail(const QString &value);
    QString getNumPortable() const;
    void setNumPortable(const QString &value);
private:

    int id;
    QString nom;
    QString prenom;
    QString mail;
    QString numPortable;

};




#endif // CONTACT_H
