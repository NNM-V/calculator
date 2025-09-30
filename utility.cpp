#include "utility.h"

using namespace std;

bool Utility::TryParse(const string &symbol){
    bool isNumber = false;
    for(char c: symbol)
    {
        if(!isdigit(c))
        {
            isNumber = false;
        }
        else
        {
            isNumber = true;
        }
    }

    return isNumber;
}

bool Utility::isOperator(const std::string &c){
    return(c == "+" || c == "-" || c == "*" || c == "/");
}