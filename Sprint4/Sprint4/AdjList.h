#ifndef ADJLIST_H
#define ADJLIST_H

#include "LinkedList.h"
#include "../../lib/DSString.h"
#include "Flight.h"
#include "ALData.h"
#include <fstream>

//adjacency list class
class AdjList{
private:
   LinkedList<ALData> adjList1;

public:
    AdjList();
    AdjList(LinkedList<ALData>&);
    ~AdjList();

    void pushback(ALData);
    void pushback(ALData, DSString);

    int contains(ALData&);

    int getLength();

    LinkedList<ALData> returnOrigins();
    AdjList& operator==(const AdjList&);

    void print();
};

#endif // ADJLIST_H
