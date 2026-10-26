🇵🇱 [Polski](README.md) | 🇬🇧 **English**

# 🏥 Patient Monitoring Simulator

![C++](https://img.shields.io/badge/C++-00599C?logo=cplusplus&logoColor=white)

> 🎓 Project for the **Object-Oriented Programming Paradigms** course (Wrocław University of Science and Technology)

A console app that simulates a hospital ward: it generates patients, tracks their vital signs over time and flags who needs attention. 🩺

## ✨ Features

- 👥 **Patient generation** — random personal data, a Polish national ID number (**PESEL**) encoding the birth year and sex, an ailment and measurements
- ⏱️ **Passing time** — patients' vitals change randomly and new people are admitted
- 🚦 **Condition rating 1–5** based on deviations from the norms for each age group (infant, child, teen, adult, senior)
- ⚠️ **Reports** — patients with out-of-range vitals and physically impossible data (e.g. measurement errors)
- 🔎 **Search** by first name, surname, condition, room or doctor
- 💾 Data stored in text files

Tracked vitals: blood pressure, heart rate, oxygen saturation, blood sugar, temperature.

## 🛠️ Tech

C++20 · object-oriented programming (classes, encapsulation, getters/setters) · file I/O

## 🚀 Run it

```bash
g++ -std=c++20 *.cpp -o main
./main
```

> 🌡️ Temperature is stored in tenths of a degree: 36.6 °C → `366`. The interface is in Polish.
