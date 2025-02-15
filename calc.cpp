
#include "calc.h"
using namespace std;

Calc::Calc(){
    
}

Calc::~Calc(){
    
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
        
