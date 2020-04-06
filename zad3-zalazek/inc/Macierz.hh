#include "rozmiar.h"
#ifndef MACIERZ_HH
#define MACIERZ_HH

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
  Wektor & operator[](int ind){//set
        if (ind < 0 || ind > ROZMIAR)
        {std::cout<<ind<<std::endl;
            std::cerr << "Przekroczenie zakresu" << std::endl;
            exit(1);
        }
        return tablica[ind];
    }
    const Wektor & operator[](int ind)const{//get
        if (ind < 0 || ind > ROZMIAR)
        {std::cout<<ind<<std::endl;
            std::cerr << "Przekroczenie zakresu" << std::endl;
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
std::istream &operator>>(std::istream &Strm, Macierz &Mac);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream &operator<<(std::ostream &Strm, const Macierz &Mac);

#endif
