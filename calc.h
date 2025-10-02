#ifndef _CALC_H
#define _CALC_H

#include <iostream>
#include <vector>
#include <stack>
#include <functional>

class Calc{
    private:
    std::vector<std::string> input;
    double num1,num2;
    std::stack<double> number;

    public:
    Calc() : num1(0.0), num2(0.0) {}
    ~Calc(){}

    void ResultHandler(bool, double);
    void Calculation(const std::vector<std::string> &rev_polish, const std::function<void(bool, double)>&callback);
    inline bool isOperator(const std::string &c){
        return(c == "+" || c == "-" || c == "*" || c == "/");
    }
};

#endif //_CALC_H