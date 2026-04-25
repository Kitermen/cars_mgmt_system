#include <iostream>
#include "Vehicles.h"
#include "Persons.h"

using namespace std;

int wybor_typ() {
    int wybor = 0;
    while (true) {
        cout << "\nJakiego typu pojazd chcesz dodac do bazy?" << endl;
        cout << "1. Osobowy" << endl;
        cout << "2. Dostawczy" << endl;
        cout << "3. Motocykl" << endl;
        cout << "Wybierz opcje: ";

        if (!(cin >> wybor)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Bledne dane! Wpisz liczbe (1-3)." << endl;
            continue;
        }

        if (wybor >= 1 && wybor <= 3)
            return wybor;

        cout << "Nieprawidlowa opcja! Wybierz 1, 2 lub 3." << endl;
    }
}

int main() {
    int wybor = 0;

    do {
        cout << "\n===== MENU GLOWNE =====" << endl;
        cout << "1. Dodaj pojazd do bazy" << endl;
        cout << "2. Wyswietl dostepne pojazdy w bazie" << endl;
        cout << "3. Wyswietl wszystkie pojazdy w bazie" << endl;
        cout << "4. Zwroc samochod" << endl;
        cout << "5. Wyszukaj samochod" << endl;
        cout << "6. Zmien stan techniczny" << endl;
        cout << "7. Zmien dostepnosc" << endl;
        cout << "8. Zmien przebieg" << endl;
        cout << "9. Wyjdz z systemu" << endl;
        cout << "Wybierz opcje: ";


        if (!(cin >> wybor)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Bledne dane! Prosze wpisac liczbe." << endl;
            continue;
        }

        switch (wybor) {
            case 1: { 
                cout << "--- Dodawanie nowego pojazdu ---" << endl;
                int typ = wybor_typ(); 

                switch (typ) {
                    case 1:
                        //Miejsce na dodanie do bazy osobowego
                        cout << "Wybrano: Samochod osobowy" << endl;
                        //Pobranie pól od ziomeczka.
                        Osobowy o();
                        o.dodaj_pojazd();
                        break;
                    case 2:
                        //Miejsce na dodanie do bazy dostawczego
                        cout << "Wybrano: Samochod dostawczy" << endl;

                        Dostawczy d();
                        d.dodaj_pojazd();
                        break;
                    case 3:
                        //Miejsce na dodanie do bazy motocykla
                        cout << "Wybrano: Motocykl" << endl;
                        Motocykl m();
                        m.dodaj_pojazd();
                        break;
                }
                break;
            }

            case 2:
                cout << "Lista pojazdow dostępnych w bazie:" << endl;
                //Połączenie z bazą i odczytanie dostępnych pojazdów: kolumny oddzielone spacją np.
                break;

            case 3:
                cout << "Lista wszystkich pojazdów w bazie:" << endl;
                //Połączenie z bazą i odczytanie wszystkich pojazdów
                break;

            case 4:
                cout << "Jaki samochód chcesz zwrócić" << endl; //Wybranie np ID z listy, która się wyświetla odnośnie pojazdu do zwrotu 
                break;

            case 5:
                cout << "Wyszukiwanie..." << endl;
                break;

            case 6:
                cout << "Aktualizacja stanu technicznego..." << endl;
                break;

            case 7:
                cout << "Zmiana statusu dostepnosci..." << endl;
                break;

            case 8:
                cout << "Aktualizacja licznika przebiegu..." << endl;
                break;

            case 9:
                cout << "Zamykanie systemu. Do widzenia!" << endl;
                break;

            default:
                cout << "Nieznana opcja menu. Sprobuj ponownie." << endl;
                break;
        }

    } while (wybor != 9);

    return 0;
}