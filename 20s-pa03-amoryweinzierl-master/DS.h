//
// Created by amory on 4/7/2020.
//

#ifndef P03_DSPARENT_H
#define P03_DSPARENT_H

#include <iostream>
#include <unordered_map>
#include <vector>

#include "LLO.h"

using namespace std;
template <typename T>
//class DS parent class
class DS{
public:
    //constructor
    DS(){};
    //pure virtual makeSet
    virtual void makeSet(T) = 0;
    //pure virtual find
    virtual T Find(T) = 0;
    //pure virtual union
    virtual void Union(T, T) = 0;
};

template <typename T>
//linked list disjoint list kid class
class LLDS : public DS<T>{
private:
    //vector of type linked list objects
    //when running on my machine, could not access memory so really unable to test this code
    vector<LLO<T>> dSet;
public:
    LLDS(){};

    //makeSet
    virtual void makeSet(T element){
        LLO<T> obj;
        obj.addToLL(element);
        dSet.push_back(obj);
    }

    //find
    virtual T Find(T element){
        for(int i = 0; i < dSet.size(); i++){
            if(dSet.at(i).findElement(element)){
                return i;
            }
        }
        return false;
    }

    //union
    virtual void Union(T root, T branch){
        T rootLoc = Find(root);
        T branchLoc = Find(branch);

        dSet.at(rootLoc).unionize(dSet.at(branchLoc));
    }
};


template <typename T>
//hash table (unordered map) disjoint set kid class
//https://www.techiedelight.com/disjoint-set-data-structure-union-find-algorithm/ referenced for this data structure
class HTDS : public DS<T>{
private:
    unordered_map<T, T> map;
public:
    //makeSet
    virtual void makeSet(T element){
        map[element] = element;
    }

    //recrusively find root of tree
    virtual T Find(T element){
        if(map[element] == element) {
            return element;
        }
        return Find(map[element]);
    }

    //union
    virtual void Union(T root, T branch) {
        T r00t = Find(root);
        T brunch = Find(branch);

        map[r00t] = brunch;
    }
};

#endif //P03_DSPARENT_H
