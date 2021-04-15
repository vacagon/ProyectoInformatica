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

    bool addUser();

    /**
     * @brief Let the user chose if the
     * wants to sign in (1) or sign up (2)
     * or close the app (0)
     */
    void FrontPageMenu();

    /**
     * @brief Allow the logged user
     * do all the actions allowed by
     * the class manager
     */
    void HomeMenu();

    bool login();

    void editAccountMenu();

    bool editUsername();

    bool editEmail();

    bool editPassword();

    void addAddress();

    void addPaymentMethod();

    void addCreditCard();

    void addPaypal();

    void showProfile();

private:

    Manager* manager;

};

#endif // INTERFACE_HPP
