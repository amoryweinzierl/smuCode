#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

//linked list class
template<typename S>
class LinkedList{
    friend class AdjList;
    friend class ALData;
    friend class Flight;

private:
    Node<S>* head;
    Node<S>* tail;
    Node<S>* iter;

    unsigned int size;
public:
    LinkedList();
    LinkedList(const LinkedList<S>&);
    ~LinkedList();

    LinkedList<S>& operator= (const LinkedList<S>&);

    unsigned int getSize();

    void insertFront(S);
    void insertEnd(S);

    void deleteFront();
    void deleteBack();

    S& returnBack();
    S& returnFront();
    S& returnData(int x);

    void iterate();
    S& returnCurrItr();
    void resetIter();

    int contains(S);
    bool isEmpty();

    void print();
};

template <class S>
LinkedList<S>::LinkedList(){
    head = nullptr;
    tail = nullptr;

    iter = nullptr;

    size = 0;
}

template <class S>
LinkedList<S>::LinkedList(const LinkedList<S>& x){
    if(x.head == nullptr){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    else{
        head = nullptr;
        tail = nullptr;
        iter = x.head;
        size = 0;
        while(iter != nullptr){
            insertEnd(iter->data);
            iter = iter->next;
        }
    }
}

template <class S>
LinkedList<S>::~LinkedList(){
    iter = head;
    while(iter != nullptr){
        iter = iter->next;
        delete head;
        head = iter;
    }

    size = 0;
}

template <class S>
LinkedList<S>& LinkedList<S>::operator= (const LinkedList<S>& x){
    if(x.head == nullptr){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    else{
        iter = x.head;
        size = 0;

        while(iter != nullptr){
            insertEnd(iter->data);
            iter = iter->next;
        }
    }
}

template <class S>
unsigned int LinkedList<S>::getSize(){
    return size;
}

//returns index of object if the list contains it
//otherwise returns -1
template<class S>
int LinkedList<S>::contains(S x){
    if(head != nullptr){
        iter = head;
       // while(iter != nullptr){
        for(int i = 0; i < size; i++){
            if(iter->data == x){
                return i;
            }
            else{
                iter = iter->next;
            }
        }
        return -1;
    }

    return -1;
}

template<class S>
bool LinkedList<S>::isEmpty(){
    if(size == 0){
        return true;
    }
    else{
        return false;
    }
}

template <class S>
void LinkedList<S>::insertFront(S x){
    Node<S>* temp2 = head;
    Node<S>* temp = new Node<S>(x);

    if(head == nullptr){
        head = temp;
        tail = temp;
    }

    else{
        head->previous = temp;
        temp->previous = nullptr;
        temp->next = head;
        head = temp;
    }
    iter = head;
    size += 1;
}

template <class S>
void LinkedList<S>::insertEnd(S x){
    Node<S>* temp = new Node<S>(x);

    if(head == nullptr){
        head = temp;
        tail = temp;
        temp->next = nullptr;
        temp->previous = nullptr;
    }
    else{
        temp->previous = tail;
        temp->next = nullptr;

        tail->next = temp;
        tail = temp;
    }
    size += 1;
}

template <class S>
void LinkedList<S>::deleteFront(){
    if(!isEmpty()){
        iter = head;
        head = head->next;
        head->previous = nullptr;

        delete iter;

        size -= 1;
    }
    else{
        std::cout<< "list is empty" << std::endl;
    }
}

template <class S>
void LinkedList<S>::deleteBack(){
    if(!isEmpty()){
        iter = tail;
        tail = tail->previous;

        delete iter;

        if(tail != nullptr)
            tail->next = nullptr;
        else{
            head = nullptr;
        }

        size -= 1;
    }
    else{
        std::cout << "list is empty" << std::endl;
    }
}

template<class S>
S& LinkedList<S>::returnFront(){
    return head->data;
}

template<class S>
S& LinkedList<S>::returnBack(){
    return tail->data;
}

//returns object at index
template<class S>
S& LinkedList<S>::returnData(int x){
    iter = head;
    if(x == 0){
        return iter->data;
    }
    else{
        int iterator = 0;
        while(iterator !=  x){
            iter = iter->next;
            iterator++;
        }

        return iter->data;
    }
}

template<class S>
void LinkedList<S>::iterate(){
    iter = iter->next;
}

template <class S>
S& LinkedList<S>::returnCurrItr(){
    return iter->data;
}

template <class S>
void LinkedList<S>::resetIter(){
    iter = head;
}

template<class S>
void LinkedList<S>::print(){
    if(head != nullptr){
        iter = head;
        while(iter != nullptr){
            std::cout << iter->data<<"->";
            iter = iter->next;
        }
        std::cout<<std::endl;
    }
    else{
        std::cout << "nothing to print" << std::endl;
    }
}
#endif // LINKEDLIST_H
