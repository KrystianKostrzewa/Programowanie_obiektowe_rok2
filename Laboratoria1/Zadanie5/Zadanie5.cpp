#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void bSort(int tab[], int n);

int main()
{
    int number = 5792901;
    string strNumber = to_string(number);
    int* digitsTab = new int[strNumber.length()];
    int multiplier = 1;
    int result = 0;

    for (int i = 0; i < strNumber.length(); i++)
    {
        digitsTab[i] = strNumber[i] - '0';
    }

    bSort(digitsTab, strNumber.length());
    
    for (int i = strNumber.length() - 1; i >= 0; i--)
    {
        result += digitsTab[i] * multiplier;
        multiplier *= 10;
    }

    cout << result;

    delete[] digitsTab;

    return 0;
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
