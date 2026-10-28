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
        std::pair<bool, double> Calculation(const std::vector<std::string> &rev_polish);
};

#endif //_CALC_H