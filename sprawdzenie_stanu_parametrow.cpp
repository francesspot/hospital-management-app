#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include "generator_pacjentow.hpp"

using namespace std;

bool Zakres::wZakresie(int wartosc) const
{
  if (wartosc >= min && wartosc <= max)
  {
    return 1;
  }
  else 
  {
    return 0;
  }
}

void sprawdzStanParametrow(vector<PacjentDane>& pacjenci, ofstream& raport)
{
    Zakres zakres_cS, zakres_cR, zakres_tetno, zakres_utl, zakres_cukier, zakres_temp;
    int liczbaOsobNiepoprawnych = 0;

    for (const auto& p : pacjenci) 
    {
      if (p.wiek < 1) { // niemowlę
          zakres_cS = {60, 90}; zakres_cR = {30, 60}; zakres_tetno = {100, 160};
          zakres_utl = {90, 100}; zakres_temp = {360, 375}; zakres_cukier = {60, 100};
      } else if (p.wiek < 12) { // dziecko
          zakres_cS = {90, 110}; zakres_cR = {55, 75}; zakres_tetno = {75, 120};
          zakres_utl = {92, 100}; zakres_temp = {360, 380}; zakres_cukier = {70, 110};
      } else if (p.wiek < 18) { // nastolatek
          zakres_cS = {100, 120}; zakres_cR = {65, 80}; zakres_tetno = {60, 100};
          zakres_utl = {94, 100}; zakres_temp = {360, 380}; zakres_cukier = {70, 110};
      } else if (p.wiek < 65) { // dorosły
          zakres_cS = {110, 130}; zakres_cR = {70, 85}; zakres_tetno = {60, 100};
          zakres_utl = {95, 100}; zakres_temp = {355, 385}; zakres_cukier = {70, 125};
      } else { // senior
          zakres_cS = {110, 140}; zakres_cR = {70, 90}; zakres_tetno = {60, 100};
          zakres_utl = {93, 100}; zakres_temp = {355, 380}; zakres_cukier = {70, 140};
      }

      vector<string> nieprawidloweParametry;

      if (!zakres_cS.wZakresie(p.cisnienie_skurczowe))
        nieprawidloweParametry.push_back("Ciśnienie skurczowe");
      if (!zakres_cR.wZakresie(p.cisnienie_rozkurczowe))
        nieprawidloweParametry.push_back("Ciśnienie rozkurczowe");
      if (!zakres_tetno.wZakresie(p.tetno))
        nieprawidloweParametry.push_back("Tętno");
      if (!zakres_utl.wZakresie(p.utlenienie))
        nieprawidloweParametry.push_back("Utlenienie");
      if (!zakres_cukier.wZakresie(p.poziom_cukru))
        nieprawidloweParametry.push_back("Poziom cukru");
      if (!zakres_temp.wZakresie(p.temperatura))
        nieprawidloweParametry.push_back("Temperatura ciała");

    if (!nieprawidloweParametry.empty())
    {
        liczbaOsobNiepoprawnych += 1;
        int ilosc = nieprawidloweParametry.size();
        stringstream linia;
        linia << p.pesel << " " << p.imie << " " << p.nazwisko << " - parametry poza zakresem: ";

        for (int i = 0; i < ilosc; i++)
        {
            linia << nieprawidloweParametry[i];
            if (i != ilosc-1)
            {
                linia << ", ";
            } else
            {
                linia << "!";
            }
        }
        cout << linia.str() << endl;
        raport << linia.str() << "\n";

    }
  }
  
  if(liczbaOsobNiepoprawnych == 0)
  {
    cout << "Brak pacjentów z nieprawidłowymi parametrami." << endl;
    raport << "Brak pacjentów z nieprawidłowymi parametrami.";
  }
}

int sprawdzenieStanuParametrow() 
{

    srand(time(0));

    vector<PacjentDane> pacjenci;
    const string nazwaPliku = "pacjenci.txt";
    const string plikBadanieParametrow = "stan_parametrow.txt";

    wczytajPacjentow(nazwaPliku, pacjenci);

    ofstream raport(plikBadanieParametrow);
        if(!raport)
        {
            cerr << "Nie ma takiego pliku!\n";
            return 1;
        }

    sprawdzStanParametrow(pacjenci, raport);

    raport.close();
    return 0;
}
