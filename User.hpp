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
    
    User(): PrivateUserData(), PublicUserData() {};

public:

    User(string& user_name, string& email, string& password, int reputation = 0);

    virtual ~User();

    /**
     * @brief Returns false if the user is not an administrator
     * and true if it is*/
    virtual bool isAdmin();

};

#endif // USER_HPP
