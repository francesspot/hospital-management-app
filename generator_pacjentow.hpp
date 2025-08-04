#ifndef GENERATOR_PACJENTOW_HPP
#define GENERATOR_PACJENTOW_HPP

#include <iostream> // cin i cout
#include <cstdlib> // rand() i srand()
#include <fstream> // działania na plikach
#include <string> // stringi i ich metody np. back()
#include <ctime> // time()
#include <vector> // dodaje vectory
#include <chrono> // aktualny czas, np. rok

struct Zakres // struktura zakresu do wykorzystywania w obliczaniu pomiarów 
{
    int min;
    int max;

    bool wZakresie(int wartosc) const;
};

class Pomiary 
{
protected: // zmienne chronione przed dostepem publicznym
    int cisnienie_skurczowe, cisnienie_rozkurczowe, tetno, utlenienie, poziom_cukru, stan, temperatura_ciala;

public:
    // Gettery - const bo są stałe
    int get_cS() const;
    int get_cR() const;
    int get_tetno() const;
    int get_utl() const;
    int get_cukier() const;
    int get_temp() const;
    int get_stan() const;

    // Settery
    void set_cS(int wartosc);
    void set_cR(int wartosc);
    void set_tetno(int wartosc);
    void set_utl(int wartosc);
    void set_cukier(int wartosc);
    void set_temp(int wartosc);
    void set_stan(int wartosc);

    // Metody sprawdzania stanu
    int ocenaStanu(double roznica);
    void sprawdzStan(int wiek);

    // konstruktor domyslny pomiarow  
    Pomiary();

    // wirtualny destruktor
    virtual ~Pomiary(){};     
};

class Pacjent 
{
protected: // zmienne chronione przed dostepem publicznym
    int id, wiek, wzrost, waga, pokoj;
    std::string imie, nazwisko, plec, pesel, dolegliwosc, lekarz;
    Pomiary pomiary;

public:
    // Gettery - const bo są stałe
    int get_id() const;
    std::string get_imie() const;
    std::string get_nazwisko() const;
    int get_stan() const;
    int get_pokoj() const;
    std::string get_lekarz() const;

    // Settery
    void set_pacjent(int Id, std::string Pesel, std::string Imie, std::string Nazwisko, int Wiek, std::string Plec, int Wzrost, int Waga, int Cisk, int Ciroz, int Tetno, int Utlenienie, int Cukier, int Temperatura, int Stan, std::string Dolegliwosc);
    void set_id(int wartosc);
    void set_imie(const std::string nazwa);
    void set_nazwisko(const std::string nazwa);
    void set_pesel(const std::string nazwa);
    void set_stan(int wartosc);
    void set_lekarz(const std::string nazwa);

    // metody
    void wylosujWzrost_Wage();
    void wylosujPomiary();
    void zapisz(std::ofstream &plik);
    void dopisz(std::ofstream &plik);
    // konstruktor
    Pacjent(){} // konstruktor domyślny
    Pacjent(int ID, std::string Pesel, std::string Imie, std::string Nazwisko, int Wiek, std::string Dolegliwosc);

    // wirtualny destruktor
    virtual ~Pacjent(){};
};

struct PacjentDane // struktura danych pacjenta
{
    int id, wiek, wzrost, waga, cisnienie_skurczowe, cisnienie_rozkurczowe, tetno, utlenienie, poziom_cukru, temperatura, stan;
    std::string pesel, imie, nazwisko, plec, dolegliwosc;
};

std::string wygenerujPesel(int wiek, std::string imie);
int rokUrodzenia(int wiek);

void wczytajPacjentow(const std::string& nazwaPliku, std::vector<PacjentDane>& pacjenci);
void zapiszPacjentow(const std::string& nazwaPliku, const std::vector<PacjentDane>& pacjenci);

int generujPacjentow();
int aktualizujPacjentow();
int sprawdzenieStanuParametrow();
int sprawdzeniePoprawnosci();

std::vector <std::string> split_text(const std::string &text, char delimiter);
int wczytaj(Pacjent *tab);
void search(Pacjent *tab);

#endif // GENERATOR_PACJENTOW_HPP
