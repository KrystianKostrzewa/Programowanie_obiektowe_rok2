#include <iostream>
#include <cstdlib>

using namespace std;

class Zwierze
{
protected:
	string imie;
	int masa;
	int liczba_nog;

public:
	Zwierze() : imie(""), masa(0), liczba_nog(0) {}
	Zwierze(string i, int m, int l) : imie(i), masa(m), liczba_nog(l) {}

	void pokaz()
	{
		cout << "Imie: " << imie << ", masa: " << masa << "kg, liczba nog: " << liczba_nog << ". \n";
	}
};

class Pies : Zwierze
{
private:
	string rasa;
	string kolor_siersci;

public:
	Pies() : Zwierze(), rasa(""), kolor_siersci("") {}
	Pies(string i, int m, int l, string r, string k) : Zwierze(i, m, l), rasa(r), kolor_siersci(k) {}

	void pokaz()
	{
		cout << "Imie: " << Zwierze::imie << ", masa: " << Zwierze::masa << "kg, liczba nog: " <<
			Zwierze::liczba_nog << ", rasa: " << rasa << ", kolor siersci: " << kolor_siersci << "\n";
	}
};

class Papuga : Zwierze
{
	string kolor_pior;

public:
	Papuga() : Zwierze(), kolor_pior("") {}
	Papuga(string i, int m, int l, string k) : Zwierze(i, m, l), kolor_pior(k) {}
};

int main()
{
	cout << "// Podpunkt A:" << endl;
	Zwierze zwierzak1 = Zwierze("Jas", 50, 4);
	zwierzak1.pokaz();

	cout << "// Podpunkt B:" << endl;
	Pies* piesek1 = new Pies("Fasolka", 33, 4, "maltanczyk", "bialy");
	piesek1->pokaz();
	delete piesek1;

	cout << "// Podpunkt C:" << endl;

	return 0;
}
