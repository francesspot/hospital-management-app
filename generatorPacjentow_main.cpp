#include <iostream> // cin i cout
#include <cstdlib> // rand() i srand()
#include <fstream> // działania na plikach
#include <string> // stringi i ich metody np. back()
#include <ctime> // time()
#include "generator_pacjentow.hpp"


using namespace std;

int generujPacjentow()
{
    srand(time(0)); // zapewnia całkowita losowość wyników

    int liczba_pacjentow = rand() % 5 + 2; // losowanie ilości pacjentów

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


    ofstream plik("pacjenci.txt");
    if(!plik)
    {
        cerr << "Nie ma takiego pliku!\n";
        return 1;
    }

    for (int i = 1; i <= liczba_pacjentow; i++)
    {
        int wiek = rand() % 121;
        string imie = imiona[rand() % 100];
        string nazwisko = nazwiska[rand() % 100];
        string dolegliwosc = dolegliwosci[rand() % 50];
        string pesel = wygenerujPesel(wiek, imie);

        Pacjent pacjent(i, pesel, imie, nazwisko, wiek, dolegliwosc);

        pacjent.zapisz(plik);

    }
    
    plik.close();
    cout << "Zapisano dane pacjentów do pliku pacjenci.txt\n";
    return 0;
}