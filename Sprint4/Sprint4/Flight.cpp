#include "Flight.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

//flight cpp
using namespace std;
Flight::Flight(){
    origin = " ";
    destination = " ";
    airline = " ";

    cost = 0;
    time = 0;
}

Flight::Flight(DSString o, DSString d, int c, int t, DSString a){
    origin = o;
    destination = d;
    airline = a;
    cost = c;
    time = t;
}

Flight::Flight(const Flight& f){
    origin = f.origin;
    destination = f.destination;
    airline = f.airline;

    cost = f.cost;
    time = f.time;
}

Flight::~Flight(){}


void Flight::setOrigin(DSString x){
    origin = x;
}

DSString Flight::getOrigin(){
    return origin;
}

void Flight::setDestination(DSString x){
    destination = x;
}

DSString Flight::getDestination(){
    return destination;
}

void Flight::setAirline(DSString x){
    airline = x;
}

DSString Flight::getAirline(){
    return airline;
}

void Flight::setCost(int x){
    cost = x;
}

int Flight::getCost(){
    return cost;
}

void Flight::setTime(int x){
    time = x;
}

int Flight::getTime(){
    return time;
}

bool Flight::operator==(const Flight& x){
    if(destination == x.destination && airline == x.airline){
        return true;
    }
    else{
        return false;
    }
}
