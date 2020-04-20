TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ../../lib/DSString.cpp \
        ALData.cpp \
        AdjList.cpp \
        Flight.cpp \
        functions.cpp \
        main.cpp \
        pathObject.cpp \
        tests.cpp

HEADERS += \
    ../../lib/Catch.hpp \
    ../../lib/DSString.h \
    ../../lib/DSVector.h \
    ALData.h \
    AdjList.h \
    DSStack.h \
    Flight.h \
    LinkedList.h \
    Node.h \
    catch.h \
    functions.h \
    pathObject.h
