#include "PrivateUserData.hpp"

PrivateUserData::PrivateUserData(const string &em, const string& pas) {
    email = em;
    password = pas;
}

PrivateUserData::~PrivateUserData() {}

void PrivateUserData::setEmail(string& em) {
    email = em;
}

const string& PrivateUserData::getEmail () const {
    return email;
}

void PrivateUserData::setPassword(string& pas) {
    password = pas;
}

const string& PrivateUserData::getPassword() const {
    return password;
}

vector<Address*> PrivateUserData::getAddresses() const {
    return addresses;
}

vector<PaymentMethod*> PrivateUserData::getPaymentMethods () const {
    return payment_methods;
}

vector<Order*> PrivateUserData::getOrders() const {
    return orders;
}
