#ifndef AVLINDEX_H
#define AVLINDEX_H
#include "indexinterface.h"
#include "AVLTree.h"

class AVLIndex : public IndexInterface
{
private:
    AVLTree<Word> words;
public:
    AVLIndex();
    void insert(Word);
    bool contains(Word);
    void getWordFreqInDoc(string);
    //add a document to the word's documents list
    void addDocForWord(string,FreqInDoc);
    int getTotalNodes();
    int getWordTotalAppearances(string);
    int getWordTotalDocuments(string);
    void save();

    virtual ~AVLIndex(){
        words.makeEmpty();
    }


};

#endif // AVLINDEX_H
