#include "ALData.h"
//ALData cpp

ALData::ALData(){
    origin="";
}
ALData::ALData(DSString originT){
    origin=originT;
}

void ALData::setOriginData(DSString x){
    origin = x;
}

DSString ALData::getOriginData(){
    return origin;
}

void ALData::addInner(DSString x){
    inner.insertEnd(x);
}
void ALData::print(){
    for (int x = 0;x<inner.getSize();x++) {
        std::cout<<inner.returnData(x);
    }
}
bool ALData::hasInner(DSString x){
    if(origin == x){
        return true;
    }
    else{
        return false;
    }
}

bool ALData::operator==(const ALData& x){
    if(origin == x.origin){
        return true;
    }
    else{
        return false;
    }
}

