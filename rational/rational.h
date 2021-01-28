// "Copyright 2019 <Khachatryan A.A.>"

#ifndef RATIONAL_H_20191001
#define RATIONAL_H_20191001

#include<sstream>

class Rational {
 public:
    Rational();
    explicit Rational(const int value);
    Rational(const int new_numerator, const int new_denominator);
    Rational& operator=(const Rational& drob);
    Rational(const Rational& drob);
    int Numerator() const;
    int Denominator() const;
    Rational& operator+=(const Rational& rhs);
    Rational& operator+=(const int rhs);
    Rational& operator-=(const Rational& rhs);
    Rational& operator-=(const int rhs);
    Rational& operator*=(const Rational& rhs);
    Rational& operator*=(const int rhs);
    Rational& operator/=(const Rational& rhs);
    Rational& operator/=(const int rhs);
    static long long Gcd(long long a, long long b);
 private:
    void Evaluate(int _numerator, int _denominator);
    int numerator{ 0 };
    int denominator{ 1 };
};

Rational operator-(const Rational& a);
Rational operator+(const Rational& a, const Rational& b);
Rational operator -(const Rational& a, const Rational& b);
bool operator ==(const Rational& a, const Rational& b);
bool operator !=(const Rational& a, const Rational& b);
bool operator<(const Rational& a, const Rational& b);
bool operator>(const Rational& a, const Rational& b);
bool operator>=(const Rational& a, const Rational& b);
bool operator<=(const Rational& a, const Rational& b);
Rational operator *(const Rational& a, const Rational& b);
Rational operator /(const Rational& a, const Rational& b);
std::istream& operator>>(std::istream& stream, Rational& tmp);
std::ostream& operator<<(std::ostream& stream, const Rational& tmp);

#endif  // RATIONAL_H_20191001