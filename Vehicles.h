#pragma once
#include <iostream>
#include <string>
#include <memory>

using namespace std;

// Struktura przechowująca surowe dane o samochodzie
struct Car {
    int ID;
    string Marka;
    string Model;
    int Rok;
    string Status_techniczny;
    string Dostepnosc;
    unique_ptr<int> userID; // Inteligentny wskaźnik - automatycznie zarządza pamięcią (brak wycieków)
    int Przebieg;
    string Sposob_rozliczenia;
};

// Abstrakcyjna klasa bazowa dla pojazdów
class Vehicle {
protected:
    string brand;  
    string model; 
    int year;      
public:
    // Wirtualny destruktor - zapewnia poprawne usuwanie obiektów klas pochodnych przez wskaźnik bazowy
    virtual ~Vehicle() = default;
    
    // Czysto wirtualna metoda - czyni klasę abstrakcyjną (nie można utworzyć jej instancji)
    virtual void display() const = 0;
};

// Klasy pochodne implementujące polimorficzną metodę display()
class PassengerCar : public Vehicle {
public:
    // override: kontrola kompilatora nad nadpisywaniem metody
    void display() const override { cout << "Passenger Car | "; } 
};

class DeliveryVan : public Vehicle {
public:
    void display() const override { cout << "Delivery Van | "; }
};

class Motorcycle : public Vehicle {
public:
    void display() const override { cout << "Motorcycle | "; }
};