#ifndef _CALC_H
#define _CALC_H

#include <iostream>
#include <vector>
#include <stack>
#include <functional>

/*
struct OptionInt {
    bool result;
    double value;
};
*/

class Calc{

    private:
    std::vector<std::string> input;
    double num1,num2;
    std::stack<double> number;

    public:
    Calc();
    ~Calc();
    void ResultHandler(bool, double);
    void Calculation(const std::vector<std::string> &rev_polish, const std::function<void(bool, double)>&callback);
    bool TryParse(const std::string &symbol);
    bool isOperator(const std::string &c);
};

#endif //_CALC_H