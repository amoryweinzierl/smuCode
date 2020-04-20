//
// Created by amory on 4/7/2020.
//

#include "kruskal.h"
#include "DS.h"
#include <time.h>
#include <chrono>

using namespace std;
int main(int argc, char* argv[]){
    vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
    DS<int>* listObj = new LLDS<int>;

    for(int i = 0; i < vec.size(); i++){
        listObj->makeSet(vec.at(i));
    }

    //map
    cout << "times demonstrated using maps" << endl;

    //graph_1 anaylsis
    kruskal<int> obj1;
    obj1.readFile("graph_1.txt");

    auto t1 = chrono::high_resolution_clock::now();
    vector<edge<int>> mapGraph1 = obj1.createMapGraph();
    auto t2 = chrono::high_resolution_clock::now();
    auto Time = chrono::duration_cast<chrono::microseconds>(t2-t1).count();
    cout << "time to analyze graph_1.txt: " << Time << "microseconds" << endl;
    obj1.output(mapGraph1, "output_1.txt");

    //graph_2 anaylsis
    kruskal<int> obj2;
    obj2.readFile("graph_2.txt");
    t1 = chrono::high_resolution_clock::now();
    vector<edge<int>> mapGraph2 = obj2.createMapGraph();
    t2 = chrono::high_resolution_clock::now();
    Time = chrono::duration_cast<chrono::microseconds>(t2-t1).count();
    cout << "time to analyze graph_2.txt: " << Time << "microseconds" << endl;
    obj2.output(mapGraph2, "output_2.txt");

    //graph_3 anaylsis
    kruskal<int> obj3;
    obj3.readFile("graph_3.txt");

    t1 = chrono::high_resolution_clock::now();
    vector<edge<int>> mapGraph3 = obj3.createMapGraph();
    t2 = chrono::high_resolution_clock::now();
    Time = chrono::duration_cast<chrono::microseconds>(t2-t1).count();
    cout << "time to analyze graph_3.txt: " << Time << "microseconds" << endl;

    obj3.output(mapGraph3, "output_3.txt");

    //graph_4 anaylsis
    kruskal<int> obj4;
    obj4.readFile("graph_4.txt");

    t1 = chrono::high_resolution_clock::now();
    vector<edge<int>> mapGraph4 = obj4.createMapGraph();
    t2 = chrono::high_resolution_clock::now();
    Time = chrono::duration_cast<chrono::microseconds>(t2-t1).count();
    cout << "time to analyze graph_4.txt: " << Time << "microseconds" << endl;

    obj4.output(mapGraph4, "output_4.txt");

    //graph_5 anaylsis
    kruskal<int> obj5;
    obj5.readFile("graph_5.txt");

    t1 = chrono::high_resolution_clock::now();
    vector<edge<int>> mapGraph5 = obj5.createMapGraph();
    t2 = chrono::high_resolution_clock::now();
    Time = chrono::duration_cast<chrono::microseconds>(t2-t1).count();
    cout << "time to analyze graph_5.txt: " << Time << "microseconds" << endl;

    obj5.output(mapGraph5, "output_5.txt");

    //graph_6 anaylsis
    kruskal<int> obj6;
    obj6.readFile("graph_6.txt");

    t1 = chrono::high_resolution_clock::now();
    vector<edge<int>> mapGraph6 = obj6.createMapGraph();
    t2 = chrono::high_resolution_clock::now();
    Time = chrono::duration_cast<chrono::microseconds>(t2-t1).count();
    cout << "time to analyze graph_6.txt: " << Time << "microseconds" << endl;

    obj6.output(mapGraph6, "output_6.txt");

    //graph_7 anaylsis
    kruskal<int> obj7;
    obj7.readFile("graph_7.txt");

    t1 = chrono::high_resolution_clock::now();
    vector<edge<int>> mapGraph7 = obj7.createMapGraph();
    t2 = chrono::high_resolution_clock::now();
    Time = chrono::duration_cast<chrono::microseconds>(t2-t1).count();
    cout << "time to analyze graph_7.txt: " << Time << "microseconds" << endl;

    obj7.output(mapGraph7, "output_7.txt");

    //graph_8 anaylsis
    kruskal<int> obj8;
    obj8.readFile("graph_8.txt");

    t1 = chrono::high_resolution_clock::now();
    vector<edge<int>> mapGraph8 = obj8.createMapGraph();
    t2 = chrono::high_resolution_clock::now();
    Time = chrono::duration_cast<chrono::microseconds>(t2-t1).count();
    cout << "time to analyze graph_8.txt: " << Time << "microseconds" << endl;

    obj8.output(mapGraph8, "output_8.txt");

    //graph_9 anaylsis
    kruskal<int> obj9;
    obj9.readFile("graph_9.txt");

    t1 = chrono::high_resolution_clock::now();
    vector<edge<int>> mapGraph9 = obj9.createMapGraph();
    t2 = chrono::high_resolution_clock::now();
    Time = chrono::duration_cast<chrono::microseconds>(t2-t1).count();
    cout << "time to analyze graph_9.txt: " << Time << "microseconds" << endl;

    obj9.output(mapGraph9, "output_9.txt");

    //graph_10 anaylsis
    kruskal<int> obj10;
    obj10.readFile("graph_10.txt");

    t1 = chrono::high_resolution_clock::now();
    vector<edge<int>> mapGraph10 = obj10.createMapGraph();
    t2 = chrono::high_resolution_clock::now();
    Time = chrono::duration_cast<chrono::microseconds>(t2-t1).count();
    cout << "time to analyze graph_10.txt: " << Time << "microseconds" << endl;

    obj10.output(mapGraph10, "output_10.txt");

    return 0;
}

