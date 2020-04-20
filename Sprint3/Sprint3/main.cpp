#include <iostream>
#include <chrono>
#include <map>

#include "Sorting.h"

using namespace std;
using namespace std::chrono;

//sorts the runtimes of the five different algorithms from smallest to largest
//maps information found at geeksforgeeks.com
void sortRuntimes2(unsigned long durA, unsigned long durB, unsigned long durC, unsigned long durD, unsigned long durE){
    vector<unsigned long> durations;

    durations.push_back(durA);
    durations.push_back(durB);
    durations.push_back(durC);
    durations.push_back(durD);
    durations.push_back(durE);



    map<unsigned long, string> durationsMap = {
        {durA, "MysterSorterA"},
        {durB, "MysterySorterB"},
        {durC, "MysterySorterC"},
        {durD, "MysterySorterD"},
        {durE, "MysterySorterE"},
    };

    unsigned long temp;

    for(unsigned long i = 0; i < durations.size() - 1; i++){
        for(unsigned long j = 0; j < durations.size() - i - 1; j++){
            if(durations[j] > durations[j + 1]){
                temp = durations[j];
                durations[j] = durations[j+1];
                durations[j+1] = temp;
            }
        }
    }

    for(unsigned long z = 0; z < durations.size(); z++){
        if(durations[z] == durA){
            if(z == 0){
                cout << durationsMap[durA] << " is MergeSort" << endl;
            }

            if(z == 1){
                cout << durationsMap[durA] << " is QuickSort" << endl;
            }

            if(z == 2){
                cout << durationsMap[durA] << " is InsertionSort" << endl;
            }

            if(z == 3){
                cout << durationsMap[durA] << " is SelectionSort" << endl;
            }

            if(z == 4){
                cout << durationsMap[durA] << " is BubbleSort" << endl;
            }
        }

        else if(durations[z] == durB){
            if(z == 0){
                cout << durationsMap[durB] << " is MergeSort" << endl;
            }

            if(z == 1){
                cout << durationsMap[durB] << " is QuickSort" << endl;
            }

            if(z == 2){
                cout << durationsMap[durB] << " is InsertionSort" << endl;
            }

            if(z == 3){
                cout << durationsMap[durB] << " is SelectionSort" << endl;
            }

            if(z == 4){
                cout << durationsMap[durB] << " is BubbleSort" << endl;
            }
        }

        else if(durations[z] == durC){
            if(z == 0){
                cout << durationsMap[durC] << " is MergeSort" << endl;
            }

            if(z == 1){
                cout << durationsMap[durC] << " is QuickSort" << endl;
            }

            if(z == 2){
                cout << durationsMap[durC] << " is InsertionSort" << endl;
            }

            if(z == 3){
                cout << durationsMap[durC] << " is SelectionSort" << endl;
            }

            if(z == 4){
                cout << durationsMap[durC] << " is BubbleSort" << endl;
            }
        }

        else if(durations[z] == durD){
            if(z == 0){
                cout << durationsMap[durD] << " is MergeSort" << endl;
            }

            if(z == 1){
                cout << durationsMap[durD] << " is QuickSort" << endl;
            }

            if(z == 2){
                cout << durationsMap[durD] << " is InsertionSort" << endl;
            }

            if(z == 3){
                cout << durationsMap[durD] << " is SelectionSort" << endl;
            }

            if(z == 4){
                cout << durationsMap[durD] << " is BubbleSort" << endl;
            };
        }

        else if(durations[z] == durE){
            if(z == 0){
                cout << durationsMap[durE] << " is MergeSort" << endl;
            }

            if(z == 1){
                cout << durationsMap[durE] << " is QuickSort" << endl;
            }

            if(z == 2){
                cout << durationsMap[durE] << " is InsertionSort" << endl;
            }

            if(z == 3){
                cout << durationsMap[durE] << " is SelectionSort" << endl;
            }

            if(z == 4){
                cout << durationsMap[durE] << " is BubbleSort" << endl;
            }
        }
    }
}

int main(){
    //vector data set of random numbers
    vector<int> test;
    for(int i = 0; i < 50000; i++){
        test.push_back(rand());
    }

    //sorter objects
    Sorter<int>* a = new MysterySorterA<int>;
    a->setData(test);
    auto startA = high_resolution_clock::now();
    a->sort();
    auto stopA = high_resolution_clock::now();
    auto durationA = duration_cast<microseconds>(stopA - startA);

    Sorter<int>* b = new MysterySorterB<int>;
    b->setData(test);
    auto startB = high_resolution_clock::now();
    b->sort();
    auto stopB = high_resolution_clock::now();
    auto durationB = duration_cast<microseconds>(stopB - startB);

    Sorter<int>* c = new MysterySorterC<int>;
    c->setData(test);
    auto startC = high_resolution_clock::now();
    c->sort();
    auto stopC = high_resolution_clock::now();
    auto durationC = duration_cast<microseconds>(stopC - startC);

    Sorter<int>* d = new MysterySorterD<int>;
    d->setData(test);
    auto startD = high_resolution_clock::now();
    d->sort();
    auto stopD = high_resolution_clock::now();
    auto durationD = duration_cast<microseconds>(stopD - startD);

    Sorter<int>* e = new MysterySorterE<int>;
    e->setData(test);
    auto startE = high_resolution_clock::now();
    e->sort();
    auto stopE = high_resolution_clock::now();
    auto durationE = duration_cast<microseconds>(stopE - startE);

    //prints runtimes
    sortRuntimes2(durationA.count(), durationB.count(), durationC.count(), durationD.count(), durationE.count());

    return 0;
}
