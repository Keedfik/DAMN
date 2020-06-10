#include <iostream>
#include <fstream> 
#include <vector>
#include <algorithm>

using namespace std;

void print(const vector<int>& a) {
    for (auto i : a) {
        cout << i << " ";
    }
    cout << endl;
}

void printMatrix(const vector<int>& v, int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << v[i * col + j] << " ";
        }
        cout << endl;
    }
}

ostream& fprint_row(const vector<int>& v, int row, int col, ofstream& f) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            f << v[i * col + j] << " ";
        }
        f << endl;
    }
    return f;
}

ostream& fprint_col(const vector<int>& v, int row, int col, ofstream& f) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            f << v[i+j*col] << " ";
        }
        f << endl;
    }
    return f;
}

double summa(const vector<int>& v) {
    double sum = 0;
    for (int i = 0; i < v.size(); ++i) {
         sum += v[i];
    }
    return sum;
}

bool comp1(int a, int b) {
    return b > a;
}

bool comp2(int a, int b) {
    return a > b;
}

int main() {

    std::ifstream inp("input.txt");
    std::ofstream outp("out_row.txt");
    std::ofstream otp("out_col.txt ");

    double mean = 0;

    int rows, cols;

    if (!inp.is_open()) {       // file isn't open
        std::cout << "Error!\n";
    }
    else {

        inp >> rows;
        inp >> cols;

        cout << rows << " " << cols << endl << endl;

        vector<int> a;

        char ch;
        int trash;

        for (int i = 0; !inp.eof(); i++) {
            inp >> ch;
            trash = (int)ch-48;
            if(trash != -4) a.push_back(trash);
        }

        a.pop_back(); // i don't know, eto kostil'

        print(a);
        cout << endl; 
        printMatrix(a, rows, cols);
        cout << endl;
        inp.close();

//---------------------------------------------------------------------------

        auto max_pos = max_element(a.begin(), a.end());
        int max = std::distance(a.begin(), max_pos);

        std::cout << "max= " << a.at(max) << '\n';

        auto min_pos = min_element(a.begin(), a.end());
        int min = std::distance(a.begin(), min_pos);

        std::cout << "min= " << a.at(min) << '\n';

        mean = summa(a) / (rows * cols);

        std::cout << "mean= " << mean << '\n';
    
//---------------------------------------------------------------------------

        vector <int> b;
        b.assign(a.begin(), a.end());

        outp << "max= " << a.at(max) << '\n';
        outp << "min= " << a.at(min) << '\n';
        outp << "mean= " << mean << '\n';
        
        int damn = 0;

        while(damn <= b.size()-rows ) {
            sort(begin(b)+damn, begin(b) + rows + damn, comp1);
            damn += rows;
        }

        fprint_row(b, rows, cols, outp);
        outp.close();

//---------------------------------------------------------------------------

        vector <int> c;

        otp << "max= " << a.at(max) << '\n';
        otp << "min= " << a.at(min) << '\n';
        otp << "mean= " << mean << '\n';

        vector <int> yeet;

        for (int i = 0; i < rows; i++) {
            for (int k = 0; k < cols; k++) {
                trash = a.at(i+k*cols);
                yeet.push_back(trash);
            }
            print(yeet);
            sort(yeet.begin(), yeet.end(), comp2);
            c.insert(c.end(), yeet.begin(), yeet.end());
            yeet.clear();
        }

        print(c);
        fprint_col(c, rows, cols, otp);
        otp.close();

//---------------------------------------------------------------------------
        a.clear();
        b.clear();
        c.clear();
    }

    return 0;
}



