#include "separator.h"

using namespace std;

vector<string> Separator::addSpace(const string& input){  
    ostringstream oss;
    //add space between string
    for (int i = 1; i < input.size(); ++i) {
        if(!isdigit(input[i]) && input[i]!='.'){
            //add space if it is not number
            oss << " ";
        }else if(!isdigit(input[i-1]) && input[i-1]!='.'){
            //add space if there is non-digit in front of number 
            oss << " ";
        }
        oss << input[i];
    }
    
    stringstream ss(oss.str());

    vector<std::string> v;
    string token;
    //divide input using space
    while(getline(ss,token,' ')){
        v.push_back(token);
    }

    /*
    //test output
    cout << "separated output:" << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    */
   
    return v;
}
