// "Copyright 2019 <Khachatryan A.A.>"

#ifndef COMPLEX_H_20191001
#define COMPLEX_H_20191001

#include <sstream>

struct Complex {
    Complex();
Complex(const double real);
    Complex(const double real, const double imaginary);
    Complex& operator=(const Complex& drob);
    Complex(const Complex& drob);
    bool operator==(const Complex& rhs) const;
    bool operator!=(const Complex& rhs) const;
    Complex& operator+=(const Complex& rhs);
    Complex& operator+=(const double rhs);
    Complex& operator-=(const Complex& rhs);
    Complex& operator-=(const double rhs);
    Complex& operator*=(const Complex& rhs);
    Complex& operator*=(const double rhs);
    Complex& operator/=(const Complex& rhs);
    Complex& operator/=(const double rhs);
    const double eps = std::numeric_limits<double>::epsilon();
    double re { 0.0 };
    double im { 0.0 };
};

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& rhs);
std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs);

std::istream& operator>>(std::istream& istrm, Complex& rhs);

#endif  // COMPLEX_H_20191001
