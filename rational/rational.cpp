// "Copyright 2019 <Khachatryan A.A.>"

#include<sstream>
#include<cmath>
#include<rational/rational.h>

Rational::Rational() {}

Rational::Rational(const int value)
    : numerator(value)
    , denominator(1)
    {}


Rational::Rational(const int new_numerator, const int new_denominator) {
    if (new_denominator == 0) {
        throw std::invalid_argument("Invalid argument");
    }
    if (new_numerator == 0) {
        denominator = 1;
        numerator = 0;
    }
    else {
        Evaluate(new_numerator, new_denominator);
    }
}

Rational& Rational::operator= (const Rational& drob) {
    numerator = drob.numerator;
    denominator = drob.denominator;
    return *this;
}


Rational::Rational(const Rational& drob)
    :numerator(drob.numerator)
    , denominator(drob.denominator)
    {}

int Rational::Numerator() const {
    return numerator;
}

int Rational::Denominator() const {
    return denominator;
}

long long Rational::Gcd(long long a, long long b) {
    if (b == 0)
        return a;
    else
        return Gcd(b, a % b);
}

Rational& Rational::operator+=(const Rational& rhs) {
    int del = Rational::Gcd(Denominator(), rhs.Denominator());
    int mn1 = Denominator() / del;
    int mn2 = rhs.Denominator() / del;
    Evaluate(Numerator() * abs(mn2) + rhs.Numerator() * abs(mn1),
        abs(mn1 * rhs.Denominator()));
    return *this;
}

Rational& Rational::operator-=(const Rational& rhs) {
    int del = Rational::Gcd(Denominator(), rhs.Denominator());
    int mn1 = Denominator() / del;
    int mn2 = rhs.Denominator() / del;
    Evaluate(Numerator() * abs(mn2) - rhs.Numerator() * abs(mn1),
        abs(mn1 * rhs.Denominator()));
    return *this;
}

Rational& Rational::operator+=(const int rhs) {
    Rational tmp(rhs);
    (*this) += tmp;
    return *this;
}

Rational& Rational::operator-=(const int rhs) {
    Rational tmp(rhs);
    (*this) -= tmp;
    return *this;
}

Rational& Rational:: operator *=(const Rational& rhs) {
    Evaluate(Numerator() * rhs.Numerator(), Denominator() * rhs.Denominator());
    return *this;
}

Rational& Rational:: operator /=(const Rational& rhs) {
    if (rhs.numerator == 0) throw std::domain_error("Division by zero");
    Evaluate(Numerator() * rhs.Denominator(), Denominator() * rhs.Numerator());
    return *this;
}

Rational& Rational::operator *=(const int rhs) {
    Rational tmp(rhs);
    (*this) *= tmp;
    return *this;
}

Rational& Rational::operator /=(const int rhs) {
    if (rhs == 0) throw std::domain_error("Division by zero");
    Rational tmp(rhs);
    (*this) /= tmp;
    return *this;
}

void Rational::Evaluate(int _numerator, int _denominator) {
    int del = Rational::Gcd(_numerator, _denominator);
    _numerator /= del;
    _denominator /= del;
    numerator = ((_numerator < 0 && _denominator > 0)
        || (_numerator > 0 && _denominator < 0))
        ? -abs(_numerator) : abs(_numerator);
    denominator = abs(_denominator);
}

Rational operator+(const Rational& a, const Rational& b) {
    int del = Rational::Gcd(a.Denominator(), b.Denominator());
    int mn1 = a.Denominator() / del;
    int mn2 = b.Denominator() / del;
    return { a.Numerator() * abs(mn2) + b.Numerator() * abs(mn1),
        abs(mn1 * b.Denominator()) };
}

Rational operator -(const Rational& a, const Rational& b) {
    int del = Rational::Gcd(a.Denominator(), b.Denominator());
    int mn1 = a.Denominator() / del;
    int mn2 = b.Denominator() / del;
    return { a.Numerator() * abs(mn2) - b.Numerator() * abs(mn1),
        abs(mn1 * b.Denominator()) };
}

bool operator ==(const Rational& a, const Rational& b) {
    if (a.Numerator() == b.Numerator()
        && a.Denominator() == b.Denominator()) return true;
    return false;
}

bool operator !=(const Rational& a, const Rational& b) {
    if (a.Numerator() != b.Numerator()
        || a.Denominator() != b.Denominator()) return true;
    return false;
}

bool operator<(const Rational& a, const Rational& b) {
    return (a - b).Numerator() < 0;
}

bool operator<=(const Rational& a, const Rational& b) {
    return (a - b).Numerator() <= 0;
}

bool operator>(const Rational& a, const Rational& b) {
    return (a - b).Numerator() > 0;
}

bool operator>=(const Rational& a, const Rational& b) {
    return (a - b).Numerator() >= 0;
}

Rational operator *(const Rational& a, const Rational& b) {
    return { a.Numerator() * b.Numerator(),
        a.Denominator() * b.Denominator() };
}

Rational operator /(const Rational& a, const Rational& b) {
    if (b.Numerator() == 0) {
        throw std::domain_error("Division by zero");
    }
    return { a.Numerator() * b.Denominator(),
        a.Denominator() * b.Numerator() };
}

std::istream& operator>>(std::istream& stream, Rational& tmp) {
    int num, den; 
    stream >> num;

    if (stream.peek() == '/') {
        stream.ignore(1);
        if (stream.peek() <= '9' && stream.peek() >= '0') {
            stream >> den;
            tmp = { num, den };
            return stream;
        }

    }
    stream.setstate(std::ios_base::failbit);    
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const Rational& tmp) {   
    stream << tmp.Numerator() << "/" << tmp.Denominator();
    return stream;
}

Rational operator-(const Rational& a) {
    return { -a.Numerator(), a.Denominator() };
}