#include <iostream>
#include <limits>
#include <vector>
#include "calc.h"
#include "temp.h"

using namespace std;

int main() {
    char closeApp = 'n';
    string input;
    vector<string> v;
    int N;
        while (closeApp == 'n' || closeApp == 'N') {
            cout << "電卓アプリへようこそ！\n";
            cout << "数値と演算子を入力してください: ";
            
            getline(cin,input);
            //cout<<input<<endl;
            stringstream ss(input);
            string token;
            
            while(getline(ss,token,' ')){
                v.push_back(token);
            }

            cout << "分割結果:" << endl;
            for (int i=0; i<v.size(); i++) {
                cout << v[i] << endl;
            }

            Calc *pcalc = new Calc;
            pcalc->infixToRPN(v);
            delete pcalc;
            
            cout<<"アプリを閉じますか(y/n):\n";
            cin>>closeApp;

            while (closeApp != 'y' && closeApp != 'n' && closeApp != 'Y' && closeApp != 'N') {
                cout << "無効な入力です。'y' または 'n' を押してください。\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "アプリを閉じますか(y/n):\n";
                cin >> closeApp;
            }
    }
    return 0;
}