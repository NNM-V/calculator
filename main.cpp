#include <iostream>
#include <limits>
#include <vector>
#include <sstream>
#include "calc.h"
#include "convertInfix.h"
#include "separator.h"

using namespace std;

int main() {
    cout << "Welcome to calculator app!\n";

    char closeApp = 'n';
    //continue while user input is "n" or "N"
    while (closeApp == 'n' || closeApp == 'N') {

        string input;
        //get user input
        while(true){
            cout << "Input digit and operator: "<<endl;
            getline(cin,input);
            if(input.empty()){
                cout << "Input digit and operator: "<<endl;
            }else{
                break;
            }
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

        calc.Calculation(rev_polish, [](bool success, double value){
            if (success) {
                std::cout << "Result:" << value << std::endl;
            } else {
                std::cerr << "Calculation failed!" << std::endl;
            }
        });
        
        //ask user to close the app or not
        cout<<"Do you want to close the app?(y/n):";
        //user input
        cin>>closeApp;

        //continue to ask for user input when the input is not "y" or "n"
        while (closeApp != 'y' && closeApp != 'n' && closeApp != 'Y' && closeApp != 'N') {
            cout << "Invalid input。Input 'y' or 'n'\n";
            //clear previous input 
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            //ask user to close the app or not
            cout << "Do you want to close the app?(y/n):\n";
            //user input
            cin >> closeApp;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return 0;
}