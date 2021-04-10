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

private:

    Manager* manager;

};

#endif // INTERFACE_HPP
