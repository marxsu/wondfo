#include "DataBaseMgr.h"

CDataBaseMgr::CDataBaseMgr(QObject *parent) : QObject(parent)
{
    _InitDataBase();
}

void CDataBaseMgr::_InitDataBase()
{
    m_HistoryDB =  QSqlDatabase::addDatabase("QSQLITE");
    m_HistoryDB.setDatabaseName("./history.db");
}


QSqlDatabase* CDataBaseMgr::GetHistoryDB()
{
    return &m_HistoryDB;
}
