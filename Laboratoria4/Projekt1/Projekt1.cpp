#include <iostream>
#include <cstdlib>

using namespace std;

class Fraction;

Fraction sum_fractions(Fraction x, Fraction y);

class Fraction
{
private:
    int numerator;
    int denominator;

    friend Fraction sum_fractions(Fraction x, Fraction y);

public:
    Fraction(int a, int b) :
        numerator(a),
        denominator(b) {}

    Fraction(int a) :
        numerator(a),
        denominator(1) {}

    operator double()
    {
        return static_cast<double>(numerator) / static_cast<double>(denominator);
    }

    int nwd()
    {
        int a = numerator;
        int b = denominator;
        while (a != b)
        {
            while (a != b)
            {
                if (a > b)
                    a = a - b;
                else
                    b = b - a;
            }
        }
        return a;
    }

    Fraction reduce_fraction()
    {
        Fraction temp(0,0);
        int x = nwd();
        temp.numerator = numerator / x;
        temp.denominator = denominator / x;
        return temp;
    }

    void print_fraction()
    {
        cout << numerator << "/" << denominator;
    }
};

Fraction sum_fractions(Fraction x, Fraction y)
{
    int new_den = x.denominator * y.denominator;
    int new_num = x.numerator * y.denominator + y.numerator * x.denominator;
    return Fraction(new_num, new_den).reduce_fraction();
}

double fraction_square(double x)
{
    return x * x;
}

int main()
{

    //a
    cout << "PODPUNKT A" << endl;
    Fraction table[3] = { Fraction(1,2), Fraction(5,8), Fraction(7,9) };
    for (int i = 0; i < size(table); i++)
    {
        table[i].print_fraction();
        cout << ", ";
    }

    //b
    cout << endl << "PODPUNKT B" << endl;
    sum_fractions(table[0], table[1]).print_fraction();

    //c
    cout << endl << "PODPUNKT C" << endl;
    sum_fractions(table[0], 7).print_fraction();

    //d
    cout << endl << "PODPUNKT D" << endl;
    cout << fraction_square(table[2]);

    //e
    cout << endl << "PODPUNKT E" << endl;
    Fraction fract = Fraction(88 / 22);
    fract.reduce_fraction().print_fraction();
    return 0;
}