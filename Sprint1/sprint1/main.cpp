#include <iostream>
#include <fstream>

#include "DSString.h"
#include "Player.h"

using namespace std;

//returns the number of players given by the given file
int numberPlayers(DSString fileName){
    DSString teamName;
    int numPlayers;

    ifstream teamFile;
    teamFile.open(fileName.c_str());

    teamFile.getline(teamName.c_str(), 30);
    teamFile >> numPlayers;

    teamFile.close();

    return numPlayers;
}

//creates arrays of type Player* for player file passed in
Player* playerObjects(DSString fileName){
    int numPlayers;
    DSString teamName;
    int ID;
    DSString name;

    ifstream teamFile;
    teamFile.open(fileName.c_str());

    Player* Players = new Player[30];

    teamFile.getline(teamName.c_str(), 30);
    teamFile >> numPlayers;

    for(int i = 0; i < numPlayers; i++){
        teamFile >> ID;
        Players[i].setPlayerID(ID);
        teamFile.getline(name.c_str(),30);
        Players[i].setPlayerName(name);
        Players[i].setTeamName(teamName);

        //cout <<"ID: " << Players[i].getPlayerID() << endl;
        //cout <<"Player name: " << Players[i].getPlayerName() << endl;
        //cout <<"Team name: " << Players[i].getTeamName() << endl;
    }
    teamFile.close();

    return Players;
}

//receives the match data from the given match data file
//goes through and increments the scores of the players that scored
void matchData(Player* a, Player* b, int totalNumPlayersA, int totalNumPlayersB, DSString fileName){
    int numTags, taggerID, targetID, timePassed, locHit;

    ifstream matchFile;
    matchFile.open(fileName.c_str());

    matchFile >> numTags;
    //cout << "num tags: " << numTags << endl;

    for(int i = 0; i < numTags; i++){
        matchFile >> taggerID >> targetID >> timePassed >> locHit;

        //cout << "tagger id: " << taggerID << endl;
        //cout << "target id: " << targetID << endl;
        //cout << "time passed: " << timePassed << endl;
        //cout << "location hit: " << locHit << endl;

        for(int j = 0; j < totalNumPlayersA; j++){
            if(a[j].getPlayerID() == taggerID){
                a[j].setNumTags(a[j].getNumTags()+1);
                if(locHit == 1){
                    a[j].setTotalPoints(a[j].getTotalPoints()+5);
                }
                else if(locHit == 2){
                    a[j].setTotalPoints(a[j].getTotalPoints()+8);
                }
                else if(locHit == 3){
                    a[j].setTotalPoints(a[j].getTotalPoints()+7);
                }
                else if(locHit == 4){
                    a[j].setTotalPoints(a[j].getTotalPoints()+4);
                }
            }
            //cout << a[j].getPlayerName() << "-" << a[j].getTotalPoints() << endl;
        }

        for(int z = 0; z < totalNumPlayersB; z++) {
            if(b[z].getPlayerID() == taggerID){
                b[z].setNumTags(b[z].getNumTags()+1);
                    if(locHit == 1){
                        b[z].setTotalPoints(b[z].getTotalPoints()+5);
                    }
                    else if(locHit == 2){
                        b[z].setTotalPoints(b[z].getTotalPoints()+8);
                    }
                    else if(locHit == 3){
                        b[z].setTotalPoints(b[z].getTotalPoints()+7);
                    }
                    else if(locHit == 4){
                        b[z].setTotalPoints(b[z].getTotalPoints()+4);
                    }
                }
           //cout << b[z].getPlayerName() << "-" << b[z].getTotalPoints() << endl;
        }
    }
}

//low verbocity method
void lowVerbOut(Player* a, Player* b, int totalNumPlayersA, int totalNumPlayersB, DSString outFile){
    ofstream outputFile;
    outputFile.open(outFile.c_str());

    int totalAScore = 0;
    int totalBScore = 0;

    DSString firstPrintTeam;
    DSString secondPrintTeam;
    int firstPrintScore;
    int secondPrintScore;

    for(int i = 0; i < totalNumPlayersA; i++){
        totalAScore += a[i].getTotalPoints();
    }

    for(int j = 0; j < totalNumPlayersB; j++){
        totalBScore += b[j].getTotalPoints();
    }

    //puts team names in alphabetical order
    //then associates the number of players of the team that is first alphabetically
    //to a variable of similar context
    if(a[0].getTeamName() < b[0].getTeamName()){
        firstPrintTeam = a[0].getTeamName();
        firstPrintScore = totalAScore;
        secondPrintTeam = b[0].getTeamName();
        secondPrintScore = totalBScore;
    }

    else{
        firstPrintTeam = b[0].getTeamName();
        firstPrintScore = totalBScore;
        secondPrintTeam = a[0].getTeamName();
        secondPrintScore = totalBScore;
    }

    outputFile << firstPrintTeam << ": " << firstPrintScore << " points" << endl;
    outputFile << secondPrintTeam << ": " << secondPrintScore << " points" << endl;
    if (firstPrintScore > secondPrintScore){
        outputFile << "Overall Winners: " << firstPrintTeam << endl;
    }
    else{
        outputFile << "Overall Winners: " << secondPrintTeam << endl;
    }

    outputFile.close();
}

//swap algorithm function
void swap(Player* x, Player* y){
    Player temp = *x;
    *x = *y;
    *y = temp;
}

//bubble sort for tags
Player* BubbleSortTag(Player* x, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(x[j].getNumTags() > x[j+1].getNumTags()){
                swap(&x[j], &x[j+1]);
                }
        }
    }
    return x;
}

//bubble sort for overall scores
Player* BubbleSortScore(Player* x, int n){
    for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < n - i - 1; j++){
                if(x[j].getTotalPoints() > x[j+1].getTotalPoints()){
                    swap(&x[j], &x[j+1]);
                }

            }
    }
    return x;
}

//bubble sort in alphabetical order
Player* BubbleSortAlphabet(Player* x, int n){
    for(int a = 0; a < n; a++){
        if(x[a].getNumTags() == x[a+1].getNumTags()){
                    for(int j = 0; j < n - a - 1; j++){
                        if(x[j].getPlayerName() < x[j+1].getPlayerName()){
                            swap(&x[j+1], &x[j]);
                        }
                    }
            }
        }
    return x;
}

//medium verbocity method
void medVerbOut(Player* a, Player* b, int totalNumPlayersA, int totalNumPlayersB, DSString outFile){
    ofstream outputFile;
    outputFile.open(outFile.c_str());

    //arrays that are set to arrays that are passed in
    Player* arrayA;
    Player* arrayB;

    //sorted tag arrays
    Player* sortedTagDataA;
    Player* sortedTagDataB;

    //sorted score arrays
    Player* sortedScoreDataA;
    Player* sortedScoreDataB;

    int numberA;
    int numberB;

    //puts team names in alphabetical order
    if(a[0].getTeamName() < b[0].getTeamName()){
        arrayA = a;
        numberA = totalNumPlayersA;
        arrayB = b;
        numberB = totalNumPlayersB;
    }
    else{
        arrayA = b;
        numberA = totalNumPlayersB;
        arrayB = a;
        numberB = totalNumPlayersA;
    }

    //bubble sort is called and acts on arrays
    sortedTagDataA = BubbleSortTag(arrayA,numberA);
    sortedTagDataB = BubbleSortTag(arrayB, numberB);

    sortedScoreDataA = BubbleSortScore(arrayA, numberA);
    sortedScoreDataB = BubbleSortScore(arrayB, numberB);

    //information printed out to file
    outputFile << sortedTagDataA[0].getTeamName() << endl;
    for(int i = 1; i <= numberA; i++){
        outputFile << sortedTagDataA[numberA - i].getPlayerName() << " had a total of " << sortedTagDataA[numberA - i].getNumTags() << " tags" << endl;
    }
    outputFile << sortedTagDataB[0].getTeamName() << endl;
    for(int j = 1; j <= numberB; j++){
        outputFile << sortedTagDataB[numberB - j].getPlayerName() << " had a total of " << sortedTagDataB[numberB - j].getNumTags() << " tags" << endl;
    }

    outputFile << "Best score from " << sortedScoreDataA[numberA-1].getTeamName() << ": " << sortedScoreDataA[numberA-1].getPlayerName() << "(" << sortedScoreDataA[numberA-1].getTotalPoints() <<" points)" << endl;
    outputFile << "Best score from " << sortedScoreDataB[numberB-1].getTeamName() << ": " << sortedScoreDataB[numberB-1].getPlayerName() << "(" << sortedScoreDataB[numberB - 1].getTotalPoints() << " points)" << endl;

//    if(arrayA!= nullptr){
//        delete arrayA;
//    }

//    if(arrayB!= nullptr){
//       delete arrayB;
//    }

//    if(sortedTagDataA!=nullptr){
//        delete sortedTagDataA;
//    }

//    if(sortedTagDataB!= nullptr){
//        delete sortedTagDataB;
//    }

//    if(sortedByAlphaA!= nullptr){
//        delete sortedByAlphaA;
//    }

//    if(sortedByAlphaB!=nullptr){
//        delete sortedByAlphaB;
//    }

    outputFile.close();
}

//high verbocity method
void highVerbOut(Player* a, Player* b, int totalNumPlayersA, int totalNumPlayersB, DSString matchFile, DSString outFile){
    ofstream outputFile;
    ifstream inputFile;

    inputFile.open(matchFile.c_str());
    outputFile.open(outFile.c_str());

    Player* arrayA;
    Player* arrayB;

    int numberA;
    int numberB;

    int numRounds;

    Player* allPlayers = new Player[60];
    int allPlayersSize = 60;

    for(int i = 0; i < totalNumPlayersA; i++){
        allPlayers[i] = a[i];
    }

    for(int j = totalNumPlayersA; j < totalNumPlayersB; j++){
        allPlayers[j] = b[j];
    }

    if(a[0].getTeamName() < b[0].getTeamName()){
        arrayA = a;
        numberA = totalNumPlayersA;
        arrayB = b;
        numberB = totalNumPlayersB;
    }
    else{
        arrayA = b;
        numberA = totalNumPlayersB;
        arrayB = a;
        numberB = totalNumPlayersA;
    }

    inputFile >> numRounds;

    inputFile.close();
    outputFile.close();
}

int main(int argc, char* argv[]){
    //variables for command line arguments
    DSString fileA;
    DSString fileB;
    DSString matchFile;
    DSString outputFile;
    DSString verbLevel;

    //variables set to command line arguments
    fileA = argv[1];
    fileB = argv[2];
    matchFile = argv[3];
    outputFile = argv[4];
    verbLevel = argv[5];

    //player arrays created for both player files
    Player* teamAData = playerObjects(fileA);
    Player* teamBData = playerObjects(fileB);

    //cout << "total num players: " << totalNumPlayers << endl;

    //match data function called
    matchData(teamAData, teamBData, numberPlayers(fileA), numberPlayers(fileB), matchFile);

    //determines verbocity as called by command line
    if (verbLevel == "vlow"){
        lowVerbOut(teamAData, teamBData, numberPlayers(fileA), numberPlayers(fileB), outputFile);
    }
    else if (verbLevel == "vmed"){
        medVerbOut(teamAData, teamBData, numberPlayers(fileA), numberPlayers(fileB), outputFile);
    }
    else if (verbLevel == "vhigh"){
        highVerbOut(teamAData, teamBData, numberPlayers(fileA), numberPlayers(fileB), matchFile, outputFile);
    }

    //if(teamAData!= nullptr){
    //    delete teamAData;
    //}

    //if(teamBData!=nullptr){
    //    delete teamBData;
    //}
}
