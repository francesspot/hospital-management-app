[Polski](README.md) | **English**

# Hospital Management App

A C++ console application that simulates monitoring the condition of patients currently in a hospital. Patient data is generated randomly, stored in a text file and can be updated, validated and searched. The interface is in Polish.

## Features

The main menu (`main.cpp`) offers:

1. **Generate patients** — creates 2–6 random patients (name, surname, age, sex, height, weight, ailment) with a generated PESEL number and vital-sign measurements, and saves them to `pacjenci.txt`.
2. **Update patients** — simulates the passage of time: each measurement changes randomly, the patient's condition is re-assessed and 0–2 new patients may be admitted.
3. **Check patient condition** — compares each patient's measurements with the normal ranges for their age group (infant, child, teenager, adult, senior) and writes patients with out-of-range values to `stan_parametrow.txt`.
4. **Check data validity** — detects physically impossible values (e.g. a measurement outside any realistic range) and writes them to `nieprawidlowosci.txt`.
5. **Search** — find patients by (part of) first name, surname, condition, room or attending doctor.

### Measurements and condition

For each patient the program stores systolic and diastolic blood pressure, heart rate, oxygen saturation, blood sugar and body temperature. The overall condition is rated **1–5** (1 — stable, 5 — critical) according to the largest deviation from the norm for the patient's age.

> **Note:** body temperature is stored as an integer in tenths of a degree, e.g. 36.6 °C → `366`, 40.1 °C → `401`.

## Project structure

```
main.cpp                          – menu
generator_pacjentow.hpp           – Patient and Measurements classes, function declarations
generatorPacjentow.cpp            – class methods, PESEL generator, search
generatorPacjentow_main.cpp       – generating new patients
aktualizacja_pacjentow.cpp        – updating patients
sprawdzenie_stanu_parametrow.cpp  – checking against age-specific norms
sprawdzenie_poprawnosci.cpp       – detecting impossible values
pacjenci.txt                      – patient data (one patient per line)
```

## Build and run

```bash
g++ -std=c++20 *.cpp -o main
./main
```

Run the program from the repository folder — it reads and writes the `.txt` files in the current directory.
