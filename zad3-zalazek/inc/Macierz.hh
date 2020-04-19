#ifndef MACIERZ_HH
#define MACIERZ_HH
#include <iostream>
#include "rozmiar.h"
#include "Wektor.hh"

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
  Wektor &operator[](int ind) //set
  {
    if (ind < 0 || ind > ROZMIAR)
    {
      std::cout << ind << std::endl;
      std::cerr << "Przekroczenie zakresu" << std::endl;
      exit(1);
    }
    return tablica[ind];
  }

  const Wektor &operator[](int ind) const //get
  {
    if (ind < 0 || ind > ROZMIAR)
    {
      std::cout << ind << std::endl;
      std::cerr << "Przekroczenie zakresu" << std::endl;
      exit(1);
    }
    return tablica[ind];
  }

  Wektor operator*(const Wektor W) const; //mnożenie macierzy przez wektor
  void transponuj_macierz(void);
  double wyz_gauss();
};

std::istream &operator>>(std::istream &Strm, Macierz &Mac);
std::ostream &operator<<(std::ostream &Strm, const Macierz &Mac);

#endif
