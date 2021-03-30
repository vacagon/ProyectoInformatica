#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <vector>
#include "PublicUserData.hpp"
#include "PrivateUserData.hpp"

using namespace std;

/** @brief Users of the plataform*/
class User: public PrivateUserData , public PublicUserData {

protected:
    
    User();

public:
    
    User(string& username, string& email, string password): PrivateUserData(email, password), PublicUserData(username) {};

    /**
     * @brief Returns false if the user is not an administrator
     * and true if it is*/
    virtual bool isAdmin();

};

#endif // USER_HPP
