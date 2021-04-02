#include "Paypal.hpp"

Paypal::Paypal(int i, Address* ad, string& em): PaymentMethod(i,ad) {
    setEmail(em);
}

Paypal::~Paypal() {}

void Paypal::setEmail(string& em) {
    email = em;
}

const string& Paypal::getEmail() const {
    return email;
}

const string Paypal::show() const {
    string output;
    return output;
}
