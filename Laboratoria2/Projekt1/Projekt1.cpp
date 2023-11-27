#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Student
{
private:
    string name;
    string surname;
    string field;
    int year;

public:
    Student()
    {
        name = "";
        surname = "";
        field = "";
        year = 0;
    }

    Student(string n, string s, string f, int y)
    {
        name = n;
        surname = s;
        field = f;
        year = y;
    }

    string get_name()
    {
        return name;
    }

    string get_surname()
    {
        return surname;
    }

    string get_field()
    {
        return field;
    }

    int get_year()
    {
        return year;
    }

    void new_surname(string newSurname)
    {
        surname = newSurname;
    }

};

class Group
{
private:
    int groupNumber;
    const int places = 10;
    Student* students = new Student[places];
    int currentSize = 0;

public:
    Group(int n)
    {
        groupNumber = n;
    }

    void write_out()
    {
        cout << "****Grupa nr: " << groupNumber << "***";
        cout << endl << "Lista studentow:" << endl;
        for (int i = 0; i < currentSize; i++)
        {
            cout <<  i+1 << ". " << students[i].get_name() << " " << students[i].get_surname() << ", "
                 << students[i].get_field() << ", rok " << students[i].get_year() << endl;
        }
    }

    void add_student(Student student)
    {
        if (currentSize < places)
        {
            students[currentSize] = student;
            currentSize++;
            cout << "Dodano studenta " <<  student.get_name() <<" do grupy.\n";
        }
        else cout << "Grupa pełna.\n";
    }

    void change_surname(int index, string newSurname)
    {
        students[index].new_surname(newSurname);
    }

    ~Group()
    {
        delete[] students;
    }
};

int main()
{
    //a)
    Student* student1 = new Student("Jan", "Kowalski", "Matematyka", 2);
    Student table[2] =
    {
        Student("Andrzej", "Piaseczny", "Informatyka", 3),
        Student("Monika", "Kociolek", "Cyberbespieczenstwo", 1)
    };
    
    cout << "***DANE STUDENTOW***" << endl;
    cout << "1. " << student1->get_name() << " " << student1->get_surname() << ", "
        << student1->get_field() << ", rok " << student1->get_year() << "," << endl;

    for(int i = 0; i<2; i++)
    {
        cout << i+2 << ". " << table[i].get_name() << " " << table[i].get_surname() << ", "
             << table[i].get_field() << ", rok " << table[i].get_year() << "," << endl;
    }

    //b)
    Group group1(1);
    cout << endl;
    group1.add_student(*student1);
    group1.add_student(table[0]);
    group1.add_student(table[1]);

    cout << endl;
    group1.write_out();

    //c)
    cout << endl;
    group1.change_surname(1, "Pszczola");
    group1.write_out();

        
    delete student1;
    return 0;
}
