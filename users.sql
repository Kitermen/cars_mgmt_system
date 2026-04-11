-- cars_mgmt_system.sql
-- Baza danych: cars_mgmt_system
-- Tabele: users, cars

-- Usuwanie istniejących tabel (opcjonalne)
DROP TABLE IF EXISTS cars;
DROP TABLE IF EXISTS users;

-- Tabela users
CREATE TABLE users (
    user_id INTEGER PRIMARY KEY AUTOINCREMENT,
    firstName TEXT NOT NULL,
    lastName TEXT NOT NULL,
    phone TEXT,
    email TEXT UNIQUE
);

-- Tabela cars
CREATE TABLE cars (
    ID INTEGER PRIMARY KEY AUTOINCREMENT,
    Marka TEXT NOT NULL,
    Model TEXT NOT NULL,
    Nadwozie TEXT,
    Rok INTEGER,
    Status_techniczny TEXT,
    Dostepnosc TEXT,
    userID INTEGER,
    Przebieg INTEGER,
    Sposob_rozliczenia TEXT,
    FOREIGN KEY (userID) REFERENCES users(user_id) ON DELETE SET NULL
);

-- Przykładowi użytkownicy
INSERT INTO users (firstName, lastName, phone, email) VALUES
('Jan', 'Kowalski', '+48 600 100 200', 'jan.kowalski@example.com'),
('Anna', 'Nowak', '+48 511 222 333', 'anna.nowak@example.com');

-- Przykładowe samochody
INSERT INTO cars (Marka, Model, Nadwozie, Rok, Status_techniczny, Dostepnosc, userID, Przebieg, Sposob_rozliczenia) VALUES
('Toyota', 'Corolla', 'Sedan', 2018, 'Dobry', 'Dostepny', 2, 85000, 'Gotowka'),
('Volkswagen', 'Golf', 'Hatchback', 2020, 'Nowy', 'Dostepny', NULL, 30000, 'Karta');   
