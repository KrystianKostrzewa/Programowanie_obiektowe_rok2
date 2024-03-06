#include <iostream>
#include <cstdlib>
#include <random>
#include <cmath>

using namespace std;

class Vector
{
private:
    int x;
    int y;

public:
    Vector() : x(0), y(0) {}
    Vector(int a, int b) : x(a), y(b) {}

    friend ostream& operator<<(ostream& out, const Vector& v)
    {
        out << "[" << v.x << "," << v.y << "]";
        return out;
    }

    Vector operator+(Vector other)
    {
        Vector sum = Vector(x + other.x, y + other.y);
        return sum;
    }

    int operator*(Vector other)
    {
        int product = x * other.x + y * other.y;
        return product;
    }

    double length()
    {
        return sqrt(pow(static_cast<double>(x), 2) + pow(static_cast<double>(y), 2));
    }

    Vector nearest_from_table(Vector tab[], int size)
    {
        Vector nearest = tab[0];
        for (int i = 1; i < size; i++)
        {
            if (fabs(tab[i].length() - length()) < fabs(nearest.length() - length())) nearest = tab[i];
        }
        return nearest;
    }
};

void bSort(Vector tab[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (tab[j].length() > tab[j + 1].length()) swap(tab[j], tab[j + 1]);
        }
    }
}

int main()
{
    //a
    cout << "Podpunkt A" << endl;
    Vector vector1 = Vector(3, 5);
    Vector vector2 = Vector(-2, 7);
    cout << "Wektor 1: " << vector1 << endl << "Wektor 2: " << vector2;
    
    //b
    cout << endl << "Podpunkt B" << endl;
    cout << "vector1 + vector2 = " << vector1 + vector2;

    //c
    cout << endl << "Podpunkt C" << endl;
    cout << "vector1 * vector2 = " << vector1 * vector2;

    //d
    cout << endl << "Podpunkt D" << endl;
    srand(time(NULL));
    Vector table[20];
    for (int i = 0; i < size(table); i++)
    {
        table[i] = Vector(rand() % 31 - 15, rand() % 31 - 15);
    }
    bSort(table, 20);
    cout << endl << endl;
    for (int i = 0; i < size(table); i++)
    {
        cout << table[i] << " ";
        cout << table[i].length() << endl;
    }

    //e
    cout << endl << "Podpunkt E" << endl;
    Vector helper = vector1.nearest_from_table(table, 20);
    cout << helper << " o dlugosci: " << helper.length();

    return 0;
}
