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

vector<User*> Manager::getUsers() const {
    return users;
}

vector<Product*> Manager::getProducts() const {
    return products;
}

bool Manager::login(const string& em,const string& pas) {
    bool flag = false;
    if (current_member == -1) {
        for (unsigned long i = 0; i < users.size(); i++) {
            if ((users[i]->getEmail() == em)&&(users[i]->getPassword() == pas)) {
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
    } else {
        cmember = nullptr;
    }
    return cmember;
}

bool Manager::addUser(const string &us, const string &em, const string &pas) {
    for (int i = 0; i < (int)users.size(); i++) {
        if ((users[i]->getEmail() == em)||(users[i]->getUsername() == us)) {
            return false;
        }
    }
    User* new_user = new User(us,em,pas);
    users.push_back(new_user);
    return true;
}

bool Manager::addAdministrator(string &us, string &em, string &pas, unsigned long emcode) {
    for (unsigned long i = 0; i < users.size(); i++) {
        if ((users[i]->getEmail() == em)||(users[i]->getUsername() == us)||(users[i]->getEmployeeCode() == emcode)) {
            return false;
        }
    }
    Administrator* new_admin = new Administrator(us,em,pas,emcode);
    users.push_back(new_admin);
    return true;
}

bool Manager::eraseCurrentMember() {
    bool flag = false;
    if (isLogged()) {
        delete users[current_member];
        users.erase(users.begin() + current_member);
        flag = true;
    }
    return flag;
}

bool Manager::editUsername(const string& new_username) {
    bool flag = true;
    if (!isLogged()) {
        return false;
    } else {
        for (unsigned long i = 0; i < users.size(); i++) {
            if (users[i]->getUsername() == new_username) {
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
        for (unsigned long i = 0; i < users.size(); i++) {
            if (users[i]->getEmail() == new_email) {
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

bool Manager::addAddress(const string &a, const string &c, const string &p, unsigned int pcode) {
    bool flag = false;
    int id = users[current_member]->getAddresses().size();
    if (isLogged()) {
        Address* new_address = new Address(id, a, c, p, pcode);
        users[current_member]->addAddress(new_address);
    }
    return flag;
}

bool Manager::addCreditCard(Address* a, unsigned long n, string& cholder) {
    bool flag = false;
    int id = users[current_member]->getPaymentMethods().size();
    if (isLogged()) {
        CreditCard* new_creditcard = new CreditCard(id, a, n, cholder);
        users[current_member]->addPaymentMethod(new_creditcard);
    }
    return flag;
}

bool Manager::addPaypal(Address* a, string& em) {
    bool flag = false;
    int id = users[current_member]->getPaymentMethods().size();
    if (isLogged()) {
        Paypal* new_paypal = new Paypal(id, a, em);
        users[current_member]->addPaymentMethod(new_paypal);
    }
    return flag;
}

//################# SEGUNDA ENTREGA ############################//

bool Manager::addProduct(string n, string d, unsigned long r, float p) {
    return false;
}

vector<PublicUserData*> Manager::showMembers() const {
    vector<PublicUserData*> members;
    return members;
}

bool Manager::makeOrder(vector<unsigned long> pr, int pm, int ddaddress) {
    return false;
}

bool Manager::createReview(unsigned long ref, int rat, string t) {
    return false;
}

vector<Review*> Manager::getReviewsByRating(unsigned long ref, int rat) {
    vector<Review*> rev;
    return rev;
}

bool Manager::upvoteReview(unsigned long i) {
    return false;
}

bool Manager::downvoteReview(unsigned long i) {
    return false;
}

bool Manager::modifyReviewRating(unsigned long i, int new_rating) {
    return false;
}

bool Manager::modifyReviewText(unsigned long i, string& new_text){
    return false;
}

bool Manager::deleteReview(unsigned long i) {
    return false;
}

//################# TERCERA ENTREGA ############################//

void Manager::saveToFile(string& route) {}

void loadFromFile(string route) {}

