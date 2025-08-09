#include "separator.h"

using namespace std;

Separator::Separator() {
    oss.str(""); 
    oss.clear();   
}

Separator::~Separator(){

}

vector<string> Separator::addSpace(const string& input){  
    //add space between string
    for (int i = 0; i < input.size(); ++i) {
        //process to not add 0 in front of the first number
        if (i > 0){
            if(!isdigit(input[i])){
                //add space if it is not number
                oss << " ";
            }else if(!isdigit(input[i-1])){
                //add space if there is non-digit in front of number 
                oss << " ";
            }
        }    
        oss << input[i];
    }

    stringstream ss(oss.str());

    //divide input using space
    while(getline(ss,token,' ')){
        v.push_back(token);
    }

    /*
    cout << "separated output:" << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    */
   
    return v;
}
