#include "convertInfix.h"

using namespace std;

convertInfix::convertInfix(){
}

convertInfix::~convertInfix(){

}

//convert infix notation to reverse polish
vector<string> convertInfix::infixToRPN(const vector<string>& input){
    for(string token : input){
        //check if it is number
        if (TryParse(token)){
            //push if it is number
            output.push_back(token);
        }else if(token == "("){
            //push if it is left parentheses
            op.push(token);
        }else if(token == ")"){
            //put preference to operation
            while(!op.empty() && op.top() != "(")
            {
                //push operation to output
                output.push_back(op.top());
                //pop from op 
                op.pop();
            }
            //pop parentheses from op
            op.pop();
        }else if(isOperator(token) == true){
            //check if it is operator
            //check priority of operation and push to output
            while(!op.empty() && Priority(op.top()) >= Priority(token)){
                output.push_back(op.top());
                op.pop();
            }
            op.push(token);
        }else{
            cerr<<"無効な入力です。計算を正しく入力してください。"<<endl;
            return {};
        }
    }

    //push the remaining operation
    while(!op.empty())
    {
        output.push_back(op.top());
        op.pop();
    }

    
    cout << "逆ポーランド表記:" << endl;
    for(string rev_str : output)
    {
        cout<<rev_str<<endl;
    }

    //if the operation before and after left parentheses are "-", pop them and pushback "+"
    for (int i = 0; i < output.size(); i++) {
        if (output[i] == "-" && output[i - 1] == "-") {
            //delete "-"
            adjustedOutput.pop_back();  
            // add "+" 
            adjustedOutput.push_back("+"); 
        } else {
            adjustedOutput.push_back(output[i]);
        }
    }

    cout << "アジャスト表記:" << endl;
    for(string adj_str : adjustedOutput)
    {
        cout<<adj_str<<endl;
    }

    return adjustedOutput;
}

bool convertInfix::TryParse(const string &symbol){
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

bool convertInfix::isOperator(const string &c){
    return(c == "+" || c == "-" || c == "*" || c == "/");
}

int convertInfix::Priority(const string &c){
    if(c == "*" || c == "/")return 2;
    if(c == "+" || c == "-")return 1;
    return 0;
}