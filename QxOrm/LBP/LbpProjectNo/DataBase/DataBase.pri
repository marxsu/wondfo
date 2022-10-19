#INCLUDEPATH += $$PWD/LBP/include
#DEPENDPATH  += $$PWD/LBP/include

HEADERS += \
    $$PWD/DataBaseMgr.h \
    $$PWD/History.gen.h \
#    $$PWD/HistoryTable.h \
    $$PWD/Sample.gen.h \
#    $$PWD/SampleTable.h

SOURCES += \
    $$PWD/DataBaseMgr.cpp \
    $$PWD/History.gen.cpp \
#    $$PWD/HistoryTable.cpp \
    $$PWD/Sample.gen.cpp \
#    $$PWD/SampleTable.cpp

# LIBS += -L$$PWD/LBP/ -lLBP
