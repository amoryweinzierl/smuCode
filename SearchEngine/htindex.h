#ifndef HTINDEX_H
#define HTINDEX_H
#include "indexinterface.h"
#include "HashTable.h"

class HTIndex : public IndexInterface
{
private:
    //key is the string version, value is the Word version of the word
    HashTable<string,Word> words;
public:
    HTIndex();
    void insert(Word);
    bool contains(Word);
    //add a document to the word's documents list
    void addDocForWord(string,FreqInDoc);
    void getWordFreqInDoc(string);
    int getTotalNodes();
    int getWordTotalAppearances(string);
    int getWordTotalDocuments(string);
    void save();

    virtual ~HTIndex(){
        words.clear();
    }
};

#endif // HTINDEX_H
