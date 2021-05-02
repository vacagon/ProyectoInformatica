#include "User.hpp"

User::User(const string &us, const string &em, const string &pas):
    PublicUserData(us), PrivateUserData(em, pas) {}

User::~User() {}

bool User::isAdmin() {
    return false;
}

unsigned long User::getEmployeeCode() const {
    return 0;
}
