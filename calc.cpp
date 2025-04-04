
#include "calc.h"

using namespace std;

Calc::Calc() : num1(0.0), num2(0.0) {
}


Calc::~Calc(){
    
}

OptionInt Calc::Calculation(const std::vector<std::string> &rev_polish){
    for(string token : rev_polish){
        if(isOperator(token)){
            if(number.size()<2){
                cerr<<"数字が足りないまたは無効な入力です"<<endl;
                return OptionInt{ false, 0 };
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
                    cerr<<"無効な入力です"<<endl;
                    return OptionInt{ false, 0 };
                }
            }
        }else if(TryParse(token)){
            number.push(stoi(token));
        }
    }
    cout<<"計算結果: "<<number.top()<<endl;

    return OptionInt{true, number.top()};
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

bool Calc::isOperator(const string &c){
    return(c == "+" || c == "-" || c == "*" || c == "/");
}