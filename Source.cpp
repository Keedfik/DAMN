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

    int rows, cols;

    if (!inp.is_open()) {       // file isn't open
        std::cout << "Error!\n";
    }else{

        int count = 0;// число чисел в файле
        int temp;//Временная переменная

        while (!inp.eof())// пробегаем пока не встретим конец файла eof
        {
            inp >> temp;//в пустоту считываем из файла числа
            count++;// увеличиваем счетчик числа чисел
        }

        inp.seekg(0, ios::beg);// переведем каретку в потоке в начало файла
        inp.clear();

        char *ch = new char [count];

        inp >> rows;
        inp >> cols;

        cout << rows << " " << cols << endl;

        a = new int* [rows];
        for (int i = 0; i < rows; i++) {
            a[i] = new int[cols];
        }

        for (int i = 0; !inp.eof(); i++) {
            inp >> ch[i];
        }
        
        for (int i = 0; i < rows; i++) { //Строка
            if (ch[i] != ',') {
                ch[i] = ch[i + 1];
                for (int k = 0; k < cols; k++) { //Столбец
                    a[i][k] = static_cast<int>(ch[i]) - 48;
                    mean += a[i][k];
                    if (a[i][k] > max) max = a[i][k];
                    if (a[i][k] < min) min = a[i][k];
                    std::cout << a[i][k] << " ";
                }
            }
            std::cout << std::endl;
        }

        mean = mean / 9;

        outp << "Max = " << max << std::endl;
        outp << "Min = " << min << std::endl;
        outp << "Mean = " << mean << std::endl;

        inp.close();
        outp.close();
        otp.close();

        for (int i = 0; i < rows; i++) {
            delete[] a[i];
        }
        delete[] a;

    }
    return 0;
}
