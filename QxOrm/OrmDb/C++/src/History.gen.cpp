/************************************************************************************************
** File created by QxEntityEditor 1.2.6 (2022/10/18 16:53) : please, do NOT modify this file ! **
************************************************************************************************/

#include "../include/LBP_precompiled_header.gen.h"

#include "../include/history.gen.h"
#include "../include/sample.gen.h"

#include <QxOrm_Impl.h>

QX_REGISTER_COMPLEX_CLASS_NAME_CPP_LBP(history, history)

namespace qx {

template <>
void register_class(QxClass<history> & t)
{
   qx::IxDataMember * pData = NULL; Q_UNUSED(pData);
   qx::IxSqlRelation * pRelation = NULL; Q_UNUSED(pRelation);
   qx::IxFunction * pFct = NULL; Q_UNUSED(pFct);
   qx::IxValidator * pValidator = NULL; Q_UNUSED(pValidator);

   t.setName("history");
   t.setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");

   pData = t.id(& history::m_id, "id", 0);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");

   pData = t.data(& history::m_no, "no", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");
   pData = t.data(& history::m_result, "result", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");
   pData = t.data(& history::m_datetime, "datetime", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");

   pRelation = t.relationManyToOne(& history::m_sampleid, "sampleid", 0);
   pRelation->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");

   qx::QxValidatorX<history> * pAllValidator = t.getAllValidator(); Q_UNUSED(pAllValidator);
}

} // namespace qx

history::history() : m_id(0), m_no(0) { ; }

history::history(const long & id) : m_id(id), m_no(0) { ; }

history::~history() { ; }

long history::getid() const { return m_id; }

long history::getno() const { return m_no; }

QString history::getresult() const { return m_result; }

QDateTime history::getdatetime() const { return m_datetime; }

history::type_sampleid history::getsampleid() const { return m_sampleid; }

void history::setid(const long & val) { m_id = val; }

void history::setno(const long & val) { m_no = val; }

void history::setresult(const QString & val) { m_result = val; }

void history::setdatetime(const QDateTime & val) { m_datetime = val; }

void history::setsampleid(const history::type_sampleid & val) { m_sampleid = val; }

history::type_sampleid history::getsampleid(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getsampleid(); }
   QString sRelation = "{id} | sampleid";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   history tmp;
   tmp.m_id = this->m_id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_sampleid = tmp.m_sampleid; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_sampleid;
}

