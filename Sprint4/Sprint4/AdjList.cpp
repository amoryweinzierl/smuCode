#include "AdjList.h"
#include "ALData.h"
#include <iostream>

//adjacency list cpp
using namespace std;
AdjList::AdjList(){}

AdjList::AdjList(LinkedList<ALData>& x){
    adjList1 = x;
}

AdjList::~AdjList(){}

void AdjList::pushback(ALData x){
    if(adjList1.contains(x) == -1){
        adjList1.insertEnd(x);
    }
}

void AdjList::pushback(ALData x, DSString y){
    if(adjList1.contains(x) != -1){
        int index = adjList1.contains(x);
        adjList1.returnData(index).addInner(y);
    }
    else{
        adjList1.insertEnd(x);
        x.addInner(y);

    }
}

int AdjList::contains(ALData& x){
    return adjList1.contains(x);
}

int AdjList::getLength(){
    return adjList1.getSize();
}

LinkedList<ALData> AdjList::returnOrigins(){
    return adjList1;
}

void AdjList::print(){
    for(int i = 0; i < adjList1.getSize(); i++){
        std::cout << adjList1.returnData(i).getOriginData() << " -> ";
        adjList1.returnData(i).inner.print();
    }

}

