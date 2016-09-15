#include <iostream>
#include <string>
#include <conio.h>
#include "matrix.h"
#include "userCheck.h"

using namespace std;

int main()
{
    cout << "Welcome to the Variable Matrix Determinant Calculator." << endl;

    char restart;

    do{ //this loop instantiates the matrix and allows the user to define its dimensions and cell values
        matrix detMat;
        int arrRow = detMat.defineRow();
        int arrCol = detMat.defineCol();

        float arr[arrRow][arrCol];

        char resp = '0';
        restart = '0';

        do {
            int x = 0;
            int y = 0;
            int z = 0;
            string counter;

            for (x; x<arrRow; x++){
                y = 0;

                if (x == 0){
                    counter = "first";
                } else {
                    counter = "next";
                }

                cout << "Input " << counter << " row of values." << endl;

                for (y; y<arrCol; y++){
                    cin >> arr[z][y];
                }

                z++;
            }

            x = 0;
            y = 0;
            z = 0;

            for (x; x<arrRow; x++){
                y = 0;

                for (y; y<arrCol; y++){
                    cout << arr[x][y] << " ";
                }

                cout << endl;
            }

            cout << "Are these values correct? y/n" << endl;
            cin >> resp;
            userCheck matConf;
            resp = matConf.respCheck(resp);

            if (resp=='N'||resp=='n'){
                cout << "Restart matrix generation? y to restart matrix generation, n to re-enter values." << endl;
                cin >> restart;
                userCheck reCheck;
                restart = reCheck.respCheck(restart);
            }

        } while ((resp=='N'&&restart=='N')||(resp=='N'&&restart=='n')||(resp=='n'&&restart=='N')||(resp=='n'&&restart=='n'));

        if (restart=='Y'||restart=='y'){
            cout << "Restarting matrix generation." << endl;
        } else {
        float det;
        float prime = 1;
        float sec = 1;
        float hold = 0;
        float primeHold = 0;
        float secHold = 0;

        int q = 0;
        int x = 0;
        int y = 0;
        int z = 0;

        for (q; q<arrCol; q++){
            for (z; z<arrCol; z++){
                hold = arr[x][y];
                prime *= hold;
                x++;
                y++;

                if (x>=arrRow){
                    x = 0;
                }
                if (y>=arrCol){
                    y = 0;
                }
            }

            switch (q){
            case 0:
                primeHold = prime;
                break;
            default:
                primeHold += prime;
            }

            x = 0;
            y = q+1;
            z = 0;
            prime = 1;
        }

        prime = primeHold;

        q = 0;
        x = arrRow - 1;
        y = 0;
        z = 0;
        hold = 0;

        for (q; q<arrCol; q++){
            for (z;z<arrCol;z++){
                hold = arr[x][y];
                sec *= hold;
                x--;
                y++;

                if (x < 0){
                    x = arrRow - 1;
                }
                if (y >= arrCol){
                    y = 0;
                }
            }

            switch (q){
            case 0:
                secHold = sec;
                break;
            default:
                secHold += sec;
            }

            x = arrRow - 1;
            y = q + 1;
            z = 0;
            sec = 1;
        }

        sec = secHold;

        det = prime - sec;

        cout << "The determinant value of this matrix is: " << det << endl << endl;

        cout << "Would you like to run the calculator again? y/n" << endl;
        cin >> restart;
        userCheck resCheck;
        restart = resCheck.respCheck(restart);
        }

    } while (restart!='N'&&restart!='n');

    cout << "Thank you for using the Variable Matrix Determinant Calculator." << endl;
    cout << "This program designed by Stardust Labs." << endl << endl;
    cout << "Press any key to close window." << endl;

    getch();

    return 0;
}
