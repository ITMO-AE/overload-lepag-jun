#include <rational.h>
#include <cassert>

Rational::Rational()
{
    numerator = 0;
    denominator = 1;
}

Rational::Rational(int numerator_in, int denominator_in)
{
    if(denominator < 0)
    {
        if(numerator < 0)
        {
            numerator_in = abs(numerator_in);
            denominator_in = abs(denominator_in);
        }
    }

    if(numerator_in == 0)
        denominator_in = 1;

    int nod = NOD(numerator_in, denominator_in);
    numerator = numerator_in / nod;
    denominator = denominator_in / nod;
}

bool operator == (const Rational& a, const Rational& b)
    {
        if((a.Numerator() == b.Numerator()) && (a.Denominator() == b.Denominator()))
                return true;
        else
            return false;
    }

Rational operator +(const Rational& a, const Rational& b)
{
    int p = (a.Numerator() * b.Denominator()) + (b.Numerator() * a.Denominator());
    int q = (a.Denominator() * b.Denominator());
    return Rational(p, q);
}

Rational operator -(const Rational& a, const Rational& b)
{
    int p = (a.Numerator() * b.Denominator()) - (b.Numerator() * a.Denominator());
    int q = (a.Denominator() * b.Denominator());
    return Rational(p, q);
}

Rational operator *(const Rational& a, const Rational& b)
{
    return Rational((a.Numerator() * b.Numerator()), (a.Denominator() * b.Denominator()));
}

Rational operator /(const Rational& a, const Rational& b)
{
    return Rational((a.Numerator() * b.Denominator()), (a.Denominator() * b.Numerator()));
}

ostream& operator <<(ostream& out, const Rational& r)
{
    return out << r.numerator << "/" << r.denominator;
}

istream& operator >>(istream& in, Rational& r)
{
    int p;
    int q;
    if(in >> p && in.ignore(1) && in >> q)
        r = {p, q};
    return in;
}
