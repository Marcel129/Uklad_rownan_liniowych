#include "Wektor.hh"

std::fstream &operator>>(std::fstream &strWej, Wektor &W)
{
    double tab[ROZMIAR]; //pomocnicza tablca do zebrania wektora
    for (int i = 0; i < ROZMIAR; i++)
        strWej >> tab[i];
    W.podstaw_do_tablicy(tab); //przekazuje do klasy tablice jako calosc
    return strWej;
}

std::ostream &operator<<(std::ostream &strWyj, const Wektor &W)
{
    double const *tab;                //wskaźnik pomocniczy
    tab = W.zwroc_tablice();          //pobieram tablice z klasy
    for (int i = 0; i < ROZMIAR; i++) //i ja wyswietlam
        std::cout << tab[i] << "\t";
    return strWyj;
}