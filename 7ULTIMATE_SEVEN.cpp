#include <iostream>
#include <fstream> 
#include <vector>
#include <algorithm>

using namespace std;

void print(const vector<double>& a) {
    for (auto i : a) {
        cout << i << " ";
    }
    cout << endl;
}

void printMatrix(const vector<double>& v, int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << v[i * col + j] << " ";
        }
        cout << endl;
    }
}

ostream& fprint_row(const vector<double>& v, int row, int col, ofstream& f) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            f << v[i * col + j] << " ";
        }
        f << endl;
    }
    return f;
}

ostream& fprint_col(const vector<double>& v, int row, int col, ofstream& f) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            f << v[i+j*col] << " ";
        }
        f << endl;
    }
    return f;
}

double summa(const vector<double>& v) {
    double sum = 0;
    for (int i = 0; i < v.size(); ++i) {
         sum += v[i];
    }
    return sum;
}

bool comp1(double a, double b) {
    return b > a;
}

bool comp2(double a, double b) {
    return a > b;
}

int main() {

    fstream inp("input.txt");
    ofstream outp("out_row.txt");
    ofstream otp("out_col.txt ");

    double mean = 0;

    int rows, cols;

    if (!inp.is_open()) {       // file isn't open
        std::cout << "Error!\n";
    }
    else {

        inp >> rows >> cols;

        cout << rows << " " << cols << endl << endl;

        int vec_size = rows * cols;

        vector<double> a(vec_size);

        for (size_t i = 0; i < vec_size-1; i++) {
            inp >> a[i];
            inp.ignore(1, ',');
        }
        inp >> a[vec_size - 1];

        print(a);
        cout << endl; 
        printMatrix(a, rows, cols);
        cout << endl;
        inp.close();

//---------------------------------------------------------------------------

        auto max = max_element(a.begin(), a.end());

        auto min = min_element(a.begin(), a.end());

        mean = summa(a) / (vec_size);

//---------------------------------------------------------------------------

        vector <double> b;
        b.assign(a.begin(), a.end());

        outp << "max= " << *max << '\n';
        outp << "min= " << *min << '\n';
        outp << "mean= " << mean << '\n';
        
        int damn = 0;

        while(damn <= b.size()-rows ) {
            sort(begin(b)+damn, begin(b) + rows + damn, comp1);
            damn += rows;
        }

        fprint_row(b, rows, cols, outp);
        outp.close();

//---------------------------------------------------------------------------

        vector <double> c;

        otp << "max= " << *max << '\n';
        otp << "min= " << *min << '\n';
        otp << "mean= " << mean << '\n';

        vector <double> yeet;
        int trash = 0;

        for (int i = 0; i < rows; i++) {
            for (int k = 0; k < cols; k++) {
                trash = a.at(i+k*cols);
                yeet.push_back(trash);
            }
            //print(yeet);
            sort(yeet.begin(), yeet.end(), comp2);
            c.insert(c.end(), yeet.begin(), yeet.end());
            yeet.clear();
        }

        //print(c);
        fprint_col(c, rows, cols, otp);
        otp.close();

//---------------------------------------------------------------------------
        a.clear();
        b.clear();
        c.clear();
    }

    return 0;
}



