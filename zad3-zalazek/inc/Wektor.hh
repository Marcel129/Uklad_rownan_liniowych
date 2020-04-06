
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

  const double &operator[](int ind) const //get
  {
    if (ind < 0 || ind > ROZMIAR)
    {std::cout<<ind<<std::endl;
      std::cerr << "Przekroczenie zakresu" << std::endl;
      exit(1);
    }
    return tablica[ind];
  }

  double &operator[](int ind) //set
  {
    if (ind < 0 || ind > ROZMIAR)
    {std::cout<<ind<<std::endl;
      std::cerr << "Przekroczenie zakresu" << std::endl;
      exit(1);
    }
    return tablica[ind];
  }
  Wektor operator*(double mnoznik)
  { //mnozenie wektora przez liczbe
    Wektor W(tablica);
    if (mnoznik != 0)
    {
      for (int i = 0; i < ROZMIAR; ++i)
        W.tablica[i] *= mnoznik;
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
  Wektor operator-(const Wektor &W2) //odejmowanie dwoch wektorow  (działa na kolumnach)
  {
    Wektor W(tablica);
    for (int i = 0; i < ROZMIAR; ++i)
      W.tablica[i] -= W2.tablica[i];

    return W;
  }
};

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream &operator>>(std::istream &Strm, Wektor &W);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream &operator<<(std::ostream &Strm, const Wektor &W);

#endif
