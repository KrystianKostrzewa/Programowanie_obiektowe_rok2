#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
    class Student
    {
    public:
        string name;
        string surname;
        string fieldOfStudy;
        int yearOfStudy;
        int term;

        Student(string n, string s, string f, int y, int t)
            : name(n), surname(s), fieldOfStudy(f), yearOfStudy(y), term(t) {}
    };

    Student students[3] = {
        Student("Krystian", "Kostrzewa", "Informatyka Techniczna", 2, 3),
        Student("Kacper", "Kamien", "Inżynieria Metali", 3, 5),
        Student("Michalina", "Dom", "Matematyka", 1, 1)
    };

    cout << "Imie: " << students[0].name << endl;
    cout << "Nazwisko: " << students[0].surname << endl;
    cout << "Kierunek studiow: " << students[0].fieldOfStudy << endl;
    cout << "Rok studiow: " << students[0].yearOfStudy << endl;
    cout << "Semestr: " << students[0].term;

    return 0;
}

    