#include "pch.h"
#include <iostream>

int suma(int a, int b)
{
	return a+b;
}
int suma(int a, int b, int c)
{
	int wynik = suma(a, b);
	return suma(wynik, c);
}
void wypisz(int w)
{
	std::cout << w << "\n";
}
int main()
{
	int a = suma(5, 4, 3);
	wypisz(a);
	int d = suma(10, a);
	wypisz(d);
	int b;
	std::cout << "Podaj liczbe calkowita \n";
	std::cin >> b;
	if (a > b)
	{
		wypisz(a);
	}
	else
	{
		std::cout << "Ale lipa!!!";
	}
}
