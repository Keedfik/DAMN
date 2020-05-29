#include <iostream>
#include <fstream> 
#include <iomanip> 
#include <string>
#include <stdlib.h>

using namespace std;

/*3 3
2, 4, 5
1, 0, 6
6, 3, 4*/

int main() {

    std::ifstream inp("input.txt");
    std::ofstream outp("out_row.txt");
    std::ofstream otp("out_col.txt ");

    int max = 0;
    int min = 9;
    double mean = 0;
    int** a;
    int** b;
    int** c;

    int rows, cols;

    if (!inp.is_open()) {       // file isn't open
        std::cout << "Error!\n";
    }else{

        char ch;

        inp >> rows;
        inp >> cols;

        cout << rows << " " << cols << endl;

        a = new int* [rows];
        for (int i = 0; i < rows; i++) {
            a[i] = new int[cols];
        }
        
        for (int i = 0; i < rows; i++) { //Ñòðîêà
            for (int k = 0; k < cols; k++) { //Ñòîëáåö
                inp >> a[i][k]; //åñëè â êîíöå ñòðîêè íåò çàïÿòîé, òî è ÷èòàòü å¸ íå áóäåì
                if (k != cols - 1) inp >> ch;    //char ch - ïåðåìåííàÿ äëÿ ÷òåíèÿ çàïÿòîé
                mean += a[i][k];
                if (a[i][k] > max) max = a[i][k];
                if (a[i][k] < min) min = a[i][k];
                cout << a[i][k] << " ";
            }
            cout << endl;
        }

        mean = mean / (rows*cols);

//--------------------------------------------------------------------------------------------
        
        b = new int* [rows];
        for (int i = 0; i < rows; i++) {
            b[i] = new int[cols];
        }

        for (int i = 0; i < rows; i++) {
            for (int k = 0; k < cols; k++) {
                b[i][k] = a[i][k];
            }
        }

        int temp;
        //â ñòðîêàõ óïîðÿäî÷èâàåì
        for (int c = 0; c <= (rows * cols); c++){//êîëëè÷åñòâî ïðîõîäîâ
            for (int i = 0; i < rows; i++){
                for (int j = 0; j < cols - 1; j++){
                    if (b[i][j] > b[i][j + 1]){
                        temp = b[i][j];
                        b[i][j] = b[i][j + 1];
                        b[i][j + 1] = temp;
                    }
                }
            }
        }

        outp << "Max = " << max << std::endl;
        outp << "Min = " << min << std::endl;
        outp << "Mean = " << mean << std::endl;

        for (int i = 0; i < rows; i++) { //Ñòðîêà
            for (int k = 0; k < cols; k++) { //Ñòîëáåö
                outp << b[i][k] << " ";
            }
            outp << endl;
        }

//--------------------------------------------------------------------------------------------

        c = new int* [rows];
        for (int i = 0; i < rows; i++) {
            c[i] = new int[cols];
        }

        for (int i = 0; i < rows; i++) {
            for (int k = 0; k < cols; k++) {
                c[i][k] = a[i][k];
            }
        }

        // Ñîðòèðîâêà ñòîëáöîâ ïî óáûâàíèþ
        int MinRow;
        for (int NumCol = 0; NumCol < cols; NumCol++) {
            for (int NumRow = 0; NumRow < rows - 1; NumRow++) {
                MinRow = NumRow;
                for (int j = NumRow + 1; j < rows; j++)
                    if (c[j][NumCol] > c[MinRow][NumCol])
                        MinRow = j;
                temp = c[NumRow][NumCol];
                c[NumRow][NumCol] = c[MinRow][NumCol];
                c[MinRow][NumCol] = temp;
            }
        }

        otp << "Max = " << max << std::endl;
        otp << "Min = " << min << std::endl;
        otp << "Mean = " << mean << std::endl;

        for (int i = 0; i < rows; i++) { //Ñòðîêà
            for (int k = 0; k < cols; k++) { //Ñòîëáåö
                otp << c[i][k] << " ";
            }
            otp << endl;
        }

//--------------------------------------------------------------------------------------------

        inp.close();
        outp.close();
        otp.close();

        for (int i = 0; i < rows; i++) {
            delete[] a[i];
        }
        delete[] a;

        for (int i = 0; i < rows; i++) {
            delete[] b[i];
        }
        delete[] b;

        for (int i = 0; i < rows; i++) {
            delete[] c[i];
        }
        delete[] c;

    }
    return 0;
}


