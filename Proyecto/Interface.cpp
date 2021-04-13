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

void Interface::FrontPageMenu() {
    bool valid_option = false;
    int option = -1;
    while ((!valid_option) || (option != 0)) {
        system("clear");
        cout << "*********"
             << "Select an option by tipping"
             << " the corresponding digit"
             << "*********" << endl
             << "-----------------------------------" << endl
             << "1. Sign in" << endl
             << "2. Sign up" << endl
             << "0. Quit the app" << endl;
        cin >> option;
        cin.ignore(10000,'\n');

        //Check if its a valid option
        if ((option != 1)&&(option != 2)&&(option != 0)) {
            valid_option = false;
            cout << "NOT A VALID OPTION"
                 << ". TRY AGAIN" << endl;
            continue;;
            system("clear");
        } else {
            if (!manager->isLogged()) {
                valid_option = true;
            } else {
                if (option == 1) {
                    cout << "Sorry! Another user is already"
                         << " logged in the platform. Please"
                         << ", come back later" << endl;
                    valid_option = false;
                    continue;
                } else {
                    valid_option = true;
                }
            }
        }

        //Implement the action requested by the user
        switch (option) {
        case 0:
            system("clear");
            cout << "See you soon!" << endl;
            break;
        case 1:
            while (!login()) {}
            HomeMenu();
            break;
        case 2:
            while (!addUser()) {}
            break;
        }
    }
}

void Interface::HomeMenu() {
    system("clear");
    cout << "Welcome " << manager->getCurrentMember()->getUsername()
         << "!" << endl;
    bool valid_option = false;
    int option = -1;
    while ((!valid_option) || (option != 0)) {
        cout << "*********"
             << "Select an option by tipping"
             << " the corresponding digit"
             << "*********" << endl
             << "-----------------------------------" << endl
             << "1. Edit account" << endl
             << "0. Log out" << endl;
        cin >> option;
        cin.ignore(10000,'\n');

        //Check if its a valid option
        if ((option != 1)&&(option != 0)) {
            valid_option = false;
            cout << "NOT A VALID OPTION"
                 << ". TRY AGAIN" << endl;
            system("clear");
            continue;
        } else {
            valid_option = true;
            system("clear");
        }

        //Implement the action requested by the user
        switch (option) {
        case 0:
            system("clear");
            while (!manager->logout()) {}
            break;
        case 1:
            //editProfileMenu();
            break;
        }
    }

}

bool Interface::login() {
    system("clear");
    string email, password;
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

bool Interface::addUser() {
    int option = -1;
    bool valid_option = false;
    string username, password, email;
    do {
        cout << endl << endl;
        cout << "**CREATE A USER ACCOUNT**" << endl;
        cout << endl << endl;
        cout << "Select an option:" << endl
             << "1. Add a normal user" << endl
             << "2. Add an administrator" << endl;
        cin >> option;
        cin.ignore(100000,'\n');

        if ((option != 1)&&(option != 2)) {
            valid_option = false;
            cout << "NOT A VALID OPTION"
                 << ". TRY AGAIN" << endl;
            system("clear");
            continue;
        } else {
            valid_option = true;
            system("clear");
        }

        switch (option) {
        case 1:
            cout << "Username: ";
            getline(cin>>ws,username);
            cout << "Email: ";
            getline(cin>>ws,email);
            cout << "Password: ";
            getline(cin>>ws,password);
            return manager->addUser(username,email,password);
            break;
        case 2:
            while(!addAdministrator()) {}
            return addAdministrator();
            break;
        default:
            return false;
        }
    } while (!valid_option);

}


bool Interface::addAdministrator() {
    string username, password, email;
    unsigned long employee_code;
    cout << endl << endl;
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
