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
            shopping_cart.clear();
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
             << "5. Products"
             << "6. Make an order" << endl
             << "7. Shopping cart" << endl
             << "0. Log out" << endl;
        cin >> option;
        cin.ignore(10000,'\n');
        if ((option < 0)||(option > 7)) {
            valid_option = false;
            system("clear");
            continue;
        } else {
            valid_option = true;
            system("clear");
        }
        switch (option) {
        case 0:
            while (!manager->logout()) {}
            shopping_cart.clear();
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
            cout << showProfile() << endl;
            cin.ignore(100, '\n');
            break;
        case 5:
            cout << showProducts() << endl;
            cin.ignore(100, '\n');
            break;
        case 6:
            makeOrderMenu();
            break;
        case 7:
            cout << showCart() << endl;
            cin.ignore(100, '\n');
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
             << "6. Products" << endl
             << "7. Add a new product" << endl
             << "8. Edit a product" << endl
             << "9. Make an order" << endl
             << "10. Show shopping cart" << endl
             << "0. Log out" << endl;
        cin >> option;
        cin.ignore(10000,'\n');
        if ((option < 0)||(option > 10)) {
            valid_option = false;
            system("clear");
            continue;
        } else {
            valid_option = true;
            system("clear");
        }
        switch (option) {
        case 0:
            while (!manager->logout()) {}
            shopping_cart.clear();
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
            cout << showProfile() << endl;
            cin.ignore(100, '\n');
            break;
        case 5:
            cout << showMembers() << endl;
            cin.ignore(100, '\n');
            break;
        case 6:
            cout << showProducts() << endl;
            cin.ignore(100, '\n');
            break;
        case 7:
            addProduct();
            break;
        case 8:
            //editProductMenu();
            break;
        case 9:
            makeOrderMenu();
            break;
        case 10:
            cout << showCart() << endl;
            cin.ignore(100, '\n');
            break;
        }
    }
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
             << "4. Edit registered addresses" << endl
             << "5. Edit registered payment method" << endl
             << "0. Back to Home Menu" << endl;
        cin >> option;
        cin.ignore(100,'\n');
        if ((option < 0)||(option > 5)) {
            valid_option = false;
            system("clear");
            continue;
        } else {
            valid_option = true;
            system("clear");
        }
        switch (option) {
        case 0:
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
        case 4:
            editAddress();
            break;
        case 5:
            //editPaymentMethod();
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
        return true;
    } else {
        cout << "Contraseña incorrecta"
             << ". Intentelo de nuevo" << endl;
        cin.ignore(100, '\n');
        return false;
    }
}

bool Interface::addUser() {
    int option = -1;
    bool valid_option = false, flag = false;
    string username, password, email;
    do {
        cout << endl << endl;
        cout << "**CREATE A USER ACCOUNT**" << endl;
        cout << endl << endl;
        cout << "Select an option:" << endl
             << "1. Add a normal user" << endl
             << "2. Add an administrator" << endl;
        cin >> option;
        cin.ignore(100,'\n');
        if ((option != 1)&&(option != 2)) {
            valid_option = false;
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
            flag = manager->addUser(username,email,password);
            break;
        case 2:
            flag = addAdministrator();
            break;
        }
    } while (!valid_option);
    return flag;
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

void Interface::editAddress() {
    bool valid_option1 = false, valid_option2 = false, valid_option3 = false;
    int option1 = -1, id = -1, option2 = -1;
    string address, city, province;
    unsigned int postal_code;
    while (!valid_option1) {
        cout << "Chose an option: " << endl
             << "----------------------" << endl
             << "1. Edit an existing address" << endl
             << "2. Delete an address" << endl
             << "3. Add a new address" << endl
             << "0. Go back" << endl;
        cin >> option1;
        cin.ignore(100, '\n');
        if ((option1 < 0)||(option1 > 3)) {
            valid_option1 = false;
        } else {
            if ((option1 < 3) && (option1 != 0) && (manager->getCurrentMember()->getAddresses().size() == 0)) {
                cout << "There are no registered options yet" << endl;
                cin.ignore(100, '\n');
                valid_option1 = false;
            } else {
                valid_option1 = true;
            }
        }
        system("clear");
    }
    switch (option1) {
    case 0:
        break;
    case 1:
        while (!valid_option2) {
            cout << "Chose an address: " << endl
                 << showAddresses() << endl;
            cin >> id;
            cin.ignore(100, '\n');
            if ((id < 0)||(id > (int)manager->getCurrentMember()->getAddresses().size())) {
                valid_option2 = false;
            } else {
                valid_option2 = true;
            }
            system("clear");
        }
        id --;
        while (!valid_option3) {
            cout << "Address you chose to edit: " << manager->getCurrentMember()->getAddresses()[id]->show() << endl
                 << "Chose what you want to edit from this address: " << endl
                 << "1. Address" << endl
                 << "2. City" << endl
                 << "3. Province" << endl
                 << "4. Postal code" << endl
                 << "0. Go back" << endl;
            cin >> option2;
            if ((option2 < 0)||(option2 > 4)) {
                valid_option3 = false;
            } else {
                valid_option3 = true;
            }
            system("clear");
        }
        switch (option2) {
        case 0:
            break;
        case 1:
            cout << "Introduce new address: ";
            getline(cin >> ws, address);
            cin.ignore(100, '\n');
            manager->getCurrentMember()->getAddresses()[id]->setAddress(address);
            break;
        case 2:
            cout << "Introduce new city: ";
            getline(cin >> ws, city);
            cin.ignore(100, '\n');
            manager->getCurrentMember()->getAddresses()[id]->setCity(city);
            break;
        case 3:
            cout << "Introduce new province: ";
            getline(cin >> ws, province);
            cin.ignore(100, '\n');
            manager->getCurrentMember()->getAddresses()[id]->setProvince(province);
            break;
        case 4:
            cout << "Introduce postal code: ";
            cin >> postal_code;
            cin.ignore(100, '\n');
            manager->getCurrentMember()->getAddresses()[id]->setPostalCode(postal_code);
            break;
        }
        break;
    case 2:
        while (!valid_option2) {
            cout << "Chose an address: " << endl
                 << showAddresses() << endl;
            cin >> id;
            cin.ignore(100, '\n');
            if ((id < 0)||(id > (int)manager->getCurrentMember()->getAddresses().size())) {
                valid_option2 = false;
            } else {
                valid_option2 = true;
            }
            system("clear");
        }
        id --;
        manager->getCurrentMember()->getAddresses().erase(manager->getCurrentMember()->getAddresses().begin() + id);
        for (unsigned int j = 0; j < manager->getCurrentMember()->getAddresses().size(); j++) {
            manager->getCurrentMember()->getAddresses()[j]->setId(j);
        }
        if (manager->getCurrentMember()->getAddresses().size() > 0) {
            cout << "Now the register addresses are: " << endl << showAddresses();
        }
        cin.ignore(100, '\n');
        break;
    case 3:
        addAddress();
        break;
    }
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
    int option1 = -1, id = 0, i = 1, option2 = -1;
    Address* billing_address;
    bool valid_option1 = false, valid_option2 = false;
    while (!valid_option1) {
        cout << "Select payment method:" << endl
             << "1. Credit card" << endl
             << "2. Paypal account" << endl
             << "0. Back to Home Menu" << endl;
        cin >> option1;
        cin.ignore(100,'\n');
        if ((option1 < 0)||(option1 > 2)) {
            valid_option1 = false;
        } else {
            valid_option1 = true;
        }
        system("clear");
    }
    while ((!valid_option2)&&(option1 != 0)) {
        cout << "Chose an option" << endl
             << "1. Chose an already registered address" << endl
             << "2. Create a new address" << endl;
        cin >> option2;
        cin.ignore(100, '\n');
        if ((option2 != 1)&&(option1 != 2)) {
            valid_option2 = false;
        } else {
            valid_option2 = true;
        }
        system("clear");
    }
    if ((manager->getCurrentMember()->getAddresses().size() > 0)&&(option2 == 1)) {
        for (Address* address: manager->getCurrentMember()->getAddresses()) {
            cout << i << ". " << address->show();
            i++;
        }
        cin >> id;
        if (id > manager->getCurrentMember()->getAddresses().size()) {
            id = manager->getCurrentMember()->getAddresses().size();
        } else {
            if (id < 1) {
                id = 1;
            }
        }
        id--;
        billing_address = manager->getCurrentMember()->getAddresses()[id];
        id  = manager->getCurrentMember()->getPaymentMethods().size();
    } else {
        cout << "There are no registered address. First"
             << " you need to create one." << endl;
        addAddress();
        billing_address = manager->getCurrentMember()->getAddresses()[0];
    }
    switch (option1) {
    case 0:
        break;
    case 1:
        addCreditCard(id, billing_address);
        break;
    case 2:
        addPaypal(id, billing_address);
        break;
    }
}

void Interface::addCreditCard(const int& id, const Address* billing_address) {
    unsigned long cardnumber = 0;
    string cardholder;

    cout << "Introduce credit card number: ";
    cin >> cardnumber;
    cin.ignore(100,'\n');
    cout << "Introduce the card holder: ";
    getline(cin >> ws, cardholder);
    cin.ignore(100,'\n');

    CreditCard* new_card = new CreditCard(id, billing_address,cardnumber,cardholder);
    manager->getCurrentMember()->addPaymentMethod(new_card);
}

void Interface::addPaypal(const int& id, const Address* billing_address) {
    string email;
    cout << "Introduce email corresponding to your paypal account: ";
    cin >> email;
    cin.ignore(100,'\n');
    Paypal* new_paypal = new Paypal(id,billing_address,email);
    manager->getCurrentMember()->addPaymentMethod(new_paypal);
}

const string Interface::showProfile() const {
    stringstream ss;
    ss << showUserData() << endl;
    ss << showAddresses() << endl;
    ss << showPaymentMethods() << endl;
    ss << showOrders() << endl;
    return ss.str();
}

const string Interface::showUserData() const {
    stringstream ss;
    ss << "Username: " << manager->getCurrentMember()->getUsername() << endl << endl;
    ss << "Email: " << manager->getCurrentMember()->getEmail() << endl << endl;
    ss << "Password: " << manager->getCurrentMember()->getPassword() << endl << endl;
    if (manager->getCurrentMember()->isAdmin()) {
        ss << "Employee code: " << manager->getCurrentMember()->getEmployeeCode() << endl << endl;
    }
    return ss.str();
}

const string Interface::showAddresses() const {
    stringstream ss;
    int i = 0;
    ss << "Registered addresses: " << endl;
    if (manager->getCurrentMember()->getAddresses().size() > 0) {
        for (Address* address: manager->getCurrentMember()->getAddresses()) {
            ss << i+1 << ". " << address->show() << endl;
        }
    } else {
        ss << "No address registered yet" << endl << endl;
    }
    return ss.str();
}

const string Interface::showPaymentMethods() const {
    stringstream ss;
    ss << "Registered payment methods: " << endl;
    if (manager->getCurrentMember()->getPaymentMethods().size() > 0) {
        for (PaymentMethod* payment_method: manager->getCurrentMember()->getPaymentMethods()) {
            ss << payment_method->show() << endl;
        }
    } else {
        ss << "No payment method registered yet" << endl << endl;
    }
    return ss.str();
}

const string Interface::showOrders() const {
    stringstream ss;
    ss << "Previous orders: " << endl;
    if (manager->getCurrentMember()->getOrders().size() > 0) {
        for (Order* order: manager->getCurrentMember()->getOrders()) {
            ss << "------------------------------" << endl;
            for (unsigned long product_reference: order->getProducts()) {
                for (Product* products: manager->getProducts()) {
                    if (products->getReference() == product_reference) {
                        ss << products << endl;
                    }
                }
            }
            ss << "------------------------------" << endl;
        }
    } else {
        ss << "No orders made yet" << endl << endl;
    }
    return ss.str();
}

const string Interface::showMembers() const {
    stringstream ss;
    int i = 0;
    ss << "The list of the registered users in the platform is:" << endl;
    ss << "---------------------------------------------------------" << endl;
    for (PublicUserData* public_data: manager->showMembers()) {
        ss << "User " << i+1 << " :" << endl
             << "Username: " << public_data->getUsername() << endl
             << "Reputation: " << public_data->getReputation() << endl << endl;
        i++;
    }
    return ss.str();
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

void Interface::makeOrderMenu() {
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

const string Interface::showProducts() {
    stringstream ss;
    for (Product* product: manager->getProducts()) {
        ss << "------------------------------" << endl
             << product << endl;;
    }
    return ss.str();
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

const string Interface::showCart() const {
    int i = 1;
    stringstream ss;
    if (shopping_cart.size() > 0) {
        ss << endl << endl << "****SHOPPING CART****" << endl
             << "-------------------------------------------" << endl
             << "-------------------------------------------" << endl;
        for (Product* product: shopping_cart) {
            ss << i << ". " << endl << *product << endl;
            i++;
        }
    } else {
        ss << "Shopping cart is empty" << endl;
    }
    ss << endl;
    return ss.str();
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

