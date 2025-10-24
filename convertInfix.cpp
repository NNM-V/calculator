#include "convertInfix.h"
#include "utility.h"

using namespace std;

//convert infix notation to reverse polish
vector<string> convertInfix::infixToRPN(const vector<string>& input){
    vector<std::string> output;
    stack<std::string> op;
    
    for(auto token : input){
        Utility utility;
        //check if it is number
        if (utility.TryParse(token)){
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
        }else if(utility.isOperator(token) == true){
            //check if it is operator
            //check priority of operation and push to output
            while(!op.empty() && Priority(op.top()) >= Priority(token)){
                output.push_back(op.top());
                op.pop();
            }
            op.push(token);
        }else{
            cerr<<"Invalid input."<<endl;
            return {};
        }
    }

    //push the remaining operation
    while(!op.empty())
    {
        output.push_back(op.top());
        op.pop();
    }

    /*
    //test output
    cout << "reverse polish output:" << endl;
    for(auto& rev_str : output)
    {
        cout<<rev_str<<endl;
    }
    */

    vector<std::string> adjustedOutput;

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

    /*
    //test output
    cout << "adjusted output:" << endl;
    for(auto& adj_str : adjustedOutput)
    {
        cout<<adj_str<<endl;
    }
    */

    return adjustedOutput;
}

int convertInfix::Priority(const string &c){
    if(c == "^"){
        return 3;
    }
    if(c == "*" || c == "/")
    {
        return 2;
    }else if(c == "+" || c == "-")
    {
        return 1;
    }else{
        return 0;
    }
}