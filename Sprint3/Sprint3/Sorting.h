#include <iostream>
#include <vector>

#ifndef SORTINGFUN_SORTER_H
#define SORTINGFUN_SORTER_H

template <typename T>
class Sorter {
protected:
    std::vector<T> data;

public:
    Sorter() {}
    Sorter(T& x):data(x) {}
    void setData(const std::vector<T>& x) {
        data = x;
    }
    virtual void sort() = 0;

};


template <typename T>
//quicksort
//code found at thepolyglotdeveloper.com
class MysterySorterA : public Sorter<T> {
public:
    virtual void sort() {
        quickSort(this->data, 0, this->data.size());
    }

    int partition(std::vector<T>& x, int low, int high){
        int pivotIndex = low + (high - low)/2;
        T pivotValue = x[pivotIndex];
        int i = low, j = high;
        T temp;

        while(i <= j){
            while(x[i] < pivotValue){
                i++;
            }

            while(x[j] > pivotValue){
                j--;
            }

            if(i <= j){
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
                i++;
                j--;
            }
        }
        return i;
    }

    void quickSort(std::vector<T>& c, int low, int high){
        if(low < high){
            int pivotIndex = partition(c, low, high);

            quickSort(c, low, pivotIndex - 1);
            quickSort(c, pivotIndex, high);
        }
    }
};

template <typename T>
//bubblesort
//code found at geeksforgeeks.com
class MysterySorterB : public Sorter<T> {
public:
    virtual void sort() {
        bubbleSort(this->data, this->data.size());
    }

    void bubbleSort(std::vector<T>& x, int n){
        T temp;

        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < n - i - 1; j++){
                if(x[j] > x[j + 1]){
                    temp = x[j];
                    x[j] = x[j+1];
                    x[j+1] = temp;
                }
            }
        }
    }
};

template <typename T>
//insertionsort
//code found at geeksforgeeks.com
class MysterySorterC : public Sorter<T> {
public:
    virtual void sort() {
        insertionSort(this->data, this->data.size());
    }

    void insertionSort(std::vector<T>& x, int n){
        int key, j;
        for(int i = 1; i < n; i++){
            key = x[i];
            j = i - 1;
            while(j >= 0 && x[j] > key){
                x[j + 1] = x[j];
                j = j - 1;
            }
            x[j + 1] = key;
        }
    }
};

template <typename T>
//selectionsort
//code found at geeksforgeeks.com
class MysterySorterD : public Sorter<T> {
public:
    virtual void sort() {
        selectionSort(this->data, this->data.size());
    }

    void selectionSort(std::vector<T>& x, int n){
        int minIndex;
        T temp;

        for(int i = 0; i < n - 1; i++){
            minIndex = i;
            for(int j = i + 1; j < n; j++){
                if(x[j] < x[minIndex]){
                    minIndex = j;
                }
            }
            temp = x[minIndex];
            x[minIndex] = x[i];
            x[i] = temp;
        }
    }
};

template <typename T>
//mergesort
//code found at cplusplus.com
class MysterySorterE : public Sorter<T> {
public:
    virtual void sort() {
        mergeSort(this->data, 0, this->data.size());
    }

    void merge(std::vector<T>& x, int low, int high, int mid){
        int i, j, k, c[x.size()];
        i = low;
        k = low;
        j = mid + 1;

        while(i <= mid && j <= high){
            if(x[i] < x[j]){
                c[k] = x[i];
                k++;
                i++;
            }
            else{
                c[k] = x[j];
                k++;
                j++;
            }
        }

        while(i <= mid){
            c[k] = x[i];
            k++;
            i++;
        }

        while(j <= high){
            c[k] = x[j];
            k++;
            j++;
        }

        for(i = low; i < k; i++){
            x[i] = c[i];
        }
    }

    void mergeSort(std::vector<T>& x, int low, int high){
        int mid;

        if(low < high){
            mid = (low + high)/2;

            mergeSort(x, low, mid);
            mergeSort(x, mid + 1, high);

            merge(x, low, high, mid);
        }
    }
};

#endif //SORTINGFUN_SORTER_H
