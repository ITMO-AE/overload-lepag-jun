#ifndef RATIONAL_H
#define RATIONAL_H

#include <sstream>

using std::ostream;
using std::istream;

class Rational
{
public:
    Rational();
    Rational(int numerator, int denominator);

    int Numerator() const
    {
        return numerator;
    }
    int Denominator() const
    {
        return denominator;
    }

private:
    friend bool operator == (const Rational& a, const Rational& b);

    friend Rational operator +(const Rational& a, const Rational& b);
    friend Rational operator -(const Rational& a, const Rational& b);
    friend Rational operator *(const Rational& a, const Rational& b);
    friend Rational operator /(const Rational& a, const Rational& b);

    friend ostream& operator <<(ostream& out, const Rational& r);
    friend istream& operator >>(istream& in, Rational& r);

    int numerator;
    int denominator;

    int NOD(int a, int b)
    {
        if(b == 0)
            return a;
        return NOD(b, a % b);
    }
};

#endif // RATIONAL_H
