#pragma once
#include <iostream>
#include <string>

using namespace std;

// Struktura reprezentująca pojedynczego użytkownika (rekord danych)
struct User {
    int userID;       // Unikalny identyfikator użytkownika (np. klucz główny)
    string Imie;      // Przechowuje imię użytkownika
    string Nazwisko;  // Przechowuje nazwisko użytkownika
    string Telefon;   // Numer telefonu (jako string, aby zachować zera wiodące i formatowanie)
    string Email;     // Adres e-mail użytkownika
};