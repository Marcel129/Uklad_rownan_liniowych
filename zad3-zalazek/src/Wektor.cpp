#include "Wektor.hh"

std::istream &operator>>(std::istream &strWej, Wektor &W)
{
    for (int i = 0; i < ROZMIAR; i++)
        strWej >> W[i];
    return strWej;
}

std::ostream &operator<<(std::ostream &strWyj, const Wektor &W)
{
    for (int i = 0; i < ROZMIAR; i++)
    {
        strWyj <<std::setw(MIEJSCE)<<std::setprecision(PRECYZJA)<< W[i];
        if (i + 1 < ROZMIAR)
            strWyj << "\t";
    }
    return strWyj;
}

double dlugosc_wektora(const Wektor W)
{
    double dl = 0;
    for (int a = 0; a < ROZMIAR; ++a)
        dl += W[a] * W[a];
    dl = sqrt(dl);
    return dl;
}