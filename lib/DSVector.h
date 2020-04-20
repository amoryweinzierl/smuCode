#ifndef DSVECTOR
#define DSVECTOR

#include <iostream>

template<typename T>
class DSVector{

private:
    int length;
    int capacity;
    T* arr;

public:
    DSVector(); //default, non-parameterized constructor
    DSVector(const int); //constructor with capacity parameter
    DSVector(const DSVector<T>&); //copy constructor
    ~DSVector(); //destructor

    DSVector<T>& operator= (const DSVector<T>&);
    T& operator[] (const int);

    T& at (const int); //finds element specified at index

    int size();
    int getCapacity();
    int getLength();
    DSVector<T> resize();
    void push_back(const T&); //adds element to end of vector
    T pop_back(); //removes element from end of vector
    void insert(const T&, int); //insert element at index
    bool empty(); //checks if vector has no items of typename T
};

template <typename T>
DSVector<T>::DSVector(){
    length = 0;
    capacity = 10;

    arr = new T[10];
}

template <typename T>
DSVector<T>::DSVector(const int x){
    length = 0;
    capacity = x;

    arr = new T[x];
}

template <typename T>
DSVector<T>::DSVector(const DSVector<T>& x){
    length = x.length;
    capacity = x.capacity;

    arr = new T[x.capacity];

    for(int i = 0; i < length; i++){
        arr[i] = x.arr[i];
    }
}

template <typename T>
DSVector<T>::~DSVector(){
    delete[] arr;
}

template <typename T>
DSVector<T>& DSVector<T>::operator= (const DSVector<T>& x){
    length = x.length;
    capacity = x.capacity;

    delete[] arr;

    arr = new T[capacity];

    for(int i = 0; i < length; i++){
        arr[i] = x.arr[i];
    }

    return *this;
}

template <typename T>
T& DSVector<T>::operator[](const int x){
    return arr[x];
}

template <typename T>
T& DSVector<T>::at (const int x){
    return arr[x];
}

template <typename T>
int DSVector<T>::size(){
    return length;
}

template <typename T>
int DSVector<T>::getCapacity(){
    return capacity;
}

template <typename T>
int DSVector<T>::getLength(){
    return length;
}

template <typename T>
DSVector<T> DSVector<T>::resize(){
    capacity = capacity*2;
    T* copy = new T[capacity];

    for(int i = 0; i < length; i++){
        copy[i] = arr[i];
    }

    delete[] arr;

    arr = copy;

    return *this;
}

template <typename T>
void DSVector<T>::push_back(const T& x){
    //resize if capacity not large enough
    if(length == capacity){
        resize();
    }
    arr[length] = x;
    length++;
}

template <typename T>
T DSVector<T>::pop_back(){
    //length can't be zero
    //returns last value
    if(length != 0){
        length--;
        return arr[length-1];
    }
}

template <typename T>
bool DSVector<T>::empty(){
    if (length == 0){
        return true;
    }

    else if (length != 0){
        return false;
    }
}

#endif
