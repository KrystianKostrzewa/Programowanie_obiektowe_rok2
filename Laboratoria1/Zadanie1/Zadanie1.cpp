#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int func(int tab[]);
void bSort(int tab[], int n);
void createOddTable(int tab[], int n);

int main()
{
    srand(time(0));
    int table[100]{};

    cout << "Punkt 2:\n";
    for (int i = 0; i < 100; i++)
    {
        table[i] = 20 + rand() % 181;
        cout << table[i] << ", ";
    }

    cout << endl << endl << "Punkt 3:";
    int x = func(table);
    cout << "\nIndeks najwiekszej wartosci: " << x;
    cout << "\nNajwieksza wartosc: " << table[x] << endl;

    cout << endl << "Punkt 4:" << endl;
    int* wsk1 = &table[x];
    cout << "Wskaznik do elementu tablicy o indeksie x: " << wsk1;
    cout << "\nWskaznik zmiennej x: " << &x << endl;

    cout << endl << "Punkt 5:" << endl;
    bSort(table, 100);
    for (int i = 0; i < 100; i++)
    {
        cout << table[i] << ", ";
    }

    cout << endl << endl << "Punkt 6:" << endl;
    createOddTable(table, 100);

    return 0;
}

int func(int tab[])
{
    int index = 0;
    int MaxValue = 0;
    for (int i = 0; i < 100; i++)
    {
        if (tab[i] > MaxValue)
        {
            index = i;
            MaxValue = tab[i];
        }
    }
    return index;
}

void bSort(int tab[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (tab[j] < tab[j + 1]) swap(tab[j], tab[j + 1]);
        }
    }
}

void createOddTable(int tab[], int n)
{
    int oddCounter = 0;
    for (int i = 0; i < n; i++)
    {
        if (tab[i] % 2 == 0) oddCounter++;
    }

    int* oddTab = new int[oddCounter];
    int tempCounter = 0;

    for (int i = 0; i < n; i++)
    {
        if (tab[i] % 2 == 0)
        {
            oddTab[tempCounter] = tab[i];
            tempCounter++;
        }
    }
    for (int i = 0; i < tempCounter; i++)
    {
        cout << oddTab[i] << ", ";
    }

    delete[] oddTab;
}