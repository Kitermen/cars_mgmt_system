#pragma once
#include <vector>
#include <iostream>
#include <memory>
#include "Database.h"

using namespace std;

class Methods {
    Storage &db;

public:
    Methods(Storage &st) : db(st) {}

    void get_all_cars() {
        auto cars = db.get_all<Car>();
        cout << "\n--- LISTA WSZYSTKICH POJAZDOW ---" << endl;
        for (auto &c : cars) {
            cout << "ID: " << c.ID << " | " << c.Marka << " " << c.Model << ", Rocznik: " << c.Rok << " [" << c.Dostepnosc << "]" << "  Przebieg: " << c.Przebieg << endl;
        }
    }

    void get_avalible_cars() {
        auto cars = db.get_all<Car>(where(c(&Car::Dostepnosc) == "Dostepny"));
        cout << "\n--- DOSTEPNE SAMOCHODY ---" << endl;
        for (auto &c : cars) {
            cout << "ID: " << c.ID << " | " << c.Marka << " " << c.Model << endl;
        }
    }

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

    void get_all_clients() {
        auto users = db.get_all<User>();
        cout << "\n--- LISTA OSOB ---" << endl;
        for (auto &u : users) {
            cout << "ID: " << u.userID << ". " << u.Imie << " " << u.Nazwisko << endl;
        }
    }

    void rent_a_car(int autoID, int osobaID) {
        auto car = db.get_pointer<Car>(autoID);
        if (car) {
            car->Dostepnosc = "Wypozyczony";
            car->userID = make_unique<int>(osobaID);
            db.update(*car);
            cout << "\n>>> Sukces: Wypozyczono auto!" << endl;
        }
    }

    void return_a_car(int autoID) {
        auto car = db.get_pointer<Car>(autoID);
        if (car) {
            car->Dostepnosc = "Dostepny";
            car->userID = nullptr;
            db.update(*car);
            cout << "\n>>> Sukces: Zwrocono auto!" << endl;
        }
    }

    bool sprawdz_auto(int id, string status_wymagany) {
        auto car = db.get_pointer<Car>(id);
        if (car && car->Dostepnosc == status_wymagany) return true;
        return false;
    }

    bool sprawdz_osobe(int id) {
        return db.get_pointer<User>(id) != nullptr;
    }
};