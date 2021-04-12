#include "Interface.hpp"

Interface::Interface(Manager &m) {
    manager = &m;
    bool flag = false;
    cout << "*****************"
         << "WELCOME TO CompuGlobalHyperMegaComponents"
         << "*****************" << endl;
    cout << "In order to get under way "
         << "first you need to create"
         <<   " an administrator" << endl;
    do {
        flag = addAdministrator();
    } while (!flag);
}

int Interface::FrontPageMenu() {
    system("clear");
    bool valid_option = false;
    int option = -1;
    while (!valid_option) {
        cout << "*********"
             << "Select an option by tipping"
             << "the corresponding digit"
             << "*********" << endl
             << "-----------------------------------" << endl
             << "1. Sign in" << endl
             << "2. Sign up" << endl
             << "0. Quit the app" << endl;
        cin >> option;
        cin.ignore(10000,'\n');
        if ((option != 1)&&(option != 2)&&(option != 0)) {
            valid_option = false;
            cout << "NOT A VALID OPTION"
                 << ". TRY AGAIN" << endl;
            system("clear");
        } else {
            valid_option = true;
        }
    }
    return option;
}

bool Interface::login() {
    system("clear");
    string username, email, password;
    cout << "Enter username: ";
    cin >> username;
    cin.ignore(10000,'\n');
    cout << "Enter email: ";
    cin >> email;
    cin.ignore(10000,'\n');
    cout << "Enter password: ";
    cin >> password;
    cin.ignore(10000,'\n');
    if (manager->login(email, password)) {
        cout << "Contraseña correcta" << endl;
        return true;
    } else {
        cout << "Contraseña incorrecta"
             << ". Intentelo de nuevo" << endl;
        return false;
    }
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
