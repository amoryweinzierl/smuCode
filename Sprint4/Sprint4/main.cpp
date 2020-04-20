#define CATCH_CONFIG_RUNNER
#include "catch.h"
#include "functions.h"

#include <iostream>

using namespace std;

int runCatchTest()
{
     return Catch::Session().run();
}

int main(int argc, char* const argv[]){
    if(argc == 1){
        return runCatchTest();

    }
    else{
        //gets files from argv
        DSString flightDetails;
        DSString flightPathCalc;
        DSString output;
        flightDetails = argv[1];
        flightPathCalc = argv[2];
        output = argv[3];

        //object of type functions
        functions f;

        //dsvectors
        DSVector<Flight> flight;
        DSVector<pathObject> pathObj;

        //performs methods based on file
        f.retrieveDestinations(flightDetails);
        flight = f.createFlightObjects(flightDetails);
        pathObj = f.retrievePaths(flightPathCalc);

        //creates paths using above
        f.createPaths(flight, pathObj, output);
    }
    return 0;
}
