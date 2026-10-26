**Polski** | [English](README.en.md)

# Aplikacja do zarządzania szpitalem

Konsolowa aplikacja w C++ symulująca monitorowanie stanu pacjentów przebywających w szpitalu. Dane pacjentów są generowane losowo, zapisywane w pliku tekstowym i mogą być aktualizowane, sprawdzane i przeszukiwane.

## Funkcje

Menu główne (`main.cpp`) oferuje:

1. **Generuj pacjentów** — tworzy 2–6 losowych pacjentów (imię, nazwisko, wiek, płeć, wzrost, waga, dolegliwość) z wygenerowanym numerem PESEL i pomiarami parametrów życiowych, a następnie zapisuje ich do `pacjenci.txt`.
2. **Aktualizuj pacjentów** — symuluje upływ czasu: każdy pomiar losowo się zmienia, stan pacjenta jest oceniany na nowo, a do szpitala może trafić 0–2 nowych pacjentów.
3. **Sprawdź stan pacjentów** — porównuje pomiary każdego pacjenta z normami dla jego grupy wiekowej (niemowlę, dziecko, nastolatek, dorosły, senior) i zapisuje pacjentów z wartościami poza normą do `stan_parametrow.txt`.
4. **Sprawdź poprawność danych** — wykrywa wartości fizycznie nierealne (poza jakimkolwiek realistycznym zakresem) i zapisuje je do `nieprawidlowosci.txt`.
5. **Wyszukiwanie** — szukanie pacjentów po (fragmencie) imienia, nazwisku, stanie, numerze pokoju lub lekarzu prowadzącym.

### Pomiary i stan pacjenta

Dla każdego pacjenta przechowywane są: ciśnienie skurczowe i rozkurczowe, tętno, saturacja, poziom cukru i temperatura ciała. Ogólny stan oceniany jest w skali **1–5** (1 — stabilny, 5 — krytyczny) na podstawie największego odchylenia od normy dla wieku pacjenta.

> **Uwaga:** temperatura ciała zapisywana jest jako liczba całkowita w dziesiątych częściach stopnia, np. 36,6 °C → `366`, 40,1 °C → `401`.

## Struktura projektu

```
main.cpp                          – menu
generator_pacjentow.hpp           – klasy Pacjent i Pomiary, deklaracje funkcji
generatorPacjentow.cpp            – metody klas, generator PESEL, wyszukiwanie
generatorPacjentow_main.cpp       – generowanie nowych pacjentów
aktualizacja_pacjentow.cpp        – aktualizacja pacjentów
sprawdzenie_stanu_parametrow.cpp  – sprawdzanie zgodności z normami dla wieku
sprawdzenie_poprawnosci.cpp       – wykrywanie wartości nierealnych
pacjenci.txt                      – dane pacjentów (jeden pacjent w wierszu)
```

## Kompilacja i uruchomienie

```bash
g++ -std=c++20 *.cpp -o main
./main
```

Program uruchamiaj z folderu repozytorium — czyta i zapisuje pliki `.txt` w bieżącym katalogu.
