
create database dbContact;

grant all privileges on dbContact.* to adminDBContact identified by 'leMotDePasse';


create table contact (	idContact integer not null primary key,
			prenom char(255) not null,
			nom char(255) not null,
			mail char(255),
			numPortable char(255) not null);
