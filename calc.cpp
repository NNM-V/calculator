
#include "calc.h"
#include "utility.h"

using namespace std;

void Calc::Calculation(const std::vector<std::string> &rev_polish, const function<void(bool, double)>&callback){
    Utility utility;

    for(auto& token : rev_polish){
        if(utility.isOperator(token)){
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
        }else if(utility.TryParse(token)){
            number.push(stod(token));
        }
    }

    return callback(true, number.top());
}
