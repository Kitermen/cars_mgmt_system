-- users.sql
-- Tabela użytkowników

CREATE TABLE IF NOT EXISTS users (
    osoba_id INTEGER PRIMARY KEY,
    imie TEXT NOT NULL,
    nazwisko TEXT NOT NULL,
    nr_telefon TEXT,
    email TEXT UNIQUE
);

INSERT INTO users (osoba_id, imie, nazwisko, nr_telefon, email) VALUES
(1, 'Jan', 'Kowalski', '+48 600 100 200', 'jan.kowalski@example.com'),
(2, 'Anna', 'Nowak', '+48 511 222 333', 'anna.nowak@example.com'),
(3, 'Marek', 'Wiśniewski', '+48 789 456 123', 'marek.wisniewski@example.com'),
(4, 'Katarzyna', 'Zielińska', '+48 502 333 444', 'katarzyna.zielinska@example.com');   
