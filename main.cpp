#include <iostream>
#include <vector>

#include "calc.h"
#include "convertInfix.h"
#include "separator.h"
#include "yesno.h"

using namespace std;

int main() {
    cout << "Welcome to calculator app!\n";

    //continue while user input is "n"
    while (true) {
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
        
        Separator sep;
        //add space between number and operation
        vector<string> space_input = sep.addSpace(input);
           
        convertInfix cinfix;
        //convert user input to reverse polish from infix notation
        vector<string> rev_polish = cinfix.infixToRPN(space_input);
        
        //return to user input in case of error
        if(rev_polish.empty()){
            continue;
        }
        
        Calc calc;
        //get calculation result from calc class
        calc.Calculation(rev_polish, [](bool success, double value){
            if (success) {
                std::cout << "Result:" << value << std::endl;
            } else {
                std::cerr << "Calculation failed!" << std::endl;
            }
        });
        
        //ask user to continue the app 
        YesNo yn("Do you want to close the app?(y/n):");
        char closeApp = yn.cont();
        if(closeApp == 'n'){
            continue;;
        }else if(closeApp == 'y'){
            break;
        }
    }
    
    return 0;
}