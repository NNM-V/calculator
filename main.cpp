#include <iostream>
#include <limits>
#include <vector>
#include <sstream>
#include "calc.h"
#include "convertInfix.h"
#include "separator.h"

using namespace std;

int main() {
    cout << "電卓アプリへようこそ！\n";

    char closeApp = 'n';
    //continue while user input is "n" or "N"
    while (closeApp == 'n' || closeApp == 'N') {

        string input;
        //get user input
        while(input.empty()){
            cout << "数値と演算子を入力してください: ";
            getline(cin,input);  
        }
        
        vector<string> space_input;
        Separator sep;
        //add space between number and operation
        space_input = sep.addSpace(input);
        
        vector<string> rev_polish;
        convertInfix cinfix;
        //convert user input to reverse polish from infix notation
        rev_polish = cinfix.infixToRPN(space_input);
        //return to user input in case of error
        if(rev_polish.empty()){
            continue;
        }
        
        Calc calc;
 
        OptionInt optionint;
        //set calculation to Calc class and calculate
        optionint = calc.Calculation(rev_polish);
        //return to user input in case of error
        if (optionint.result == false) {
            continue;
        }
        
        cout<<"アプリを閉じますか(y/n):";
        //ask user to close the app or not
        cin>>closeApp;

        //continue to ask for user input when the input is not "y" or "n"
        while (closeApp != 'y' && closeApp != 'n' && closeApp != 'Y' && closeApp != 'N') {
            cout << "無効な入力です。'y' または 'n' を押してください。\n";
            //clear previous input 
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "アプリを閉じますか(y/n):\n";
            cin >> closeApp;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return 0;
}