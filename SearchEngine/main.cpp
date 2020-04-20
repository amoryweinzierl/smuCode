#define CATCH_CONFIG_RUNNER
#include "parser.h"
#include "catch.hpp"
#include <vector>
#include <list>
#include "HashTable.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

using namespace std;

int runCatchTests(int argc,char *argv[]){
    return Catch::Session().run();
}

Word toWord(string sWord){
    stringstream ss(sWord);
    string tempWord;
    vector<string> documents;
    vector<int> frequencies;
    int count = 1;
    Word word;
    while(ss >> tempWord){
        if(count == 1){
            //the first word in this string is the string version of the word
            word.setWord(tempWord);
        }
        //every even word is a document
        else if(count % 2 == 0){
            documents.push_back(tempWord);
        }
        else{
            int frequency = stoi(tempWord);
            frequencies.push_back(frequency);
        }
        count++;
    }
    //save all the frequencies to the word
    for(int i = 0; i < documents.size(); i++){
        FreqInDoc freq(frequencies.at(i),documents.at(i));
        word.addFreq(freq);
    }
    return word;
}

void mode(){
    //what mode the user wants to enter maintenence or interface
}

IndexInterface* loadIndex(){
    int choice = -1;
    while(choice < 0 || choice > 2){
    cout << "Would you like to load the index into an AVL Tree or a Hash Table?" << endl;
    cout << "Press 1 for AVL Tree and Press 2 for Hash Table. Press 0 to exit." << endl;

    cin >> choice;

    if(choice < 0 || choice > 2){
        cout << "Invalid choice, press 1 for AVL Tree and 2 for Hash Table!" << endl;
        cout << endl;
    }
    else{
    if(choice == 0){
        exit(0);
    }
    ifstream fin;
    fin.open("../SearchEngine/persistentIndex.txt");
    IndexInterface *interface;
    if(fin.is_open()){
        if(choice == 1){
            //load into avl tree
            interface = new AVLIndex;

            string row;
            while(getline(fin,row)){
                Word word = toWord(row);
                interface->insert(word);
            }
            return interface;
        }
        else if(choice == 2){
            interface = new HTIndex;

            string row;
            while(getline(fin,row)){
                Word word = toWord(row);
                interface->insert(word);
            }
            return interface;
        }

    }
    else{
        throw std::runtime_error("Persistent index file could not be opened!");
    }
    fin.close();
    }
    }
}

void queryProcessor(IndexInterface *DSType){
    char buffer[50];

    cout << "For searches of files that include multiple words, please prefix your search with AND." << endl;
    cout << "For searches of files with at least one of the query words, please prefix your search with OR" << endl;
    cout << "If you do not want to return any files that contain a selected word, please prefix the word with NOT" << endl;
    cout << "Please enter your search: ";
    cin >> buffer;

    istringstream ss(buffer);

    string word;
    ss >> word;

    if(word == "AND"){
        do{
            string word;
            ss >> word;

            cout << word << endl;

            transform(word.begin(), word.end(), word.begin(), ::tolower);
            Porter2Stemmer::stem(word);

            DSType->getWordFreqInDoc(word);

        }while(ss);
    }

    else if(word == "OR"){

    }

    else{
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        Porter2Stemmer::stem(word);

        DSType->getWordFreqInDoc(word);
    }
}

int main(int argc, char *argv[])
{

    if(argc == 1){
        return runCatchTests(argc, argv);
    }

    Parser parser(argv);
    parser.save();

    IndexInterface *DSType = loadIndex();

    queryProcessor(DSType);

//        string wordToSearch = argv[2];
//        transform(wordToSearch.begin(),wordToSearch.end(),wordToSearch.begin(),::tolower);


    return 0;
}
