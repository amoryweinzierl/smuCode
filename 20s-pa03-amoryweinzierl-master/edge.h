//
// Created by amory on 4/13/2020.
//

#ifndef P03_PATHPAIRS_H
#define P03_PATHPAIRS_H

#include <iostream>

using namespace std;
template <typename T>
//edge class
//used to keep track of and store edges
//origin, destination, and weight getters and setters
class edge{
private:
    T root;
    T dest;
    int weight;
public:
    //constructor!!
    void setRoot(T);
    T getRoot();

    void setDest(T);
    T getDest();

    void setWeight(int);
    int getWeight();
};

template <typename T>
void edge<T>::setRoot(T element) {
    root = element;
}

template <typename T>
T edge<T>::getRoot() {
    return root;
}

template <typename T>
void edge<T>::setDest(T element) {
    dest = element;
}

template <typename T>
T edge<T>::getDest() {
    return dest;
}

template <typename T>
void edge<T>::setWeight(int element) {
    weight = element;
}

template <typename T>
int edge<T>::getWeight() {
    return weight;
}

#endif //P03_PATHPAIRS_H
