// nauka.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "nauka.h"

void wypisz(int a)
{
    std::cout << a << "\n";
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
int min(std::vector<int>tab)
{
    int a = tab[0];
    for (int i = 0; i < tab.size(); i++)
    {
        if (tab[i] < a)
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
        if (tab[i] > a)
        {
            a = tab[i];
        }
    }
    return a;
}
bool czyNalezy(int element, std::vector<int>tab)
{
    for (int i = 0; i < tab.size(); i++)
    {
        if (tab[i] == element)
            return true;
    }
    return false;
}
bool czyZawiera(std::vector<int>tab, std::vector<int>podzbior)
{
    for (int i = 0; i < podzbior.size(); i++)
    {
        if (!czyNalezy(podzbior[i], tab))
            return false;
    }
    return true;
}
std::vector<int>unikalny(std::vector<int>tab)
{
    std::vector<int>wynik;
    for (int i = 0; i < tab.size(); i++)
    {
        if (!czyNalezy(tab[i], wynik))
        {
            wynik.push_back(tab[i]);
        }
    }
    return wynik;
}

std::vector<std::vector<int>>ileWystapien(std::vector<int>tab)
{
    std::vector<std::vector<int>>wynik;
    std::vector<int>liczby = unikalny(tab);
    std::vector<int>zliczone;
    int licznik=0;
    int element;
    for (int i = 0; i < liczby.size(); i++)
    {
        element = liczby[i];
        for(int j=0;j<tab.size();j++)
            if (element == tab[j])
            {
                licznik++;
            }
        zliczone.push_back(licznik);
        licznik = 0;
    }
    wynik.push_back(liczby);
    wynik.push_back(zliczone);
    return wynik;
}

int main()
{
    int w = 5;
    std::vector<int>tab = { 4,4,4,5,3,3,4,7,4};
    std::vector<int>tab2 = {4,5,3};
    wypisz(w);
    wypisz(tab);
    wypisz(min(tab));
    wypisz(max(tab));
    wypisz(unikalny(tab));
    std::cout << "\n";
    wypisz(ileWystapien(tab));
    std::cout << "\n";
   if (czyNalezy(3, tab))
    {
        std::cout << "tak \n";
    }
    else
        std::cout << "nie \n";
    if (czyZawiera(tab, tab2))
    {
        std::cout << "Zawiera \n";
    }
    else
        std::cout << "Nie zawiera \n";
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
