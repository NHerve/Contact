#include <QApplication>
#include "mainwindow.h"
#include <QSqlDatabase>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    
    QSqlDatabase maBase=QSqlDatabase::addDatabase("QMYSQL");
    maBase.setDatabaseName("dbContact");
    maBase.setHostName("localhost");
    maBase.setUserName("adminDBContact");
    maBase.setPassword("@42Bz8ai");
    if(maBase.open())
    {
    MainWindow w;
    w.show();
    return a.exec();
    }else
    {
        qDebug()<<"connection a la base a echoué"<<endl;
    }

    return a.exec();
}
