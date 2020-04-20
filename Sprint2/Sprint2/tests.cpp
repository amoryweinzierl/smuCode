#include "../../lib/Catch.hpp"
#include "DSVector.h"
#include "../../lib/DSString.h"
#include <iostream>

TEST_CASE("obtaining elements", "at(int x)"){
    DSVector<int> testVector;

    testVector.at(0) = 10;
    REQUIRE (testVector.at(0) == 10);

    testVector.at(1) = 20;
    REQUIRE (testVector.at(1) == 20);

    testVector.at(2) = 30;
    REQUIRE (testVector.at(2) == 30);

    testVector.at(3) = 40;
    REQUIRE (testVector.at(3) == 40);

    testVector.at(4) = 20;
    REQUIRE (testVector.at(4) == 20);

}

TEST_CASE("sizing", "size()"){
    DSVector<int> testVector;
    testVector.push_back(10);

    REQUIRE(testVector.size() == 1);

    testVector.push_back(20);

    REQUIRE(testVector.size() == 2);

    testVector.push_back(30);

    REQUIRE(testVector.size() == 3);

    testVector.pop_back();

    REQUIRE(testVector.size() == 2);

    testVector.pop_back();

    REQUIRE(testVector.size() == 1);
}

TEST_CASE("capacity", "getCapacity()"){
    DSVector<int> integers;
    REQUIRE(integers.getCapacity() == 10);

    integers.resize(10);
    REQUIRE(integers.getCapacity() == 20);

    integers.resize(10);
    REQUIRE(integers.getCapacity() == 30);

    integers.resize(10);
    REQUIRE(integers.getCapacity() == 40);

    integers.resize(10);
    REQUIRE(integers.getCapacity() == 50);
}

TEST_CASE("push back", "push_back(const T&)"){
    DSVector<int> testVector;
    testVector.push_back(10);

    REQUIRE(testVector.at(0) == 10);

    testVector.push_back(20);

    REQUIRE(testVector.at(1) == 20);

    testVector.push_back(30);

    REQUIRE(testVector.at(2) == 30);

    testVector.push_back(40);

    REQUIRE(testVector.at(3) == 40);

    testVector.push_back(50);

    REQUIRE(testVector.at(4) == 50);
}

TEST_CASE("pop back" , "pop_back()"){
    DSVector<int> testVector;
    testVector.push_back(10);
    testVector.push_back(20);
    testVector.push_back(30);
    testVector.push_back(40);
    testVector.push_back(50);
    REQUIRE(testVector.size() == 5);

    testVector.pop_back();
    REQUIRE(testVector.size() == 4);

    testVector.pop_back();
    REQUIRE(testVector.size() == 3);

    testVector.pop_back();
    REQUIRE(testVector.size() == 2);

    testVector.pop_back();
    REQUIRE(testVector.size() == 1);

    testVector.pop_back();
    REQUIRE(testVector.size() == 0);

}

TEST_CASE("resize", "resize(int x)"){
    DSVector<int> integers;
    REQUIRE(integers.getCapacity() == 10);

    integers.resize(10);
    REQUIRE(integers.getCapacity() == 20);

    integers.resize(10);
    REQUIRE(integers.getCapacity() == 30);

    integers.resize(10);
    REQUIRE(integers.getCapacity() == 40);

    integers.resize(10);
    REQUIRE(integers.getCapacity() == 50);
}

TEST_CASE("get length", "getLength()"){
    DSVector<int> testVector;
    testVector.push_back(10);

    REQUIRE(testVector.getLength() == 1);

    testVector.push_back(20);

    REQUIRE(testVector.getLength() == 2);

    testVector.push_back(30);

    REQUIRE(testVector.getLength() == 3);

    testVector.pop_back();

    REQUIRE(testVector.getLength() == 2);

    testVector.pop_back();

    REQUIRE(testVector.getLength() == 1);
}

TEST_CASE("empty", "empty()"){
    DSVector<int> integers;

    integers.push_back(1);
    REQUIRE(integers.empty() == false);

    integers.push_back(2);
    REQUIRE(integers.empty() == false);

    integers.pop_back();
    REQUIRE(integers.empty() == false);

    integers.pop_back();
    REQUIRE(integers.empty() == true);

    integers.push_back(1);
    REQUIRE(integers.empty() == false);
}

TEST_CASE("incrementing number of negative words","incrementNumNegWords()"){
    DSVector<DSString> words;

    words.incrementNumNegWords();
    REQUIRE(words.getNumNegWords() == 1);

    words.incrementNumNegWords();
    REQUIRE(words.getNumNegWords() == 2);

    words.incrementNumNegWords();
    REQUIRE(words.getNumNegWords() == 3);

    words.incrementNumNegWords();
    REQUIRE(words.getNumNegWords() == 4);

    words.incrementNumNegWords();
    REQUIRE(words.getNumNegWords() == 5);

}

TEST_CASE("get number of negative words","getNumNegWords()"){
    DSVector<DSString> words;

    words.incrementNumNegWords();
    REQUIRE(words.getNumNegWords() == 1);

    words.incrementNumNegWords();
    REQUIRE(words.getNumNegWords() == 2);

    words.incrementNumNegWords();
    REQUIRE(words.getNumNegWords() == 3);

    words.incrementNumNegWords();
    REQUIRE(words.getNumNegWords() == 4);

    words.incrementNumNegWords();
    REQUIRE(words.getNumNegWords() == 5);

}

TEST_CASE("incrementing number of positive words","incrementNumPosWords()"){
    DSVector<DSString> words;

    words.incrementNumPosWords();
    REQUIRE(words.getNumPosWords() == 1);

    words.incrementNumPosWords();
    REQUIRE(words.getNumPosWords() == 2);

    words.incrementNumPosWords();
    REQUIRE(words.getNumPosWords() == 3);

    words.incrementNumPosWords();
    REQUIRE(words.getNumPosWords() == 4);

    words.incrementNumPosWords();
    REQUIRE(words.getNumPosWords() == 5);

}

TEST_CASE("get number of positive words","getNumPosWords()"){
    DSVector<DSString> words;

    words.incrementNumPosWords();
    REQUIRE(words.getNumPosWords() == 1);

    words.incrementNumPosWords();
    REQUIRE(words.getNumPosWords() == 2);

    words.incrementNumPosWords();
    REQUIRE(words.getNumPosWords() == 3);

    words.incrementNumPosWords();
    REQUIRE(words.getNumPosWords() == 4);

    words.incrementNumPosWords();
    REQUIRE(words.getNumPosWords() == 5);

}


