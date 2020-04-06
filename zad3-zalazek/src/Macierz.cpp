#include "Macierz.hh"

std::istream &operator>>(std::istream &strWej, Macierz &M)
{
    for (int i = 0; i < ROZMIAR; i++)
        strWej >> M[i];
    return strWej;
}

std::ostream &operator<<(std::ostream &strWyj, const Macierz &M)
{
    for (int i = 0; i < ROZMIAR; i++)
        std::cout << M[i] << std::endl;
    return strWyj;
}

void Macierz::transponuj_macierz()
{
    for (int i = 0; i < ROZMIAR; i++)//kopiuje wczytaną macierz do tablicy 
    {
        for (int j = i; j < ROZMIAR; j++)
            std::swap(tablica[i][j],tablica[j][i]);
    }
}