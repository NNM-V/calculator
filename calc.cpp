
#include "calc.h"
using namespace std;

Calc::Calc(){
    
}

Calc::~Calc(){
    
}

vector<string> Calc::infixToRPN(const vector <string>& input){
    //string infix = "3 ^ 4 + ( 11 - ( 3 * 2 ) ) / 2";
    //istringstream iss(infix);
    //vector<string> tokens;
    vector<string> output;
    stack<string> op;
    /*
    while(iss)
    {
        string temp;
        iss >> temp;
        tokens.push_back(temp);
    }*/

    for(unsigned int i=0; i<input.size(); i++){
        if (TryParse(input[i])){
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

    //pop any remaining operators from the stack and insert to outputlist
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

bool Calc::TryParse(const string &symbol){
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

bool Calc::isOperator(const string &c){
    return(c == "+" || c == "-" || c == "*" || c == "/");
}

int Calc::Priority(const string &c){
    if(c == "*" || c == "/"){
        return 2;
    }
    if(c == "+" || c == "-"){
        return 1;
    }else{
        return 0;
    }
}

void Calc::keisan(){

    double result = 0.0;    
    
    /*
    while (!(cin >> num1 >> op >> num2)) {
            cout << "無効な入力です。数値と演算子を再入力してください: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    }*/

    switch (op) {
        case '+': 
            result = num1+num2;
            break;
        case '-': 
            result = num1-num2;
            break;
        case '*':
            result = num1*num2;
            break;
        case '/':
            if (num2 != 0)
            result = num1/num2;
            else 
            cout << "エラー: 0で割ることはできません。\n";
            break;
        default:
            cout << "無効な演算子です。\n";
            return;
        }

        cout<<"計算結果:\n"<<result<<"\n";
};
        
