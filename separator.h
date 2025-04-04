#ifndef _SEPARATOR_H
#define _SEPARATOR_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class Separator{

    private:
    std::ostringstream oss;
    std::vector<std::string> v;
    std::string token;


    public:
    Separator();
    ~Separator();
    std::vector<std::string> addSpace(const std::string& input);
};

#endif //SEPARATOR_H