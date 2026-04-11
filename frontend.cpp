#include <iostream>
 
using namespace std;
 
int main() {
    int wybor;
 
    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Wyswietl pojazdy" << endl;
        cout << "2. Wyswietl dostepne pojazdy" << endl;
        cout << "3. Wynajmij samochod" << endl;
        cout << "4. Zwroc samochod" << endl;
        cout << "5. Wyszukaj samochod" << endl;
        cout << "6. Zmien stan techniczny" << endl;
        cout << "7. Zmien dostepnosc" << endl;
        cout << "8. Zmien przebieg" << endl;
        cout << "9. Wyjdz z systemu" << endl;
        cout << "Wybierz opcje: ";
        cin >> wybor;
 
        switch (wybor) {
            case 1:
                cout << "Wybrano: Wyswietl pojazdy" << endl;
                break;
            case 2:
                cout << "Wybrano: Wyswietl dostepne pojazdy" << endl;
                break;
            case 3:
                cout << "Wybrano: Wynajmij samochod" << endl;
                break;
            case 4:
                cout << "Wybrano: Zwroc samochod" << endl;
                break;
            case 5:
                cout << "Wybrano: Wyszukaj samochod" << endl;
                break;
            case 6:
                cout << "Wybrano: Zmien stan techniczny" << endl;
                break;
            case 7:
                cout << "Wybrano: Zmien dostepnosc" << endl;
                break;
            case 8:
                cout << "Wybrano: Zmien przebieg" << endl;
                break;
            case 9:
                cout << "Wyjscie z systemu..." << endl;
                break;
            default:
                cout << "Nieprawidlowa opcja!" << endl;
        }
 
    } while (wybor != 9);
 
    return 0;
}
