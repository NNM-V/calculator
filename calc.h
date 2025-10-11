#ifndef _CALC_H
#define _CALC_H

#include <iostream>
#include <vector>
#include <stack>
#include <functional>

class Calc{
    public:
        Calc(){}
        ~Calc(){}

        void ResultHandler(bool, double);
        void Calculation(const std::vector<std::string> &rev_polish, const std::function<void(bool, double)>&callback);
};

#endif //_CALC_H