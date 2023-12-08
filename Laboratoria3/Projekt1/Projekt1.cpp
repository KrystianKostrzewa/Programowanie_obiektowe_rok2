#include <iostream>
#include <cstdlib>
#include <cmath>
#include <random>

#define SMALL_VALUE 0.005
#define table1_size 10000

using namespace std;

class Point;
class Segment;
class Circle;
void wypisz(Point A);
void wypisz(Segment AB);
void wypisz(Circle C);

class Point
{
private:
    int x;
    int y;

    friend class Segment;
    friend class Circle;
    friend void wypisz(Point A);
    friend void wypisz(Segment AB);
    friend void wypisz(Circle C);

public:
    Point()
    {
        x = 0;
        y = 0;
    }

    Point(int a, int b)
    {
        x = a;
        y = b;
    }

    int check_equality(Point A)
    {
        if (x == A.x && y == A.y) return 1;
        else return 0;
    }
};

class Segment
{
private:
    Point start;
    Point finish;

    friend void wypisz(Segment AB);

public:
    Segment():
        start(0, 0),
        finish(0, 0) {}

    Segment(int xs, int ys, int xf, int yf):
        start(xs, ys),
        finish(xf, yf) {}

    Segment(Point A, Point B) :
        start(A.x, A.y),
        finish(B.x, B.y) {}

    double segment_length()
    {
        double length = sqrt(pow(start.x- finish.x, 2) + pow(start.y - finish.y, 2));
        return length;
    }
};

class Circle
{
private:
    Point centre;
    int radius;

    friend void wypisz(Circle C);

public:
    Circle() :
        centre(0, 0),
        radius(0) {}

    Circle(Point c, int r) :
        centre(c),
        radius(r) {}

    Circle(int x, int y, int r) :
        centre(x, y),
        radius(r) {}

    int check_contact(Circle circle0) 
    {
        Segment centres(centre, circle0.centre);
        double centresDistance = centres.segment_length();

        if (fabs(fabs(radius - circle0.radius) - centresDistance) < SMALL_VALUE) return 1; // styczne wewnetrznie 
        else if (fabs((radius + circle0.radius) - centresDistance) < SMALL_VALUE) return 2; //styczne zewnetrznie
        else return 0; //niestyczne
    }
};

void wypisz(Point A)
{
    cout << endl << "Wspolrzedne punktu to: x = " << A.x << ", y = " << A.y << "." << endl;
}

void wypisz(Segment AB)
{
    cout << endl << "Wspolrzedne koncow odcinka to: A(" << AB.start.x << ", " << AB.start.y << ") oraz B(" << AB.finish.x << ", " << AB.finish.y << ")." << endl;
    cout << "A jego dlugosc wynosi: " << AB.segment_length() << "." << endl;
}

void wypisz(Circle C)
{
    cout << endl << "Wspolrzedne srodka okregu to: x = " << C.centre.x << ", y = " << C.centre.y << "." << endl;
    cout << "Promien okregu wynsi: " << C.radius << "." << endl;
}

int main()
{
    //a
    Segment table[3] = { Segment(Point(-4,1),Point(6,1)),
                        Segment(Point(0,6),Point(1,1)),
                        Segment(Point(3,8),Point(-3,-2)) };

    //b
    for (int i = 0; i < size(table); i++)
    {
        cout << "Dlugosc odcinka " << i + 1 << " = " << table[i].segment_length() << endl;
    }

    //c
    srand(time(NULL));
    Circle circle0(0,0,6);
    Circle table1[table1_size]{};
    int insideCounter = 0;
    int outsideCounter = 0;

    for (int i = 0; i < table1_size; i++)
    {
        table1[i] = Circle(rand() % 41 - 20, rand() % 41 - 20, rand() % 20 + 1);
    }

    //d
    for (int i = 0; i < table1_size; i++)
    {
        if (circle0.check_contact(table1[i]) == 1) insideCounter++;
        else if (circle0.check_contact(table1[i]) == 2) outsideCounter++;
    }

    cout << endl << "Styczne wewnetrznie: " << insideCounter;
    cout << endl << "Styczne zewnetrznie: " << outsideCounter << endl; 
    

    //e
    Point A(4, 5);
    Segment AB(0, 4, 3, 0);
    Circle O(6, 7, 8);

    wypisz(A);
    wypisz(AB);
    wypisz(O);

    return 0;
}
