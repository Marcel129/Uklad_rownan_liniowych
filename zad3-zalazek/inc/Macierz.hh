#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include "Wektor.hh"
#include <iostream>

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Macierz
{
  Wektor tablica[ROZMIAR];

public:
  Macierz(){};
  Macierz(Wektor tab[])
  {
    for (int i = 0; i < ROZMIAR; i++)
      tablica[i] = tab[i];
  };
  void wpisz_wektory(Wektor *tab)
  {
    for (int i = 0; i < ROZMIAR; i++)
      tablica[i] = *(tab + i);
  }
  Wektor const *zwroc_macierz(void) const
  {
    return tablica;
  }
  Wektor const *zwroc_wektor(int ind) const
  {
    return tablica + ind;
  }
  const Wektor operator[](int ind) const
  {
    if (ind < 0 || ind > ROZMIAR)
    {
      std::cerr << "Przekroczenie zakrestu tablicy" << std::endl;
      exit(1);
    }
    return tablica[ind];
  }
  void transponuj_macierz(void);
};

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::fstream &operator>>(std::fstream &Strm, Macierz &Mac);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream &operator<<(std::ostream &Strm, const Macierz &Mac);

#endif
