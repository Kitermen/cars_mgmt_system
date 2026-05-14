#include <iostream>
#include "Methods.h"
#include "Vehicles.h"
#include "Persons.h"

using namespace std;

int main() {
    auto storage = initStorage("cars_mgmt_system.db");
    Wypozyczalnia wyp(storage);
    int wybor = 0;

    do {
        cout << "\n===== MENU GLOWNE =====" << endl;
        cout << "1. Dodaj pojazd do bazy" << endl;
        cout << "2. Wyswietl dostepne pojazdy" << endl;
        cout << "3. Wyswietl WSZYSTKIE pojazdy" << endl;
        cout << "4. Wyswietl WSZYSTKIE osoby" << endl; // Dodana opcja
        cout << "9. Wyjdz z systemu" << endl;
        cout << "Wybierz opcje: ";

        if (!(cin >> wybor)) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (wybor) {
            case 3:
                wyp.wyswietl_wszystkie();
                break;
            case 4:
                wyp.wyswietl_osoby();
                break;
            case 9:
                cout << "Zamykanie systemu..." << endl;
                break;
            default:
                break;
        }
    } while (wybor != 9);

    return 0;
}
