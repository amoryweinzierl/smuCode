#define CATCH_CONFIG_RUNNER

#include "../../lib/Catch.hpp"
#include "Functions.h"

using namespace std;

int main(int argc, char* argv[])
{
    if(argc == 1){
        return Catch::Session().run();
    }
    else{
        Functions func;
        func.runProgram(argv);
    }
    return 0;
}
