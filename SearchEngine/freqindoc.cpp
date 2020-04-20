#include "freqindoc.h"

FreqInDoc::FreqInDoc()
{
    frequency = 0;
    documentTitle = "";
    documentID = 0;
    excerpt = "";
}

FreqInDoc::FreqInDoc(int frequency, string documentTitle){
    this->frequency = frequency;
    this->documentTitle = documentTitle;
}

FreqInDoc::FreqInDoc(int frequency, string documentTitle, int documentID){
    this->frequency = frequency;
    this->documentTitle = documentTitle;
    this->documentID = documentID;
}

FreqInDoc::FreqInDoc(const FreqInDoc& f){
    frequency = f.frequency;
    documentTitle = f.documentTitle;
}

FreqInDoc& FreqInDoc::operator=(const FreqInDoc& f){
    this->frequency = f.frequency;
    this->documentTitle = f.documentTitle;
    return *this;
}

FreqInDoc::~FreqInDoc(){

}

int FreqInDoc::getFrequency(){
    return frequency;
}

string FreqInDoc::getDocumentTitle(){
    return documentTitle;
}

int FreqInDoc::getDocumentID(){
    return documentID;
}

string FreqInDoc::getExcerpt(){
    return excerpt;
}
