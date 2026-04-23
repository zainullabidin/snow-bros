#include"../../include/auth/Session_holder.h"

Session_holder::~Session_holder() {}

bool Session_holder::isLoggedIn() {
    return loggedIn;
}

std::string Session_holder::getUsername() {
    return username;
}

int Session_holder::getUserId() {
    return user_id;
}

void Session_holder::clear() {
    loggedIn = false;
    username = "";
    user_id = 0;
}