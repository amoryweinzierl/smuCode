#include "htindex.h"

HTIndex::HTIndex()
{

}

void HTIndex::insert(Word word){
    words.insert(word.getWord(),word);
}

bool HTIndex::contains(Word word){
    return words.contains(word.getWord());
}

//add a document to the word's documents list
void HTIndex::addDocForWord(string word,FreqInDoc freq){
    words.get(word).addFreq(freq);
}

int HTIndex::getTotalNodes(){
    return words.getSize();
}

void HTIndex::getWordFreqInDoc(string word){
    FreqInDoc temp;

    if(words.contains(word)){
        Word wordToReturn = words.get(word);
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

    else if(!words.contains(word)){
        cout << "word not found" << endl;
    }

}

int HTIndex::getWordTotalAppearances(string word){
    return words.get(word).getTotalAppearance();
}

int HTIndex::getWordTotalDocuments(string word){
    return words.get(word).getNumDocument();
}

void HTIndex::save(){
    words.saveToFile();
}
