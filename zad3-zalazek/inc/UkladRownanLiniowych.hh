#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "rozmiar.h"

class UkladRownanLiniowych
{
  
  Wektor W;                //wektor wyrazów wolnych
  Macierz M;               //macierz współczynników
  Wektor R;                //wektor rozwiązań układu

public:
  UkladRownanLiniowych(){};
  UkladRownanLiniowych(Macierz MM, Wektor WW)
  {
    M = MM;
    W = WW;
  };

  void wstawWektor(Wektor wek) { W = wek; }
  const Wektor &wezWektor() const { return W; }

  void wpiszRoz(Wektor wek) { R = wek; }
  const Wektor &wezRoz() const { return R; }

  void wstawMacierz(Macierz mac) { M = mac; }
  const Macierz &wezMacierz() const { return M; }

  void Oblicz();
  double Blad() const;
};

std::istream &operator>>(std::istream &Strm, UkladRownanLiniowych &UklRown);
std::ostream &operator<<(std::ostream &Strm, const UkladRownanLiniowych &UklRown);

#endif
