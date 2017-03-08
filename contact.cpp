#include "contact.h"


Contact::Contact()
{
}
Contact::Contact(int idContact,QString nomContact,QString prenomContact,QString mailContact,QString numPortableContact)
{
    id=idContact;
    nom=nomContact;
    prenom=prenomContact;
    mail=mailContact;
    numPortable=numPortableContact;

}

int Contact::getId() const
{
return id;
}

void Contact::setId(int value)
{
id = value;
}
QString Contact::getNom() const
{
return nom;
}

void Contact::setNom(const QString &value)
{
nom = value;
}
QString Contact::getPrenom() const
{
return prenom;
}

void Contact::setPrenom(const QString &value)
{
prenom = value;
}
QString Contact::getMail() const
{
return mail;
}

void Contact::setMail(const QString &value)
{
mail = value;
}
QString Contact::getNumPortable() const
{
return numPortable;
}

void Contact::setNumPortable(const QString &value)
{
numPortable = value;
}
