#include "Interface.hpp"

Interface::Interface(Manager &m) {
    manager = &m;
    shopping_cart = vector<Product*> ();

    //Flag to check the user is correctly created
    bool flag = false;
    cout << "*****************"
         << "WELCOME TO CompuGlobalHyperMegaComponents"
         << "*****************" << endl << endl;

    //Make sure is the first time the app is ejecuted,
    //and add an administrator
    if (manager->getUsers().size() == 0) {
        cout << endl << "In order to get under way "
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
            if (!manager->getCurrentMember()->isAdmin()) {
                HomeMenu();
            } else {
                HomeMenuAdministrator();
            }
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
             << "!" << endl << endl;
        cout << "*********"
             << "Select an option by tipping"
             << " the corresponding digit"
             << "*********" << endl
             << "-----------------------------------" << endl
             << "1. Edit account" << endl
             << "2. Add address" << endl
             << "3. Add payment information" << endl
             << "4. Show profile" << endl
             << "5. Make an order" << endl
             << "0. Log out" << endl;
        cin >> option;
        cin.ignore(10000,'\n');

        //Check if its a valid option
        if ((option < 0)||(option > 5)) {
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
        case 5:
            makeOrder();
            break;
        }
    }
}

void Interface::HomeMenuAdministrator() {
    bool valid_option = false;
    int option = -1;

    while ((!valid_option) || (option != 0)) {
        system("clear");
        cout << "Welcome administrator " << manager->getCurrentMember()->getUsername()
             << ", with employee code " << manager->getCurrentMember()->getEmployeeCode()
             << "!" << endl << endl;
        cout << "*********"
             << "Select an option by tipping"
             << " the corresponding digit"
             << "*********" << endl
             << "-----------------------------------" << endl
             << "1. Edit account" << endl
             << "2. Add address" << endl
             << "3. Add payment information" << endl
             << "4. Show profile" << endl
             << "5. Show members" << endl
             << "6. Add a new product" << endl
             << "7. Make an order" << endl
             << "0. Log out" << endl;
        cin >> option;
        cin.ignore(10000,'\n');

        //Check if its a valid option
        if ((option < 0)||(option > 7)) {
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
        case 5:
            showMembers();
            break;
        case 6:
            addProduct();
            break;
        case 7:
            makeOrder();
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

void Interface::showProfile() const {
    int option = -1;
    while (option != 0) {
        cout << "Username: " << manager->getCurrentMember()->getUsername() << endl << endl;
        cout << "Email: " << manager->getCurrentMember()->getEmail() << endl << endl;
        cout << "Password: " << manager->getCurrentMember()->getPassword() << endl << endl;
        if (manager->getCurrentMember()->isAdmin()) {
            cout << "Employee code: " << manager->getCurrentMember()->getEmployeeCode() << endl << endl;
        }
        cout << "Registered addresses: " << endl;
        if (manager->getCurrentMember()->getAddresses().size() > 0) {
            for (Address* address: manager->getCurrentMember()->getAddresses()) {
                cout << address->show() << endl;
            }
        } else {
            cout << "No address registered yet" << endl << endl;
        }
        cout << "Registered payment methods: " << endl;
        if (manager->getCurrentMember()->getPaymentMethods().size() > 0) {
            for (PaymentMethod* payment_method: manager->getCurrentMember()->getPaymentMethods()) {
                cout << payment_method->show() << endl;
            }
        } else {
            cout << "No payment method registered yet" << endl << endl;
        }
        cout << endl << "To go back to Home Menu enter 0" << endl;
        cin >> option;
    }
}

void Interface::showMembers() const {
    int i = 0;
    int option = -1;
    system("clear");
    cout << "The list of the registered users in the platform is:" << endl;
    cout << "---------------------------------------------------------" << endl;
    while (option != 0) {
        for (PublicUserData* public_data: manager->showMembers()) {
            cout << "User " << i+1 << " :" << endl
                 << "Username: " << public_data->getUsername() << endl
                 << "Reputation: " << public_data->getReputation() << endl << endl;
            i++;
        }
        cout << "To go back to Home Menu enter 0" << endl;
        cin >> option;
    }
}

void Interface::addProduct() {
    string name, description;
    unsigned long reference;
    float price;
    do {
        system("clear");
        cout << "You are about to add a new"
             << " product to the platform" << endl
             << endl << "Introduce the name of the product: ";
        getline(cin >> ws,name);
        cout << "Introduce a description for the product: ";
        getline(cin >> ws,description);
        cout << "Reference of the product: ";
        cin >> reference;
        cin.ignore(100, '\n');
        cout << "Price of the article [$]: ";
        cin >> price;
        cin.ignore(100, '\n');
    } while (!manager->addProduct(name,description,reference,price));
}

void Interface::makeOrder() {
    vector<unsigned long> products = vector<unsigned long> ();
    bool valid_option = false;
    int option = -1, payment_method = 0, shipping_address = 0;
    int i = 1;
    cout << "Chose products from the list:" << endl;
    showProducts();
    while ((!valid_option) || (option != 0)) {
        system("clear");
        cout << "*********"
             << "Select an option by tipping"
             << " the corresponding digit"
             << "*********" << endl
             << "-----------------------------------" << endl
             << "1. Add a new product to the cart" << endl
             << "2. Erase a product from the cart" << endl
             << "3. Show cart" << endl
             << "4. Make order" << endl
             << "0. Back to home menu" << endl;
        cin >> option;
        cin.ignore(10000,'\n');

        //Check if its a valid option
        if ((option < 0)||(option > 4)) {
            valid_option = false;
            system("clear");
            continue;
        } else {
            valid_option = true;
            system("clear");
        }

        //Implement the action requested by the user
        switch (option) {
        case 0:
            break;
        case 1:
            while (!addProductToCart()) {}
            break;
        case 2:
            while (!eraseProductFromCart()) {};
            break;
        case 3:
            showCart();
            break;
        case 4:
            for (Product* product: shopping_cart) {
                products.push_back(product->getReference());
            }
            if (manager->getCurrentMember()->getAddresses().size() > 0) {
                cout << "Chose a shipping address:" << endl;
                for (Address* address: manager->getCurrentMember()->getAddresses()) {
                    cout << i << ". " << address->show();
                    i++;
                }
                cin >> shipping_address;
                cin.ignore(100, '\n');
                shipping_address--;
            } else {
                cout << "There are no registered address. First"
                     << " you need to create one. It will be"
                     << "selected as this order's shipping address." << endl;
                addAddress();
            }
            if (manager->getCurrentMember()->getPaymentMethods().size() > 0) {
                cout << "Chose a payment method:" << endl;
                i = 1;
                for (PaymentMethod* paymethod: manager->getCurrentMember()->getPaymentMethods()) {
                    cout << i << ". " << paymethod->show();
                    i++;
                }
                cin >> payment_method;
                cin.ignore(100, '\n');
                payment_method--;
            } else {
                cout << "There are no registered payment methods. First"
                     << " you need to create one. It will be"
                     << "selected as this order's payment method." << endl;
                addPaymentMethod();
            }
            manager->makeOrder(products, payment_method, shipping_address);
            shopping_cart.clear();
            break;
        }
    }
}

void Interface::showProducts() {
    for (Product* product: manager->getProducts()) {
        cout << "------------------------------" << endl
             << product << endl;;
    }
}

bool Interface::addProductToCart() {
    unsigned long reference;
    bool flag = false;
    cout << endl << "Introduce the reference of the "
         << "product you want to add to the cart:";
    cin >> reference;
    cin.ignore(100, '\n');
    for (Product* product: manager->getProducts()) {
        if (reference == product->getReference()) {
            flag = true;
            shopping_cart.push_back(product);
        }
    }
    return flag;
}

void Interface::showCart() const {
    int option = -1;
    int i = 1;
    while (option != 0) {
        if (shopping_cart.size() > 0) {
            cout << endl << endl << "****SHOPPING CART****" << endl
                 << "-------------------------------------------" << endl
                 << "-------------------------------------------" << endl;
            for (Product* product: shopping_cart) {
                cout << i << ". " << endl << product << endl;
            }
        } else {
            cout << "Shopping cart is empty" << endl;
        }
        cout << endl << "Enter a 0 to go back";
        cin >> option;
        cin.ignore(100, '\n');
        cout << endl;
    }
}

bool Interface::eraseProductFromCart() {
    bool flag = false;
    int option = -1;
    system("clear");
    showCart();
    if (shopping_cart.size() > 0) {
        cout << "Enter the product you want to erase by "
             << "entering its number: ";
        cin >> option;
        cin.ignore(100, '\n');
        if (option < (int)shopping_cart.size()) {
            option --;
            shopping_cart.erase(shopping_cart.begin() + option);
            flag = true;
        } else {
            flag = false;
        }
    } else {
        flag = true;
    }
    return flag;
}

