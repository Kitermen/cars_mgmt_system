#include <iostream>

#include "Methods.h"

using namespace std;

int main() {
    auto storage = initStorage("cars_mgmt_system.db");
    Methods action(storage);
    int choice = 0;

    do {
        cout << "\n========== MENU ==========" << endl;
        cout << "1. Wyswietl wszystkie pojazdy" << endl;
        cout << "2. Wyswietl wszystkie osoby" << endl;
        cout << "3. Wynajmij samochod" << endl;
        cout << "4. Zwroc samochod" << endl;
        cout << "5. Filtruj po modelu lub marce" << endl;
        cout << "6. Filtruj po przebiegu" << endl;
        cout << "7. Zmien przebieg(1) lub stan techniczny(2) pojazdu" << endl;
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
                    if (cin >> car_id && action.check_a_car(car_id, "Dostepny")) break;
                    cout << "Blad! Sprobuj ponownie: ";
                    cin.clear(); cin.ignore(1000, '\n');
                }
                action.get_all_clients();
                while (true) {
                    cout << "Podaj ID osoby: ";
                    if (cin >> client_id && action.check_client(client_id)) break;
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
                    if (cin >> car_id && action.check_a_car(car_id, "Wypozyczony")) break;
                    cout << "To auto nie jest wypozyczone! Sprobuj ponownie: ";
                    cin.clear(); cin.ignore(1000, '\n');
                }
                action.return_a_car(car_id);
                break;
            }
            case 5: {
                std::string response;
                std::cout << "Podaj marke lub model: ";
                std::cin >> response;
                action.get_available_cars_filter(response);   
                break;
            }
            case 6: {
                int mileage;
                std::cout<< "Podaj maksymalny akceptowalny przebieg: ";
                std::cin >> mileage;
                action.get_cars_mileage(mileage);
                break;  
            }
            case 7: {
                action.get_all_cars();
                int car_id;
                while (true) {
                    cout << "Podaj ID auta: ";
                    if (cin >> car_id && action.check_car_existence(car_id)) break;
                    cout << "Podaj poprawna wartosc!" << endl;
                    cin.clear(); cin.ignore(1000, '\n');
                }
                int sub_choice;
                while (true) {
                    cout << "Wybor: ";
                    if (cin >> sub_choice && (sub_choice == 1 || sub_choice == 2)) break;
                    cout << "Podaj poprawna wartosc!" << endl;
                    cin.clear(); cin.ignore(1000, '\n');
                }
                if (sub_choice == 1) {
                    int new_mileage;
                    while (true) {
                        cout << "Podaj nowy przebieg: ";
                        if (cin >> new_mileage && new_mileage >= 0) break;
                        cout << "Podaj poprawna wartosc!" << endl;
                        cin.clear(); cin.ignore(1000, '\n');
                    }
                    action.update_mileage(car_id, new_mileage);
                } 
                else {
                    string new_status;
                    cout << "Podaj nowy stan techniczny: ";
                    cin >> new_status;
                    action.update_technical_status(car_id, new_status);
                }
                break;
            }
        }
    } 
    while (choice != 9);
    return 0;
}