#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "rozmiar.h"
#define ROZ_UKL (ROZMIAR + 1)
/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class UkladRownanLiniowych
{
  Wektor tablica[ROZ_UKL]; //połączona macierz współczynników i wyrazów wolnych, dla Gaussa łatwiej operować na całości
public:

  Wektor &operator[](int ind)
  { //set
    if (ind < 0 || ind > ROZ_UKL)
    {std::cout<<ind<<std::endl;
      std::cerr << "Przekroczenie zakresu" << std::endl;
      exit(1);
    }
    return tablica[ind];
  }
  const Wektor &operator[](int ind) const
  { //get
  
    if (ind < 0 || ind > ROZ_UKL)
    { std::cout<<ind<<std::endl;
      std::cerr << "Przekroczenie zakresu" << std::endl;
      exit(1);
    }
    return tablica[ind];
  }
  
};

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream &operator>>(std::istream &Strm, UkladRownanLiniowych &UklRown);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream &operator<<(std::ostream &Strm,
                         const UkladRownanLiniowych &UklRown);

#endif
