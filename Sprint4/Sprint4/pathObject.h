#ifndef PATHOBJECT_H
#define PATHOBJECT_H

#include "../../lib/DSString.h"

//class for path object based on requested paths file
class pathObject{
private:
    DSString origin;
    DSString destination;
    DSString flightAnalysis;

public:
    void setOrigin(DSString);
    DSString getOrigin();

    void setDestination(DSString);
    DSString getDestination();

    void setFlightAnalysis(DSString);
    DSString getFlightAnalysis();
};

#endif // PATHOBJECT_H
