# cars_mgmt_system
Temat 5: System Zarządzania Flotą Pojazdów (Wypożyczalnia) 
  • Hierarchia: Pojazd → Osobowy, Dostawczy, Motocykl. 
  • Wymagania: Status techniczny, przebieg, historia wypożyczeń, różne taryfy rozliczeń.

========================================================================================

Początkowe założenia i ustalenia dot. aplikacji:


Członkowie projektu: Maciej Matuszczyk(L), Aleksander Urban, Michał Żądło, Yurii Tsal-Tsalko

Kolumny bazy danych samochody: ID;Marka;Model;Rok;Status_techniczny;Dostepnosc;Przebieg;Sposob_rozliczenia;UserID(na razie eksperymentalnie)


Wstępna lista funkcjonalności: 
  1. Wyświetlenie wszystkich pojazdów
  2. Wyświetlenie obecnie dostępnych pojazdów
  3. Wynajęcie / zwrot samochodu
  4. Wyszukiwanie samochodu po atrybucie
  5. Zmiana Status_techniczny;Dostepnosc;Przebieg;Sposob_rozliczenia po ID (część edycji)

Podział zadań:
1. Maciej Matuszczyk - stworzenie main.json i dodanie testowych danych, przygotowanie i wklejenie metod do obsługi jsona
2. Aleksander Urban - pozątek kodu, utrzymanie wstępnej estetyki i składni zapisu (zaczyna od wędrujących opcji switch)
3. Michał Żądło - stworzenie klasy (i generalnie przygotowanie klas)
4. Yurii Tsal-Tsalko -stworzenie rent.json i dodanie testowych danych


========================================================================================

REZULTAT PRACY I OSTATECZNA FORMA APLIKACJI:


Baza samochodów i klientów została oparta na sqlite, ze względu na kompatybilność z założeniami, wg których teraz działa aplikacja (operacje na bazie danych, którą można filtrować i wyciągać z niej dane, a plik json, który byłby ciągle pobierany, modyfikowany i zapisywany - nieoptymalne).
Do komunikacji z bazą danych została wykorzystana lekka biblioteka sqlite_orm.


Praca nad funckjonalnościami:
- funckja get_all_cars() - zaimplementowana
- funckja get_all_clients() - zaimplementowana
- funckja rent_a_car() - zaimplementowana
- funckja return_a_car() - zaimplementowana
- funckja get_available_cars_filter() - zaimplementowana
- funckja get_cars_mileage() - zaimplementowana
- funkcja update_mileage() - zaimplementowana
- funkcja update_technical_status() - zaimplementowana