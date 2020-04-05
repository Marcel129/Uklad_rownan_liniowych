#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>
#include <fstream>

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Wektor
{
  double tablica[ROZMIAR];

public:
  Wektor(){}; //kompilator krzyczy że nie zna metody jak nie ma wąsatych nawiasów
  Wektor(double moja_tab[])
  {
    for (int i = 0; i < ROZMIAR; i++)
      tablica[i] = moja_tab[i];
  }

  void podstaw_do_tablicy(double *war)
  {
    for (int i = 0; i < ROZMIAR; i++)
      tablica[i] = war[i];
  }

  double const *zwroc_tablice(void) const
  {
    return tablica;
  }
  double operator[](int ind) const
  {
    if (ind < 0 || ind > ROZMIAR)
    {
      std::cerr << "Przekroczenie zakrestu tablicy" << std::endl;
      exit(1);
    }
    return tablica[ind];
  }
  void operator/(double dzielnik)//dzielenie wektora przez liczbe
  {
    for (int i = 0; i < ROZMIAR; i++)
    {
      tablica[i] /= dzielnik;
      std::cout<<tablica[i];
    }
    std::cout<<std::endl;
  }
};

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::fstream &operator>>(std::fstream &Strm, Wektor &W);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream &operator<<(std::ostream &Strm, const Wektor &W);

#endif
