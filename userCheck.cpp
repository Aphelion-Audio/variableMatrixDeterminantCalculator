#include <iostream>
#include <string>
#include "userCheck.h"

using namespace std;

userCheck::userCheck(){}

userCheck::intCheck(int x)
{
    while (! cin >> x)
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid entry.  Please enter an integer value." << endl;
        cin >> x;
    }

    return x;
}

userCheck::respCheck(char x)
{
    while (x!='Y'&&x!='y'&&x!='N'&&x!='n')
    {
        cout << "Invalid entry.  Please respond y/n" << endl;
        cin >> x;
    }

    return x;
}
