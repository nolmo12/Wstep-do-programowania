// wyklad4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <map>
#include <ctime>
#include <limits>

void wypisz(std::vector<int>tab)
{
	for (int i = 0; i < tab.size(); i++)
	{
		std::cout << tab[i]<<"\n";
	}
}

int potega(int a, int b)
{
	int wynik = a;
	for (int i = 1; i < b; i++)
	{
		wynik=wynik*a;
	}
	return wynik;
}

std::vector<int>generuj(int dlugosc = 10, int min = 0, int max = 50)
{
	std::vector<int>wynik;
	for (int i = 0; i < dlugosc; i++)
	{
		wynik.push_back(rand() % (max - min) + min+1);
	}
	return wynik;
}
int dlugoscCiagu(std::vector<int>tab, int n, int x)
{
	int wynik = 0;
	int licznik = 0;
	for (int i = 0; i < tab.size(); i++)
	{
		if (wynik < licznik)
		{
			wynik = licznik;
		}
		if (tab[i] > n && tab[i] % x == 0)
		{
			licznik++;
		}
		else
		{
			licznik = 0;
		}
	}
	return wynik;
}
int suma(std::vector<int>tab)
{
	int wynik = 0;
	int x=0;
	for (int i = 0; i < tab.size(); i++)
	{
		for (int j = i; j < tab.size(); j++)
		{
			 x= x + tab[i];
		}
		if (wynik < x)
		{
			wynik = x;
		}
	}
	return wynik;
}

bool czyPierwsza(int liczba)
{
	if (liczba == 0 || liczba == 1)
	{
		return false;
	}
	if (liczba == 2)
	{
		return true;
	}
	for (int i = 2; i < liczba; i++)
	{
		if (liczba % i == 0)
		{
			return false;
		}
	}
	return true;
}

std::vector<int>wypisanieLiczbPierwszych(int n)
{
	std::vector<int>wynik;
	int max = INT_MAX;
	int licznik=0;
	for (int i = 0; i < max; i++)
	{
		if (czyPierwsza(i))
		{
			wynik.push_back(i);
			licznik++;
		}
		if (licznik == n)
		{
			return wynik;
		}
	}
}

int main()
{
	srand(time(NULL));
	int unsigned a=5;
	int liczba1, liczba2;
	liczba1 = 4;
	liczba2 = 5;
	int signed b=-33;
	double c=2.5;
	float d=3.334;
	char e='a';
	std::string f= "Ala ma kota";
	bool g = true;
	std::vector<int>tab = {1,2,3,4,5};
	std::vector<int>tab2 = {3,6,9,11,13,14,15,18,21,24,25};
	std::vector<int>tab3 = { 2,-3,6 };
	std::map<int, int > mapa;
	std::cout<<potega(liczba1,liczba2);
	std::cout << "\n";
	/*wypisz(generuj(5, 10, 20));
	choinka(5);
	schodki(5);*/
	//std::cout<<dlugoscCiagu(tab2, 2, 3);
	//std::cout<< suma(tab3);
	wypisz(wypisanieLiczbPierwszych(5));

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
