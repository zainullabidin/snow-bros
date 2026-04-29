#include"../../include/auth/Session_holder.h"

Session::~Session() {}

bool Session::isLoggedIn() {
    return loggedIn;
}

std::string Session::getUsername() {
    return username;
}

int Session::getUserId() {
    return user_id;
}

void Session::clear() {
    loggedIn = false;
    username = "";
    user_id = 0;
}


string Session::setUsername(string username) {
    this->username = username;
    return username;
}

void Session::setUserId(int user_id) {
    this->user_id = user_id;
}
