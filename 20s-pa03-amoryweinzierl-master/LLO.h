//
// Created by amory on 4/10/2020.
//

#include <list>
#include <iterator>
#include <iostream>

#ifndef P03_LLO_H
#define P03_LLO_H

using namespace std;
template <typename T>
//linked list object class
class LLO{
private:
    list<T> LL;
    typename list<T>::iterator iter;
public:
    list<T> returnLL();  //returns entire list
    void addToLL(T); //adds an element to linked list
    bool findElement(T); //finds the element and returns a boolean of true if exists
    void unionize(LLO<T>); //takes in linked list object an unions it to this linked list
};

template <typename T>
list<T> LLO<T>::returnLL() {
    return LL;
}

template <typename T>
void LLO<T>::addToLL(T element) {
    LL.push_back(element);
}

template <typename T>
bool LLO<T>::findElement(T element) {
    for(iter = LL.begin(); iter != LL.end(); ++iter) {
        if (*iter == element)
            return true;
    }
    return false;
}

template <typename T>
void LLO<T>::unionize(LLO<T> branch) {
    for(iter = branch.returnLL().begin(); iter != branch.returnLL().end(); ++iter) {
        addToLL(*iter);
    }
}

#endif //P03_LLO_H
