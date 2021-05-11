#include "Paypal.hpp"

Paypal::Paypal(const int &id, Address *address, const string &email): PaymentMethod(address,id) {
    setEmail(email);
}

Paypal::~Paypal() {}

void Paypal::setEmail(const string &em) {
    email = em;
}

const string& Paypal::getEmail() const {
    return email;
}

const string Paypal::show() const {
    stringstream ss;
    ss << "\tid " << id << " - Paypal Account:" << endl
       << "\tBilling address: " << billing_address->show()
       << "\t" << email << endl;
    return ss.str();
}
