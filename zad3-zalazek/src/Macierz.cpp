#include "Macierz.hh"
#include "rozmiar.h"

std::fstream &operator>>(std::fstream &strWej, Macierz &M)
{
    Wektor tab[ROZMIAR];
    for (int i = 0; i < ROZMIAR; i++)
        strWej >> tab[i];
    M.wpisz_wektory(tab);
    return strWej;
}

std::ostream &operator<<(std::ostream &strWyj, const Macierz &M)
{
    const Wektor *tab; //wskaźnik pomocniczy
    tab = M.zwroc_macierz();
    for (int i = 0; i < ROZMIAR; i++)
        std::cout << tab[i] << std::endl;
    return strWyj;
}

void Macierz::transponuj_macierz()
{
    double tab[ROZMIAR][ROZMIAR];
    Wektor tab_wek[ROZMIAR];

    for (int i = 0; i < ROZMIAR; i++)//kopiuje wczytaną macierz do tablicy 
    {
        for (int j = 0; j < ROZMIAR; j++)
            tab[i][j] = tablica[j][i];
        tab_wek[i] = tab[i];//tworzę z niej tablice wektorów
    }
    wpisz_wektory(tab_wek);// wykorzystuje metode klasy podstawiajac nową tablice wektorów w miejsce starej macierzy
}