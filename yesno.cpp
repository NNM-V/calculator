#include "yesno.h"
#include <limits>

using namespace std;

char YesNo::cont(){
    cout<<message<<endl;
    //user input
    cin >> input;
    input = tolower(input);

    //continue to ask for user input when the input is not "y" or "n"
    while (input != 'y' && input != 'n') {
        cout << "Invalid input。Input 'y' or 'n'\n";
        //clear previous input 
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //user input
        cin >> input;
        input = tolower(input);
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return input;
}
