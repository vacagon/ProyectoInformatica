#ifndef ADMINISTRATOR_HPP
#define ADMINISTRATOR_HPP

#include <iostream>
#include "User.hpp"

using namespace std;

class Administrator: public User{

public:

    Administrator();

    bool isAdmin();

protected:



};

#endif // ADMINISTRATOR_HPP
