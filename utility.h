#ifndef _UTILITY_H
#define _UTILITY_H

#include <iostream>

class Utility{
    public:
    Utility(){}
    ~Utility(){}
    
    bool TryParse(const std::string &symbol);
    bool isOperator(const std::string &c);
};

#endif //_UTILITY_H