#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <cctype>

#include "Functions.h"

using namespace std;

Functions::Functions() {}

//parses through tweet file
//assigns member variables
//returns dsvector or objects tweetobj
DSVector<TweetObj> Functions::trainTweetAssigner(DSString fileName){
    char buffer[20];
    DSVector<TweetObj> tweet;
    DSString rowNumber;
    DSString tweetId;
    DSString username;
    DSString textTweet;

    ifstream trainTweets;
    trainTweets.open(fileName.c_str());

    trainTweets >> buffer;

    for(int i = 0; i < 200000; i++){
        char buffer[280];
        TweetObj x;

        trainTweets.getline(buffer, 100, ',');
        x.setRowNum(buffer);

        trainTweets.getline(buffer, 100, ',');
        x.setTweetID(buffer);

        trainTweets.getline(buffer, 75, ',');
        x.setUser(buffer);

        trainTweets.getline(buffer, 280, '\n');
        x.setTweetText(buffer);

        tweet.push_back(x);
    }

    trainTweets.close();
    return tweet;
}

//parses through tweet file
//assigns member variables
//returns dsvector or objects tweetobj
DSVector<TweetObj> Functions::testTweetAssigner(DSString fileName){
    char buffer[20];
    DSVector<TweetObj> tweet;
    DSString rowNumber;
    DSString tweetId;
    DSString username;
    DSString textTweet;

    ifstream testTweets;
    testTweets.open(fileName.c_str());

    testTweets >> buffer;

    for(int i = 0; i < 20000; i++){
        char buffer[500];
        TweetObj x;

        testTweets.getline(buffer, 100, ',');
        x.setRowNum(buffer);

        testTweets.getline(buffer, 100, ',');
        x.setTweetID(buffer);

        testTweets.getline(buffer, 75, ',');
        x.setUser(buffer);

        testTweets.getline(buffer, 280, '\n');
        x.setTweetText(buffer);

        tweet.push_back(x);
    }

    testTweets.close();
    return tweet;
}

//parses target file
//makes new tweet objects and assigns member attributes that has
//such as row number, tweet id, and sentiment
//returns dsvector of type tweetObj objects
DSVector<TweetObj> Functions::trainTargetFile(DSString fileName){
    char buffer[20];
    DSString rowNumber;
    DSString tweetId;
    DSString sentiment;

    DSVector<TweetObj> target;

    ifstream trainTarget;
    trainTarget.open(fileName.c_str());

    trainTarget >> buffer;

    for(int i = 0; i < 200000; i++){
        char buffer[500];
        TweetObj x;

        trainTarget.getline(buffer, 100, ',');
        x.setRowNum(buffer);

        trainTarget.getline(buffer, 100, ',');
        x.setSentiment(buffer);

        trainTarget.getline(buffer, 100, '\n');
        x.setTweetID(buffer);

        target.push_back(x);
    }
    trainTarget.close();
    return target;
}

//parses target file
//makes new tweet objects and assigns member attributes that has
//such as row number, tweet id, and sentiment
//returns dsvector of type tweetObj objects
DSVector<TweetObj> Functions::testTargetFile(DSString fileName){
    char buffer[20];
    DSString rowNumber;
    DSString tweetId;
    DSString sentiment;

    DSVector<TweetObj> target;

    ifstream testTarget;
    testTarget.open(fileName.c_str());

    testTarget >> buffer;

    for(int i = 0; i < 20000; i++){
        char buffer[280];
        TweetObj x;

        testTarget.getline(buffer, 100, ',');
        x.setRowNum(buffer);

        testTarget.getline(buffer, 100, ',');
        x.setSentiment(buffer);

        testTarget.getline(buffer, 100, '\n');
        x.setTweetID(buffer);

        target.push_back(x);
    }
    testTarget.close();
    return target;
}

//assigns the sentiments from the training target file to its respect tweet
//in the train data tweets file
DSVector<TweetObj> Functions::setTrainSentiment(DSVector<TweetObj> trainData, DSVector<TweetObj> trainTarget){
    for(int j = 0; j < 200000; j++){
        for(int k = 0; k < 200000; k++){
            if(trainTarget.at(j).getTweetID() == trainData.at(k).getTweetID()){
                trainData.at(k).setSentiment(trainTarget.at(j).getSentiment());
            }
        }
    }

    return trainData;
}

//creates a dsvector that holds two dsvectors of type dsstring - one for positive words, one for negative
//parsed through dsvector of tweets and gets tweet messages
//also gets sentiment associated with tweet message
//puts all words in the positive tweets in the positive words vector
//puts all words in the negative tweets in the negative word vector
//returns dsvector of dsvectors of dsstrings
DSVector<DSVector<DSString>> Functions::wordDatabase(DSVector<TweetObj> tweetObjects){
    DSVector<DSVector<DSString>> database;
    DSVector<DSString> posWords;
    DSVector<DSString> negWords;

    posWords.push_back("Yes");
    negWords.push_back("No");
    posWords.push_back("Absolutely");
    negWords.push_back("Not");

    for(int i = 0; i < 20000; i++){
        char* token = strtok(tweetObjects.at(i).getTweetText().c_str(), "( );?.,\n\"!#$%^&*-_+=/ ");

        if(tweetObjects.at(i).getSentiment() == "0"){
            while(token != nullptr){
                negWords.push_back(token);
                token = strtok(nullptr, "( );?.,\n\"!#$%^&*-_+=/ ");
            }
        }

        else if(tweetObjects.at(i).getSentiment() == "4"){

            while(token != nullptr){
                posWords.push_back(token);
                token = strtok(nullptr, "( );?.,\n\"!#$%^&*-_+=/ ");
            }
        }

    }

    database.push_back(negWords);
    database.push_back(posWords);

    return database;
}

//finds frequency of each word and assigns to object
//returns dsvector of dsvectors of dsstring
DSVector<DSVector<DSString>> Functions::wordFrequency(DSVector<DSVector<DSString>> database){
    DSVector<DSString> negWordsCopy = database.at(0);
    DSVector<DSString> posWordsCopy = database.at(1);

    DSVector<DSString> negWordFreq;
    DSVector<DSString> posWordFreq;
    DSVector<DSVector<DSString>> all;

        DSString temp;

        for(int z = 0; z < negWordsCopy.getLength(); z++){
            DSString* last = new DSString[3];

            *last = negWordsCopy.at(negWordsCopy.getLength());

            if(*last == negWordsCopy.at(z)){
                last->incrementTimesUsedNegative();
            }

            else if(*last != negWordsCopy.at(z)){
                negWordFreq.push_back(*last);
            }
        delete[] last;
        negWordsCopy.pop_back();
        }


        for(int z = 0; z < posWordsCopy.getLength(); z++){
            DSString* last = new DSString[3];

            *last = posWordsCopy.at(posWordsCopy.getLength());

            if(*last == posWordsCopy.at(z)){
                last->incrementTimesUsedPositive();
            }

            else if(*last != posWordsCopy.at(z)){
                posWordFreq.push_back(*last);
            }
        delete[] last;
        posWordsCopy.pop_back();
        }

    all.push_back(negWordFreq);
    all.push_back(posWordFreq);

    return all;
}

//using the database of words - both positive and negative -- assign sentiments to each message
//returns dsvector of tweetobj objects with associated sentiments
DSVector<TweetObj> Functions::assignSentiments(DSVector<TweetObj> fileTweets, DSVector<DSVector<DSString>> classifierVectors){
    DSVector<TweetObj> redefTweet = fileTweets;
    DSVector<DSString> tweetData;
    DSString tweetWords;

    DSVector<DSString> negWords = classifierVectors.at(0);
    DSVector<DSString> posWords = classifierVectors.at(1);

    for(int y = 0; y < 1000; y++){
        tweetWords = redefTweet.at(y).getTweetText();

        for(int i = 0; i < tweetWords.size(); i++){
             char* token = strtok(tweetWords.c_str(), "( );?.,\n\"!#$%^&*-_+=/ ");

             while(token != nullptr){
                 tweetData.push_back(token);
                 token = strtok(nullptr, "( );?.,\n\"!#$%^&*-_+=/ ");
             }
        }

        for(int z = 0; z < tweetData.getLength(); z++){
            for(int k = 0; k < negWords.getLength(); k++){
                if(tweetData.at(z) == negWords.at(k)){
                    tweetData.incrementNumNegWords();
                }
            }
        }

        for(int a = 0; a < tweetData.getLength(); a++){
            for(int n = 0; n < posWords.getLength(); n++){
                if(tweetData.at(a) == posWords.at(n)){
                    tweetData.incrementNumPosWords();
                }
            }
        }

        if(tweetData.getNumPosWords() > tweetData.getNumNegWords()){
            redefTweet.at(y).setSentiment("4");
        }

        else if(tweetData.getNumNegWords() > tweetData.getNumPosWords()){
            redefTweet.at(y).setSentiment("0");

        }


    }
    return redefTweet;
}


//returns float that is accuracy
//compares assigned sentiment according to algorithm to the target file and finds numerical accuracy
//formats file
void Functions::calcAccuracy(DSString filename, DSVector<TweetObj> testingData, DSVector<TweetObj> targetFile){
    ofstream outputFile;
    outputFile.open(filename.c_str());

    float correct = 0;
    float incorrect = 0;

    float totalAccuracy;

    float numTweets = testingData.getLength();

    for(int i = 0; i < 20000; i++){
        for(int j = 0; j < 20000; j++){
            if(testingData.at(i).getTweetID() == targetFile.at(j).getTweetID()){
                if(testingData.at(i).getSentiment() == targetFile.at(j).getSentiment()){
                    correct+=1;
                    testingData.at(i).setAccuracy("c");
                }
                else{
                    incorrect+=1;
                    testingData.at(i).setAccuracy("i");
                }
            }
        }
    }
    totalAccuracy = correct/numTweets;
    cout << totalAccuracy << endl;

    outputFile << totalAccuracy << endl;

    DSVector<TweetObj> correctID;
    DSVector<TweetObj> incorrectID;

    for(int i = 0; i < testingData.getLength(); i++){
        if (testingData.at(i).getAccuracy() == "c"){
            correctID.push_back(testingData.at(i));
        }
        else{
            incorrectID.push_back(testingData.at(i));
        }
    }

    for(int j = 0; j < correctID.getLength(); j++){
        outputFile << correctID.at(j).getTweetID() << "," << correctID.at(j).getAccuracy() << endl;
    }

    for(int k = 0; k < incorrectID.getLength(); k++){
        outputFile << incorrectID.at(k).getTweetID() << "," << incorrectID.at(k).getAccuracy() << endl;
    }

    outputFile.close();
}

void Functions::runProgram(char* argv[]){
    //DSStrings to hold argv
    DSString trainData;
    DSString trainTarget;
    DSString testData;
    DSString testTarget;
    DSString output;

    trainData = argv[1];
    trainTarget = argv[2];
    testData = argv[3];
    testTarget = argv[4];
    output = argv[5];

    //holds training tweets
    DSVector<TweetObj> trainingData;
    //holds training targets
    DSVector<TweetObj> trainingDataTargets;
    //holds testing tweets
    DSVector<TweetObj> testingData;
    //holds testing targets
    DSVector<TweetObj> testingDataTargets;
    //holds tweets with determined sentiments
    DSVector<TweetObj> finalTweets;

    //holds training tweets with sentiments assigned from target file
    DSVector<TweetObj> setTrainSent;

    //database of words
    DSVector<DSVector<DSString>> completeDatabase;
    //word frequency from train file
    DSVector<DSVector<DSString>> wordFreq;
    //word frequency from test file
    DSVector<DSVector<DSString>> wordFreq2;


    trainingData = trainTweetAssigner(trainData);
    trainingDataTargets = trainTargetFile(trainTarget);
    setTrainSent = setTrainSentiment(trainingData, trainingDataTargets);

    completeDatabase = wordDatabase(setTrainSent);
    wordFreq = wordFrequency(completeDatabase);

    testingData = testTweetAssigner(testData);
    testingDataTargets = testTargetFile(testTarget);
    wordFreq2 = wordFrequency(completeDatabase);
    finalTweets = assignSentiments(testingData, wordFreq2);

    calcAccuracy(output, finalTweets, testingDataTargets);
}
