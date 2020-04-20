//"Owner": James Huang
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <list>
#include <functional>
#include <fstream>

using namespace std;

template <class K, class V>
class HashTable{
private:
    template <class X, class Y>
    class HashNode{
    public:
        X key;
        Y value;
        //key and value have to be created at the same time
        HashNode(){}
        HashNode(X key, Y value){
            this->key = key;
            this->value = value;
        }
    };
    //max capacity of hashtable
    int capacity;
    //current size of hashtable
    int size;
    //array of list of hashnodes
    list<HashNode<K,V>*> *hashLists;
public:
    HashTable();
    HashTable(int);
    HashTable(const HashTable<K,V>&);
    HashTable& operator=(const HashTable<K,V>&);
    ~HashTable();
    //hash the key
    int hashFunc(K);
    //insert a node
    void insert(K,V);
    //get value given a key
    V& get(K);
    //remove a certain key based on node
    void remove(K);
    //check if the map contains a certain key
    bool contains(K);
    
    int getSize();
    int getCapacity();
    //display the map
    void display();
    //remove all items from map
    void clear();
    //save all the nodes to file
    void saveToFile();
};

template <class K, class V>
HashTable<K,V>::HashTable(){
    //default capacity is 100
    capacity = 100;
    size = 0;
    //allocate memory for the array
    hashLists = new list<HashNode<K,V>*>[capacity];
}

template <class K, class V>
HashTable<K,V>::HashTable(int capacity){
    //takes capacity as input
    this->capacity = capacity;
    size = 0;
    //allocate memory for the array
    hashLists = new list<HashNode<K,V>*>[capacity];
}

template <class K, class V>
HashTable<K,V>::HashTable(const HashTable &h){
    capacity = h.capacity;
    size = h.size;
    hashLists = new list<HashNode<K,V>*>[capacity];
    //deep copy
    for(int i = 0; i < h.capacity; i++){
        //if the current list is empty, ignore it
        if(h.hashLists[i].empty()){
            continue;
        }
        //for each node in h's current list
        for(auto *node : h.hashLists[i]){
            //allocate memory and initialize the new node to the value of the same node in h
            HashNode<K,V> *newNode = new HashNode<K,V>(node->key,node->value);
            //insert the node to the current list
            hashLists[i].push_back(newNode);
        }
    }
}

template <class K, class V>
HashTable<K,V>& HashTable<K,V>::operator=(const HashTable &h){
    capacity = h.capacity;
    size = h.size;
    hashLists = new list<HashNode<K,V>*>[capacity];
    //deep copy
    for(int i = 0; i < h.capacity; i++){
        //if the current list is empty, ignore it
        if(h.hashLists[i].empty()){
            continue;
        }
        //for each node in h's current list
        for(auto *node : h.hashLists[i]){
            //allocate memory and initialize the new node to the value of the same node in h
            HashNode<K,V> *newNode = new HashNode<K,V>(node->key,node->value);
            //insert the node to the current list
            hashLists[i].push_back(newNode);
        }
    }
    return *this;
}

template <class K, class V>
HashTable<K,V>::~HashTable<K,V>(){
    clear();
}

//function to generate an hashed index for a key
template <class K, class V>
int HashTable<K,V>::hashFunc(K key){
    //instantiation of a stl hash object
    hash<K> myHash;
    //hash the key
    int hashVal = myHash(key);
    //mod the capacity so that the value fits in the array
    //use abs to return a positive value
    return abs(hashVal % capacity);
}

//insert a node
template <class K, class V>
void HashTable<K,V>::insert(K key, V value){
    //get the index that the node's going into
    int index = hashFunc(key);
    //initialize the node
    HashNode<K,V> *node = new HashNode<K,V>(key,value);
    //check if the key already exists in that list
    for(auto *node : hashLists[index]){
        //if it does, throw an exception
        if(node->key == key){
            throw std::runtime_error("Keys cannot be duplicated!");
        }
    }
    hashLists[index].push_back(node);
    size++;
}

//return a value given the key
template <class K, class V>
V& HashTable<K,V>::get(K k){
    int index = hashFunc(k);
    //go through the list at this index
    for(auto *node : hashLists[index]){
        if(k == node->key){
            return node->value;
        }
    }
    //if by this point, nothing has been returned
    throw std::runtime_error("Requested Key to get does not exist!");
}

template <class K, class V>
void HashTable<K,V>::remove(K key){
    //get the index that the node's going to in
    int index = hashFunc(key);
    //go through the list at this index
    for(auto *node : hashLists[index]){
        //if the key of the current node equals to the key inserted
        //return that node's value
        if(node->key == key){
            //STL list remove() deletes all occurances of that value. However, since node is unique, there is only one occurance
            hashLists[index].remove(node);
            size--;
            //break after removal because keys are unique
            return;
        }
    }
    //if by this point, nothing has been returned
    throw std::runtime_error("Requested Key to remove does not exist!");
}

template <class K, class V>
bool HashTable<K,V>::contains(K key){
    //get the index that the node's going to in
    int index = hashFunc(key);
    //go through the list at this index
    for(auto *node : hashLists[index]){
        //if the key of the current node equals to the key inserted
        //return true
        if(node->key == key){
            return true;
        }
    }
    //if by this point, nothing has been returned
    return false;
}

template <class K, class V>
int HashTable<K,V>::getSize(){
    return size;
}

template <class K, class V>
int HashTable<K,V>::getCapacity(){
    return capacity;
}

template <class K, class V>
void HashTable<K,V>::display(){
    for(int i = 0; i < capacity;i++){
        if(hashLists[i].empty()){
            continue;
        }
        for(auto *node : hashLists[i]){
            cout << node->key << " " << node->value << endl;
        }
    }
}

template <class K, class V>
void HashTable<K,V>::clear(){
    for(int i = 0; i < capacity; i++){
        if(hashLists[i].empty()){
            continue;
        }
        //delete individual nodes
        for(auto it = hashLists[i].begin(); it != hashLists[i].end();){
            it = hashLists[i].erase(it);
        }
    }
    //delete the array
    delete[] hashLists;
}

template <class K, class V>
void HashTable<K,V>::saveToFile(){
    ofstream output;
    output.open("../SearchEngine/persistentIndex.txt");
    if(output.is_open()){
        for(int i = 0; i < capacity; i++){
            if(hashLists[i].empty()){
                continue;
            }
            for(auto *node : hashLists[i]){
                output << node->value << endl;
            }
        }
    }
    else{
        throw std::runtime_error("Output file could not be opened!");
    }
    output.close();
}
#endif // HASHTABLE_H
