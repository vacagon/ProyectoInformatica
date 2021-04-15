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
<<<<<<< HEAD
    ss << "\tid " << id << " - Paypal Account:" << endl
       << "\tBilling address: " << billing_address->show() << endl
       << "\t" << email << endl;
=======
    ss << "\t" << id << " - Paypal Account :" << endl
         << "\tBilling address: " <<billing_address->show() << endl
         << "\t" << email << endl;
>>>>>>> ffc13430eb63d940fdc5ada3e9e97eedc95cbc43
    return ss.str();
}
