#include "yesno.h"
#include <limits>

using namespace std;

string YesNo::cont(const std::string& message, const std::vector<std::string>& valid_string){
    cout<<message<<endl;

    string input;
    while(true){
        getline(cin,input);
        auto it = std::find(valid_string.begin(), valid_string.end(), input);
        if(input.empty()){
            cout<<"Empty Input"<<endl;
        }else if(it == valid_string.end()){
            cout<<"Unexpected input/無効な入力です"<<endl;
        }else{
            return input;
        }
    }
}
