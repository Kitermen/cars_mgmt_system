#pragma once

#include <iostream>
#include <unistd.h>
#include <string>
#include <fstream>


using namespace std;

class Osoba {

    private:
        string imie;
        string nazwisko;
        string nr_telefonu;
        string email;

    public:
        Osoba(string imie, string nazwisko, string nr_telefonu, string email) :imie(imie), nazwisko(nazwisko), nr_telefonu(nr_telefonu), email(email) {}

        void dodaj_osobe(){
            cout << "Dodano nową osobę do bazy" << endl;
            cout << imie << " " << nazwisko << " " << nr_telefonu << " " << email << endl;
        }

        void usun_osobe(){
            cout << "Usunięto osobę do bazy" << endl;
            cout << imie << " " << nazwisko << " " << nr_telefonu << " " << email << endl;

        }



    
};