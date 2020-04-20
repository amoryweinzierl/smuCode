#include "Player.h"

//constructor
Player::Player(){
    playerID = 0;
    numTags = 0;
    totalPoints = 0;
}

//getter for player id
int Player::getPlayerID(){
    return playerID;
}

//setter for player id
void Player::setPlayerID(int x){
    playerID = x;
}

//getter for player name
DSString Player::getPlayerName(){
    return playerName;
}

//setter for player name
void Player::setPlayerName(DSString x){
    playerName = x;
}

//getter for number of tags player has done
int Player::getNumTags(){
    return numTags;
}

//setter for number of tags player has done
void Player::setNumTags(int x){
    numTags = x;
}

//getter for team name player is on
DSString Player::getTeamName(){
    return teamName;
}

//setter for team name player is on
void Player::setTeamName(DSString x){
    teamName = x;
}

//getter for total number of points player has
int Player::getTotalPoints(){
    return totalPoints;
}

//setter for total number of points player has
void Player::setTotalPoints(int x){
    totalPoints = x;
}

//getter for other player id that player has tagged
int Player::getTaggedID(){
    return taggedID;
}

//setter for other player id that player has tagged
void Player::setTaggedID(int x){
    taggedID = x;
}
