#include <iostream>
#include "Manager.hpp"
#include "Interface.hpp"

using namespace std;

int main()
{
    Manager* manager = new Manager;
    Interface* interface = new Interface(*manager);

    //Used to select the option in the front page menu
    //The user can either log in into an existing account (1);
    //sign up (2), so a new user is created; or quit the app
    // and the execution finishes (0)
    int option1 = -1;
    while (option1 != 0) {
        option1 = interface->FrontPageMenu();
        switch (option1) {
        case 0:
            break;
        case 1:
            bool flag_login = false;
            while (!flag_login) {
                interface->login();
            }

        }
    }

    //Delete the objects created with dynamic memory
    delete interface;
    delete manager;
    return 0;
}
