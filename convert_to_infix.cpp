#include "convert_to_infix.h"


Convert_to_Infix::Convert_to_Infix(){

}

Convert_to_Infix::~Convert_to_Infix(){


}

//convert infix notation to reverse polish
vector<string> Convert_to_Infix::infixToRPN(const vector <string>& input){
    for(unsigned int i=0; i<input.size(); i++){
        if (TryParse(input[i])){
            //pushback if it is
            output.push_back(input[i]);
        }if(input[i] == "("){
            op.push(input[i]);
        }if(input[i] == ")"){
            while(!op.empty() && op.top() != "(")
            {
                output.push_back(op.top());
                op.pop();
            }
            op.pop();
        }if(isOperator(input[i]) == true){
            while(!op.empty() && Priority(op.top()) >= Priority(input[i])){
                output.push_back(op.top());
                op.pop();
            }
            op.push(input[i]);
        }
    }


    while(!op.empty())
    {
        output.push_back(op.top());
        op.pop();
    }

    cout << "逆ポーランド表記:" << endl;
    for(unsigned int i = 0; i < output.size(); i++)
    {
        cout<<output[i]<<endl;
    }
    return output;
}

bool Convert_to_Infix::TryParse(const string &symbol){
    bool isNumber = false;
    for(unsigned int i = 0; i < symbol.size(); i++)
    {
        if(!isdigit(symbol[i]))
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

bool Convert_to_Infix::isOperator(const string &c){
    return(c == "+" || c == "-" || c == "*" || c == "/");
}

int Convert_to_Infix::Priority(const string &c){
    if(c == "*" || c == "/"){
        return 2;
    }
    if(c == "+" || c == "-"){
        return 1;
    }else{
        return 0;
    }
}