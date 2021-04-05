#include "PrivateUserData.hpp"

PrivateUserData::PrivateUserData(const string &em, const string& pas) {
    email = em;
    password = pas;
}

PrivateUserData::~PrivateUserData() {}

void PrivateUserData::setEmail(const string& em) {
    email = em;
}

const string& PrivateUserData::getEmail () const {
    return email;
}

void PrivateUserData::setPassword(const string& pas) {
    password = pas;
}

const string& PrivateUserData::getPassword() const {
    return password;
}

vector<Address*> PrivateUserData::getAddresses() const {
    return addresses;
}

void PrivateUserData::addAddress(Address *new_address) {
    addresses.push_back(new_address);
}

vector<PaymentMethod*> PrivateUserData::getPaymentMethods () const {
    return payment_methods;
}

void PrivateUserData::addPaymentMethod(PaymentMethod* new_paymentmethod) {
    payment_methods.push_back(new_paymentmethod);
}

vector<Order*> PrivateUserData::getOrders() const {
    return orders;
}

void PrivateUserData::addOrder(Order* new_order) {
    orders.push_back(new_order);
}
