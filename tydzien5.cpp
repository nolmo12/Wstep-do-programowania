#include "pch.h"
#include <iostream>
#include <vector>

void wypisz(int w)
{
	std::cout << w << "\n";
}
void wypisz(std::vector<int>tab)
{
	for (int i = 0; i <tab.size() ;i++)
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
int Min(std::vector<int>tab)
{
	int a;
	a = tab[0];
	for (int i = 0; i < tab.size(); i++)
	{
		if(tab[i]<a)
		{
			a = tab[i];
		}
	}
	return a;
}
int Max(std::vector<int>tab)
{
	int a;
	a = tab[0];
	for (int i = 0; i < tab.size(); i++)
	{
		if (tab[i] > a)
		{
			a = tab[i];
		}
	}
	return a;
}
int suma(int a, int b)
{
	return a + b;
}
int main()
{
	int element;
	std::cin >> element;
	std::vector<int>tab = { 2, 3,4,6, 5,20,8 };
	std::vector<int>tab2 = { 4,5,8 };
	std::vector<int>dom = {1,2,5,7,8,9,11};
	wypisz(tab);
	if (czyNalezy(tab, element))
	{
		std::cout << "tak\n";
	}
	else
	{
		std::cout << "Nie\n";
	}
	if (czyZawiera(tab, tab2))
	{
		std::cout << "tak2\n";
	}
	else
	{
		std::cout << "nie2\n";
	}
	wypisz(Min(dom));
	wypisz(Max(dom));
}
