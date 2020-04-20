#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "../../lib/DSString.h"
#include "TweetObj.h"
#include "DSVector.h"


class Functions{
public:
    Functions();
    DSVector<TweetObj> trainTweetAssigner(DSString);
    DSVector<TweetObj> testTweetAssigner(DSString);
    DSVector<TweetObj> trainTargetFile(DSString);
    DSVector<TweetObj> testTargetFile(DSString);
    DSVector<TweetObj> setTrainSentiment(DSVector<TweetObj>, DSVector<TweetObj>);
    DSVector<DSVector<DSString>> wordDatabase(DSVector<TweetObj>);
    DSVector<DSVector<DSString>> wordFrequency(DSVector<DSVector<DSString>>);
    DSVector<TweetObj> assignSentiments(DSVector<TweetObj>, DSVector<DSVector<DSString>>);
    void calcAccuracy(DSString filename, DSVector<TweetObj>, DSVector<TweetObj>);
    void runProgram(char* []);
};

#endif // FUNCTIONS_H
