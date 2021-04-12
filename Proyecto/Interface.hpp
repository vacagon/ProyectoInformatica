#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "Manager.hpp"

using namespace std;

class Interface {

public:

    Interface(Manager& m);

    bool addAdministrator();

    /**
     * @brief Let the user chose if the
     * wants to sign in (1) or sign up (2)
     * @return Option selected by
     * the user
     */
    int FrontPageMenu();

    bool login();

private:

    Manager* manager;

};

#endif // INTERFACE_HPP
