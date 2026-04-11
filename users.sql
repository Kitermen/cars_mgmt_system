-- users.sql
-- Tabela użytkowników

CREATE TABLE IF NOT EXISTS users (
    user_id INTEGER PRIMARY KEY,
    firstName TEXT NOT NULL,
    lastName TEXT NOT NULL,
    phone TEXT,
    email TEXT UNIQUE
);

INSERT INTO users (user_id, firstName, lastName, phone, email) VALUES
(1, 'Jan', 'Kowalski', '+48 600 100 200', 'jan.kowalski@example.com'),
(2, 'Anna', 'Nowak', '+48 511 222 333', 'anna.nowak@example.com'),
(3, 'Marek', 'Wiśniewski', '+48 789 456 123', 'marek.wisniewski@example.com'),
(4, 'Katarzyna', 'Zielińska', '+48 502 333 444', 'katarzyna.zielinska@example.com');   