#include "UkladRownanLiniowych.hh"

std::istream &operator>>(std::istream &strWej, UkladRownanLiniowych &U)
{
    Macierz M;
    Wektor W;

    strWej >> M;
    M.transponuj_macierz(); //wczytaj macierz w postaci wierszowej
    strWej >> W;

    UkladRownanLiniowych url(M, W);
    U = url;
    return strWej;
}

std::ostream &operator<<(std::ostream &strWyj, const UkladRownanLiniowych &U)
{
    for (int i = 0; i < ROZMIAR; ++i)
    { //użyte funkcje setw,setprecision oraz showpos regulują precyzję wyświetlanych liczb oraz rozkład układu
        std::cout << '|' << U.wezMacierz()[i] << "||" << std::setprecision(PRECYZJA) << std::setw(MIEJSCE) << U.wezWektor()[i] << '|';

        ((ROZMIAR % 2 == 0 && i == ROZMIAR / 2) || (ROZMIAR % 2 == 1 && (i) == ROZMIAR / 2)) ? std::cout << std::setw(MIEJSCE / 2) << std::setfill(' ')
                                                                                                         << "=" << std::setw(MIEJSCE / 2 + MIEJSCE % 2) << std::setfill(' ')
                                                                                             : std::cout << std::setw(MIEJSCE);

        std::cout << '|' << std::showpos << std::setprecision(PRECYZJA) << std::setw(MIEJSCE) << U.wezRoz()[i] << std::noshowpos << '|' << "(x" << i + 1 << ')' << std::endl;
    }
    return strWyj;
}

void UkladRownanLiniowych::Oblicz()
{
    double wyz_g = M.wyz_gauss(); //oblicz wyznacznik główny macierzy
    if (wyz_g != 0)
    {
        M.transponuj_macierz(); //zmień układ macierzy na kolumnowy, aby móc zamieniać kolumny z wektorem wyrazów wolnych

        for (int i = 0; i < ROZMIAR; ++i)
        {
            std::swap(M[i], W);           //podmieniaj kolejne kolumny na wektor wyrazów wolnych
            R[i] = M.wyz_gauss() / wyz_g; //oblicz wyznacznik powstałej macierzy i podziel go przez wyznacznik główny, otrzymując kolejne pierwiastki równania
            std::swap(M[i], W);           //zamień wektory spowrotem, aby móc podmienić następne kolumny macierzy
        }
        M.transponuj_macierz(); //przywróć macierz współczynników do postaci wejściowej
    }
    else
    {
        std::cout << "Zerowy wyznacznik macierzy.Obliczenie niemożliwe." << std::endl;
        exit(1);
    }
}

double UkladRownanLiniowych::Blad() const
{
    double blad;
    blad = dlugosc_wektora(M * R - W);
    return blad;
}
