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


class Vehicle {
protected:
    string brand;  
    string model; 
    int year;      
public:
    virtual ~Vehicle() = default;
    virtual void display() const = 0;
};

class PassengerCar : public Vehicle {
public:
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