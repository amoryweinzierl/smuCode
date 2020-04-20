#ifndef TWEETOBJ_H
#define TWEETOBJ_H

#include "DSVector.h"
#include "../../lib/DSString.h"

class TweetObj{
private:
    //private variables for each line of tweet files plus a couple extra
    //rownum, tweet id, username. text of tweet, associated sentinment, and then if sentiment accurate
    DSString rowNum;
    DSString tweetID;
    DSString user;
    DSString tweetText;
    DSString sentiment;

    DSString accuracy;

public:
    TweetObj();//constructor

    void setRowNum(DSString);//sets row number
    DSString getRowNum();//gets row number
    void setTweetID(DSString);//sets tweet id
    DSString getTweetID();//gets tweet id
    void setUser(DSString);//set username
    DSString getUser();//get username
    void setTweetText(DSString);//sets tweet text
    DSString getTweetText();//gets tweet text
    void setSentiment(DSString x);//sets sentiment = 0 or 4
    DSString getSentiment();//gets sentiment = 0 or 4
    void setAccuracy(DSString);//sets accuracy = c or i
    DSString getAccuracy();//gets accuracy = c or i
};

#endif // TWEETOBJ

