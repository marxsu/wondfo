#include "HistoryTable.h"

QX_REGISTER_COMPLEX_CLASS_NAME_CPP_EXPORT_DLL(CHistoryTable,CHistoryTable)

namespace qx{

    template <> void register_class(QxClass<CHistoryTable> &t){

        t.setName("history");  // 'CHistoryTable' C++ 类映射到 'history' 数据库表

        t.id(&CHistoryTable::m_Id, "id");  // Register 'CHistoryTable::m_Id' <=> primary key in your database

        t.data(&CHistoryTable::m_No, "no");  // Register 'CHistoryTable::m_No' property mapped to 'no' database column name

        t.data(&CHistoryTable::m_Result, "result"); // Register 'CHistoryTable::m_Result' property mapped to 'result' database column name

        t.data(&CHistoryTable::m_DateTime, "datetime");    // Register 'CHistoryTable::m_DateTime' property mapped to 'datetime' database column name

        t.relationManyToOne(& CHistoryTable::m_SampleId, "sampleid", 0);

    }
}
