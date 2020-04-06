#include "UkladRownanLiniowych.hh"

std::istream &operator>>(std::istream &strWej, UkladRownanLiniowych &U)
{/*
   Macierz M;
    for (int i = 0; i < ROZMIAR; i++)
        strWej >> M[i];
    M.transponuj_macierz();//to trzeba będzie gdzieś przenieść (albo i nie, do przemyślenia)   SKASUJ KOMENTARZ JAK SKOŃCZYSZ!!!
    */for (int i = 0; i < ROZMIAR; i++)
        strWej >> U[i];
    strWej >> U[ROZMIAR];
    return strWej;
}

std::ostream &operator<<(std::ostream &strWyj, const UkladRownanLiniowych &U)
{
    for (int i = 0; i < ROZMIAR; i++)
        std::cout << U[i] << std::endl;
    std::cout << std::endl
              << U[ROZMIAR] << std::endl;
    return strWyj;
}