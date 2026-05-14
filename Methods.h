#pragma once
#include <vector>
#include <iostream>
#include <memory>
#include "Database.h"

using namespace std;

class Wypozyczalnia {
    Storage &db;

public:
    Wypozyczalnia(Storage &st) : db(st) {}

    void wyswietl_wszystkie() {
        auto cars = db.get_all<Car>();
        cout << "\n--- LISTA WSZYSTKICH POJAZDOW ---" << endl;
        for (auto &c : cars) {
            cout << "ID: " << c.ID << " | " << c.Marka << " " << c.Model << ", Rocznik: " << c.Rok << " [" << c.Dostepnosc << "]" << "  Przebieg: " << c.Przebieg << endl;
        }
    }

    void wyswietl_dostepne() {
        auto cars = db.get_all<Car>(where(c(&Car::Dostepnosc) == "Dostepny"));
        cout << "\n--- DOSTEPNE SAMOCHODY ---" << endl;
        for (auto &c : cars) {
            cout << "ID: " << c.ID << " | " << c.Marka << " " << c.Model << endl;
        }
    }

    void wyswietl_wypozyczone() {
        auto cars = db.get_all<Car>(where(c(&Car::Dostepnosc) == "Wypozyczony"));
        cout << "\n--- SAMOCHODY DO ZWROTU (WYPOZYCZONE) ---" << endl;
        if (cars.empty()) cout << "[Brak wypozyczonych aut]" << endl;
        for (auto &c : cars) {
            cout << "ID: " << c.ID << " | " << c.Marka << " " << c.Model << endl;
        }
    }

    void wyswietl_osoby() {
        auto users = db.get_all<User>();
        cout << "\n--- LISTA OSOB ---" << endl;
        for (auto &u : users) {
            cout << "ID: " << u.user_id << ". " << u.firstName << " " << u.lastName << endl;
        }
    }

    void wynajmij(int autoID, int osobaID) {
        auto car = db.get_pointer<Car>(autoID);
        if (car) {
            car->Dostepnosc = "Wypozyczony";
            car->userID = make_unique<int>(osobaID);
            db.update(*car);
            cout << "\n>>> Sukces: Wypozyczono auto!" << endl;
        }
    }

    void zwroc(int autoID) {
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