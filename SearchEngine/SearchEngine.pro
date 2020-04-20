TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Porter2Stemmer.cpp \
        avlindex.cpp \
        freqindoc.cpp \
        htindex.cpp \
        main.cpp \
        parser.cpp \
        test.cpp \
        word.cpp

HEADERS += \
    AVLTree.h \
    HashTable.h \
    Porter2Stemmer.h \
    avlindex.h \
    freqindoc.h \
    htindex.h \
    indexinterface.h \
    parser.h \
    word.h

DISTFILES += \
    stopWords.txt
