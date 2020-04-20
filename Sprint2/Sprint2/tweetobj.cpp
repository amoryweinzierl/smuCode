#include "TweetObj.h"

//definitions
TweetObj::TweetObj(){
    rowNum = "0";
    tweetID = "0";
    user= "\0";
    tweetText = "\0";
    sentiment = "1";
}

void TweetObj::setRowNum(DSString x){
    rowNum = x;
}

DSString TweetObj::getRowNum(){
    return rowNum;
}

void TweetObj::setTweetID(DSString x){
    tweetID = x;
}

DSString TweetObj::getTweetID(){
    return tweetID;
}

void TweetObj::setUser(DSString x){
    user = x;
}

DSString TweetObj::getUser(){
    return user;
}

void TweetObj::setTweetText(DSString x){
    tweetText = x;
}

DSString TweetObj::getTweetText(){
    return tweetText;
}

void TweetObj::setSentiment(DSString x){
    sentiment = x;
}

DSString TweetObj::getSentiment(){
    return sentiment;
}

void TweetObj:: setAccuracy(DSString x){
    accuracy = x;
}
DSString TweetObj:: getAccuracy(){
    return accuracy;
}
