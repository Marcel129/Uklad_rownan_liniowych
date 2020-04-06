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
        strWyj << W[i] << "\t";
    return strWyj;
}