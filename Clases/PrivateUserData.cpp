#include "PrivateUserData.hpp"

PrivateUserData::PrivateUserData(const string &email, const string& password) {
    setEmail(email);
    setPassword(password);
    addresses = vector<Address*> ();
    orders = vector<Order*> ();
    payment_methods = vector<PaymentMethod*> ();
    reviews_made = vector<Review*> ();
    creditcards = vector<CreditCard*> ();
    paypals = vector<Paypal*> ();
}

PrivateUserData::~PrivateUserData() {
    for (Address* user_address: addresses) {
        delete user_address;
    }
    for (CreditCard* user_cards: creditcards) {
        delete user_cards;
    }
    for (Paypal* user_paypals: paypals) {
        delete user_paypals;
    }
    for (Order* user_orders: orders) {
        delete user_orders;
    }
}

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

vector<CreditCard*> PrivateUserData::getCreditCards() const {
    return creditcards;
}

vector<Paypal*> PrivateUserData::getPaypals() const {
    return paypals;
}

void PrivateUserData::addPaymentMethod(PaymentMethod* new_paymentmethod) {
    payment_methods.push_back(new_paymentmethod);
}

void PrivateUserData::addCreditCard(CreditCard* new_creditcard) {
    creditcards.push_back(new_creditcard);
}

void PrivateUserData::addPaypal(Paypal *new_paypal) {
    paypals.push_back(new_paypal);
}

void PrivateUserData::addOrder(Order *new_order) {
    orders.push_back(new_order);
}

vector<Order *> PrivateUserData::getOrders() {
    return orders;
}

vector<Review*> PrivateUserData::getUserReviews() const {
    return reviews_made;
}

void PrivateUserData::addReview(Review *new_review) {
    reviews_made.push_back(new_review);
}

void PrivateUserData::deleteReview(Review *r) {
    reviews_made.erase(std::remove(reviews_made.begin(), reviews_made.end(), r), reviews_made.end());
}
