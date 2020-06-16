#include "Vector3.h"

using namespace std;

int main() {
    Vector3 a(17, -16, 41);
    Vector3 b(7, 51, 17);
    cout << acos(a.getScalarProduct(b) / (a.getNorma() * b.getNorma())) << endl;
    return 0;
}