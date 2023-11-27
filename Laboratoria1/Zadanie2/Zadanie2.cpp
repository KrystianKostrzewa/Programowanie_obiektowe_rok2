#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
	string text = "L0s0w3 l1cz3y n4 prz7k14d 123\n";
	int* digits = new int[text.length() - 1];
	int digitsCounter = 0;
	int digitsSum = 0;

	for (int i = 0; i < text.length() - 1; i++)
	{
		if (isdigit(text[i]))
		{
			digitsSum = digitsSum + int(text[i] - '0');
		}
	}

	cout << digitsSum;
	delete[] digits;

	return 0;
}