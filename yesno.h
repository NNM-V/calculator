#ifndef _YEESNO_H
#define _YEESNO_H

#include <iostream>
#include <vector>
#include <algorithm>

class YesNo{
    public:
        YesNo(){}
        ~YesNo(){}

        std::string cont(const std::string& message, const std::vector<std::string>& valid_string);
};

#endif //_YEESNO_H