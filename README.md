### cars_mgmt_system
Temat 5: System Zarządzania Flotą Pojazdów (Wypożyczalnia) 

Członkowie projektu: Maciej Matuszczyk(L), Aleksander Urban, Michał Żądło, Yurii Tsal-Tsalko

Początkowa planowana lista funkcjonalności: 
  1. Wyświetlenie wszystkich pojazdów
  2. Wyświetlenie obecnie dostępnych pojazdów
  3. Wynajęcie / zwrot samochodu
  4. Wyszukiwanie samochodu po atrybucie
  5. Zmiana Status_techniczny;Dostepnosc;Przebieg;Sposob_rozliczenia po ID (część edycji)



========================================================================================

### Rezultat pracy i ostateczna forma aplikacji

Aplikacja stanowi konsolowy system zarządzania flotą pojazdów oraz procesem ich wynajmu i zwrotu przez klientów. Narzędzie zostało zaprojektowane z myślą o intuicyjnej obsłudze z poziomu interaktywnego menu CLI (Command Line Interface), umożliwiając szybkie operacje na bazie danych.

Baza samochodów i klientów została oparta na bazie danych **SQLite**. Decyzja ta wynika z pełnej kompatybilności z założeniami projektowymi, według których aplikacja wykonuje zaawansowane operacje na danych (takie jak filtrowanie, wyszukiwanie i dynamiczna aktualizacja rekordów). Wykorzystanie relacyjnej bazy danych eliminuje nieoptymalne podejście, jakim byłoby ciągłe pobieranie, modyfikowanie i zapisywanie całego pliku JSON przy każdej operacji. 

Do płynnej komunikacji z bazą danych wykorzystano lekką i nowoczesną bibliotekę typu ORM dla języka C++ – **sqlite_orm**, która pozwala na  mapowanie obiektów na tabele SQL bez konieczności pisania klasycznych zapytań tekstowych.

========================================================================================

### Struktura aplikacji
<img width="599" height="445" alt="image" src="https://github.com/user-attachments/assets/5ebd22c6-9a11-4dc9-a829-1ac9a03d9a07" />


========================================================================================

### Informacje o autorach i ich wkładzie

🚶‍➡️ Maciej Matuszczyk(L):
📝---> koordynacja oraz konsultacje przy tworzeniu aplikacji, 
📝---> przygotowanie sqlite oraz sqlite_orm oraz opisanie sposobu ich wdrażania,
⚙️---> troubleshooting na drodze do opublikowania wersji "beta" aplikacji
📝---> przygotowanie pliku (nazwa wstępna "jak_kompilowac.txt") w razie ponownego napotkania problemów przy kompilacji
⚙️---> scalenie opracowywanych komponentów aplikacji - pierwsza działająca wersja "beta"
⚙️---> dodanie do aplikacji możliwości wynajęcia / zwrotu samochodu
📝---> aktualizacja pliku README.md

🚶‍➡️ Aleksander Urban:
📝---> przedstawienie konceptu dla warstwy frontendowej aplikacji
⚙️---> przygotowanie frontendu w oparciu o switch zamknięty w pętli do - while
⚙️---> dodanie do aplikacji aktualizowania przebiegu i stanu samochodów
📝---> dodanie do kodu komentarzy opisujących poszczególne sekcje

🚶‍➡️ Michał Żądło
📝---> konsultacje dotyczące wdrożenia OOP
📝---> przedstawienie i wybór biblioteki sqlite jako sposobu na przechowywanie danych
⚙️---> przygotowanie klas Persons.h, Vehicles.h oraz wstępnej wersji klasy z metodami
⚙️---> dodanie do aplikacji wyszukiwania samochodów po modelu, marce oraz przebiegu
📝---> aktualizacja pliku scheme.png

🚶🏻‍➡️ Yurii Tsal-Tsalko
📝---> przygotowanie sqlite oraz sqlite_orm oraz opisanie sposobu ich wdrażania,
⚙️---> przygotowanie cars_mgmt_system.sql - kwerenda do tworzenia bazy danych
⚙️---> troubleshooting na drodze do opublikowania wersji "beta" aplikacji
📝---> przygotowanie pliku (nazwa wstępna "jak_kompilowac.txt") w razie ponownego napotkania problemów przy kompilacji
⚙️---> scalenie opracowywanych komponentów aplikacji - pierwsza działająca wersja "beta"

========================================================================================

### Status Prac nad funkcjonalnościami

* ✅ - **Wyświetlenie wszystkich pojazdów** (oparte na metodzie `get_all_cars()`)
* ✅ - **Wyświetlenie wszystkich osób** (oparte na metodzie `get_all_clients()`)
* ✅ - **Wynajem samochodu** (oparte na metodach `get_avalible_cars()`, `check_a_car()`, `get_all_clients()`, `check_client()` oraz `rent_a_car()`)
* ✅ - **Zwrot samochodu** (oparte na metodach `get_rented_cars()`, `check_a_car()` oraz `return_a_car()`)
* ✅ - **Filtrowanie po modelu lub marce** (oparte na metodzie `get_available_cars_filter()`)
* ✅ - **Filtrowanie po przebiegu** (oparte na metodzie `get_cars_mileage()`)
* ✅ - **Zmiana przebiegu lub stanu technicznego pojazdu** (oparte na metodach `check_car_existence()`, `update_mileage()` oraz `update_technical_status()`)

========================================================================================

### Instrukcja Kompilacji i Uruchomienia

Aplikacja była testowana w IDE Visual Stuido Code ze względu na jego przejrzystość i kompatybilność (między innymi z C++).
W związku z tym poniższe kroki przewidują wykorzystanie VSC jako środowiska do skompilowania i uruchomienia aplikacji.

### Wymagania wstępne
Do poprawnej kompilacji projektu wymagane są:
1. Kompilator zgodny co najmniej ze standardem C++17 (np. MinGW-w64 z GCC w wersji 7+, samodzielny GCC 7+, Clang 5+ lub MSVC 2017+).
2. Elementy biblioteki `sqlite3` (znajdujące się w ścieżce projektu).
3. Nagłówki biblioteki `sqlite_orm` (znajdujące się w ścieżce projektu).

### Inicjalizacja bazy danych
1. Zainstaluj sqlite, sqlite viewer
2. Przygotuj plik .sql z komendami / konfiguracją
3. Utwórz cars_mgmt_system.db
4. W Pasku wyszukiwania na górze wpisz: Sqlite: new query
5. Do nowego okna wklej zawartość pliku .sql
6. W Pasku wyszukiwania na górze wpisz: Sqlite: run query
7. Gotowe

### Kompilacja (MinGW-w64 / g++)
1. gcc -c sqlite3.c -o sqlite3.o
2. g++ -std=c++17 main.cpp sqlite3.o -o main.exe -I. -I./sqlite_orm/include
3. .\main.exe

### Troubleshooting przy kompilacji
Jeżeli korzystamy z popularnego IDE Visual Stuido Code warto zwrócić uwagę na plik tasks.json.
W przypadku problemów z bibliotekami podczas kompilacji, wspomniany plik (wygenerowany przez IDE) można zastąpić poniższą strukturą:
(kompliator g++ jest wybredny dla kodu napisanego w C):

{
    "tasks": [
        {
            "type": "cppbuild",
            "label": "C/C++: g++.exe build active file",
            "command": "C:\\msys64\\ucrt64\\bin\\g++.exe",
            "args": [
                "-fdiagnostics-color=always",
                "-g",
                "-std=c++17",
                "${fileDirname}\\main.cpp",
                "${fileDirname}\\sqlite3.c",
                "-o",
                "${fileDirname}\\main.exe",
                "-I", "${fileDirname}",
                "-I", "${fileDirname}\\sqlite_orm\\include",
                "-fpermissive"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
        }
    ],
    "version": "2.0.0"
}
