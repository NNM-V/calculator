
#include "calc.h"

using namespace std;

Calc::Calc() : num1(0.0), num2(0.0) {
}


Calc::~Calc(){
    
}


void Calc::Calculation(const std::vector<std::string> &rev_polish, const function<void(bool, double)>&callback){
    for(auto& token : rev_polish){
        if(isOperator(token)){
            if(number.size()<2){
                cerr<<"Not enough digits or invalid input"<<endl;
                return callback(false, 0);
            }
           
            num1 = number.top();
            number.pop();
            num2 = number.top();
            number.pop();

            if(token == "+"){
                number.push(num2+num1);
            }else if(token == "-"){
                number.push(num2-num1);
            }else if(token == "*"){
                number.push(num2*num1);
            }else if(token == "/"){
                if (num1 != 0){
                    number.push(num2/num1);
                }else {
                    cerr<<"Invalid input"<<endl;
                    return callback(false, 0);
                }
            }
        }else if(TryParse(token)){
            number.push(stod(token));
        }
    }

    return callback(true, number.top());
}

bool Calc::TryParse(const string &symbol){
    bool isNumber = false;
    for(char c: symbol)
    {
        if(!isdigit(c))
        {
            isNumber = false;
        }
        else
        {
            isNumber = true;
        }
    }

    return isNumber;
}