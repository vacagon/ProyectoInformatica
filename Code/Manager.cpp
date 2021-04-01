#include "Manager.hpp"

//################# PRIMERA ENTREGA ############################//

Manager::Manager() {}

Manager::~Manager() {}

const vector<User*> Manager::getUsers() const {
    return users;
}

vector<Product*> Manager::getProducts() const {
    return products;
}

bool Manager::login(string em, string pas) {
    return false;
}

bool Manager::logout() {
    return false;
}

bool Manager::isLogged() {
    return false;
}

User* Manager::getCurrentMember() {
    return nullptr;
}

bool Manager::addUser(string us, string em, string pas) {
    return false;
}

bool Manager::addAdministrator(string us, string em, string pas, unsigned long emcode) {
    return false;
}

bool Manager::eraseCurrentMember() {
    return false;
}

bool Manager::editUsername(string new_username) {
    return false;
}

bool Manager::editEmail(string new_email) {
    return false;
}

bool Manager::editPassword(string new_password) {
    return false;
}

bool Manager::addAddress(string a, string c, string p, unsigned int pcode) {
    return false;
}

bool Manager::addCreditcard(Address* a, unsigned long n, string& cholder) {
    return false;
}

bool Manager::addPaypal(Address* a, string& em) {
    return false;
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
    false;
}

bool Manager::deleteReview(unsigned long i) {
    return false;
}

//################# TERCERA ENTREGA ############################//

void Manager::saveToFile(string& route) {}

void loadFromFile(string route) {}
