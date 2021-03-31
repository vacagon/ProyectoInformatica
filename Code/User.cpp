#include "User.hpp"

User::User(string& username, string& email, string& password, int reputation){
    PrivateUserData(email, password);
    PublicUserData(username, reputation);
};

User::~User() {}

bool User::isAdmin() {
    return false;
}
