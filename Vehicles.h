#pragma once

#include <iostream>
#include <unistd.h>
#include <string>
#include <fstream>


using namespace std;

class Pojazd {

protected:
    string marka;
    string model;
    string rok;
    string status_techniczny;
    string dostepnosc;
    int przebieg;
    string sposob_rozl;

public:
    Pojazd(string marka, string model, string rok, string status_techniczny, string dostepnosc, int przebieg, string sposob_rozl) 
    :marka(marka), model(model), rok(rok), status_techniczny(status_techniczny), dostepnosc(dostepnosc), przebieg(przebieg), sposob_rozl(sposob_rozl)  {}
    virtual ~Pojazd() = default;
    virtual void dodaj_pojazd() = 0;
    virtual void usun_pojazd() = 0;

};


class Osobowy: public Pojazd{

    private:
        const string typ = "Osobowy";


    public:

        Osobowy(string marka, string model) : Pojazd(marka, model, rok, status_techniczny, dostepnosc, przebieg, sposob_rozl) {}
        ~Osobowy() override;

        void dodaj_pojazd() override{
            
            cout << "Pojazd typu osobowy został dodany do bazy" << endl;
            cout << marka <<" "<< model <<" "<< typ << endl;

        }


        void usun_pojazd() override{


            cout << "Pojazd osobowy został usunięty z bazy" << endl;
            cout << marka <<" "<< model << " "<< typ << endl;

        }

};


class Dostawczy : public Pojazd{

    private:
        const string typ = "Dostawczy";


    public:

        Dostawczy(string marka, string model) : Pojazd(marka, model, rok, status_techniczny, dostepnosc, przebieg, sposob_rozl){}
        ~Dostawczy() override;

        void dodaj_pojazd() override{

            cout << "Pojazd typu dostawczy został dodany do bazy" << endl;

            //Wpisanie do bazy danych logika
            cout << marka <<" "<< model << " "<< typ << endl;
        }

        void usun_pojazd() override{
            
            cout << "Pojazd typu dostawczy został usunięty z bazy" << endl;
            cout << marka <<" "<< model << " "<< typ << endl;
        }


};


class Motocykl : public Pojazd{

    private:
        const string typ = "Motocykl";

    public:

        Motocykl(string marka, string model) : Pojazd(marka, model, rok, status_techniczny, dostepnosc, przebieg, sposob_rozl) {}
        ~Motocykl() override;

        void dodaj_pojazd() override{
            cout << "Pojazd typu motocykl został dodany do bazy" << endl;
            cout << marka <<" "<< model << " "<< typ << endl;
        }

        void usun_pojazd() override{
            cout << "Pojazd typu motocykl został usunięty z bazy" << endl;
            cout << marka <<" "<< model << " "<< typ << endl;
        }
};

