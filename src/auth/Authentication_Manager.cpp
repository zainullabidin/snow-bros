#include "../../include/auth/Authentication_Manager.h"

// constructor

Authentication::Authentication(Session *s) : session(s) {}

// djb2 hash implementation
string Authentication::hashPassword(const string& pass)
{
    unsigned long hash = 5381;

    // pass 1 1 character of pass into c
    for(char c : pass)
    {
        hash = hash * 33 + c;
    }

    return to_string(hash);
}


AuthResult Authentication::registerUser(const string& username, const string& password)
{
    // no input
    if (username.empty() || password.empty())
        return INVALID_INPUT;

    // If user is found, it means username is already taken
    if (userRepo.findByUsername(username))
        return USERNAME_TAKEN;

    // Create the new user
    string hashedPass = hashPassword(password);
    if (userRepo.create(username, hashedPass))
    {
        // Automatically log in the new user
        return login(username, password);
    }

    // just a fallback
    return INVALID_INPUT;
}

// simply auto save on every level end
// simply save all the current states
void Authentication::autoSave(int level, int lives, int gems, int score)
{
    if(!session->isLoggedIn())
        return;

    // simply save all the current states
    progressRepo.saveProgress(session->getUserId(), level, lives, gems, score);
}


// check already present data
AuthResult Authentication::login(const string &username, const string &password)
{
    if (username.empty() || password.empty())
        return INVALID_INPUT;

    if (!userRepo.findByUsername(username))
        return USER_NOT_FOUND;

    if (userRepo.getPasswordHash() != hashPassword(password))
        return WRONG_PASSWORD;

    // set data
    session->isLoggedIn();
    session->setUsername(username);
    session->setUserId(userRepo.getUserId());

    return SUCCESS;
}


bool Authentication::isLoggedIn() {
    return session->isLoggedIn();
}

Session* Authentication::getSession() {
    return session;
}