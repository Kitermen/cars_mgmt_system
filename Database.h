#pragma once
#include <string>

#include "sqlite3.h" 

#include "sqlite_orm/include/sqlite_orm/sqlite_orm.h"

#include "Vehicles.h"
#include "Persons.h"

using namespace sqlite_orm;
using namespace std;

inline auto initStorage(const string &path) {
    return make_storage(path,
        make_table("users",
            make_column("user_id", &User::user_id, primary_key().autoincrement()),
            make_column("firstName", &User::firstName),
            make_column("lastName", &User::lastName),
            make_column("phone", &User::phone),
            make_column("email", &User::email)),
        make_table("cars",
            make_column("ID", &Car::ID, primary_key().autoincrement()),
            make_column("Marka", &Car::Marka),
            make_column("Model", &Car::Model),
            make_column("Rok", &Car::Rok),
            make_column("Status_techniczny", &Car::Status_techniczny),
            make_column("Dostepnosc", &Car::Dostepnosc),
            make_column("userID", &Car::userID),
            make_column("Przebieg", &Car::Przebieg),
            make_column("Sposob_rozliczenia", &Car::Sposob_rozliczenia))
    );
}

typedef decltype(initStorage("")) Storage;