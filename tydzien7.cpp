// ConsoleApplication39.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <vector>

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
		if (tab[i] < a)
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
std::vector<int>unikalny(std::vector<int>tab)
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

std::vector < std::vector<int>>czestosc(std::vector<int>tab)
{
	std::vector<std::vector<int>>wynik;
	std::vector<int>u=unikalny(tab);
	std::vector<int>c;
	int licznik = 0;
	for (int i = 0; i < u.size(); i++)
	{
		int element = u[i];
		for (int j = 0; j < tab.size(); j++)
		{
			if (element == tab[j])
			{
				licznik++;
			}
		}
		c.push_back(licznik);
	}
	wynik.push_back(u);
	wynik.push_back(c);
	return wynik;
}

int main()
{
	int element;
	std::cin >> element;
	std::vector<int>tab = { 8, 3, 1, 8, 2, 5, 3, 1, 8 };
	std::vector<int>tab2 = { 4,5,8 };
	std::vector<int>dom = { 1,2,5,7,8,9,11 };
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
	wypisz(unikalny(tab));
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
