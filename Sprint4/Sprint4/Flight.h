#ifndef FLIGHT_H
#define FLIGHT_H

#include "../../lib/DSString.h"
#include "../../lib/DSVector.h"

//flight object made from flightData.txt
class Flight{
    friend class ALData;
private:
    DSString origin;
    DSString destination;
    DSString airline;

    int cost;
    int time;

public:
    Flight();
    Flight(DSString, DSString, int, int, DSString);
    Flight(const Flight&);
    ~Flight();

    DSVector<Flight> readFlightDetails(DSString);

    void setOrigin(DSString);
    DSString getOrigin();

    void setDestination(DSString);
    DSString getDestination();

    void setAirline(DSString);
    DSString getAirline();

    void setCost(int);
    int getCost();

    void setTime(int);
    int getTime();

    bool operator==(const Flight&);
};

#endif // FLIGHT_H
