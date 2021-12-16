#include "pch.h"
#include <iostream>
#include <vector>
#include <map>
#include <ctime>

void wypisz(int w)
{
	std::cout << w << "\n";
}

void wypisz(std::vector<int>tab)
{
	for (int i = 0; i < tab.size(); i++)
	{
		std::cout << tab[i] << " ";
	}
}

void wypisz(std::map<int, int>m)
{
	for (auto const& item : m)
	{
		std::cout << item.first << " : " << item.second << "\n";
	}
}

bool czyNalezy(std::vector<int>tab, int element)
{
	for (int i = 0; i < tab.size(); i++)
	{
		if (tab[i] == element)
		{
			return true;
		}
	}
	return false;
}

bool czyNalezyKlucz(std::map<int, int>m, int klucz)
{
	for (auto const& item : m)
	{
		if (item.first == klucz)
			return true;
	}
	return false;
}
bool palindrom(std::vector<int>tab)
{
	int koniec = tab.size() - 1;
	for (int i = 0; i < tab.size() / 2; i++)
	{
		if (tab[i != tab[koniec - i]])
		{
			return false;
		}
	}
	return true;
}
int min(std::vector<int>tab)
{
	int a = tab[0];
	for (int i = 0; i < tab.size(); i++)
	{
		if (a > tab[i])
		{
			a = tab[i];
		}
	}
	return a;
}
int max(std::vector<int>tab)
{
	int a = tab[0];
	for (int i = 0; i < tab.size(); i++)
	{
		if (a < tab[i])
		{
			a = tab[i];
		}
	}
	return a;
}
bool czyZawiera(std::vector<int>tab, std::vector<int>podzbior)
{
	for (int i = 0; i < podzbior.size(); i++)
	{
		if (!czyNalezy(tab, podzbior[i]))
		{
			return false;
		}
	}
	return true;
}
std::vector<int>unikalnosc(std::vector<int>tab)
{
	std::vector<int>wynik;
	for (int i = 0; i < tab.size(); i++)
	{
		if (!czyNalezy(wynik, tab[i]))
		{
			wynik.push_back(tab[i]);
		}
	}
	return wynik;
}
std::map<int, int>czestosc(std::vector<int>tab)
{
	std::map<int, int>wynik;
	for (int i = 0; i < tab.size(); i++)
	{
		if (!czyNalezyKlucz(wynik, tab[i]))
		{
			wynik.insert({ tab[i], 1 });
		}
		else
		{
			wynik[tab[i]]++;
		}
	}
	return wynik;
}

std::vector<int>podzielnosc(std::vector<int>tab, int dzielnik = 50, int reszta = 0)
{
	std::vector<int>wynik;
	for (int i = 0; i < tab.size(); i++)
	{
		if (tab[i] % dzielnik == reszta)
		{
			wynik.push_back(tab[i]);
		}
	}
	return wynik;
}

std::vector<int>generuj(int dlugosc = 10, int min = 0, int max = 50)
{
	std::vector<int>wynik;
	for (int i = 0; i < dlugosc; i++)
	{
		wynik.push_back(rand() % (max - min + 1) + min);
	}
	return wynik;
}

void linia(int wielkosc=5)
{
	for (int i = 0; i < wielkosc; i++)
	{
		std::cout << "*\n";
	}
}
void schodki(int wielkosc = 5)
{
	for (int i = 0; i <=wielkosc; i++)
	{
		for (int j = 0; j < i; j++)
		{
			std::cout << "*";
		}
		std::cout << "\n";
	}
}

int main()
{
	std::vector<int>tab = { 1,1,2,2,3,3,4,4,4,9 };
	std::vector<int>tab2 = { 1,1,2,2};
	std::map<int, int>mapa;
	mapa.insert({ 1, 2 });
	mapa.insert({ 2, 4 });
	mapa.insert({ 3, 1 });
	srand(time(NULL));
	wypisz(generuj(10, 0, 10));
	std::cout << "\n";
	wypisz(podzielnosc(tab, 3));
	wypisz(czestosc(tab));
	std::cout << "\n";
	wypisz(unikalnosc(tab));
	std::cout << "\n";
	wypisz(min(tab));
	wypisz(max(tab));
	std::cout << "\n";
	if (czyNalezy(tab, 1))
		std::cout << "tak\n";
	else
		std::cout << "nie \n";
	if(czyNalezyKlucz(mapa, 1))
		std::cout << "tak\n";
	else
		std::cout << "nie\n";
	if (czyZawiera(tab, tab2))
		std::cout << "tak\n";
	else
		std::cout << "nie\n";
	if(palindrom(tab2))
		std::cout << "tak\n";
	else
		std::cout << "nie\n";
	int a,b;
	std::cout << "Podaj dlugosc wektora\n";
	std::cin >> a;
	std::vector<int>wygenerowany=generuj(a);
	wypisz(podzielnosc(wygenerowany, 7));
	std::cout << "Podaj dlugosc lini\n";
	std::cin >> b;
	linia(b);
	schodki(b);
	std::cout << "\n";
}
