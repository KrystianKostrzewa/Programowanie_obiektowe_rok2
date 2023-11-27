#include <iostream>
#include <cstdlib>

#define TAB_LEN 10

using namespace std;

int main()
{
    int tab[TAB_LEN] = { 1, -1, -2, 1, 1, 2, 3, -5, -7, 11};
    int result[2]{};

    int positiveCounter = 0;
    int negativeSum = 0;


    for (int i = 0; i < TAB_LEN; i++)
    {
        if (tab[i] > 0) positiveCounter++;

        if (tab[i] < 0) negativeSum += tab[i];
    }

    result[0] = positiveCounter;
    result[1] = negativeSum;

    cout << result[0] << endl << result[1];

    return 0;
}
