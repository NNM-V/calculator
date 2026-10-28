
#include "calc.h"
#include "utility.h"

using namespace std;

pair<bool, double> Calc::Calculation(const std::vector<std::string> &rev_polish){
    std::stack<double> number;
    
    for(auto& token : rev_polish){
        Utility utility;
        if(utility.isOperator(token)){
            double num1,num2;
            if(number.size()<2){
                cerr<<"Not enough digits or invalid input"<<endl;
                return {false, 0};
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
                    return {false, 0};
                }
            }
        }else if(utility.TryParse(token)){
            number.push(stod(token));
        }
    }

    return {true, number.top()};
}
