#include "ReadThread.h"
#include "LbpProjectNo/DataBase/HistoryTable.h"
#include "LbpProjectNo/DataBase/DataBaseMgr.h"

CReadThread::CReadThread(QObject *parent) : QObject(parent)
{

}

void CReadThread::Run()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","READ");
    db.setDatabaseName("./history.db");

    while (1)
    {
//        CHistoryTable historyTable;
//        qx::dao::fetch_all(historyTable,&db);
//        QThread::sleep(1);
    }
    db.close();
}
