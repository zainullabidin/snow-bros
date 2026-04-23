#pragma once
#include <string>
using namespace std;


class Session_holder {

protected:
    string username;
    int user_id;
    bool loggedIn;

    public:
    Session_holder() : loggedIn(false), username(""), user_id(0) {};
    ~Session_holder();

    // basic methids
    bool isLoggedIn();
    string getUsername();
    int getUserId();
    void clear();
};