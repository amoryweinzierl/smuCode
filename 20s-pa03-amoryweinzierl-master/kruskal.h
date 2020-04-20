//
// Created by amory on 4/7/2020.
//

#ifndef P03_KRUSKAL_H
#define P03_KRUSKAL_H

#include <iostream>
#include <fstream>
#include <algorithm>
#include "DS.h"
#include "edge.h"

using namespace std;
template <typename T>
class kruskal{
private:
    DS<T>* graph = new HTDS<T>; //total paths stored in maps
    vector<edge<T>> edges; //all edges in graph
    vector<T> nodes; //all nodes in graph
public:
    void readFile(string); //reads in file
    vector<edge<T>> createMapGraph(); //creates kruskal MST
    bool checkForNode(T); //checks if node is in node vector B)
    void output(vector<edge<T>>, string); //returns edges and sum of their weights to output file
};

template <typename T>
void kruskal<T>::readFile(string fileName) {
    ifstream ifile;

    ifile.open(fileName);

    if (ifile.fail()) {
        cout << "file not open" << endl;
    }
    else {
        char buffer[50];
        ifile.getline(buffer, 50, '\n'); //takes in num at the top of the file
        string numPaths = buffer;

        string::size_type sz;
        int loopNum = stoi(numPaths, &sz); //converts string to integer

        for (int a = 0; a < loopNum; a++) {
             buffer[50];

            edge<T> newPath;

            string::size_type sz;

            ifile.getline(buffer, 50, ',');
            int root = stoi(buffer, &sz);
            newPath.setRoot(root);

            //if nodes vector is empty add node root
            //or if it isn't already in nodes
            if(!checkForNode(newPath.getRoot()) || nodes.size() == 0){
                nodes.push_back(newPath.getRoot());
            }

            ifile.getline(buffer, 50, ',');
            int dest = stoi(buffer, &sz);
            newPath.setDest(dest);

            //if nodes vector is empty add node dest
            //or if it isn't already in nodes
            if(!checkForNode(newPath.getDest()) || nodes.size() == 0){
                nodes.push_back(newPath.getDest());
            }

            ifile.getline(buffer, 50, '\n');
            int weight = stoi(buffer, &sz); //converts string to integer
            newPath.setWeight(weight);

            //after data read in from file pushes to edges vector
            edges.push_back(newPath);
        }

        //sorts graph vector by highest to least weights
        //bubble sort code from geeksforgeeks
        for (int i = 0; i < edges.size() - 1; i++) {
            for (int j = 0; j < edges.size() - i - 1; j++) {
                if (edges.at(j).getWeight() > edges.at(j + 1).getWeight()) {
                    edge<T> *xp = &edges.at(j);
                    edge<T> *yp = &edges.at(j + 1);

                    edge<T> temp = *xp;
                    *xp = *yp;
                    *yp = temp;
                }
            }
        }
    }
}

//checks if element is in nodes vector
template <typename T>
bool kruskal<T>::checkForNode(T element) {
    for(int i = 0; i < nodes.size(); i++){
        if(nodes.at(i) == element){
            return true;
        }
    }
    return false;
}


//use disjoint here
//kruskal part
template <typename T>
vector<edge<T>> kruskal<T>::createMapGraph() {
    vector<edge<T>> MST;

    //makes set from each node in nodes vector
    for(int i = 0; i < nodes.size(); i++){
        graph->makeSet(nodes.at(i));
    }


    while(MST.size() != nodes.size() - 1){
        //creates no edge object from edge that has least weight
        edge<T> edgy = edges.front();
        //erases edge from vector of edges
        edges.erase(edges.begin());

        //graphs are of ints
        //so creates new int variables x and y equal to where root and dest are found in graph map
        int x = graph->Find(edgy.getRoot());
        int y = graph->Find(edgy.getDest());

        //if x and y are not in the same set, add them to the MST and union them
        if(x != y){
            MST.push_back(edgy);
            graph->Union(x, y);
        }
    }

    //return MST vector
    return MST;
}

//outputs MST from kruskals to output file
//format is (origin, destination, weight)
template <typename T>
void kruskal<T>::output(vector<edge<T>> MST, string fileName){
    ofstream ofile;
    ofile.open(fileName);

    if (ofile.fail()) {
        cout << "file not open" << endl;
    }

    else{
        ofile << "Kruskal's Using Unordered Map Results" << endl;
        for(int i = 0; i < MST.size(); i++){
            ofile << "(" << MST.at(i).getRoot();
            ofile << "," << MST.at(i).getDest();
            ofile << "," << MST.at(i).getWeight();
            ofile << ")" << endl;
        }

        //adds up total weight of all the edges
        int totWeight = 0;
        for(int j = 0; j < MST.size(); j++){
            totWeight += MST.at(j).getWeight();
        }

        ofile << "Total Weight of MST: " << totWeight;
    }
}

#endif //P03_KRUSKAL_H
