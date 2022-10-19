#ifndef CHISTORYTABLE_H
#define CHISTORYTABLE_H

#include "QxOrm.h"

class CSampleTable;

class CHistoryTable
{

public:
    CHistoryTable(){}

    typedef std::shared_ptr<CSampleTable> Type_SampleId;

public:

    int m_Id;

    QString m_Result;

    QDateTime m_DateTime;

    int m_No;

    Type_SampleId m_SampleId;

public:

      static QString relation_sampleid(bool key = false) { Q_UNUSED(key); return "sampleid"; }
};
QX_REGISTER_PRIMARY_KEY(CHistoryTable,int) //注册主键类型

/**

 QX_REGISTER_HPP_EXPORT_DLL宏是在 QxOrm 上下文中注册 'CHistoryTable' 类所必需的
 参数 1：要注册的当前类 => 'CHistoryTable'
 参数 2 : 基类，如果没有基类，使用 qx trait => 'qx::trait::no_base_class_defined'
 参数 3 : 序列化引擎用来提供“上升兼容性”的类版本
*/
QX_REGISTER_COMPLEX_CLASS_NAME_HPP_EXPORT_DLL(CHistoryTable,qx::trait::no_base_class_defined, 0,CHistoryTable)

#include "SampleTable.h"

#endif // CHISTORYTABLE_H
