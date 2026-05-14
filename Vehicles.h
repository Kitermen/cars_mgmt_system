#pragma once
#include <iostream>
#include <string>
#include <memory>

using namespace std;


struct Car {
    int ID;
    string Marka;
    string Model;
    int Rok;
    string Status_techniczny;
    string Dostepnosc;
    unique_ptr<int> userID;
    int Przebieg;
    string Sposob_rozliczenia;
};

class Pojazd {
protected:
    string marka;
    string model;
    int rok;
public:
    virtual ~Pojazd() = default;
    virtual void wyswietl() const = 0;
};

class Osobowy : public Pojazd {
public:
    void wyswietl() const override { cout << "Osobowy | "; }
};

class Dostawczy : public Pojazd {
public:
    void wyswietl() const override { cout << "Dostawczy | "; }
};

class Motocykl : public Pojazd {
public:
    void wyswietl() const override { cout << "Motocykl | "; }
};
