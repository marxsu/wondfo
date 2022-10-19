#include "SampleTable.h"

QX_REGISTER_COMPLEX_CLASS_NAME_CPP_EXPORT_DLL(CSampleTable,CSampleTable)

namespace qx{
    template <> void register_class(QxClass<CSampleTable> &t){

        t.setName("sample");
        t.id(&CSampleTable::m_SampleId,"Id");
        t.data(&CSampleTable::m_SampleType,"Type");

        t.relationOneToMany(& CSampleTable::m_ListOfHistory, "list_of_history", "sampleid", 0);
    }
}
