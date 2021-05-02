#include "PrivateUserData.hpp"

PrivateUserData::PrivateUserData(const string &email, const string& password) {
    setEmail(email);
    setPassword(password);
    addresses = vector<Address*> ();
    orders = vector<Order*> ();
    payment_methods = vector<PaymentMethod*> ();
    reviews_made = vector<Review*> ();
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

vector<Address *> PrivateUserData::getAddresses() const {
    return addresses;
}

void PrivateUserData::addAddress(Address *new_address) {
    addresses.push_back(new_address);
}

vector<PaymentMethod *> PrivateUserData::getPaymentMethods() const {
    return payment_methods;
}

void PrivateUserData::addPaymentMethod(PaymentMethod* new_paymentmethod) {
    payment_methods.push_back(new_paymentmethod);
}

vector<Order *> PrivateUserData::getOrders() const {
    return orders;
}

void PrivateUserData::addOrder(Order *new_order) {
    orders.push_back(new_order);
}

vector<Review*> PrivateUserData::getUserReviews() const {
    return reviews_made;
}

void PrivateUserData::addReview(Review *new_review) {
    reviews_made.push_back(new_review);
}
