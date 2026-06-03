-- Usuwanie istniejacych tabel
DROP TABLE IF EXISTS cars;
DROP TABLE IF EXISTS users;

-- Tabela users
CREATE TABLE users (
    userID INTEGER PRIMARY KEY AUTOINCREMENT,
    Imie TEXT NOT NULL,
    Nazwisko TEXT NOT NULL,
    Telefon TEXT,
    Email TEXT UNIQUE
);

-- Tabela cars
CREATE TABLE cars (
    ID INTEGER PRIMARY KEY AUTOINCREMENT,
    Marka TEXT NOT NULL,
    Model TEXT NOT NULL,
    Rok INTEGER,
    Status_techniczny TEXT,
    Dostepnosc TEXT,
    userID INTEGER,
    Przebieg INTEGER,
    Sposob_rozliczenia TEXT,
    FOREIGN KEY (userID) REFERENCES users(user_id) ON DELETE SET NULL
);

-- Wstawianie 20 uzytkownikow (bez polskich znakow)
INSERT INTO users (Imie, Nazwisko, Telefon, Email) VALUES
('Jan', 'Kowalski', '+48 600 100 200', 'jan.kowalski@example.com'),
('Anna', 'Nowak', '+48 511 222 333', 'anna.nowak@example.com'),
('Piotr', 'Wisniewski', '+48 700 300 400', 'piotr.wisniewski@test.pl'),
('Maria', 'Wojcik', '+48 800 400 500', 'm.wojcik@poczta.pl'),
('Krzysztof', 'Kowalczyk', '+48 900 500 600', 'krzysiek.k@firma.com'),
('Agnieszka', 'Kaminska', '+48 501 600 700', 'aga.kaminska@example.com'),
('Michal', 'Lewandowski', '+48 502 700 800', 'm.lewandowski@domena.pl'),
('Ewa', 'Zielinska', '+48 503 800 900', 'ewa.ziel@office.com'),
('Tomasz', 'Szymanski', '+48 504 900 000', 't.szymanski@provider.net'),
('Malgorzata', 'Wozniak', '+48 505 000 111', 'gosia.wozniak@web.pl'),
('Pawel', 'Kozlowski', '+48 506 111 222', 'p.kozlowski@serwis.pl'),
('Barbara', 'Jankowska', '+48 507 222 333', 'basia.j@portal.pl'),
('Jakub', 'Mazur', '+48 508 333 444', 'j.mazur@mail.com'),
('Magdalena', 'Wojciechowska', '+48 509 444 555', 'magda.w@info.pl'),
('Lukasz', 'Kwiatkowski', '+48 510 555 666', 'l.kwiatkowski@media.pl'),
('Katarzyna', 'Krawczyk', '+48 511 666 777', 'kasia.krawczyk@skrzynka.pl'),
('Andrzej', 'Kaczmarek', '+48 512 777 888', 'a.kaczmarek@expert.com'),
('Joanna', 'Piotrowska', '+48 513 888 999', 'j.piotrowska@pro.pl'),
('Robert', 'Grabowski', '+48 514 999 000', 'r.grabowski@biznes.pl'),
('Marta', 'Pawlak', '+48 515 000 123', 'marta.pawlak@life.pl');

-- Wstawianie 20 samochodow (Wszystkie Dostepne, userID to NULL)
INSERT INTO cars (Marka, Model, Rok, Status_techniczny, Dostepnosc, userID, Przebieg, Sposob_rozliczenia) VALUES
('Toyota', 'Corolla', 2018, 'Dobry', 'Dostepny', NULL, 85000, 'Gotowka'),
('Volkswagen', 'Golf', 2020, 'Nowy', 'Dostepny', NULL, 30000, 'Karta'),
('Ford', 'Focus', 2015, 'Uzywany', 'Dostepny', NULL, 145000, 'Przelew'),
('BMW', '320i', 2021, 'Idealny', 'Dostepny', NULL, 15000, 'Leasing'),
('Audi', 'A4', 2017, 'Dobry', 'Dostepny', NULL, 110000, 'Gotowka'),
('Skoda', 'Octavia', 2019, 'Bardzo dobry', 'Dostepny', NULL, 60000, 'Karta'),
('Mercedes', 'C-Klasa', 2022, 'Nowy', 'Dostepny', NULL, 5000, 'Leasing'),
('Honda', 'Civic', 2016, 'Uzywany', 'Dostepny', NULL, 120000, 'Przelew'),
('Hyundai', 'Tucson', 2020, 'Idealny', 'Dostepny', NULL, 45000, 'Gotowka'),
('Kia', 'Sportage', 2018, 'Dobry', 'Dostepny', NULL, 90000, 'Karta'),
('Volvo', 'XC60', 2021, 'Idealny', 'Dostepny', NULL, 25000, 'Leasing'),
('Renault', 'Clio', 2014, 'Sredni', 'Dostepny', NULL, 160000, 'Gotowka'),
('Peugeot', '3008', 2019, 'Bardzo dobry', 'Dostepny', NULL, 55000, 'Przelew'),
('Opel', 'Astra', 2017, 'Dobry', 'Dostepny', NULL, 105000, 'Karta'),
('Fiat', '500', 2022, 'Nowy', 'Dostepny', NULL, 2000, 'Gotowka'),
('Mazda', 'CX-5', 2019, 'Bardzo dobry', 'Dostepny', NULL, 48000, 'Przelew'),
('Tesla', 'Model 3', 2021, 'Idealny', 'Dostepny', NULL, 22000, 'Karta'),
('Dacia', 'Duster', 2020, 'Dobry', 'Dostepny', NULL, 35000, 'Gotowka'),
('Nissan', 'Qashqai', 2016, 'Uzywany', 'Dostepny', NULL, 130000, 'Przelew'),
('Lexus', 'RX', 2023, 'Nowy', 'Dostepny', NULL, 1000, 'Leasing');