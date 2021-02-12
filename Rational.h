#ifndef LINAL_RATIONAL_H
#define LINAL_RATIONAL_H

#include <numeric>
#include <iostream>

class Rational {
public:
    int num, den;
    void normalize() {
        int d = std::gcd(num, den);
        num /= d;
        den /= d;
    }
    Rational() {
        num = 0;
        den = 1;
        normalize();
    }
    Rational(int _numerator) {
        num = _numerator;
        den = 1;
        normalize();
    }
    Rational(int _numerator, int _denominator) {
        if (_denominator < 0) {
            _numerator *= -1;
            _denominator *= -1;
        }
        num = _numerator;
        den = _denominator;
        normalize();
    }
    Rational operator+(const Rational &b) const {
        int lcm = std::lcm(den, b.den);
        return Rational(num * (lcm / den)
                        + b.num * (lcm / b.den), lcm);
    }
    Rational operator-() const {
        return Rational(-num, den);
    }
    Rational operator+() const {
        return Rational(num, den);
    }
    Rational operator-(const Rational &b) const {
        return Rational::operator+(-b);
    }
    Rational operator*(const Rational &b) const {
        return Rational(num * b.num, den * b.den);
    }
    Rational operator/(const Rational &b) const {
        return Rational::operator*(Rational(b.den, b.num));
    }
    Rational operator+(const int &x) const {
        return Rational::operator+(Rational(x));
    }
    Rational operator-(const int &x) const {
        return Rational::operator-(Rational(x));
    }
    Rational operator*(const int &x) const {
        return Rational::operator*(Rational(x));
    }
    Rational operator/(const int &x) const {
        return Rational::operator/(Rational(x));
    }
    int numerator() const {
        return num;
    }
    int denominator() const {
        return den;
    }
    Rational& operator+=(const Rational &b) {
        *this = Rational::operator+(b);
        return *this;
    }
    Rational& operator*=(const Rational &b) {
        *this = Rational::operator*(b);
        return *this;
    }
    Rational& operator-=(const Rational &b) {
        *this = Rational::operator-(b);
        return *this;
    }
    Rational& operator/=(const Rational &b) {
        *this = Rational::operator/(b);
        return *this;
    }
    Rational& operator++() {
        *this = Rational::operator+(1);
        return *this;
    }
    Rational operator++(int) {
        Rational c = *this;
        *this = Rational::operator+(1);
        return c;
    }
    Rational& operator--() {
        *this = Rational::operator-(1);
        return *this;
    }
    Rational operator--(int) {
        Rational c = *this;
        *this = Rational::operator-(1);
        return c;
    }
    bool operator==(const Rational &b) const {
        return num == b.num && den == b.den;
    }
    bool operator!=(const Rational &b) const {
        return !Rational::operator==(b);
    }
};

Rational operator+(const int &x, const Rational &b) {
    return Rational(x).operator+(b);
}
Rational operator-(const int &x, const Rational &b) {
    return Rational(x).operator-(b);
}
Rational operator*(const int &x, const Rational &b) {
    return Rational(x).operator*(b);
}
Rational operator/(const int &x, const Rational &b) {
    return Rational(x).operator/(b);
}

std::ostream& operator <<(std::ostream &out, const Rational &a) {
    out << a.num << '/' << a.den;
    return out;
}

#endif //LINAL_RATIONAL_H
