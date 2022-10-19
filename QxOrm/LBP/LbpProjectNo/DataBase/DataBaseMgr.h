#ifndef CDATABASEMGR_H
#define CDATABASEMGR_H

#include <QObject>
#include <QSqlDatabase>
#include "./Common/Singleton/Singleton.h"

class CDataBaseMgr : public QObject,public CSingleton<CDataBaseMgr>
{
    Q_OBJECT
    friend class CSingleton;
public:

    QSqlDatabase* GetHistoryDB();

private:
    explicit CDataBaseMgr(QObject *parent = nullptr);

    void _InitDataBase();

private:

    QSqlDatabase m_HistoryDB;

signals:

};

#endif // CDATABASEMGR_H
