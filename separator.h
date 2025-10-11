#ifndef _SEPARATOR_H
#define _SEPARATOR_H

#include <iostream>
#include <sstream>
#include <vector>

class Separator{
    public:
        Separator() {}
        ~Separator(){}
    
        std::vector<std::string> addSpace(const std::string& input);
};

#endif //SEPARATOR_H