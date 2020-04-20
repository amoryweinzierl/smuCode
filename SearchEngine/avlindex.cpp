#include "avlindex.h"

AVLIndex::AVLIndex()
{

}

void AVLIndex::insert(Word word){
    words.insert(word);
}

bool AVLIndex::contains(Word word){

    return words.contains(word);
}

void AVLIndex::addDocForWord(string word,FreqInDoc freq){
    Word wordWord(word);
    words.getNode(wordWord).addFreq(freq);
}

void AVLIndex::getWordFreqInDoc(string word){
    Word wordWord(word);
    FreqInDoc temp;

    if(words.contains(word)){
        Word wordToReturn = words.getNode(wordWord);
        for(int i = 0; i < wordToReturn.getFrequencies().size() - 1; i++){
            for(int j = 0; j < wordToReturn.getFrequencies().size() - i - 1; j++){
                if(wordToReturn.getFrequencies().at(j).getFrequency() < wordToReturn.getFrequencies().at(j + 1).getFrequency()){
                    temp = wordToReturn.getFrequencies().at(j);
                    wordToReturn.getFrequencies().at(j) = wordToReturn.getFrequencies().at(j + 1);
                    wordToReturn.getFrequencies().at(j+1) = temp;
                }
            }
        }

        for(int z = 0; z < 5; z++){
            cout << wordToReturn.getFrequencies().at(z).getFrequency() << endl;
            cout << wordToReturn.getFrequencies().at(z).getDocumentTitle() << endl;
        }
    }

    else{
        cout << "word not found" << endl;
    }

}

int AVLIndex::getTotalNodes(){
    return words.getTotalNodes();
}

int AVLIndex::getWordTotalAppearances(string word){
    Word wordWord(word);
    if(words.contains(word)){
        Word wordToReturn = words.getNode(wordWord);
        return wordToReturn.getTotalAppearance();
    }
    else return 0;
}

int AVLIndex::getWordTotalDocuments(string word){
    Word wordWord(word);
    if(words.contains(word)){
        Word wordToReturn = words.getNode(wordWord);
        return wordToReturn.getNumDocument();
    }
    else return 0;
}

void AVLIndex::save(){
    words.saveToFile();
}
