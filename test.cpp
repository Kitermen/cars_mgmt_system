#include <iostream>
#include <cstdlib>
#include <vector>




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
    Pojazd(string marka, string model, string rok, string status_techniczny,
           string dostepnosc, int przebieg, string sposob_rozl)
        : marka(marka), model(model), rok(rok), status_techniczny(status_techniczny),
          dostepnosc(dostepnosc), przebieg(przebieg), sposob_rozl(sposob_rozl) {}

    virtual ~Pojazd() = default;

    virtual void wyswietl() const = 0;
};



class Osobowy : public Pojazd {
public:
    Osobowy(string marka, string model, string rok, string status_techniczny,
            string dostepnosc, int przebieg, string sposob_rozl)
        : Pojazd(marka, model, rok, status_techniczny, dostepnosc, przebieg, sposob_rozl) {}

    void wyswietl() const override {
        cout << "Osobowy " << marka << " " << model << " (" << rok << ")\n";
    }
};


class Dostawczy : public Pojazd{
public:
    Dostawczy(string marka, string model, string rok, string status_techniczny, string dostepnosc, int przebieg, string sposob_rozl) : Pojazd(marka, model, rok, status_techniczny, dostepnosc, przebieg, sposob_rozl){}

    void wyswietl() const override {
        cout << "Dostawczy " << marka << " " << model << " (" << rok << ")\n";
    }

};


class Motocykl : public Pojazd {
public:
    Motocykl(string marka, string model, string rok, string status_techniczny,
             string dostepnosc, int przebieg, string sposob_rozl)
        : Pojazd(marka, model, rok, status_techniczny, dostepnosc, przebieg, sposob_rozl) {}

    void wyswietl() const override {
        cout << "Motocykl " << marka << " " << model << " (" << rok << ")\n";
    }
};




class Wypozyczalnia {
    vector<Pojazd*> pojazdy;

public:
    Wypozyczalnia() {
        cout << "Stworzono obiekt wypozyczalnia\n";
    }

    ~Wypozyczalnia() {
        for (auto p : pojazdy) delete p; 
    }

    void dodaj_pojazd(Pojazd* p) {
        pojazdy.push_back(p);
        cout << "Dodano pojazd\n";
    }

    void usun_pojazd(int i) {
        pojazdy.erase(pojazdy.begin() + i);
        cout << "Usunieto pojazd pod indeksem" << i << endl;
    }

    void wyswietl_wszystkie() const {
        if (pojazdy.size() <= 0){
            cout << "Nie ma żadnych pojazdów w wypozyczalni" << endl;
        } else{
            cout << "Lista pojazdow" << endl;
            for (auto p : pojazdy) p->wyswietl();
        }
        
    }
};



int main() {
    int numer_pojazdu;
    Wypozyczalnia w;
    w.dodaj_pojazd(new Osobowy("Honda", "Civic", "1998", "DOBRY", "DOSTEPNY", 200000, "GOTOWKA"));
    w.wyswietl_wszystkie();
    cin >> numer_pojazdu;
    w.usun_pojazd(numer_pojazdu);
    w.wyswietl_wszystkie();

    return 0;
}