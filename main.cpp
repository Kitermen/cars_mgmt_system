#include <iostream>
#include "Methods.h"

using namespace std;

int main() {
    auto storage = initStorage("cars_mgmt_system.db");
    Methods action(storage);
    int choice = 0;

    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Wyswietl wszystkie pojazdy" << endl;
        cout << "2. Wyswietl wszystkie osoby" << endl;
        cout << "3. Wynajmij samochod" << endl;
        cout << "4. Zwroc samochod" << endl;
        cout << "9. Wyjdz" << endl;
        cout << "Wybor: ";

        if (!(cin >> choice)) {
            cin.clear(); cin.ignore(1000, '\n');
            continue;
        }

        switch (choice) {
            case 1: action.get_all_cars(); break;
            case 2: action.get_all_clients(); break;
            case 3: {
                action.get_avalible_cars();
                int car_id, client_id;
                while (true) {
                    cout << "Podaj ID auta: ";
                    if (cin >> car_id && action.sprawdz_auto(car_id, "Dostepny")) break;
                    cout << "Blad! Sprobuj ponownie: ";
                    cin.clear(); cin.ignore(1000, '\n');
                }
                action.get_all_clients();
                while (true) {
                    cout << "Podaj ID osoby: ";
                    if (cin >> client_id && action.sprawdz_osobe(client_id)) break;
                    cout << "Blad! Sprobuj ponownie: ";
                    cin.clear(); cin.ignore(1000, '\n');
                }
                action.rent_a_car(car_id, client_id);
                break;
            }
            case 4: {
                if (!action.get_rented_cars()) continue;
                int car_id;
                while (true) {
                    cout << "Podaj ID auta do zwrotu: ";
                    if (cin >> car_id && action.sprawdz_auto(car_id, "Wypozyczony")) break;
                    cout << "To auto nie jest wypozyczone! Sprobuj ponownie: ";
                    cin.clear(); cin.ignore(1000, '\n');
                }
                action.return_a_car(car_id);
                break;
            }
        }
    } 
    while (choice != 9);
        return 0;
}