TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lwinmm

SOURCES += \
    main.cpp \
    plateaujeu.cpp \
    serpent.cpp \
    vitamine.cpp \
    jeuserpent.cpp \
    countdown.cpp

HEADERS += \
    plateaujeu.h \
    serpent.h \
    vitamine.h \
    jeuserpent.h \
    positionxy.h \
    countdown.h
