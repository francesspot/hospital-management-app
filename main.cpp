#include <iostream>
#include <cstdlib>
#include "generator_pacjentow.hpp"

using namespace std;

const int ile = 20;
Pacjent tab[ile];

int main()
{
    int wybor;
    bool dziala = true;
    string nazwa_pliku;
    const char* msg_0 = "Aby uruchomić funkcję wyszukiwania wybierz 1\nAby zakończyć działanie programu wybierz 0\n";

    while (dziala)
    {
        cout << "\nMENU" << endl;
        cout << "1. Generuj Pacjentów" << endl;
        cout << "2. Aktualizuj Pacjentów" << endl;
        cout << "3. Sprawdź poprawność stanu Pacjentów" << endl;
        cout << "4. Sprawdź poprawność parametrów Pacjentów" << endl;
        cout << "5. Uruchom funkcję Search - wyszukaj pacjentów o zadanych cechach" << endl;
        cout << "0. Koniec programu" << endl;
        cout << "Wybierz operację: " << endl;
        cin >> wybor;

        switch (wybor)
        {
        case 1:
            generujPacjentow();
            break;
        case 2:
            aktualizujPacjentow();
            break;
        case 3:
            sprawdzenieStanuParametrow();
            break;
        case 4:
            sprawdzeniePoprawnosci();
            break;
        case 5:
            cout<<msg_0;
            search(tab);
            break;
        case 0:
            cout << "Koniec programu!" << endl;
            dziala = false;
            break;
        default:
            cout << "Nie ma takiej opcji!" << endl;
            break;
        }
    }
    return 0;
}
