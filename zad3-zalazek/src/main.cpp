#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"
#include "rozmiar.h"

using namespace std;

int main(int argc, char **argv)
{

  if (argc < 2)
  {
    cout << endl;
    cout << "Nie wskazano pliku z bazą danych." << endl;
    exit(1);
  }

  fstream baza_pytan;
  baza_pytan.open(argv[1], ios::in);

  if (baza_pytan.good() == false)
  {
    cout << "Błąd otwarcia pliku. Koniec działania programu" << endl;
    exit(1);
  }

  cout << endl
       << " Start programu  " << endl
       << endl;

  UkladRownanLiniowych UklRown;
  baza_pytan >> UklRown;
  UklRown.Oblicz();

  cout << UklRown << endl
       << endl;
  cout << "Błąd obliczeń wynosi: " << UklRown.Blad() << endl
       << endl;
}
