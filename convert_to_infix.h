#ifndef _CONVERT_TO_INFIX_H
#define _CONVERT_TO_INFIX_H

#include <iostream>
#include <sstream>
#include  <vector>
#include <stack>

using namespace std;

class Convert_to_Infix{

    private:
    vector<string> output;
    stack<string> op;

    public:
    Convert_to_Infix();
    ~Convert_to_Infix();

    vector<string> infixToRPN(const vector <string>& input);
    vector<string> splitString(const string& input);
    bool TryParse(const string &symbol);
    bool isOperator(const string &c);
    int Priority(const string &c);
};

#endif //_CONVERT_TO_INFIX_H