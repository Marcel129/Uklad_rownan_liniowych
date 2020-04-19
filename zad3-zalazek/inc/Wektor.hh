
#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

class Wektor
{
  double tablica[ROZMIAR];

public:
  Wektor(){};
  Wektor(double moja_tab[])
  {
    for (int i = 0; i < ROZMIAR; i++)
      tablica[i] = moja_tab[i];
  }

  const double &operator[](int ind) const //get
  {
    if (ind < 0 || ind > ROZMIAR)
    {
      std::cout << ind << std::endl;
      std::cerr << "Przekroczenie zakresu" << std::endl;
      exit(1);
    }
    return tablica[ind];
  }

  double &operator[](int ind) //set
  {
    if (ind < 0 || ind > ROZMIAR)
    {
      std::cout << ind << std::endl;
      std::cerr << "Przekroczenie zakresu" << std::endl;
      exit(1);
    }
    return tablica[ind];
  }

  Wektor operator*(double mnoznik)//mnozenie wektora przez liczbe
  { 
    Wektor W(tablica);

    for (int i = 0; i < ROZMIAR; ++i)
      W.tablica[i] *= mnoznik;

    return W;
  }

  Wektor operator/(double dzielnik)//dzielenie wektora przez liczbe
  { 
    Wektor W(tablica);
    if (dzielnik != 0)
    {
      for (int i = 0; i < ROZMIAR; ++i)
        W.tablica[i] /= dzielnik;
    }
    else
    {
      std::cout << "Błąd:dzielenie przez 0" << std::endl;
      exit(1);
    }
    return W;
  }

  Wektor operator+(const Wektor &W2) //dodawanie dwoch wektorow
  {
    Wektor W(tablica);
    for (int i = 0; i < ROZMIAR; ++i)
      W.tablica[i] += W2.tablica[i];

    return W;
  }
  
  Wektor operator-(const Wektor &W2) //odejmowanie dwoch wektorow
  {
    Wektor W(tablica);
    for (int i = 0; i < ROZMIAR; ++i)
      W.tablica[i] -= W2.tablica[i];

    return W;
  }
};
double dlugosc_wektora(const Wektor W);
std::istream &operator>>(std::istream &Strm, Wektor &W);
std::ostream &operator<<(std::ostream &Strm, const Wektor &W);

#endif
