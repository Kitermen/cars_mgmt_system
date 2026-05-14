#pragma once
#include <iostream>
#include <string>

using namespace std;

// Struktura mapująca tabelę 'users'
struct User {
    int user_id;
    string firstName;
    string lastName;
    string phone;
    string email;
};

class Osoba {
private:
    string imie;
    string nazwisko;
public:
    Osoba(string i, string n) : imie(i), nazwisko(n) {}
    void dodaj_osobe() {
        cout << "Dodano osobe: " << imie << " " << nazwisko << endl;
    }
};
