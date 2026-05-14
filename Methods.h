#pragma once
#include <vector>
#include <iostream>
#include "Database.h"

using namespace std;

class Wypozyczalnia {
    Storage &db;

public:
    Wypozyczalnia(Storage &st) : db(st) {}

    void wyswietl_wszystkie() {
        auto cars = db.get_all<Car>();
        cout << "\n--- LISTA POJAZDOW W BAZIE ---" << endl;
        for (auto &c : cars) {
            cout << c.ID << ". " << c.Marka << " " << c.Model 
                 << " (" << c.Rok << ") - Przebieg: " << c.Przebieg << " km" << endl;
        }
    }

    void wyswietl_osoby() {
        auto users = db.get_all<User>();
        cout << "\n--- LISTA OSOB W BAZIE ---" << endl;
        for (auto &u : users) {
            cout << u.user_id << ". " << u.firstName << " " << u.lastName 
                 << " | Tel: " << u.phone << endl;
        }
    }
};