#ifndef FREQINDOC_H
#define FREQINDOC_H
#include <iostream>
#include <string>
using namespace std;

//this class holds the frequency of a word in a certain document
class FreqInDoc
{
private:
    int frequency;
    string documentTitle;
    int documentID;
    string excerpt;
public:
    FreqInDoc();
    FreqInDoc(int, string);
    FreqInDoc(int, string, int);
    //copy constructor
    FreqInDoc(const FreqInDoc&);
    //overloaded assignment operator
    FreqInDoc& operator=(const FreqInDoc&);
    ~FreqInDoc();
    //getters of frequency and document
    int getFrequency();
    string getDocumentTitle();
    int getDocumentID();
    string getExcerpt();
};

#endif // FREQINDOC_H
