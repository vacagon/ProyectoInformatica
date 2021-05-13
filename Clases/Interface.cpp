#include "Interface.hpp"

Interface::Interface(Manager &m) {
    manager = &m;
    shopping_cart = vector<Product*> ();
    bool flag = false;
    cout << "*****************"
         << "WELCOME TO CompuGlobalHyperMegaComponents"
         << "*****************" << endl << endl;
    manager->loadFromFile("manager_data.dat");
    if (manager->getUsers().size() == 0) {
        cout << endl << "In order to get under way "
             << "first you need to create"
             <<   " an administrator" << endl;
        do {
            flag = addAdministrator();
        } while (!flag);
    }
}

Interface::~Interface() {
    for (Product* card: shopping_cart) {
        delete card;
    }
}

void Interface::FrontPageMenu() {
    bool valid_option= false;
    int option = -1;
    while ((!valid_option) || (option != 0)) {
            cin.ignore(100, '\n');
            system("clear");
            cout << "*********"
                 << "Select an option by tipping"
                 << " the corresponding digit"
                 << "*********" << endl
                 << "-----------------------------------" << endl
                 << "1. Sign in" << endl
                 << "2. Sign up" << endl
                 << "0. Quit the app" << endl;
            option = ValidOption(0, 2);
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
        switch (option) {
        case 0:
            system("clear");
            shopping_cart.clear();
            manager->saveToFile("manager_data.dat");
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
        default:
            valid_option = false;
            break;
        }
    }
}

void Interface::HomeMenu() {
    int option = -1, delete_account;
    while (option != 0) {
        system("clear");
        cout << "Welcome administrator " << manager->getCurrentMember()->getUsername()
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
             << "5. Products" << endl
             << "6. Make an order" << endl
             << "7. Show shopping cart" << endl
             << "8. Reviews" << endl
             << "0. Log out/Delete account" << endl;
        option = ValidOption(0, 8);
        switch (option) {
        case 0:
            system("clear");
            cout << "Do you want to delete your account?" << endl
                 << "1. Yes" << endl
                 << "0. No" << endl;
            delete_account = ValidOption(0, 1);
            switch (delete_account) {
            case 0:
                manager->logout();
                break;
            case 1:
                manager->eraseCurrentMember();
                break;
            }
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
            cin.ignore(100, '\n');
            break;
        case 5:
            cout << showProducts() << endl;
            cin.ignore(100, '\n');
            cin.ignore(100, '\n');
            break;
        case 6:
            makeOrderMenu();
            break;
        case 7:
            cout << showCart() << endl;
            cin.ignore(100, '\n');
            cin.ignore(100, '\n');
            break;
        case 8:
            reviewsMenu();
            break;
        }
    }
}

void Interface::HomeMenuAdministrator() {
    int option = -1, delete_account = -1;
    while (option != 0) {
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
             << "11. Edit a product" << endl
             << "12. Reviews" << endl
             << "0. Log out/Delete account" << endl;
        option = ValidOption(0, 12);
        system("clear");
        switch (option) {
        case 0:
            system("clear");
            cout << "Do you want to delete your account?" << endl
                 << "1. Yes" << endl
                 << "0. No" << endl;
            delete_account = ValidOption(0, 1);
            switch (delete_account) {
            case 0:
                manager->logout();
                break;
            case 1:
                manager->eraseCurrentMember();
                break;
            }
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
            cin.ignore(100, '\n');
            break;
        case 5:
            cout << showMembers() << endl;
            cin.ignore(100, '\n');
            cin.ignore(100, '\n');
            break;
        case 6:
            cout << showProducts() << endl;
            cin.ignore(100, '\n');
            cin.ignore(100, '\n');
            break;
        case 7:
            addProduct();
            break;
        case 8:
            editProductMenu();
            break;
        case 9:
            makeOrderMenu();
            break;
        case 10:
            cout << showCart() << endl;
            cin.ignore(100, '\n');
            cin.ignore(100, '\n');
            break;
        case 11:
            if (manager->getProducts().size() > 0) {
                editProductMenu();
            } else {
                cout << "No product added yet" << endl;
                cin.ignore(100, '\n');
            }
        case 12:
            reviewsMenu();
            break;
        }
    }
}

void Interface::editAccountMenu() {
    int option = -1;
    while (option != 0) {
        system("clear");
        cout << "What do you want to edit?" << endl;
        cout << "----------------------------------" << endl;
        cout << "1. Edit username" << endl
             << "2. Edit email" << endl
             << "3. Edit password" << endl
             << "4. Edit registered addresses" << endl
             << "0. Back to Home Menu" << endl;
        option = ValidOption(0, 4);
        system("clear");
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
        }
    }
}

void Interface::makeOrderMenu() {
    vector<unsigned long> products = vector<unsigned long> ();
    int option = -1;
    while (option != 0) {
        system("clear");
        cout << showProducts() << endl;
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
        option = ValidOption(0, 4);
        if (manager->getProducts().size() == 0) {
            if ((option == 1)||(option == 2)) {
                cout << "No products added to the platform" << endl;
                cin.ignore(100, '\n');
                option = 0;
            }
        }
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
            cout << showCart() << endl;
            cin.ignore(100, '\n');
            cin.ignore(100, '\n');
            break;
        case 4:
            if (shopping_cart.size() > 0) {
                while (!makeOrder()) {}
                cout << showOrders() << endl;
                cin.ignore(100, '\n');
                shopping_cart.clear();
            } else {
                cout << "Shopping cart is empty. Choose a product first" << endl;
                cin.ignore(100, '\n');
            }
            break;
        }
    }
}

void Interface::reviewsMenu() {
    int option = -1;
    while (option != 0) {
        system("clear");  
        cout << "*********" << endl
             << "Select an option by tipping"
             << " the corresponding digit"
             << "*********" << endl
             << "-----------------------------------" << endl
             << "1. Make a review" << endl
             << "2. Show all reviews" << endl
             << "3. Show reviews by rating" << endl
             << "4. Vote review" << endl
             << "5. Modify review" << endl
             << "0. Back to home menu" << endl;
        option  = ValidOption(0, 5);
        cout << endl;
        switch (option) {
        case 0:
            break;
        case 1:
            createReview();
            break;
        case 2:
            cout << showReviews() << endl;
            cin.ignore(100, '\n');
            cin.ignore(100, '\n');
            break;
        case 3:
            cout << showReviewsByRating() << endl;
            cin.ignore(100, '\n');
            break;
        case 4:
            if (manager->getIdReviews().size() > 0) {
                voteReview();
            } else {
                cout << "No review has been made in the platform yet" << endl;
                cin.ignore(100, '\n');
            }
            break;
        case 5:
            if (manager->getIdReviews().size() > 0) {
                modifyReviewMenu();
            } else {
                cout << "No review has been made in the platform yet" << endl;
                cin.ignore(100, '\n');
            }
            break;
        }
    }
}

bool Interface::login() {
    system("clear");
    string email, password;
    cout << "Enter email: ";
    cin >> email;
    cin.ignore(100,'\n');
    cout << "Enter password: ";
    cin >> password;
    cin.ignore(100,'\n');
    if (manager->login(email, password)) {
        return true;
    } else {
        for (User* users: manager->getUsers()) {
            if (users->getEmail() == email) {
                cout << "Wrong password"
                     << ". Try again" << endl;
                cin.ignore(100, '\n');
                break;
            }
            if (users->getPassword() == password) {
                cout << "Wrong email"
                     << ". Try again" << endl;
                cin.ignore(100, '\n');
                break;
            }
        }
        return false;
    }
}

bool Interface::addUser() {
    int option = -1;
    bool flag = false;
    string username, password, email;
    system("clear");
    cout << "**CREATE A USER ACCOUNT**" << endl;
    cout << endl << endl;
    cout << "Select an option:" << endl
         << "1. Add a normal user" << endl
         << "2. Add an administrator" << endl;
    option = ValidOption(1, 2);
    system("clear");
    switch (option) {
    case 1:
        cout << "Username: ";
        getline(cin>>ws, username);
        cout << "Email: ";
        getline(cin>>ws, email);
        cout << "Password: ";
        getline(cin>>ws, password);
        flag = manager->addUser(username,email,password);
        break;
    case 2:
        flag = addAdministrator();
        break;
    }
    return flag;
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
    string new_password, new_password2;
    bool flag = false;
    do {
        system("clear");
        cout << "Introduce a new password: ";
        cin >> new_password;
        cin.ignore(100, '\n');
        cout << "Confirm the new password: ";
        cin >> new_password2;
        cin.ignore(100, '\n');
        if (new_password == new_password2) {
            manager->getCurrentMember()->setPassword(new_password);
            flag = true;
        } else {
            cout << "Wrong password. Try again" << endl;
            cin.ignore(100, '\n');
            flag = false;
        }
    } while (!flag);
    return flag;
}

void Interface::editAddress() {
    bool valid_option1 = false, valid_option2 = false;
    int option1 = -1, id = -1, option2 = -1;
    string address, city, province;
    unsigned int postal_code;
    while (!valid_option1) {
        system("clear");
        cout << "Chose an option: " << endl
             << "----------------------" << endl
             << "1. Edit an existing address" << endl
             << "2. Add a new address" << endl
             << "0. Go back" << endl;
        option1 = ValidOption(0, 2);

        if ((option1 == 1) && (manager->getCurrentMember()->getAddresses().size() == 0)) {
            cout << "There are no registered addresses yet" << endl;
            cin.ignore(100, '\n');
            valid_option1 = false;
        } else {
            valid_option1 = true;
        }
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
        cout << "Address you chose to edit: " << manager->getCurrentMember()->getAddresses()[id]->show() << endl
             << "Chose what you want to edit from this address: " << endl
             << "1. Address" << endl
             << "2. City" << endl
             << "3. Province" << endl
             << "4. Postal code" << endl
             << "0. Go back" << endl;
        option2 = ValidOption(0, 4);
        switch (option2) {
        case 0:
            break;
        case 1:
            cout << "Introduce new address: ";
            getline(cin >> ws, address);
            manager->getCurrentMember()->getAddresses()[id]->setAddress(address);
            break;
        case 2:
            cout << "Introduce new city: ";
            getline(cin >> ws, city);
            manager->getCurrentMember()->getAddresses()[id]->setCity(city);
            break;
        case 3:
            cout << "Introduce new province: ";
            getline(cin >> ws, province);
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
        addAddress();
        break;
    }
    system("clear");
    cout << "The registered addresses are:" << endl
         << showAddresses() << endl;
    cin.ignore(100, '\n');
}

void Interface::editProductMenu() {
    int option1 = -1, option2 = -1;
    bool valid_option1 = false, flag = true;
    string name, description;
    unsigned long reference;
    float price;
    while (!valid_option1) {
        system("clear");
        cout << "Chose the product to edit:" << endl
             << showProducts() << endl;
        cin >> option1;
        cin.ignore(100, '\n');
        if ((option1 < 1)||(option1 > (int)manager->getProducts().size())) {
                valid_option1 = false;
        } else {
            valid_option1 = true;
        }
    }
    option1--;
        system("clear");
        cout << "What do you want to edit?" << endl
             << "1. Name" << endl
             << "2. Description" << endl
             << "3. Reference" << endl
             << "4. Price" << endl;
        option2 = ValidOption(1, 4);
    switch (option2) {
    case 1:
        cout << "Actual name: " << manager->getProducts()[option1]->getName() << endl
             << "Introduce the new name: ";
        getline(cin >> ws, name);
        manager->getProducts()[option1]->setName(name);
        break;
    case 2:
        cout << "Actual description: " << manager->getProducts()[option1]->getDescription() << endl
             << "Introduce the new description: ";
        getline(cin >> ws, description);
        manager->getProducts()[option1]->setDescription(description);
        break;
    case 3:
        cout << "Actual reference: " << manager->getProducts()[option1]->getReference() << endl
             << "Introduce the new reference: ";
        cin >> reference;
        cin.ignore(100, '\n');
        for (Product* product : manager->getProducts()) {
            if (reference == product->getReference()) {
                flag = false;
            }
        }
        if (flag) {
            manager->getProducts()[option1]->setReference(reference);
        } else {
            cout << "There is other product with that reference" << endl;
            cin.ignore(100, '\n');
        }
        break;
    case 4:
        cout << "Actual price: " << manager->getProducts()[option1]->getPrice() << endl
             << "Introduce the new price: ";
        cin >> price;
        cin.ignore(100, '\n');
        if (price > 0) {
            manager->getProducts()[option1]->setPrice(price);
        } else {
            cout << "Price can't be negative" << endl;
            cin.ignore(100, '\n');
        }
        break;
    }
    system("clear");
    cout << "The new catalog of products is:" << endl
         << showProducts() << endl;
    cin.ignore(100, '\n');
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
    int option1 = -1, id_pm = 0, id_baddress = 0, option2 = -1;
    Address* billing_address;
    cout << "Select payment method:" << endl
         << "1. Credit card" << endl
         << "2. Paypal account" << endl
         << "0. Back to Home Menu" << endl;
    option1 = ValidOption(0, 2);
    if (option1 != 0) {
        cout << "Chose an option" << endl
             << "1. Chose an already registered address" << endl
             << "2. Create a new address" << endl;
        option2 = ValidOption(1, 2);
        system("clear");
        switch (option2) {
        case 1:
            cout << showAddresses() << endl;
            if (manager->getCurrentMember()->getAddresses().size() > 0) {
                cout << "Introduce the number of the address: ";
                cin >> id_baddress;
                if (id_baddress > (int)manager->getCurrentMember()->getAddresses().size()) {
                    id_baddress = manager->getCurrentMember()->getAddresses().size();
                }
                if (id_baddress < 1) {
                    id_baddress = 1;
                }
                id_baddress--;
                billing_address = manager->getCurrentMember()->getAddresses()[id_baddress];
            } else {
                cout << "You need to register a new address" << endl
                     << "This address will be selected as this "
                     << "payment method's you are about to register"
                     << " billing address" << endl;
                cin.ignore(100, '\n');
                addAddress();
                billing_address = manager->getCurrentMember()->getAddresses()[0];
            }
            break;
        case 2:
            addAddress();
            billing_address = manager->getCurrentMember()->getAddresses()[manager->getCurrentMember()->getAddresses().size() - 1];
            break;
        }
        id_pm  = manager->getCurrentMember()->getPaymentMethods().size();
        switch (option1) {
        case 0:
            break;
        case 1:
            addCreditCard(id_pm, billing_address);
            break;
        case 2:
            addPaypal(id_pm, billing_address);
            break;
        }
    }
}

void Interface::addCreditCard(const int& id, Address* billing_address) {
    unsigned long cardnumber = 0;
    string cardholder;
    cout << "Introduce credit card number: ";
    cin >> cardnumber;
    cin.ignore(100,'\n');
    cout << "Introduce the card holder: ";
    getline(cin >> ws, cardholder);
    CreditCard* new_card = new CreditCard(id, billing_address,cardnumber,cardholder);
    manager->getCurrentMember()->addPaymentMethod(new_card);
    manager->getCurrentMember()->addCreditCard(new_card);
}

void Interface::addPaypal(const int& id, Address* billing_address) {
    string email;
    cout << "Introduce email corresponding to your paypal account: ";
    cin >> email;
    cin.ignore(100,'\n');
    Paypal* new_paypal = new Paypal(id,billing_address,email);
    manager->getCurrentMember()->addPaymentMethod(new_paypal);
    manager->getCurrentMember()->addPaypal(new_paypal);
}

const string Interface::showProfile() {
    stringstream ss;
    ss << *manager->getCurrentMember() << endl;
    return ss.str();
}

const string Interface::showAddresses() const {
    stringstream ss;
    int i = 1;
    ss << "Registered addresses: " << endl << endl;
    if (manager->getCurrentMember()->getAddresses().size() > 0) {
        for (Address* address: manager->getCurrentMember()->getAddresses()) {
            ss << i << ". " << *address << endl;
            i++;
        }
    } else {
        ss << "No address registered yet" << endl << endl;
    }
    return ss.str();
}

const string Interface::showPaymentMethods() const {
    stringstream ss;
    int i = 0;
    ss << "Registered payment methods: " << endl << endl;
    if (manager->getCurrentMember()->getPaymentMethods().size() > 0) {
        for (PaymentMethod* payment_method: manager->getCurrentMember()->getPaymentMethods()) {
            ss << i+1 << ". " << payment_method->show() << endl;
            i++;
        }
    } else {
        ss << "No payment method registered yet" << endl << endl;
    }
    return ss.str();
}

const string Interface::showOrders() {
    stringstream ss;
    ss << "Previous orders: " << endl << endl;
    if (manager->getCurrentMember()->getOrders().size() > 0) {
        for (Order* order: manager->getCurrentMember()->getOrders()) {
            ss << "------------------------------" << endl;
            ss << *order << endl;
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
        ss << "User " << i+1 << endl << "-------------------" << endl
             << "Username: " << public_data->getUsername() << endl
             << "Reputation: " << public_data->getReputation() << endl << "********************" << endl;
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

const string Interface::showProducts() const {
    stringstream ss;
    ss << "***PRODUCT CATALOG***" << endl
       << "---------------------" << endl;
    if (manager->getProducts().size() > 0) {
        for (Product* product: manager->getProducts()) {
            ss << "------------------------------" << endl
               << *product << endl;;
        }
    } else {
        ss << "There are no products yet. "
           << "Please, come back later" << endl;
    }
    return ss.str();
}

bool Interface::addProductToCart() {
    unsigned long reference;
    bool flag = false;
    cout << endl << "Introduce the reference of the "
         << "product you want to add to the cart: ";
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
    int option = -1;
    system("clear");
    cout << showCart() << endl
         << "----------------------" << endl;
    if (shopping_cart.size() > 0) {
        cout << "Enter the product you want to erase by "
             << "entering its number: ";
        cin >> option;
        cin.ignore(100, '\n');
        if (option <= (int)shopping_cart.size()) {
            option --;
            shopping_cart.erase(shopping_cart.begin() + option);
            return true;
        } else {
            return false;
        }
    } else {
        cout << "There is no product added to shopping cart" << endl;
        cin.ignore(100, '\n');
        return true;
    }
}

bool Interface::makeOrder() {
    vector<unsigned long> products = vector<unsigned long> ();
    int payment_method = -1, shipping_address = -1, option_address = -1, option_pm = -1;
    for (Product* product: shopping_cart) {
        products.push_back(product->getReference());
    }
    system("clear");
    cout << "Where do you want to recieve your products?" << endl
         << "1. Chose an already registered address" << endl
         << "2. Add a new address" << endl;
    option_address = ValidOption(1, 2);
    if ((option_address == 1)&&(manager->getCurrentMember()->getAddresses().size() == 0)) {
        cout << "You don't have any registred address"
             << ". You'll need to create one" << endl;
        cin.ignore(100, '\n');
        option_address = 2;
    }
    system("clear");
    switch (option_address) {
    case 1:
        cout << "Chose the address: " << endl << showAddresses() << endl;
        cin >> shipping_address;
        cin.ignore(100, '\n');
        if (shipping_address < 0) {
            shipping_address = 0;
        }
        if (shipping_address > (int)manager->getCurrentMember()->getAddresses().size()) {
            shipping_address = (int)manager->getCurrentMember()->getAddresses().size();
        }
        shipping_address--;
        break;
    case 2:
        cout << "The address you're about to register will be"
             << "selected as this order's shipping address." << endl;
        cin.ignore(100, '\n');
        addAddress();
        shipping_address = manager->getCurrentMember()->getAddresses().size() - 1;
        break;
    }
    system("clear");
    cout << "How do you want to pay your products?" << endl
         << "1. Chose an already registered payment method" << endl
         << "2. Add a new payment method" << endl;
    option_pm = ValidOption(1, 2);
    if ((option_pm == 1)&&(manager->getCurrentMember()->getPaymentMethods().size() == 0)) {
        cout << "You don't have any registred payment method"
             << ". You'll need to create one" << endl;
        cin.ignore(100, '\n');
        option_pm = 2;
    }
    system("clear");
    switch (option_pm) {
    case 1:
        cout << "Chose the payment method: " << endl << showPaymentMethods() << endl;
        cin >> payment_method;
        cin.ignore(100, '\n');
        if(payment_method < 0) {
            payment_method = 0;
        }
        if (payment_method > (int)manager->getCurrentMember()->getPaymentMethods().size()) {
            payment_method = manager->getCurrentMember()->getPaymentMethods().size();
        }
        payment_method--;
        break;
    case 2:
        cout << "The payment method you're about to register will be"
             << "selected as this order's payment method." << endl;
        cin.ignore(100, '\n');
        addPaymentMethod();
        payment_method = manager->getCurrentMember()->getPaymentMethods().size() - 1;
        break;
    }
    return manager->makeOrder(products, payment_method, shipping_address);
}

void Interface::createReview() {
    system("clear");
    unsigned long reference;
    int rating;
    string text;
    bool valid_reference = false;
    if (manager->getCurrentMember()->getOrders().size() > 0) {
        do {
            cout << showProducts() << endl;
            cout << "Choose the product you want to review by introducing its reference: ";
            cin >> reference;
            for (Product* products: manager->getProducts()) {
                if (reference == products->getReference()) {
                    valid_reference = true;
                }
            }
            if (!valid_reference) {
                cout << "That reference doesn't correspond to any registered product" << endl;
                cin.ignore(100, '\n');
                system("clear");
            }
        } while(!valid_reference);
        cout << "Rate the product from 0 to 5: ";
        cin >> rating;
        cin.ignore(100, '\n');
        cout << "Introduce your review of the product: " << endl;
        getline(cin, text, '\n');
        cin.ignore(100, '\n');
    } else {
        cout << "You haven't ordered any product yet" << endl;
        cin.ignore(100, '\n');
    }
    if(manager->createReview(reference, rating, text)) {
        cout << "Your review has been succesfully created" << endl;
        for(Product* products: manager->getProducts()) {
            if (products->getReference() == reference) {
                cout << *products << endl;
            }
        }
        cin.ignore(100, '\n');
    } else {
        cout << "You need to buy the product in order to review it" << endl;
        cin.ignore(100, '\n');
    }
}

const string Interface::showReviews() const{
    stringstream ss;
    ss << "Reviews made in the platform:" << endl
       << "-------------------------------" << endl;
    for(Product* every_product: manager->getProducts()) {
        for (Review* every_review: every_product->getReviews()) {
            ss << "Id: " << every_review->getId() << endl
               << every_review->show() << endl;
        }
    }
    return ss.str();
}

const string Interface::showReviewsByRating() const {
    int rating = -1;
    stringstream ss;
    unsigned long reference;
    vector<Review*> reviews_rating = vector<Review*> ();
    cout << showProducts() << endl;
    cout << endl << "Introduce the reference of the product whose "
         << "reviews you want to filter by rating: ";
    cin >> reference;
    cin.ignore(100, '\n');
    system("clear");
    cout << showReviews() << endl;
    cout << endl << "By which rating you want to filter the reviews? "
         << "Introduce a number from 0 to 5: ";
    cin >> rating;
    cin.ignore(100, '\n');
    if (rating < 0) rating = 0;
    if (rating > 5) rating = 5;
    reviews_rating = manager->getReviewsByRating(reference, rating);
    if (reviews_rating.size() > 0) {
        for (Review* review: reviews_rating) {
            ss << "Id: " << review->getId() << endl
               << review->show() << endl;
        }
    } else {
        ss << "Wrong reference, or no review with that rating" << endl;
    }
    return ss.str();
}

void Interface::voteReview() {
    unsigned long id;
    int option = -1;
    system("clear");
    cout << showReviews() << endl
         << endl << "Enter the id of the review "
         << "you want to vote: ";
    cin >> id;
    cin.ignore(100, '\n');
    cout << "Choose an option" << endl
         << "1. Up vote" << endl
         << "2. Down vote" << endl;
    option = ValidOption(1, 2);
    switch (option) {
    case 1:
        if(manager->upvoteReview(id)) {
            cout << "Your vote has been registered" << endl;
            cin.ignore(100, '\n');
        } else {
            cout << "Something went wrong. Maybe the introduced id does "
                 << "not correspond to any existing review, and remember, "
                 << "you can not vote your own reviews" << endl;
            cin.ignore(100, '\n');
        }
        break;
    case 2:
        if(manager->downvoteReview(id)) {
            cout << "Your vote has been registered" << endl;
            cin.ignore(100, '\n');
        } else {
            cout << "Something went wrong. Maybe the introduced id does "
                 << "not correspond to any existing review, and remember, "
                 << "you can not vote your own reviews" << endl;
            cin.ignore(100, '\n');
        }
        break;
    }
}

void Interface::modifyReviewMenu() {
    int option = -1;
    unsigned long id;
    int new_rating = 0;
    string new_text;
    system("clear");
    cin.clear();
    cout << showReviews() << endl
         << endl << "Enter the id of the review "
         << "you want to modify: ";
    cin >> id;
    cin.ignore(100, '\n');
    cout << "Choose an option" << endl
         << "1. Rating" << endl
         << "2. Text" << endl
         << "3. Delete review" << endl;
    option = ValidOption(1, 3);
    system("clear");
    switch (option) {
    case 1:
        cout << "Introduce the new rating: ";
        new_rating = ValidOption(0, 5);
        if (manager->modifyReviewRating(id, new_rating)) {
            cout << "Your have modified the rating to " << new_rating << endl;
            cin.ignore(100, '\n');
        } else {
            cout << "Something went wrong. Maybe the introduced id does "
                 << "not correspond to any existing review, and remember, "
                 << "you can not modify other user's reviews" << endl;
            cin.ignore(100, '\n');
        }
        break;
    case 2:
        cin.clear();
        cout << "Introduce the new text: ";
        getline(cin, new_text);
        if (manager->modifyReviewText(id, new_text)) {
            cout << "Your have modified the text of the review to: " << new_text << endl;
            cin.ignore(100, '\n');
        } else {
            cout << "Something went wrong. Maybe the introduced id does "
                 << "not correspond to any existing review, and remember, "
                 << "you can not modify other user's reviews" << endl;
            cin.ignore(100, '\n');
        }
        break;
    case 3:
        if(manager->deleteReview(id)) {
            cout << "You have deleted review with id " << id << endl;
            cin.ignore(100, '\n');
        } else {
            cout << "Something went wrong. Maybe the introduced id does "
                 << "not correspond to any existing review, and remember, "
                 << "you can not delete other user's reviews unless"
                 << " you're an administrator" << endl;
            cin.ignore(100, '\n');
        }
        break;
    }
}

int Interface::ValidOption(int lower_bound, int upperbound) {
    int x = -1;
    cin >> x;
    while ((cin.fail())||(x < lower_bound)||(x > upperbound)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Bad entry. Enter a number" << endl;
        cin >> x;
    }
    return x;
}
