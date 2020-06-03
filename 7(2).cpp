#include <iostream>
#include <fstream> 
#include <iomanip> 
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

class MyIterator : public std::iterator<std::random_access_iterator_tag, int>
{
public:
    MyIterator() : container(nullptr), i(0), j(0) {}

    MyIterator(const std::vector<std::vector<int>>& container,
        std::size_t i,
        std::size_t j) : container(&container), i(i), j(j)
    {
        // Skip empty container
        if (i < container.size() && container[i].empty())
        {
            j = 0;
            ++(*this);
        }
    }
    MyIterator(const MyIterator& rhs) = default;
    MyIterator& operator = (const MyIterator& rhs) = default;

    MyIterator& operator ++() {
        if (++j >= (*container)[i].size()) {
            do { ++i; } while (i < (*container).size() && (*container)[i].empty());
            j = 0;
        }
        return *this;
    }
    MyIterator operator ++(int) { auto it = *this; ++(*this); return it; }

    MyIterator& operator --() {
        if (j-- == 0) {
            do { --i; } while (i != 0 && (*container)[i].empty());
            j = (*container)[i].size();
        }
        return *this;
    }
    MyIterator operator --(int) { auto it = *this; --(*this); return it; }

    int operator *() const { return (*container)[i][j]; }


    bool operator == (const MyIterator& rhs) const {
        return container == rhs.container && i == rhs.i && j == rhs.j;
    }
    bool operator != (const MyIterator& rhs) const { return !(*this == rhs); }

private:
    const std::vector<std::vector<int>>* container;
    std::size_t i;
    std::size_t j;
};

MyIterator MyIteratorBegin(const std::vector<std::vector<int>>& container)
{
    return MyIterator(container, 0, 0);
}

MyIterator MyIteratorEnd(const std::vector<std::vector<int>>& container)
{
    return MyIterator(container, container.size(), 0);
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

        vector<vector<int> > a(rows, vector<int>(cols));
        vector<vector<int> > WOW(rows, vector<int>(cols));  //hehe
        char ch;    //,

        for (int i = 0; i < rows; i++) {     // rows
            for (int j = 0; j < cols; j++) // cols
            {
                inp >> a[i][j]; 
                WOW[i][j] = a[i][j];
                if (j != cols - 1) inp >> ch;    
                cout << a[i][j] << " ";
                mean += a[i][j];
            }
            cout << endl;
        }
        
        mean = mean / (cols*rows);

        cout << endl;
        inp.close();

//--------------------------------------------------------------------------------------------

        auto damn = MyIteratorBegin(a);
        auto yeet = MyIteratorEnd(a);
        auto what = std::minmax_element(damn, yeet);

        if (what.first != yeet) {
            outp << "min = " << *what.first << " max = " << *what.second << std::endl;
        }

        if (what.first != yeet) {
            otp << "min = " << *what.first << " max = " << *what.second << std::endl;
        }
        
//--------------------------------------------------------------------------------------------

        int temp;
        for (int c = 0; c <= (rows * cols); c++) {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols - 1; j++) {
                    if (a[i][j] > a[i][j + 1]) {
                        temp = a[i][j];
                        a[i][j] = a[i][j + 1];
                        a[i][j + 1] = temp;
                    }
                }
            }
        }

        outp << "Mean = " << mean << std::endl;

        for (int i = 0; i < rows; i++) {
            for (int k = 0; k < cols; k++) {
                outp << a[i][k] << " ";
            }
            outp << endl;
        }
        outp.close();

//--------------------------------------------------------------------------------------------

        int MinRow;
        for (int NumCol = 0; NumCol < cols; NumCol++) {
            for (int NumRow = 0; NumRow < rows - 1; NumRow++) {
                MinRow = NumRow;
                for (int j = NumRow + 1; j < rows; j++)
                    if (WOW[j][NumCol] > WOW[MinRow][NumCol])
                        MinRow = j;
                temp = WOW[NumRow][NumCol];
                WOW[NumRow][NumCol] = WOW[MinRow][NumCol];
                WOW[MinRow][NumCol] = temp;
            }
        }
        
        otp << "Mean = " << mean << std::endl;

        for (int i = 0; i < rows; i++) {
            for (int k = 0; k < cols; k++) {
                otp << WOW[i][k] << " ";
            }
            otp << endl;
        }
        otp.close();

    }

    return 0;
}



