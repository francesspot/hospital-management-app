🇵🇱 **Polski** | 🇬🇧 [English](README.en.md)

# 🏥 Symulator monitorowania pacjentów

![C++](https://img.shields.io/badge/C++-00599C?logo=cplusplus&logoColor=white)

> 🎓 Projekt na przedmiot **Paradygmaty Programowania Obiektowego** (Politechnika Wrocławska)

Konsolowa aplikacja, która symuluje oddział szpitalny: generuje pacjentów, śledzi ich parametry życiowe w czasie i oznacza pacjentów wymagających uwagi.

## ✨ Funkcje

- **Generowanie pacjentów** — losowe dane osobowe, **PESEL** zakodowany zgodnie z rokiem urodzenia i płcią, dolegliwość i pomiary
- **Upływ czasu** — parametry pacjentów losowo się zmieniają, a do szpitala trafiają nowe osoby
- **Ocena stanu w skali 1–5** na podstawie odchyleń od norm dla wieku (niemowlę, dziecko, nastolatek, dorosły, senior)
- **Raporty** — pacjenci z parametrami poza normą oraz dane fizycznie niemożliwe (np. błędy pomiaru)
- **Wyszukiwarka** po imieniu, nazwisku, stanie, pokoju lub lekarzu
- Dane zapisywane w plikach tekstowych

Mierzone parametry: ciśnienie, tętno, saturacja, cukier, temperatura.

## 🛠️ Technologie

C++20 · programowanie obiektowe (klasy, enkapsulacja, gettery/settery) · operacje na plikach

## 🚀 Uruchomienie

```bash
g++ -std=c++20 *.cpp -o main
./main
```

> Temperatura zapisywana jest w dziesiątych częściach stopnia: 36,6 °C `366`.
