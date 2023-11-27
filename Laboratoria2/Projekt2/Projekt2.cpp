#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Passenger
{
private:
    string name;
    string surname;
    int birthYear;

public:
    static int counter;

    Passenger()
    {
        name = "imie";
        surname = "nazwisko";
        birthYear = 1111;
        counter ++;
    }

    Passenger(string n, string s, int y)
    {
        name = n;
        surname = s;
        birthYear = y;
        counter++;
    }

    Passenger(const Passenger& base)
    {
        name = base.name;
        surname = base.surname;
        birthYear = base.birthYear;
        cout << "Wykonano konstruktor kopiujacy." << endl;
        counter++;
    }

    string get_name()
    {
        return name;
    }

    string get_surname()
    {
        return surname;
    }

    int get_birth_year()
    {
        return birthYear;
    }

    int get_counter()
    {
        return counter;
    }
};

int Passenger::counter = 0;

class Bus
{
private:
    string destination;
    int vMax;
    const int places = 10;
    Passenger* list[10]{};
    int amountOfPassengers = 0;
    
public:
    Bus(string d, int v)
    {
        destination = d;
        vMax = v;
    }

    Bus(const Bus& base)
    {
        destination = base.destination;
        vMax = base.vMax;
        amountOfPassengers = base.amountOfPassengers;
        for (int i = 0; i < amountOfPassengers; i++)
        {
            list[i] = new Passenger(*base.list[i]);
        }
    }

    void add_passenger(Passenger& base)
    {
        if (amountOfPassengers < places)
        {
            list[amountOfPassengers] = &base;
            amountOfPassengers++;
        }
        else
        {
            cout << endl << "Autokar jest juz pelny." << endl;
        }
    }

    int check_free_places()
    {
        if (amountOfPassengers < places) return 1;
        else return 0;
    }

    void write_out()
    {
        cout << endl << "DANE AUTOKARU JADACEGO DO " << destination << endl
             << "Predkosc maksymana autkaru: " << vMax << "km/h" << endl
             << "Lista pasazerow: " << endl;
        for (int i = 0; i < amountOfPassengers; i++)
        {
            cout << "Pasazer " << i + 1 << ": " << list[i]->get_name() << " " << list[i]->get_surname() << ", urodzony w roku " << list[i]->get_birth_year() << endl;
        }
        cout << "WOLNE MIEJSCA: " << places - amountOfPassengers << endl << endl;
    }

    void delete_passenger(int index)
    {
        if (index >= 0 && index < amountOfPassengers)
        {
            delete list[index];
            for (int i = index; i < amountOfPassengers - 1; i++)
            {
                list[i] = list[i + 1];
            }
            list[amountOfPassengers - 1] = nullptr;
            amountOfPassengers--;
        }
    }
};



int main()
{
    //a)
    Passenger passenger0;
    Passenger passenger1("Jan", "Kowalski", 1983);
    Passenger passenger2(passenger1);
    
    cout << "Pasazer 1 = " << passenger0.get_name() << " " << passenger0.get_surname() << ", urodzony w roku " << passenger0.get_birth_year() << endl
         << "Pasazer 2 = " << passenger1.get_name() << " " << passenger1.get_surname() << ", urodzony w roku " << passenger1.get_birth_year() << endl
         << "Pasazer 3 = " << passenger2.get_name() << " " << passenger2.get_surname() << ", urodzony w roku " << passenger2.get_birth_year() << endl;

    //b)
    cout << endl << "Licznik przed definicja tablicy dynamicznej: " << passenger0.get_counter();
    Passenger* dynamic_table = new Passenger[100];
    cout << endl << "Licznik po definicji tablicy dynamicznej: " << passenger0.get_counter() << endl;

    //c)
    Bus myBus("Berlin", 130);

    myBus.add_passenger(passenger0);
    myBus.add_passenger(passenger1);
    myBus.add_passenger(passenger2);

    for (int i = 0; i < 100; i++)
    {
        dynamic_table[i] = Passenger("Freddy", "Fazbear" + to_string(i), 1923 + i);
    }

    int freePlaceChecker = 1;
    for (int i = 0; i < sizeof(dynamic_table); i++)
    {
        freePlaceChecker = myBus.check_free_places();
        if(freePlaceChecker == 1) myBus.add_passenger(dynamic_table[i]);
        else
        {
            cout << endl << "Autokar jest juz pelny." << endl;
            break;
        }
    }

    cout << "Informacje o myBus" << endl;
    myBus.write_out();

    //d)
    Bus myBus2(myBus);
    cout << endl << "Informacje o myBus2";
    myBus.write_out();

    myBus2.delete_passenger(0);
    myBus2.delete_passenger(1);
    myBus2.delete_passenger(2);

    cout << "Informacje o myBus2";
    myBus2.write_out();

    //e)
    cout << endl << "Licznik przed usunieciem dynamicznej tablicy pasazerow: " << passenger0.get_counter();
    delete[] dynamic_table;
    cout << endl << "Licznik po usunieciu dynamicznej tablicy pasazerow: " << passenger0.get_counter();
    return 0;
}