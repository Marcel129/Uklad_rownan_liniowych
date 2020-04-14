#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"
#include "rozmiar.h"

using namespace std;
/*zaczęta implementacja eliminacji Gaussa, narazie roboczo wszystko w mainie, docelowo będzie to przeniesione do układu równań*/
int main()
{
  UkladRownanLiniowych UklRown; // To tylko przykladowe definicje zmiennej
  fstream baza_pytan;
  baza_pytan.open("/home/mracel/Pulpit/baza_danych.txt", ios::in);
  if (baza_pytan.good() == false)
  {
    cout << "Błąd otwarcia pliku. Koniec działania programu" << endl;
    exit(1);
  }

  cout << endl
       << " Start programu  " << endl
       << endl;
  //baza_pytan >> UklRown;

  Wektor wektor_wyr_woln;
  Macierz mac_wsp;
  baza_pytan >> mac_wsp;
  baza_pytan >> wektor_wyr_woln;

  cout << "Wczytane wspolczynniki ukladu rownan:" << endl
       << mac_wsp << endl;

  cout << "Wektor wyrazów wolnych:" << endl
       << wektor_wyr_woln << endl;
  //mac_wsp.transponuj_macierz();
  /*
  for (int k = 0; k < 2; k++)
  {
    double tab[ROZMIAR][ROZMIAR];
    Wektor tab_wek[ROZMIAR];

    for (int i = 1; i < ROZMIAR; i++) //zaczynam od drugiego wiersza
    {
      for (int j = 0; j < ROZMIAR; j++)
      {
        if (mac_wsp[k][k] != 0)
          tab[i + k][j + k] = mac_wsp[i + k][j + k] - (mac_wsp[i + k][k] / mac_wsp[k][k]) * mac_wsp[k][j + k];
        else
        {
          cerr << "Błąd: dzielenie przez 0" << endl;
          exit(1);
        }
      }
      for (int a = 0; a <= k; a++)
        tab_wek[a] = mac_wsp[a];

      if (i + k < ROZMIAR)
      { //nie przekraczamy zakresu

        tab_wek[i + k] = tab[i + k];
      }
    }
    mac_wsp = Macierz(tab_wek);
  }
  
    ETAP 1
    double dzielnik = UklRown[0][0];
    for (int i = 0; i < ROZ_UKL; ++i)
      UklRown[i][0] /= dzielnik;
    
    ETAP 2

    for (int k = 1; k < ROZMIAR; ++k)
    {
      for (int i = 0; i < ROZMIAR; ++i)
        UklRown[i][k] = UklRown[i][k] - UklRown[i][0] * UklRown[i][k];
    }
  

  cout << "Uklad po pierwszej operacji:" << endl
       << UklRown << endl; 
  cout << "Wektor wyrazow wolnych" << endl
       << wektor_wyr_woln << endl;*/
}
