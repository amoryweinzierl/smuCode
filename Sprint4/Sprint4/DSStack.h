#ifndef DSSTACK_H
#define DSSTACK_H

#include <iostream>
#include "../../lib/DSVector.h"
#include "LinkedList.h"

//stack class
template <typename T>
class DSStack{
private:
    LinkedList<T> LL;

public:
    DSStack();

    bool empty();
    T top();
    void push(T);
    T pop();
    int contains(T);
};
template <typename T>
DSStack<T>::DSStack(){}

template <typename T>
bool DSStack<T>::empty(){
    if(LL.isEmpty()){
        return true;
    }
    else{
        return false;
    }
}

template <typename T>
T DSStack<T>::top(){
    return LL.returnBack();
}

template <typename T>
void DSStack<T>::push(T x){
    LL.insertEnd(x);
}

template <typename T>
T DSStack<T>::pop(){
    T returnState;
    returnState = LL.returnBack();
    LL.deleteBack();
    return returnState;
}

template <typename T>
int DSStack<T>::contains(T x){
    return LL.contains(x);
}

#endif // DSSTACK_H
