#pragma once
#include <iostream>
#include <memory>
#include <vector>

#include "Database.h"

#include "sqlite_orm/include/sqlite_orm/sqlite_orm.h"

using namespace std;

class Methods {
private:
    Storage &db;

public:
    Methods(Storage &st) : db(st) {}

    // Pobiera i wyświetla wszystkie rekordy z tabeli Car
    void get_all_cars() {
        auto cars = db.get_all<Car>();
        cout << "\n--- LISTA WSZYSTKICH POJAZDOW ---" << endl;
        for (auto &c : cars) {
            cout << "ID: " << c.ID << " | " << c.Marka << " " << c.Model << ", Rocznik: " << c.Rok << " [" << c.Dostepnosc << "]" << "  Przebieg: " << c.Przebieg << endl;
        }
    }

    // Filtruje samochody po statusie "Dostepny"
    void get_avalible_cars() {
        auto cars = db.get_all<Car>(where(c(&Car::Dostepnosc) == "Dostepny"));
        cout << "\n--- DOSTEPNE SAMOCHODY ---" << endl;
        for (auto &c : cars) {
            cout << "ID: " << c.ID << " | " << c.Marka << " " << c.Model << endl;
        }
    }

    // Wyszukiwanie po nazwie marki lub modelu przy użyciu operatora LIKE
    void get_available_cars_filter(string response) {
            auto cars = db.get_all<Car>(where(like(&Car::Marka, response) || like(&Car::Model, response)));
            if (cars.empty()){    
            cout << "\n--- WYNIKI FILTROWANIA ---" << endl; 
        cout << "(Brak samochodów o takich parametrach!)" << endl;
            }
            else {
            cout << "\n--- WYNIKI FILTROWANIA ---" << endl;
            for (auto &c : cars) {
                    cout << "ID: " << c.ID << " | " << c.Marka << " " << c.Model << ", Rocznik: " << c.Rok << " [" << c.Dostepnosc << "]" << "  Przebieg: " << c.Przebieg << endl;
            }
            }
    }

    // Filtrowanie aut o przebiegu mniejszym niż podana wartość
    void get_cars_mileage(int mileage){
            auto cars = db.get_all<Car>(where(c(&Car::Przebieg) < mileage));
            if (cars.empty()) {    
                cout << "\n--- WYNIKI FILTROWANIA ---" << endl;
        cout << "(Brak samochodów o takich parametrach!)" << endl;
            }
            else {

                cout << "\n--- WYNIKI FILTROWANIA ---" << endl;
            for (auto &c : cars) {
                    cout << "ID: " << c.ID << " | " << c.Marka << " " << c.Model << ", Rocznik: " << c.Rok << " [" << c.Dostepnosc << "]" << "  Przebieg: " << c.Przebieg << endl;
            }   
        }
    }

    // Pobiera wypożyczone auta; zwraca true jeśli znaleziono jakiekolwiek rekordy
    bool get_rented_cars() {
        auto cars = db.get_all<Car>(where(c(&Car::Dostepnosc) == "Wypozyczony"));
        cout << "\n--- SAMOCHODY DO ZWROTU (WYPOZYCZONE) ---" << endl;
        
        if (cars.empty()) {
            cout << "(Brak wypozyczonych aut w bazie!)" << endl;
            return false; 
        }
        
        for (auto &c : cars) {
            cout << "ID: " << c.ID << " | " << c.Marka << " " << c.Model << endl;
        }
        return true; 
    }

    // Pobiera wszystkie osoby w bazie
    void get_all_clients() {
        auto users = db.get_all<User>();
        cout << "\n--- LISTA OSOB ---" << endl;
        for (auto &u : users) {
            cout << "ID: " << u.userID << ". " << u.Imie << " " << u.Nazwisko << endl;
        }
    }

    // Aktualizacja rekordu: zmiana statusu i przypisanie klienta do auta
    void rent_a_car(int autoID, int osobaID) {
        auto car = db.get_pointer<Car>(autoID);
        if (car) {
            car->Dostepnosc = "Wypozyczony";
            car->userID = make_unique<int>(osobaID);
            db.update(*car);
            cout << "\n>>> Sukces: Wypozyczono auto!" << endl;
        }
    }

    // Zmiana statusu na 'Dostepny' i usunięcie przypisania klienta
    void return_a_car(int autoID) {
        auto car = db.get_pointer<Car>(autoID);
        if (car) {
            car->Dostepnosc = "Dostepny";
            car->userID = nullptr;
            db.update(*car);
            cout << "\n>>> Sukces: Zwrocono auto!" << endl;
        }
    }

    // Weryfikacja dostępności auta o konkretnym statusie (np. czy auto jest wolne)
    bool check_a_car(int id, string status_required) {
        auto car = db.get_pointer<Car>(id);
        if (car && car->Dostepnosc == status_required) return true;
        return false;
    }

    // Sprawdzenie istnienia użytkownika w bazie po ID
    bool check_client(int id) {
        return db.get_pointer<User>(id) != nullptr;
    }

    // Sprawdzenie istnienia samochodu w bazie po ID
    bool check_car_existence(int id) {
        return db.get_pointer<Car>(id) != nullptr;
    }

    // Aktualizuje przebieg samochodu
    void update_mileage(int car_id, int new_mileage) {
        auto car = db.get_pointer<Car>(car_id);
        if (car) {
            car->Przebieg = new_mileage;
            db.update(*car);
            cout << "\n>>> Sukces: Zmieniono przebieg!" << endl;
        }
    }

    // Aktualizuje opis stanu technicznego pojazdu
    void update_technical_status(int car_id, string new_status) {
        auto car = db.get_pointer<Car>(car_id);
        if (car) {
            car->Status_techniczny = new_status;
            db.update(*car);
            cout << "\n>>> Sukces: Zmieniono stan techniczny!" << endl;
        }
    }
};