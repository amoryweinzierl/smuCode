#ifndef INDEXINTERFACE_H
#define INDEXINTERFACE_H
#include "word.h"

class IndexInterface
{

public:
    IndexInterface(){}
    virtual void addDocForWord(string,FreqInDoc) = 0;
    virtual void insert(Word) = 0;
    virtual bool contains(Word) = 0;
    virtual int getTotalNodes() = 0;
    virtual int getWordTotalAppearances(string) = 0;
    virtual int getWordTotalDocuments(string) = 0;
    virtual void getWordFreqInDoc(string) = 0;
    virtual void save() = 0;
    virtual ~IndexInterface(){}
};

#endif // INDEXINTERFACE_H
