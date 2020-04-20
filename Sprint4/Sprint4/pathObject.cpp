#include "pathObject.h"
//path object cpp

void pathObject::setOrigin(DSString x){
    origin = x;
}

DSString pathObject::getOrigin(){
    return origin;
}

void pathObject::setDestination(DSString x){
    destination = x;
}

DSString pathObject::getDestination(){
    return destination;
}

void pathObject::setFlightAnalysis(DSString x){
    flightAnalysis = x;
}

DSString pathObject::getFlightAnalysis(){
    return flightAnalysis;
}
