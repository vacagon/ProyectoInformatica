#include "Interface.hpp"

Interface::Interface(Manager &m) {
    manager = &m;
    bool flag = false;
    cout << "*****************"
         << "WELCOME TO CompuGlobalHyperMegaComponents"
         << "*****************" << endl;
    if (manager->getUsers().size() == 0) {
        cout << "In order to get under way "
             << "first you need to create"
             <<   " an administrator" << endl;
        do {
            flag = addAdministrator();
        } while (!flag);
    }
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
    bool valid_option = false;
    int option = -1;
    while ((!valid_option) || (option != 0)) {
        system("clear");
        cout << "Welcome " << manager->getCurrentMember()->getUsername()
             << "!" << endl;
        cout << "*********"
             << "Select an option by tipping"
             << " the corresponding digit"
             << "*********" << endl
             << "-----------------------------------" << endl
             << "1. Edit account" << endl
             << "2. Add address" << endl
             << "3. Add payment information" << endl
             << "4. Show profile" << endl
             << "0. Log out" << endl;
        cin >> option;
        cin.ignore(10000,'\n');

        //Check if its a valid option
        if ((option < 0)||(option > 4)) {
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
            editAccountMenu();
            break;
        case 2:
            addAddress();
            break;
        case 3:
            addPaymentMethod();
            break;
        case 4:
            showProfile();
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

void Interface::editAccountMenu() {
    int option = -1;
    bool valid_option = false;
    while ((!valid_option)||(option != 0)) {
        system("clear");
        cout << "What do you want to edit?" << endl;
        cout << "----------------------------------" << endl;
        cout << "1. Edit username" << endl
             << "2. Edit email" << endl
             << "3. Edit password" << endl
             << "0. Back to Home Menu" << endl;
        cin >> option;
        cin.ignore(10000,'\n');

        //Check if its a valid option
        if ((option < 0)||(option > 3)) {
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
            break;
        case 1:
            while (!editUsername()) {};
            break;
        case 2:
            while (!editEmail()) {};
            break;
        case 3:
            while (!editPassword()) {};
            break;
        }
    }
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

bool Interface::editUsername() {
    string new_username;
    bool flag = true;
    cout << "Actual username: "
         << manager->getCurrentMember()->getUsername()
         << endl << "Introduce a new username: ";
    cin >> new_username;
    cin.ignore(100, '\n');
    for (unsigned long i = 0; i < manager->getUsers().size(); i++) {
        if (new_username == manager->getUsers()[i]->getUsername()) {
            flag = false;
            cout << "Another User has that username" << endl;
        }
    }
    if (flag) manager->getCurrentMember()->setUsername(new_username);
    return flag;
}

bool Interface::editEmail() {
    string new_email;
    bool flag = true;
    cout << "Actual email: "
         << manager->getCurrentMember()->getEmail()
         << endl << "Introduce a new email: ";
    cin >> new_email;
    cin.ignore(100, '\n');
    for (unsigned long i = 0; i < manager->getUsers().size(); i++) {
        if (new_email == manager->getUsers()[i]->getEmail()) {
            flag = false;
            cout << "Another User has that email" << endl;
        }
    }
    if (flag) manager->getCurrentMember()->setEmail(new_email);
    return flag;
}

bool Interface::editPassword() {
    string new_password, old_password;
    bool flag = false;
    cout << "Introduce your actual password: ";
    cin >> old_password;
    cin.ignore(100, '\n');
    if (old_password == manager->getCurrentMember()->getPassword()) {
        cout << "Introduce a new password: ";
        cin >> new_password;
        cin.ignore(100,'\n');
        manager->getCurrentMember()->setPassword(new_password);
        flag = true;
    } else {
        cout << "Wrong password. Try again" << endl;
        flag = false;
    }
    return flag;
}

void Interface::addAddress() {
    system("clear");
    string address, city, province;
    unsigned int postal_code;
    int id = -1;
    cout << "Introduce an address: ";
    getline(cin >> ws, address);
    cout << "Introduce the city: ";
    getline(cin >> ws, city);
    cout << "Introduce province: ";
    getline(cin >> ws, province);
    cout << "Introduce postal code: ";
    cin >> postal_code;
    id = manager->getCurrentMember()->getAddresses().size();
    Address* new_address = new Address(address,city,province,postal_code,id);
    manager->getCurrentMember()->addAddress(new_address);
    system("clear");
}

void Interface::addPaymentMethod() {
    system("clear");
    int option = -1;
    bool valid_option = false;
    while (!valid_option) {
        cout << "Select payment method:" << endl
             << "1. Credit card" << endl
             << "2. Paypal account" << endl;
        cin >> option;
        cin.ignore(100,'\n');
        if ((option != 1)&&(option != 2)) {
            valid_option = false;
        } else {
            valid_option = true;
        }
        system("clear");
    }
    switch (option) {
    case 1:
        addCreditCard();
        break;
    case 2:
        addPaypal();
        break;
    }
}

void Interface::addCreditCard() {
    unsigned long cardnumber = 0;
    string cardholder;
    int id = 0;
    int i = 1;
    Address* billing_address = nullptr;
    if (manager->getCurrentMember()->getAddresses().size() > 0) {
        cout << "Chose a billing address:" << endl;
        for (Address* address: manager->getCurrentMember()->getAddresses()) {
            cout << i << ". " << address->show();
            i++;
        }
        cin >> id;
        id--;
        billing_address = manager->getCurrentMember()->getAddresses()[id];
    } else {
        cout << "There are no registered address. First"
             << " you need to create one." << endl;
        addAddress();
        billing_address = manager->getCurrentMember()->getAddresses()[id];
    }
    cout << "Introduce credit card number: ";
    cin >> cardnumber;
    cin.ignore(100,'\n');
    cout << "Introduce the card holder: ";
    getline(cin, cardholder);
    cin.ignore(100,'\n');
    id  = manager->getCurrentMember()->getPaymentMethods().size();
    CreditCard* new_card = new CreditCard(id, billing_address,cardnumber,cardholder);
    manager->getCurrentMember()->addPaymentMethod(new_card);
}

void Interface::addPaypal() {
    string email;
    int id = 0;
    int i = 1;
    Address* billing_address = nullptr;
    if (manager->getCurrentMember()->getAddresses().size() > 0) {
        cout << "Chose a billing address:" << endl;
        for (Address* address: manager->getCurrentMember()->getAddresses()) {
            cout << i << ". " << address->show();
            i++;
        }
        cin >> id;
        id--;
        billing_address = manager->getCurrentMember()->getAddresses()[id];
    } else {
        cout << "There are no registered address. First"
             << " you need to create one." << endl;
        addAddress();
        billing_address = manager->getCurrentMember()->getAddresses()[id];
    }
    cout << "Introduce email corresponding to your paypal account: ";
    cin >> email;
    cin.ignore(100,'\n');
    id  = manager->getCurrentMember()->getPaymentMethods().size();
    Paypal* new_paypal = new Paypal(id,billing_address,email);
    manager->getCurrentMember()->addPaymentMethod(new_paypal);
}

void Interface::showProfile() {
    int option = -1;
    while (option != 0) {
        cout << "Username: " << manager->getCurrentMember()->getUsername() << endl;
        cout << "Email: " << manager->getCurrentMember()->getEmail() << endl;
        cout << "Password: " << manager->getCurrentMember()->getPassword() << endl;
        if (manager->getCurrentMember()->isAdmin()) {
            cout << "Employee code: " << manager->getCurrentMember()->getEmployeeCode() << endl;
        }
        cout << "Registered addresses: " << endl;
        if (manager->getCurrentMember()->getAddresses().size() > 0) {
            for (Address* address: manager->getCurrentMember()->getAddresses()) {
                cout << address->show() << endl;
            }
        } else {
            cout << "No address registered yet" << endl;
        }
        cout << "Registered payment methods: " << endl;
        if (manager->getCurrentMember()->getPaymentMethods().size() > 0) {
            for (PaymentMethod* payment_method: manager->getCurrentMember()->getPaymentMethods()) {
                cout << payment_method->show() << endl;
            }
        } else {
            cout << "No payment method registered yet" << endl;
        }
        cout << "To go back to Home Menu enter 0" << endl;
        cin >> option;
    }
}
