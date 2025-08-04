#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include "generator_pacjentow.hpp"

using namespace std;

void sprawdzPoprawnoscParametrow(vector<PacjentDane>& pacjenci, ofstream& raport)
{
    Zakres zakres_cS, zakres_cR, zakres_tetno, zakres_utl, zakres_cukier, zakres_temp;
    int liczbaOsobzBledami = 0;

    for (const auto& p : pacjenci) 
    {
      if (p.wiek < 1) { // niemowlę
          zakres_cS = {30, 160}; zakres_tetno = {60, 220};
      } else if (p.wiek < 12) { // dziecko
          zakres_cS = {50, 180}; zakres_tetno = {40, 180};
      } else if (p.wiek < 18) { // nastolatek
          zakres_cS = {60, 200}; zakres_tetno = {30, 160};
      } else if (p.wiek < 65) { // dorosły
          zakres_cS = {70, 250}; zakres_tetno = {30, 150};
      } else { // senior
          zakres_cS = {80, 230}; zakres_tetno = {35, 140};
      }
    // zakresy niezależne od wieku
    zakres_cR = {15, 200}; zakres_utl = {70, 100}; zakres_temp = {300, 420}; zakres_cukier = {20, 1000};


    vector<string> nierealneParametry;

      if (!zakres_cS.wZakresie(p.cisnienie_skurczowe))
        nierealneParametry.push_back("Ciśnienie skurczowe");
      if (!zakres_cR.wZakresie(p.cisnienie_rozkurczowe))
        nierealneParametry.push_back("Ciśnienie rozkurczowe");
      if (!zakres_tetno.wZakresie(p.tetno))
        nierealneParametry.push_back("Tętno");
      if (!zakres_utl.wZakresie(p.utlenienie))
        nierealneParametry.push_back("Utlenienie");
      if (!zakres_cukier.wZakresie(p.poziom_cukru))
        nierealneParametry.push_back("Poziom cukru");
      if (!zakres_temp.wZakresie(p.temperatura))
        nierealneParametry.push_back("Temperatura ciała");

    if (!nierealneParametry.empty())
    {
        liczbaOsobzBledami += 1;
        int ilosc = nierealneParametry.size();
        stringstream linia;
        linia << p.pesel << " " << p.imie << " " << p.nazwisko << " - nierealne parametry: ";

        for (int i = 0; i < ilosc; i++)
        {
            linia << nierealneParametry[i];
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
  
  if(liczbaOsobzBledami == 0)
  {
    cout << "Brak pacjentów z nierealnymi parametrami." << endl;
    raport << "Brak pacjentów z nierealnymi parametrami.";
  }
}

int sprawdzeniePoprawnosci() 
{

    srand(time(0));

    vector<PacjentDane> pacjenci;
    const string nazwaPliku = "pacjenci.txt";
    const string plikNieprawidlowe = "nieprawidlowosci.txt";

    wczytajPacjentow(nazwaPliku, pacjenci);

    ofstream raport(plikNieprawidlowe);
        if(!raport)
        {
            cerr << "Nie ma takiego pliku!\n";
            return 1;
        }

    sprawdzPoprawnoscParametrow(pacjenci, raport);

    raport.close();
    return 0;
}
