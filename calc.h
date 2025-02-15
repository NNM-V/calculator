#ifndef _CALC_H
#define _CALC_H

#include <iostream>
#include <sstream>
#include  <vector>
#include <stack>
#include <limits>

using namespace std;

class Calc{

    private:
    double num1,num2;
    char op;

    public:
    Calc();
    ~Calc();

    vector<string> infixToRPN(const vector <string>& input);
    vector<string> splitString(const string& input);
    bool TryParse(const string &symbol);
    bool isOperator(const string &c);
    int Priority(const string &c);
    void keisan();  
};

#endif //_CALC_H