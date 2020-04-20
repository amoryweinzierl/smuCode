#ifndef ALDATA_H
#define ALDATA_H

#include "LinkedList.h"
#include "Flight.h"

//class for data held in the origin nodes of the adjacency list
//data consists of linked list inner of type DSString which holds the destinations of each origin
//data also consists of a DSString of name origin
class ALData{
    friend class Flight;
    friend class AdjList;
protected:
    LinkedList<DSString> inner;
    DSString origin;
    
public:
    ALData();
    ALData(DSString);
    void setOriginData(DSString);
    DSString getOriginData();
    void print();

    void addInner(DSString);
    bool hasInner(DSString);

    bool operator==(const ALData&);
};
#endif // ALDATA_H
