#include <iostream>
#include "Methods.h"

using namespace std;

int main() {
    auto storage = initStorage("cars_mgmt_system.db");
    Wypozyczalnia wyp(storage);
    int wybor = 0;

    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Wyswietl wszystkie pojazdy" << endl;
        cout << "2. Wyswietl wszystkie osoby" << endl;
        cout << "3. WYNAJMIJ samochod" << endl;
        cout << "4. ZWROC samochod" << endl;
        cout << "9. Wyjdz" << endl;
        cout << "Wybor: ";

        if (!(cin >> wybor)) {
            cin.clear(); cin.ignore(1000, '\n');
            continue;
        }

        switch (wybor) {
            case 1: wyp.wyswietl_wszystkie(); break;
            case 2: wyp.wyswietl_osoby(); break;
            case 3: {
                wyp.wyswietl_dostepne();
                int idA, idO;
                while (true) {
                    cout << "Podaj ID auta: ";
                    if (cin >> idA && wyp.sprawdz_auto(idA, "Dostepny")) break;
                    cout << "Blad! Sprobuj ponownie: ";
                    cin.clear(); cin.ignore(1000, '\n');
                }
                wyp.wyswietl_osoby();
                while (true) {
                    cout << "Podaj ID osoby: ";
                    if (cin >> idO && wyp.sprawdz_osobe(idO)) break;
                    cout << "Blad! Sprobuj ponownie: ";
                    cin.clear(); cin.ignore(1000, '\n');
                }
                wyp.wynajmij(idA, idO);
                break;
            }
            case 4: {
                wyp.wyswietl_wypozyczone();
                int idA;
                while (true) {
                    cout << "Podaj ID auta do zwrotu: ";
                    // ZMIANA: Sprawdzamy status "Wypozyczony"
                    if (cin >> idA && wyp.sprawdz_auto(idA, "Wypozyczony")) break;
                    cout << "To auto nie jest wypozyczone! Sprobuj ponownie: ";
                    cin.clear(); cin.ignore(1000, '\n');
                }
                wyp.zwroc(idA);
                break;
            }
        }
    } while (wybor != 9);

    return 0;
}