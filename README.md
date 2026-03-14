# cars_mgmt_system
Temat 5: System Zarządzania Flotą Pojazdów (Wypożyczalnia) 
  • Hierarchia: Pojazd → Osobowy, Dostawczy, Motocykl. 
  • Wymagania: Status techniczny, przebieg, historia wypożyczeń, różne taryfy rozliczeń.

========================================================================================

Członkowie projektu: Maciej Matuszczyk(L), Aleksander Urban, Michał Żądło, Yurii Tsal-Tsalko

Kolumny bazy danych samochody: ID;Marka;Model;Typ;Rok;Status_techniczny;Dostepnosc;Przebieg;:Sposob_rozliczenia


Po konsultacji zdecydowaliśmy o wyborze rozszerzenia pliku .json

Lista funkcjonalności: 
  1. Wyświetlenie wszystkich pojazdów
  2. Wyświetlenie obecnie dostępnych pojazdów
  3. Wynajęcie / zwrot samochodu
  4. Wyszukiwanie samochodu po atrybucie
  5. Zmiana Status_techniczny;Dostepnosc;Przebieg;:Sposob_rozliczenia po ID (część edycji)

Podziłą zadań:
1. Maciej Matuszczyk - stworzenie main.json i dodanie testowych danych, przygotowanie i wklejenie metod do obsługi jsona
2. Aleksander Urban - pozątek kodu, utrzymanie wstępnej estetyki i składni zapisu (zaczyna od wędrujących opcji switch)
3. Michał Żądło - stworzenie klasy (i generalnie przygotowanie klas)
4. Yurii Tsal-Tsalko -stworzenie rent.json i dodanie testowych danych

Estetyka:
for(){ tak, for () { nie
