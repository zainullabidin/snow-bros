#pragma once
#include <string>
using namespace std;


class Session {

protected:
    string username;
    int user_id;
    bool loggedIn;

    public:
    Session() : loggedIn(false), username(""), user_id(0) {};
    ~Session();

    // basic methids
    string getUsername();
    int getUserId();

    string setUsername(string username);
    void setUserId(int user_id);
    bool setLoggedIn(bool log);


    bool isLoggedIn();
    void clear();
};