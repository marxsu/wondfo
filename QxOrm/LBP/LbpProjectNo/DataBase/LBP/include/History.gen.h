/************************************************************************************************
** File created by QxEntityEditor 1.2.6 (2022/10/18 16:53) : please, do NOT modify this file ! **
************************************************************************************************/

#ifndef _LBP_HISTORY_H_
#define _LBP_HISTORY_H_

class sample;

class LBP_EXPORT history
{

   QX_REGISTER_FRIEND_CLASS(history)

public:

   typedef std::shared_ptr<sample> type_sampleid;

protected:

   long m_id;
   long m_no;
   QString m_result;
   QDateTime m_datetime;
   type_sampleid m_sampleid;

public:

   history();
   history(const long & id);
   virtual ~history();

   long getid() const;
   long getno() const;
   QString getresult() const;
   QDateTime getdatetime() const;
   type_sampleid getsampleid() const;

   void setid(const long & val);
   void setno(const long & val);
   void setresult(const QString & val);
   void setdatetime(const QDateTime & val);
   void setsampleid(const type_sampleid & val);

   type_sampleid getsampleid(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);

public:

   static QString relation_sampleid(bool key = false) { Q_UNUSED(key); return "sampleid"; }

public:

   static QString column_id(bool key = false) { Q_UNUSED(key); return "id"; }
   static QString column_no(bool key = false) { Q_UNUSED(key); return "no"; }
   static QString column_result(bool key = false) { Q_UNUSED(key); return "result"; }
   static QString column_datetime(bool key = false) { Q_UNUSED(key); return "datetime"; }

public:

   static QString table_name(bool key = false) { Q_UNUSED(key); return "history"; }

};

typedef std::shared_ptr<history> history_ptr;
typedef qx::QxCollection<long, history_ptr> list_of_history;
typedef std::shared_ptr<list_of_history> list_of_history_ptr;

QX_REGISTER_COMPLEX_CLASS_NAME_HPP_LBP(history, qx::trait::no_base_class_defined, 0, history)

#include "../include/sample.gen.h"


#endif // _LBP_HISTORY_H_
