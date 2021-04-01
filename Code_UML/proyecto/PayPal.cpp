#include "PayPal.hpp"

PayPal::PayPal(int i, Address* ad, string& em): PaymentMethod(i,ad) {
    setEmail(em);
}

PayPal::~PayPal() {}

void PayPal::setEmail(string& em) {
    email = em;
}

const string& PayPal::getEmail() const {
    return email;
}

const string PayPal::show() const {
    string output;
    return output;
}
