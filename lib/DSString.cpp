#include "DSString.h"

//constructor
DSString::DSString() {
    data = new char[1];
    data[0] = '\0';
    length = 0;

}

DSString::DSString(const char *x){
    length = (strlen(x));
    data = new char[length+1];
    strcpy(data,x);
}

//copy constructor
DSString::DSString(const DSString &copy){
    length = copy.length;
    data = new char[length+1];
    strcpy(data,copy.data);
}

//destructor
DSString::~DSString(){
    if (data != nullptr){
        delete[] data;
    }
}

//operator= definition
DSString& DSString::operator= (const char *a){
    length = strlen(a);
    delete[] data;
    data = new char[length+1];
    strcpy(data,a);
    return *this;
}

//operator= definition
DSString& DSString::operator= (const DSString &b){
    length = b.length;
    delete[] data;
    data = new char[length+1];
    strcpy(data,b.data);
    return *this;
}

//operator+ definition
DSString& DSString::operator+ (const DSString &c){
    length = c.length + length;
    char* pointer = new char[length+1];
    pointer[0] = '\0';
    strcat(pointer,data);
    strcat(pointer,c.data);
    delete[] data;
    data = pointer;
    return *this;
}

//operator+= definition
DSString& DSString::operator+= (const DSString &d){
    length = d.length + length;
    char* pointer = new char[length+1];
    pointer[0] = '\0';
    strcat(pointer,data);
    strcat(pointer,d.data);
    delete[] data;
    data = pointer;
    return *this;

}

//operator == definition
bool DSString::operator== (const char *e){
    if(length != strlen(e)){
        return false;
    }
    if (strcmp(data,e) == 0){
        return true;
    }
    else{
        return false;
    }
}

//operator== definition
bool DSString::operator== (const DSString &f){
    if(length != f.length){
        return false;
    }
    if (strcmp(data,f.data) == 0){
        return true;
    }
    else{
        return false;
    }
}

bool DSString::operator!= (const char *e){
    if(length != strlen(e)){
        return true;
    }
    if (strcmp(data,e) == 0){
        return false;
    }
    else{
        return true;
    }
}

bool DSString::operator!= (const DSString &f){
    if(length != f.length){
        return true;
    }
    if (strcmp(data,f.data) == 0){
        return false;
    }
    else{
        return true;
    }
}

//operator< defintiion
bool DSString::operator< (const char *g){
    if(strcmp(data,g) < 0){
        return true;
    }
    else{
        return false;
    }
}

//operator< defintion
bool DSString::operator< (const DSString &h){
    if(strcmp(data, h.data) < 0){
        return true;
    }
    else{
        return false;
    }
}

//operator[] definition
char& DSString::operator[](const int i){
    //if(i <= (length- 1)){
    return data[i];
    //}
}


//size definition
int DSString::size(){
    return length;
}

//substring definition
DSString DSString::substring(int a, int b){
    DSString substring;

    substring.data = new char[a + 1];

    for(int i = 0; i < a; i++){
        data++;
    }

    if(b > 0){
        for(int j = 0; j < b; j++){
            substring[j] = *data;
            data++;
        }
    }
    else if(b < 0){
        for(int z = 0; z > b; z--){
            substring[z] = *data;
            data--;
        }
    }
    return substring;
}

//c_str definition
char* DSString::c_str(){
    return data;
}

//operator<< definition
std::ostream& operator << (std:: ostream &x, const DSString &y){
    x << y.data;
    return x;
}
