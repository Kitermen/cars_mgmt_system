# cars_mgmt_system
Temat 5: System Zarządzania Flotą Pojazdów (Wypożyczalnia) 
  • Hierarchia: Pojazd → Osobowy, Dostawczy, Motocykl. 
  • Wymagania: Status techniczny, przebieg, historia wypożyczeń, różne taryfy rozliczeń.

========================================================================================

Członkowie projektu: Maciej Matuszczyk(L), Aleksander Urban, Michał Żądło, Yurii Tsal-Tsalko

Kolumny bazy danych samochody: ID;Marka;Model;Typ;Rok;Status_techniczny;Dostepnosc;Przebieg;:Sposob_rozliczenia
Kolumny bazy danych osoby: ID;imie;nazwisko
Kolumny bazy danych relacje: ID;osoby(id);samochod(id)

Po konsultacji zdecydowaliśmy o wyborze rozszerzenia pliku .db

Lista funkcjonalności: 
  1. Wyświetlenie wszystkich pojazdów
  2. Wyświetlenie obecnie dostępnych pojazdów
  3. Dodanie, edycja, usunięcie pojazdu z bazy osoby
  4. Dodanie relacji (osoba wynajmuje pojazd)
  5. Usunięcie relacji (osoba kończy wynajmować)
  6. Wyszukiwanie samochodu po atrybucie
  7. Zmiana Status_techniczny;Dostepnosc;Przebieg;:Sposob_rozliczenia po ID
