#ifndef _CONVERTINFIX_H
#define _CONVERTINFIX_H

#include <iostream>
#include <vector>
#include <stack>

class convertInfix{
    public:
        convertInfix(){}
        ~convertInfix(){}

        std::vector<std::string> infixToRPN(const std::vector<std::string>& input);
        int Priority(const std::string & c);
};

#endif //_CONVERTINFIX_H