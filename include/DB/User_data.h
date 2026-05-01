
// Minahil

#pragma once
#include "Data_base.h"

class User_data  {
private:
    int userId;
    string username;
    string passwordHash;    // we get the hash pass here , doo hashing in auth.h
    string email;
    Data_base db;     // composition

    // splitstring(string str, char symbol);

public:
    
    User_data();
    ~User_data();

    // fills the members above, returns true if found
    bool findByUsername(const string& name);

    bool create(const string& uname, const string& hash);
    bool usernameExists(const string& name);

    // could have just done db.getCount() + 1  but what if we delete a user in file, it wont work
    int  getNextId();

    // getters so other classes can read the found record
    int getUserId() const;
    string getUsername() const;
    string getPasswordHash() const;
    string getEmail() const;
    
};