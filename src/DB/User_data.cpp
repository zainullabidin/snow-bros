// Minahil

#include"../../include/DB/User_data.h"

// constructor
User_data::User_data() : db(10), userId(0), username(""), passwordHash(""), email("") {
    db.createFileIfMissing(USERS_FILE);
} 


User_data::~User_data() {
    db.clear();
}

// fills the members above, returns true if found
bool User_data::findByUsername(const string& name) {
    db.readAllLines(USERS_FILE);

    string parts[4];  // id|name|pass hash|email
    int partCount = 0;

    // check for every line
    for (int i = 0; i < db.getCount(); i++) {
        splitstring(db.getLine(i), '|', parts, partCount);

        // parts >= 2 means that we have read the name, and the data was not incomplete or empty
        if (partCount >= 2 && parts[1] == name) {
            // found the user
            userId = stoi(parts[0]);
            username = parts[1];
            passwordHash = parts[2];
            email = parts[3];
            return true;
        }
    }

    // not found
    return false;
}

bool User_data::create(const string& uname, const string& hash, const string& mail) {
    if (usernameExists(uname)) {
        return false; // already occupied
    }

    int newId = getNextId();

    string line = to_string(newId) + "|" + uname + "|" + hash + "|" + mail;
    db.appendLine(USERS_FILE , line);  // add line at the end of file
    return true;
}

bool User_data::usernameExists(const string& name) {
    return findByUsername(name);        // simply call already checking function
}

// could have just done db.getCount() + 1  but what if we delete a user in file, it wont work
int User_data::getNextId() {
    db.readAllLines(USERS_FILE );

    int maxId = 0;
    int partCount = 0;
    string parts[4];  // id|name|pass hash|email

    for (int i = 0; i < db.getCount(); i++) {
        splitstring(db.getLine(i), '|', parts, partCount);

        if (partCount > 0 && !parts[0].empty()) {
            int id = stoi(parts[0]);        // 1st one is always the id
            if (id > maxId) {
                maxId = id;             // keep trackk of highest
            }
        }
    }
    return maxId + 1; // next id is the highest + 1
}

// getters 
int User_data::getUserId() const {
    return userId;
}

string User_data::getUsername() const {
    return username;
}

string User_data::getPasswordHash() const {
    return passwordHash;
}

string User_data::getEmail() const {
    return email;
}