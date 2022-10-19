/************************************************************************************************
** File created by QxEntityEditor 1.2.6 (2022/10/18 16:53) : please, do NOT modify this file ! **
************************************************************************************************/

#include "Sample.gen.h"
#include "History.gen.h"

#include <QxOrm_Impl.h>

QX_REGISTER_COMPLEX_CLASS_NAME_CPP_EXPORT_DLL(sample, sample)

namespace qx {

template <>
void register_class(QxClass<sample> & t)
{
   qx::IxDataMember * pData = NULL; Q_UNUSED(pData);
   qx::IxSqlRelation * pRelation = NULL; Q_UNUSED(pRelation);
   qx::IxFunction * pFct = NULL; Q_UNUSED(pFct);
   qx::IxValidator * pValidator = NULL; Q_UNUSED(pValidator);

   t.setName("sample");
   t.setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");

   pData = t.id(& sample::m_Id, "Id", 0);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");

   pData = t.data(& sample::m_Type, "Type", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");

   pRelation = t.relationOneToMany(& sample::m_list_of_history, "list_of_history", "sampleid", 0);

   qx::QxValidatorX<sample> * pAllValidator = t.getAllValidator(); Q_UNUSED(pAllValidator);
}

} // namespace qx

sample::sample() : m_Id(""), m_Type(0) { ; }

sample::sample(const QString & id) : m_Id(id), m_Type(0) { ; }

sample::~sample() { ; }

QString sample::getId() const { return m_Id; }

long sample::getType() const { return m_Type; }

sample::type_list_of_history sample::getlist_of_history() const { return m_list_of_history; }

sample::type_list_of_history & sample::list_of_history() { return m_list_of_history; }

const sample::type_list_of_history & sample::list_of_history() const { return m_list_of_history; }

void sample::setId(const long & val) { m_Id = val; }

void sample::setType(const long & val) { m_Type = val; }

void sample::setlist_of_history(const sample::type_list_of_history & val) { m_list_of_history = val; }

sample::type_list_of_history sample::getlist_of_history(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return getlist_of_history(); }
   QString sRelation = "{Id} | list_of_history";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   sample tmp;
   tmp.m_Id = this->m_Id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_history = tmp.m_list_of_history; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_history;
}

sample::type_list_of_history & sample::list_of_history(bool bLoadFromDatabase, const QString & sAppendRelations /* = QString() */, QSqlDatabase * pDatabase /* = NULL */, QSqlError * pDaoError /* = NULL */)
{
   if (pDaoError) { (* pDaoError) = QSqlError(); }
   if (! bLoadFromDatabase) { return list_of_history(); }
   QString sRelation = "{Id} | list_of_history";
   if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
   else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
   sample tmp;
   tmp.m_Id = this->m_Id;
   QSqlError daoError = qx::dao::fetch_by_id_with_relation(sRelation, tmp, pDatabase);
   if (! daoError.isValid()) { this->m_list_of_history = tmp.m_list_of_history; }
   if (pDaoError) { (* pDaoError) = daoError; }
   return m_list_of_history;
}

