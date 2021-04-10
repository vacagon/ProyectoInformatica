#include "Interface.hpp"

Interface::Interface(Manager &m) {
    manager = &m;
    bool flag = false;
    cout << "WELCOME TO CompuGlobalHyperMegaComponents" << endl;
    cout << "In order to get under way "
         << "you need to create an administrator" << endl;
    do {
        flag = addAdministrator();
    } while (!flag);
}

bool Interface::addAdministrator() {
    string username, password, email;
    unsigned long employee_code;
    system("clear");
    cout << "**CREATE AN ADMINISTRATOR ACCOUNT**" << endl;
    cout << "Username: ";
    getline(cin>>ws,username);
    cout << "Email: ";
    getline(cin>>ws,email);
    cout << "Password: ";
    getline(cin>>ws,password);
    cout << ("Employee code: ");
    cin >> employee_code;
    return manager->addAdministrator(username,email,password,employee_code);
}
