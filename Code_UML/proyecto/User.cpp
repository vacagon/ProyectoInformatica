#include "User.hpp"

User::User(string& us, string& em, string& pas) {
    int rep = 0;
    PublicUserData(us,rep);
    PrivateUserData(em, pas);
}

User::~User() {}

bool User::isAdmin() {
    return false;
}

