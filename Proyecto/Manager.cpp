#include "Manager.hpp"

//################# PRIMERA ENTREGA ############################//

Manager::Manager() {
    users = vector<User*> ();
    products = vector<Product*> ();
    current_member = -1;
}

Manager::~Manager() {
    for (unsigned long i = 0; i < users.size(); i++) {
        delete users[i];
    }
    for (unsigned long i = 0; i < products.size(); i++) {
        delete products[i];
    }
    users.clear();
    products.clear();
}

const vector<User *> &Manager::getUsers() const {
    return users;
}

const vector<Product *> &Manager::getProducts() const {
    return products;
}

bool Manager::login(const string& email, const string& password) {
    bool flag = false;
    if (current_member == -1) {
        for (unsigned long i = 0; i < users.size(); i++) {
            if ((users[i]->getEmail() == email)&&(users[i]->getPassword() == password)) {
                current_member = i;
                flag = true;
                break;
            }
        }
    }
    return flag;
}

bool Manager::logout() {
    bool flag = false;
    if (isLogged()) {
        current_member = -1;
        flag = true;
    }
    return flag;
}

bool Manager::isLogged() {
    bool flag = false;
    if ((current_member != -1) && (current_member < (int)users.size())) {
        flag = true;
    }
    return flag;
}

User* Manager::getCurrentMember() {
    User* cmember;
    if (isLogged()) {
        cmember = users[current_member];
        return cmember;
    } else {
        return nullptr;
    }
}

bool Manager::addUser(const string &username, const string &email, const string &password) {
    for (User* user: users) {
        if ((user->getEmail() == email)||(user->getUsername() == username)) {
            return false;
        }
    }
    User* new_user = new User(username,email,password);
    users.push_back(new_user);
    return true;
}

bool Manager::addAdministrator(const string &username, const string &email, const string &password, const unsigned long &employee_code) {
    for (User* user: users) {
        if ((user->getEmail() == email)||(user->getUsername() == username)||(user->getEmployeeCode() == employee_code)) {
            return false;
        }
    }
    Administrator* new_admin = new Administrator(username,email,password,employee_code);
    users.push_back(new_admin);
    return true;
}

bool Manager::eraseCurrentMember() {
    bool flag = false;
    if (isLogged()) {
        delete users[current_member];
        users.erase(users.begin() + current_member);
        current_member = -1;
        flag = true;
    }
    return flag;
}

bool Manager::editUsername(const string& new_username) {
    bool flag = true;
    if (!isLogged()) {
        return false;
    } else {
        for (User* user: users) {
            if (user->getUsername() == new_username) {
                flag = false;
            }
        }
        if (flag) {
           users[current_member]->setUsername(new_username);
           return true;
        } else {
            return false;
        }
    };
}

bool Manager::editEmail(const string& new_email) {
    bool flag = true;
    if (!isLogged()) {
        return false;
    } else {
        for (User* user: users) {
            if (user->getEmail() == new_email) {
                flag = false;
            }
        }
        if (flag) {
           users[current_member]->setEmail(new_email);
           return true;
        } else {
            return false;
        }
    };
}

bool Manager::editPassword(const string& new_password) {
    if (!isLogged()) {
        return false;
    } else {
        users[current_member]->setPassword(new_password);
        return true;
    }
}

bool Manager::addAddress(const string &address, const string &city, const string &province, const unsigned int &postal_code) {
    bool flag = false;
    int id = users[current_member]->getAddresses().size();
    if (isLogged()) {
        Address* new_address = new Address(address, city, province, postal_code,id);
        users[current_member]->addAddress(new_address);
        flag = true;
    }
    return flag;
}

bool Manager::addCreditCard(const Address *address, const unsigned long &number, const string &cardholder) {
    bool flag = false;
    int id = users[current_member]->getPaymentMethods().size();
    if (isLogged()) {
        CreditCard* new_creditcard = new CreditCard(id, address, number, cardholder);
        users[current_member]->addPaymentMethod(new_creditcard);
        flag = true;
    }
    return flag;
}

bool Manager::addPaypal(const Address* address, string& email) {
    bool flag = false;
    int id = users[current_member]->getPaymentMethods().size();
    if (isLogged()) {
        Paypal* new_paypal = new Paypal(id, address, email);
        users[current_member]->addPaymentMethod(new_paypal);
        flag = true;
    }
    return flag;
}

//################# SEGUNDA ENTREGA ############################//

bool Manager::addProduct(const string& name, const string& description, const unsigned long& reference, const float& price) {
    bool flag = true;
    if (!isLogged()) {
        return false;
    } else {
        if (!getCurrentMember()->isAdmin()) {
            return false;
        } else {
            for (Product* product: products) {
                if (product->getReference() == reference) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
            Product* new_product = new Product(name, description, reference, price);
            products.push_back(new_product);
            return true;
            } else {
                return false;
            }
        }
    }
}

vector<PublicUserData*> Manager::showMembers() {
    vector<PublicUserData*> members = vector<PublicUserData*> ();
    if ((isLogged())&&(getCurrentMember()->isAdmin())) {
        for (PublicUserData* public_data: users) {
            members.push_back(public_data);
        }
    }
    return members;
}

bool Manager::makeOrder(const vector<unsigned long> products, int payment_method, int delivery_daddress) {
    return false;
}

bool Manager::createReview(const unsigned long &reference, const int &rating, const string& t) {
    return false;
}

vector<Review*> Manager::getReviewsByRating(const unsigned long &reference, const int &rating) {
    vector<Review*> rev;
    return rev;
}

bool Manager::upvoteReview(const unsigned long& id) {
    return false;
}

bool Manager::downvoteReview(const unsigned long& id) {
    return false;
}

bool Manager::modifyReviewRating(const unsigned long &id, const int &new_rating) {
    return false;
}

bool Manager::modifyReviewText(const unsigned long &id, const string& new_text){
    return false;
}

bool Manager::deleteReview(const unsigned long &id) {
    return false;
}

//################# TERCERA ENTREGA ############################//

void Manager::saveToFile(string& route) {}

void loadFromFile(string route) {}

