#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include "generator_pacjentow.hpp"

using namespace std;

void wczytajPacjentow(const string& nazwaPliku, vector<PacjentDane>& pacjenci) 
{
    ifstream plik(nazwaPliku);
    string linia;

    if (!plik) 
    {
        cerr << "Nie można otworzyć pliku do odczytu.\n";
        return;
    }

    while (getline(plik, linia)) 
    {
        istringstream iss(linia);
        PacjentDane p;
        iss >> p.id >> p.pesel >> p.imie >> p.nazwisko >> p.wiek >> p.plec >> p.wzrost >> p.waga
        >> p.cisnienie_skurczowe >> p.cisnienie_rozkurczowe >> p.tetno >> p.utlenienie
        >> p.poziom_cukru >> p.temperatura >> p.stan;
        getline(iss >> ws, p.dolegliwosc); // ws - odczytuje do końca linii (pomijanie znaków białych (spacji) przy nazwie choroby)
        pacjenci.push_back(p);
    }
}

void zapiszPacjentow(const string& nazwaPliku, const vector<PacjentDane>& pacjenci) 
{
    ofstream plik(nazwaPliku);

    for (const auto& p : pacjenci) 
    {
        plik << p.id << " " << p.pesel << " " << p.imie << " " << p.nazwisko << " " << p.wiek << " " << p.plec << " "
        << p.wzrost << " " << p.waga << " " << p.cisnienie_skurczowe << " " << p.cisnienie_rozkurczowe << " "
        << p.tetno << " " << p.utlenienie << " " << p.poziom_cukru << " " << p.temperatura << " "
        << p.stan << " " << p.dolegliwosc << '\n';
    }
}

int aktualizujPacjentow() 
{

    srand(time(0));

    vector<PacjentDane> pacjenci;
    const string nazwaPliku = "pacjenci.txt";

    wczytajPacjentow(nazwaPliku, pacjenci);

    for (auto& p : pacjenci) {
        Pomiary npomiary;

        int znak, mnoznik;

        mnoznik = (znak = rand() % 2) == 0 ? 1 : -1;
        npomiary.set_cS((rand() % 20) * mnoznik + p.cisnienie_skurczowe);
        p.cisnienie_skurczowe = npomiary.get_cS();

        mnoznik = (znak = rand() % 2) == 0 ? 1 : -1;
        npomiary.set_cR((rand() % 20) * mnoznik + p.cisnienie_rozkurczowe);
        p.cisnienie_rozkurczowe = npomiary.get_cR();

        mnoznik = (znak = rand() % 2) == 0 ? 1 : -1;
        npomiary.set_tetno((rand() % 20) * mnoznik + p.tetno);
        p.tetno = npomiary.get_tetno();

        mnoznik = (znak = rand() % 2) == 0 ? 1 : -1;
        npomiary.set_cukier((rand() % 20) * mnoznik + p.poziom_cukru);
        p.poziom_cukru = npomiary.get_cukier();

        npomiary.set_utl(p.utlenienie);

        mnoznik = (znak = rand() % 2) == 0 ? 1 : -1;
        npomiary.set_temp((rand() % 20) * mnoznik + p.temperatura);
        p.temperatura = npomiary.get_temp();

        npomiary.sprawdzStan(p.wiek);
        p.stan = npomiary.get_stan();
    }

    zapiszPacjentow(nazwaPliku, pacjenci);

    int liczba_nowych_pacjentow = rand() % 3; // losowanie ilości nowych pacjentów

    string imiona[100] =
    {
        //Imiona kobiet kończą się literą 'a'
        "Anna", "Maria", "Katarzyna", "Magdalena", "Agnieszka",
        "Joanna", "Barbara", "Ewa", "Krystyna", "Elżbieta",
        "Zofia", "Teresa", "Halina", "Irena", "Jadwiga",
        "Danuta", "Grażyna", "Beata", "Urszula", "Małgorzata",
        "Natalia", "Patrycja", "Karolina", "Sylwia", "Paulina",
        "Dorota", "Martyna", "Alicja", "Justyna", "Weronika",
        "Milena", "Izabela", "Renata", "Gabriela", "Julia",
        "Emilia", "Olga", "Lucyna", "Aneta", "Wioletta",
        "Jan", "Andrzej", "Piotr", "Krzysztof", "Stanisław",
        "Tomasz", "Paweł", "Józef", "Marcin", "Marek",
        "Michał", "Grzegorz", "Jerzy", "Tadeusz", "Adam",
        "Zbigniew", "Ryszard", "Dariusz", "Wojciech", "Henryk",
        "Roman", "Kazimierz", "Edward", "Robert", "Sebastian",
        "Mateusz", "Antoni", "Julian", "Ignacy", "Oskar",
        "Bartosz", "Łukasz", "Hubert", "Karol", "Kamil",
        "Przemysław", "Daniel", "Konrad", "Szymon", "Damian",
        "Cezary", "Filip", "Maciej", "Mariusz", "Arkadiusz",
        "Patryk", "Rafał", "Norbert", "Tymoteusz", "Waldemar",
        "Lech", "Bogdan", "Borys", "Witold", "Albert"
    };

    string nazwiska[100] =
    {
        "Kowalski", "Nowak", "Wiśniewski", "Wójcik", "Kowalczyk",
        "Kamiński", "Lewandowski", "Zieliński", "Szymański", "Woźniak",
        "Dąbrowski", "Kozłowski", "Jankowski", "Mazur", "Wojciechowski",
        "Kwiatkowski", "Kaczmarek", "Piotrowski", "Grabowski", "Zając",
        "Król", "Wieczorek", "Jabłoński", "Wróbel", "Pawłowski",
        "Michalski", "Nowicki", "Adamczyk", "Dudek", "Sikora",
        "Walczak", "Baran", "Rutkowski", "Szewczyk", "Olszewski",
        "Bąk", "Szymańska", "Lis", "Makowski", "Chmielewski",
        "Szulc", "Brzeziński", "Czarnecki", "Sawicki", "Sokołowski",
        "Urbański", "Kubiak", "Kucharski", "Tomczak", "Jaworski",
        "Malinowski", "Piekarski", "Głowacki", "Czerwiński", "Sikorski",
        "Włodarczyk", "Marciniak", "Jastrzębski", "Zarzycki", "Rogowski",
        "Maj", "Sobczak", "Tomaszewski", "Cieślak", "Kubicki",
        "Kołodziej", "Milewski", "Szczepański", "Leszczyński", "Borowski",
        "Borkowski", "Majewski", "Urban", "Pawlak", "Kopeć",
        "Mróz", "Orłowski", "Musiał", "Wrona", "Brodziński",
        "Zawadzki", "Stefański", "Andrzejewski", "Błaszczyk", "Strzelczyk",
        "Marcinkowski", "Chojnacki", "Słowik", "Drozd", "Wilk",
        "Bednarek", "Białek", "Michalik", "Gajda", "Jóźwiak"
    };

    string dolegliwosci[50] =
    {
        "Grypa", "Angina", "Zapalenie płuc", "COVID-19", "Astma",
        "Cukrzyca", "Choroba wieńcowa", "Zawał serca", "Nadciśnienie", "Nowotwór",
        "Złamanie ręki", "Złamanie nogi", "Złamanie biodra", "Rana cięta", "Rana szarpana",
        "Oparzenie", "Odleżyny", "Reumatoidalne zapalenie stawów", "Osteoporoza", "Skolioza",
        "Zapalenie ucha", "Zatrucie pokarmowe", "Kamica nerkowa", "Wrzody żołądka", "Alzheimer",
        "Parkinson", "Migrena", "Depresja", "Nerwica", "Bezsenność",
        "Padaczka", "Choroba Crohna", "Hemoroidy", "Reumatyzm", "Stwardnienie rozsiane",
        "Zespół Downa", "Autyzm", "Biegunka", "Zaparcia", "Zapalenie gardła",
        "Angina ropna", "Ospa", "Różyczka", "Świnka", "Zapalenie spojówek",
        "Zawał mózgu", "Gruźlica", "Zapalenie oskrzeli", "Zatrucie chemiczne", "Wstrząśnienie mózgu"
    };


    if (liczba_nowych_pacjentow != 0) 
    {

        ofstream plik("pacjenci.txt", ios::app);
        if(!plik)
        {
            cerr << "Nie ma takiego pliku!\n";
            return 1;
        }

        int id = pacjenci.size() + 1;
        liczba_nowych_pacjentow += pacjenci.size();
        for (int i = id; i <= liczba_nowych_pacjentow; i++)
        {
            int wiek = rand() % 121;
            string imie = imiona[rand() % 100];
            string nazwisko = nazwiska[rand() % 100];
            string dolegliwosc = dolegliwosci[rand() % 50];
            string pesel = wygenerujPesel(wiek, imie);

            Pacjent nowy_pacjent(i, pesel, imie, nazwisko, wiek, dolegliwosc);

            nowy_pacjent.zapisz(plik);
        }
    }


    cout << "Zaktualizowano stan wszystkich pacjentów.\n";
    return 0;
}
