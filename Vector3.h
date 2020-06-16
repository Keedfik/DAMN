#ifndef VECTOR3_H
#define VECTOR3_H
#include <iostream>
#include <cassert>
#include <limits>

class Vector3 {
public:
    const static unsigned int n = 3;
    Vector3(); // пустой конструктор
    Vector3(double arg);
    Vector3(const double arg[3]);
    Vector3(const Vector3& other);
    Vector3(double arg1, double arg2, double arg3);
    ~Vector3();//+
    double& operator[](unsigned int i);
    double operator[](unsigned int i) const;
    Vector3& operator=(const Vector3& other);
    Vector3& operator+=(const Vector3& other);
    Vector3& operator-=(const Vector3& other);
    Vector3& operator*=(const double number);
    Vector3& operator/=(const double number);
    friend bool operator==(const Vector3& lhs, const Vector3& rhs);
    friend Vector3 operator+(const Vector3& our, const Vector3& other);
    friend Vector3 operator-(const Vector3& our, const Vector3& other);
    friend Vector3 operator*(const Vector3& our, double number);
    friend Vector3 operator*(const double number, const Vector3& our);
    friend Vector3 operator/(const Vector3& our, const double number);
    double getNorma() const;
    void normalize();
    Vector3 getNormalized()const;
    double getScalarProduct(const Vector3& other) const;
    friend Vector3 getVectorProduct(const Vector3& our, const Vector3& other);
    Vector3 operator-()const;
    friend std::ostream& operator<<(std::ostream& stream, const Vector3& V);
    const double* getElements();
private:
    double elem[n];
}; // class Vector3

bool operator!=(const Vector3& our, const Vector3& other);

#endif // VECTOR3_H
