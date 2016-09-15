#include <iostream>
#include <string>
#include "matrix.h"
#include "userCheck.h"

using namespace std;


matrix::matrix()
{
    char resp;

    do {
        cout << "How many rows are in the matrix?" << endl;
        cin >> row;
        userCheck rowCheck;
        row = rowCheck.intCheck(row);

        cout << "How many columns are in the matrix?" << endl;
        cin >> col;
        userCheck colCheck;
        col = colCheck.intCheck(col);

        cout << "This matrix contains " << row << " rows and " << col << " columns." << endl;
        cout << "Are these dimensions correct? y/n" << endl;

        cin >> resp;
        userCheck confirm;
        resp = confirm.respCheck(resp);
    } while (resp!='Y'&&resp!='y');
}

matrix::defineRow()
{
    return row;
}

matrix::defineCol()
{
    return col;
}
