TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ../../lib/DSString.cpp \
        Functions.cpp \
        main.cpp \
        tests.cpp \
        tweetobj.cpp

HEADERS += \
    ../../lib/Catch.hpp \
    ../../lib/DSString.h \
    DSVector.h \
    Functions.h \
    TweetObj.h
