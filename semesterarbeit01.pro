TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    attlib.cpp \
    tokenlib.cpp \
    textlib.cpp \
    dtd.cpp

data.path = $$OUT_PWD/

data.files += $$PWD/*.dat

data.files += $$PWD/*.xml

data.files += $$PWD/*.dtd

data.files += $$PWD/*.txt

INSTALLS += data

DISTFILES += \
    lagerbestand.txt \
    modekatalog.xml \
    modekatalog.dtd

HEADERS += \
    att.h \
    token.h \
    dtd.h \
    text.h
