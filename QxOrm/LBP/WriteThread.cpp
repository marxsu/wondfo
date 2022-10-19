#include "WriteThread.h"
#include "LbpProjectNo/DataBase/HistoryTable.h"
#include "LbpProjectNo/DataBase/DataBaseMgr.h"
#include <QSet>
#include <QSharedPointer>

CWriteThread::CWriteThread(QObject *parent) : QObject(parent)
{

}

void CWriteThread::Run()
{
    int i = 0;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","WRITE");
    db.setDatabaseName("./history.db");

    while(1)
    {
//        CHistoryTable historyTable;
//        historyTable.m_No = i++;
//        historyTable.m_Result = "result";
//        historyTable.m_DateTime = QDateTime::currentDateTime();

//        CHistoryTable::ForeignKey test;
//        QSharedPointer<CSampleTable> sampleTable = QSharedPointer<CSampleTable>(new CSampleTable());
//        test.insert(sampleTable);
//        historyTable.m_ForeignKey = test;

//        qx::dao::insert(historyTable,&db);

        QThread::sleep(1);
    }
    db.close();
}
