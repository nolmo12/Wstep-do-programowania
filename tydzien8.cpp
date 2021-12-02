#include "pch.h"
#include <iostream>
#include <vector>
#include<map>

void wypisz(int w)
{
	std::cout << w<<"\n";
}

void wypisz(std::vector<int>tab)
{
	for (int i = 0; i < tab.size(); i++)
	{
		std::cout << tab[i] << " ";
	}
}

void wypisz(std::vector<std::vector<int>>tab)
{
	for (int i = 0; i < tab[0].size(); i++)
	{
		std::cout << tab[0][i] << " ";
		std::cout << tab[1][i] << " ";
	}
}

bool czyNalezy(std::vector<int>tab, int element)
{
	for (int i = 0; i < tab.size(); i++)
	{
		if (tab[i] == element)
			return true;
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

bool czyZawiera(std::vector<int>tab, std::vector<int>podzbior)
{
	for (int i = 0; i < podzbior.size(); i++)
	{
		if (!czyNalezy(tab, podzbior[i]))
			return false;
	}
	return true;
}

int min(std::vector<int>tab)
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
int max(std::vector<int>tab)
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

std::vector<std::vector<int>>czestotliwosc(std::vector<int>tab)
{
	int licznik=0;
	std::vector<std::vector<int>>wynik;
	std::vector<int>liczby=unikalnosc(tab);
	std::vector<int>ileLiczb;
	int element;
	for (int i=0;i<liczby.size();i++)
	{
		element = liczby[i];
		for (int j = 0; j < tab.size(); j++)
			if (element == tab[j])
			{
				licznik++;
			}
		ileLiczb.push_back(licznik);
			licznik=0;
	}
	wynik.push_back(liczby);
	wynik.push_back(ileLiczb);
	return wynik;
}

std::map<int, int>czestosc(std::vector<int>tab)
{
	std::map<int, int>wynik;
	for (int i = 0; i < tab.size(); i++)
	{
		if (!czyNalezyKlucz(wynik, tab[i]))
		{
			wynik.insert({tab[i], 1})
		}
		else
		{
		wynik[tab[i]]++;
		}
	}
	return wynik;
}

int main()
{

	int w = 5;
	std::vector<int>tab = { 4,4,4,3,3,2,2,5 };
	std::vector<int>tab2 = { 4,4,4 };
	wypisz(tab);
	std::cout << "\n";
	wypisz(unikalnosc(tab));
	std::cout << "\n";
	wypisz(czestotliwosc(tab));
	std::cout << "\n";
	wypisz(w);
	wypisz(min(tab));
	wypisz(max(tab));
	if (czyNalezy(tab, w))
	{
		std::cout << "nalezy\n";
	}
	else
	{
		std::cout << "Nie nalezy\n";
	}
	if (czyZawiera(tab, tab2))
	{
		std::cout << "Zawiera\n";
	}
	else
	{
		std::cout << "Nie zawiera\n";
	}
	std::map<int, int>m;
	m.insert({ 8,5 });
	m.insert({ 4,2 });
	m.insert({ -3,1 });
	m.insert({ 9,3 });
	if (czyNalezyKlucz(m, 8))
	{
		std::cout << "Nalezy klucz\n";
	}
	else
	{
		std::cout << "Nie nalezy klucz\n";
	}
}
