#include "pch.h"
#include <iostream>
#include <vector>

void wypisz(int w)
{
	std::cout << w;
}
void wypisz(std::vector<int>tab)
{
	for (int i = 0; i < tab.size(); i++)
	{
		std::cout << tab[i] << " ";
	}
	std::cout << "\n";
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
int suma(int a, int b)
{
	return a + b;
}
int main()
{
	int x, y, i;
	x = 5;
	y = 3;
	i = 0;
	wypisz(suma(x, y));
	std::cout << "\n";
	std::vector<int>tab = { 1, 3, 5 };
	std::vector<int>tab2 = { 3, 5};
	std::cout << tab[i++] << " " << tab[i++] << " " << tab[i++] << "\n";
	wypisz(tab);
	if (czyNalezy(tab, 3))
	{
		std::cout << "Nalezy\n";
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
}
