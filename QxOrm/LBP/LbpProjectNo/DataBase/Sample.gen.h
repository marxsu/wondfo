/************************************************************************************************
** File created by QxEntityEditor 1.2.6 (2022/10/18 16:53) : please, do NOT modify this file ! **
************************************************************************************************/

#ifndef _LBP_SAMPLE_H_
#define _LBP_SAMPLE_H_

#include "QxOrm.h"

class history;

class  sample
{

   QX_REGISTER_FRIEND_CLASS(sample)

public:

   typedef qx::QxCollection<long, std::shared_ptr<history> > type_list_of_history;

public:

   QString m_Id;
   long m_Type;
   type_list_of_history m_list_of_history;

public:

   sample();
   sample(const QString & id);
   virtual ~sample();

   QString getId() const;
   long getType() const;
   type_list_of_history getlist_of_history() const;
   type_list_of_history & list_of_history();
   const type_list_of_history & list_of_history() const;

   void setId(const long & val);
   void setType(const long & val);
   void setlist_of_history(const type_list_of_history & val);

   type_list_of_history getlist_of_history(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);
   type_list_of_history & list_of_history(bool bLoadFromDatabase, const QString & sAppendRelations = QString(), QSqlDatabase * pDatabase = NULL, QSqlError * pDaoError = NULL);

public:

   static QString relation_list_of_history(bool key = false) { Q_UNUSED(key); return "list_of_history"; }

public:

   static QString column_Id(bool key = false) { Q_UNUSED(key); return "Id"; }
   static QString column_Type(bool key = false) { Q_UNUSED(key); return "Type"; }

public:

   static QString table_name(bool key = false) { Q_UNUSED(key); return "sample"; }

};

typedef std::shared_ptr<sample> sample_ptr;
typedef qx::QxCollection<long, sample_ptr> list_of_sample;
typedef std::shared_ptr<list_of_sample> list_of_sample_ptr;

QX_REGISTER_PRIMARY_KEY(sample,QString) //注册主键类型

QX_REGISTER_COMPLEX_CLASS_NAME_HPP_EXPORT_DLL(sample, qx::trait::no_base_class_defined, 0, sample)

#include "History.gen.h"

#endif // _LBP_SAMPLE_H_
