#ifndef CSAMPLETABLE_H
#define CSAMPLETABLE_H

#include "QxOrm.h"

class CHistoryTable;

class CSampleTable
{
    typedef qx::QxCollection<long, std::shared_ptr<CHistoryTable> > Type_List_Of_History;

public:
    CSampleTable(){}

    int m_SampleId;

    int m_SampleType;

    Type_List_Of_History m_ListOfHistory;
};

QX_REGISTER_PRIMARY_KEY(CSampleTable,int) //注册主键类型
//QX_REGISTER_HPP_EXPORT_DLL(CSampleTable,qx::trait::no_base_class_defined, 0)


#include "HistoryTable.h"

#endif // CSAMPLETABLE_H
