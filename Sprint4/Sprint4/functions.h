#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "DSStack.h"
#include "ALData.h"
#include "pathObject.h"
#include "AdjList.h"

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

//reads all the files and creates vectors based on what's contained in the functions
class functions{
private:
    DSStack<DSString> pathStack;
    DSVector<DSVector<DSString>> totalPaths;
public:
    functions();

    DSVector<Flight> createFlightObjects(DSString);
    DSVector<DSString> retrieveDestinations(DSString);
    DSVector<pathObject> retrievePaths(DSString);

    void createPaths(DSVector<Flight>, DSVector<pathObject>, DSString);

    DSVector<DSVector<DSString>> returnPaths();
};

#endif
