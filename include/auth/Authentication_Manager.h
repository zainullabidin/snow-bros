#pragma once
#include "Session_holder.h"
#include "../DB/User_data.h"
#include "../DB/Progress_data.h"

enum AuthResult
{
    SUCCESS, NOT_FOUND, WRONG_PASS, ALREADY_TAKEN, INVALID_INPUT
};

class Authentication
{

private:
    Session *session; // aggreagation
    User_data userRepo;         // composition
    Progress_data progressRepo;     // compositon

    string hashPassword(const string& pass);

public:
 
    Authentication(Session* s);

    AuthResult login(const string& username, const string& password);
    AuthResult registerUser(const string& username, const string& password);
    
    // simply auto save on every level end
    void autoSave(int level, int lives, int gems, int score);

    bool isLoggedIn();
    Session* getSession();
};