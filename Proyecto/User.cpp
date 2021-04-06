#include "User.hpp"

User::User(string &us, string &em, string &pas):
    PublicUserData(us), PrivateUserData(em, pas) {}

User::~User() {}

bool User::isAdmin() {
    return false;
}

unsigned long User::getEmployeeCode() const {
    return 0;
}
