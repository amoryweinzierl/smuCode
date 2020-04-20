#include "functions.h"
#include "AdjList.h"
#include "ALData.h"
#include "Flight.h"
#include "DSStack.h"
#include "../../lib/DSVector.h"
#include <fstream>
#include <iostream>
using namespace std;

//iterative backtracking strategy
    //push source(origin) to stack
    //while stack is not empty:
        //check if top is destination
        //if true:
            //store path(in vector) & pop
        //if false:
            //for city on top:
                //is city on stack?
                    //is city null?
                        //if true:
                            //pop top & reset iter
                    //if true:
                        //continue
                    //if false:
                        //push city, continue to step three

functions::functions(){}

//creates flight objects from file
DSVector<Flight> functions::createFlightObjects(DSString fileName){
    DSVector<Flight> flights;

    int num;
    std::ifstream details;

    details.open(fileName.c_str());

    if(!details.is_open()){
        std::cout << "help " << std::endl;
    }

    details >> num;
    for(int i = 0; i < num; i++){
        DSString dest;
        Flight f;
        char buffer[500];

        details.getline(buffer, 100, '|');
        f.setOrigin(buffer);

        details.getline(buffer, 100, '|');
        f.setDestination(buffer);

        details.getline(buffer, 100, '|');
        f.setCost(atoi(buffer));

        details.getline(buffer, 100, '|');
        f.setTime(atoi(buffer));

        details.getline(buffer, 100, '\n');
        f.setAirline(buffer);

        flights.push_back(f);
    }

    details.close();
    return flights;
}

//retrieves destinations from flight file
DSVector<DSString> functions::retrieveDestinations(DSString fileName){
    DSVector<DSString> destinations;

    int num;
    std::ifstream details;
    AdjList aList;
    details.open(fileName.c_str());

    if(!details.is_open()){
    }

    details >> num;

    for(int i = 0; i < num; i++){
        DSString dest;
        DSString originCity;


        char buffer[500];

        details.getline(buffer, 100, '|');
        originCity = buffer;
        details.getline(buffer, 100, '|');
        dest = buffer;
        details.getline(buffer, 100, '|');
        //cost
        details.getline(buffer, 100, '|');
        //time
        details.getline(buffer, 100, '\n');
        //airline

        ALData newdata;

        newdata.setOriginData(originCity);
        aList.pushback(newdata,dest);


    }
    details.close();
    return destinations;
}

//retrieves wanted paths
DSVector<pathObject> functions::retrievePaths(DSString fileName){
    DSVector<pathObject> pathsToCalc;
    int num;

    std::ifstream paths;

    paths.open(fileName.c_str());

    if(!paths.is_open()){
        std::cout << "help " << std::endl;
    }

    paths >> num;

    for(int i = 0; i < num; i++){
        pathObject p;
        char buffer[500];

        paths.getline(buffer, 100, '|');
        p.setOrigin(buffer);

        paths.getline(buffer, 100, '|');
        p.setDestination(buffer);

        paths.getline(buffer, 100, '\n');
        p.setFlightAnalysis(buffer);
    }

    paths.close();
    return pathsToCalc;
}

//creates adjacency list and utilizes backtracking to output
void functions::createPaths(DSVector<Flight> x, DSVector<pathObject> y, DSString filename){
    AdjList aList;
    DSStack<DSString> stack;
    DSVector<DSVector<DSString>> totPaths;
    DSVector<DSString> path;

    ofstream output;
    output.open(filename.c_str());

    //creates adjacency list
    for(int i = 0; i < x.getLength(); i++){
        ALData a;
        ALData b;
        DSString origin = x.at(i).getOrigin();
        DSString destination = x.at(i).getDestination();

        a.addInner(destination);
        a.setOriginData(origin);
        output << origin << "->" << destination << std::endl;

        aList.pushback(a,destination);

        b.addInner(origin);
        b.setOriginData(destination);
        output << destination << "->" << origin << std::endl;
        aList.pushback(b);
    }

    aList.print();
    output.close();

    //iterative backtracking
    for(int j = 0; j < y.getLength(); j++){
        DSString originCity = y.at(j).getOrigin();
        DSString destCity = y.at(j).getDestination();

        int index = aList.returnOrigins().contains(originCity);
        if(index != -1){
            ALData nodeData = aList.returnOrigins().returnData(index);
            stack.push(nodeData.getOriginData());
        }
        
        while(!stack.empty()){
            DSString topCity = stack.top();
            
            if(topCity == destCity){
                while(!stack.empty()){
                    path.push_back(stack.pop());
                }
                totPaths.push_back(path);
            }
            else{
                if(stack.contains(topCity)){
                    stack.pop();
                }
                //rest of backtracking code caused seg fault due to pointers, so deleted
            }
        }
    }

}

//returns all paths
DSVector<DSVector<DSString>> functions::returnPaths(){
    return totalPaths;
}
