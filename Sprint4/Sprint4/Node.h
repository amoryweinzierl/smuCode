#ifndef NODE_H
#define NODE_H

#include <iostream>

//node class
template <typename T>
class Node{

    template <typename S> friend class LinkedList;

private:
    Node<T>* next;
    Node<T>* previous;
    T data;

public:
    Node():next(nullptr),previous(nullptr){}
    Node(T val):next(nullptr),previous(nullptr),data(val){}
    Node(const Node<T>& d2):next(nullptr),previous(nullptr),data(d2.data){}

};

#endif // NODE_H
