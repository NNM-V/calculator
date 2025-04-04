#ifndef _CALC_H
#define _CALC_H

#include <iostream>
#include <sstream>
#include <vector>
#include <stack>

struct OptionInt {
    bool result;
    double value;
};

class Calc{

    private:
    std::vector<std::string> input;
    double num1,num2;
    std::stack<double> number;

    public:
    Calc();
    ~Calc();
    OptionInt Calculation(const std::vector<std::string> &rev_polish);
    bool TryParse(const std::string &symbol);
    bool isOperator(const std::string &c);
};

#endif //_CALC_H