#ifndef PLAYER
#define PLAYER

#include <iostream>
#include "DSString.h"

class Player{
    //private member attributes: name, ID, number of tags player has done, total amount of points,
    //team that player belongs to, other player they've tagged, array of all players player has tagged
    private:
        int playerID;
        DSString playerName;
        int numTags;
        int totalPoints;
        DSString teamName;
        int taggedID;
        int* otherTeamTagged = new int[30];

    //public member functions
    public:
        //constructor
        Player();

        //getter and setter for player's id
        int getPlayerID();
        void setPlayerID(int x);

        //getter and setter for player name
        DSString getPlayerName();
        void setPlayerName(DSString x);

        //getter and setter for amount of tags
        int getNumTags();
        void setNumTags(int x);

        //getter and setter for the team the player belongs to
        DSString getTeamName();
        void setTeamName(DSString x);

        //getter and setter for the total amont of points scored by player
        int getTotalPoints();
        void setTotalPoints(int x);

        //getter and setter for other player's id that player has tagged
        int getTaggedID();
        void setTaggedID(int x);
};

#endif // PLAYER
