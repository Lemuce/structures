// "Copyright 2019 <Khachatryan A.A.>"
#include <complex/complex.h>

Complex::Complex() {}

Complex::Complex(const double real): Complex(real, 0.0) {}

Complex::Complex(const double real, const double imaginary)
    : re(real)
    , im(imaginary)
    {}

Complex& Complex::operator=(const Complex& lhs) {
    re = lhs.re;
    im = lhs.im;
    return *this;
}

Complex::Complex(const Complex& lhs)
    : re(lhs.re)
    , im(lhs.im)
    {}

bool Complex::operator==(const Complex& rhs) const {
    return (fabs(re - rhs.re)<=Complex::eps) && (fabs(im - rhs.im)<=Complex::eps);
}

bool Complex::operator!=(const Complex& rhs) const {
    return !operator==(rhs);
}

Complex& Complex::operator+=(const Complex& rhs) {
    re += rhs.re;
    im += rhs.im;
    return *this;
}

Complex& Complex::operator+=(const double rhs) {
    return operator+=(Complex(rhs));
}

Complex& Complex::operator-=(const Complex& rhs) {
    re -= rhs.re;
    im -= rhs.im;
    return *this;
}

Complex& Complex::operator-=(const double rhs) {
    return operator-=(Complex(rhs));
}

Complex& Complex::operator*=(const double rhs) {
    re *= rhs;
    im *= rhs;
    return *this;
}

Complex& Complex::operator*=(const Complex& rhs) {
    *this = (*this) * rhs;
    return *this;
}

Complex& Complex::operator/=(const double rhs) {
    *this = (*this) / Complex(rhs);
    return *this;
}

Complex& Complex::operator/=(const Complex& rhs) {
    *this = (*this) / rhs;
    return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs) {
    Complex sum(lhs);
    sum += rhs;
    return sum;
}

Complex operator-(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}

Complex operator*(const Complex& lhs, const Complex& rhs) {
    double re, im;
    re = lhs.re * rhs.re - lhs.im * rhs.im;
    im = lhs.re * rhs.im + lhs.im * rhs.re;
    return Complex( re, im );
}

Complex operator/(const Complex& lhs, const Complex& rhs) {
    if (rhs.im == 0 && rhs.re == 0) throw std::invalid_argument("");
    Complex tmp;
    tmp.re = (lhs.re * rhs.re + lhs.im * rhs.im) /
        (rhs.re * rhs.re + rhs.im * rhs.im);
    tmp.im = (lhs.im * rhs.re - lhs.re * rhs.im) /
        (rhs.re * rhs.re + rhs.im * rhs.im);
    return tmp;
}

Complex operator-(const Complex& rhs) {
    return { -rhs.re,-rhs.im };
}

std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) {
    ostrm << '{' << rhs.re << ',' << rhs.im << '}';
    return ostrm;
}

std::istream& operator>>(std::istream& istrm, Complex& rhs) {
    double re, im; char leftbr, rightbr, dif;
    istrm >> leftbr >> re >> dif >> im >> rightbr;
    if (istrm.good()) {
        if (leftbr == '{' && dif == ',' && rightbr == '}') {
            rhs = { re, im };
        }
        else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}
