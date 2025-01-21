#include <iostream>
#include <limits>
#include "calc.h"
using namespace std;

int main() {
    char closeApp = 'n';

    while (closeApp == 'n' || closeApp == 'N') {
        cout << "電卓アプリへようこそ！\n";
        cout << "数値と演算子を入力してください (例: 3+5): ";

        Calc  calc;
        calc.keisan();

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