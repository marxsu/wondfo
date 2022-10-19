#include "MainWindow.h"
#include "QxOrm.h"
#include <QApplication>

#include "LbpProjectNo/DataBase/HistoryTable.h"
#include "LbpProjectNo/DataBase/SampleTable.h"
#include "LbpProjectNo/DataBase/DataBaseMgr.h"

#include "LbpProjectNo/DataBase/Sample.gen.h"
#include "LbpProjectNo/DataBase/History.gen.h"

//#include "Sample.gen.h"
//#include "History.gen.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qx::QxSqlDatabase::getSingleton()->setDriverName("QSQLITE");
    qx::QxSqlDatabase::getSingleton()->setDatabaseName("./history.db");
    qx::QxSqlDatabase::getSingleton()->setHostName("localhost");
    qx::QxSqlDatabase::getSingleton()->setUserName("root");
    qx::QxSqlDatabase::getSingleton()->setPassword("12345678");


//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","CREATE");
//    db.setDatabaseName("./history.db");
//    QSqlError daoError = qx::dao::create_table<CSampleTable>(&db);
//    daoError = qx::dao::create_table<CHistoryTable>(&db);

    QSqlError daoError = qx::dao::create_table<sample>(); //只能创建一些基本的表结构，像有外键的表结构就无法创建
    daoError = qx::dao::create_table<history>();

//    db.close();

    MainWindow w;
    w.show();
    return a.exec();
}
