#ifndef _CONVERTINFIX_H
#define _CONVERTINFIX_H

#include <iostream>
#include <vector>
#include <stack>

class convertInfix{

    private:
    std::vector<std::string> output;
    std::stack<std::string> op;
    std::vector<std::string> adjustedOutput;

    public:
    convertInfix(){}
    ~convertInfix(){}

    std::vector<std::string> infixToRPN(const std::vector<std::string>& input);
    inline bool isOperator(const std::string &c){
        return(c == "+" || c == "-" || c == "*" || c == "/");
    }
    int Priority(const std::string & c);
};

#endif //_CONVERTINFIX_H