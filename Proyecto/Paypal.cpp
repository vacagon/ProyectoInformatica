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
    stringstream ss;
    ss << "\tid " << id << " - Paypal Account:" << endl
       << "\tBilling address: " << billing_address->show() << endl
       << "\t" << email << endl;
    return ss.str();
}
