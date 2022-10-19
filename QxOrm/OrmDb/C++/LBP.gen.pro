#################################################################################################
## File created by QxEntityEditor 1.2.6 (2022/10/18 16:53) : please, do NOT modify this file ! ##
#################################################################################################

include(D:/QxEntityEditor/QxOrmDll/QxOrm.pri)

TEMPLATE = lib
CONFIG += dll
DEFINES += _BUILDING_LBP
INCLUDEPATH += D:/QxEntityEditor/QxOrmDll/include
DESTDIR = $$PWD/bin/

CONFIG(debug, debug|release) {
TARGET = LBPd
} else {
TARGET = LBP
} # CONFIG(debug, debug|release)

LIBS += -L"D:/QxEntityEditor/QxOrmDll/lib"

CONFIG(debug, debug|release) {
LIBS += -l"QxOrmd"
} else {
LIBS += -l"QxOrm"
} # CONFIG(debug, debug|release)

include($$PWD/LBP.gen.pri)

!contains(DEFINES, _QX_UNITY_BUILD) {
SOURCES += $$PWD/src/LBP_main.gen.cpp
} # !contains(DEFINES, _QX_UNITY_BUILD)
