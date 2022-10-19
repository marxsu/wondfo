#################################################################################################
## File created by QxEntityEditor 1.2.6 (2022/10/18 16:53) : please, do NOT modify this file ! ##
#################################################################################################

include(QxOrm/QxOrm.pri)

!contains(DEFINES, _QX_NO_PRECOMPILED_HEADER) {
PRECOMPILED_HEADER += $$PWD/include/LBP_precompiled_header.gen.h
} # !contains(DEFINES, _QX_NO_PRECOMPILED_HEADER)

HEADERS += $$PWD/include/LBP_precompiled_header.gen.h
HEADERS += $$PWD/include/LBP_export.gen.h

HEADERS += $$PWD/include/history.gen.h
HEADERS += $$PWD/include/sample.gen.h

HEADERS += $$PWD/custom/include/history.h
HEADERS += $$PWD/custom/include/sample.h

contains(DEFINES, _QX_UNITY_BUILD) {

SOURCES += $$PWD/src/LBP_all.gen.cpp

} else {

SOURCES += $$PWD/src/history.gen.cpp
SOURCES += $$PWD/src/sample.gen.cpp

SOURCES += $$PWD/custom/src/history.cpp
SOURCES += $$PWD/custom/src/sample.cpp

} # contains(DEFINES, _QX_UNITY_BUILD)

include($$PWD/custom/LBP.pri)
