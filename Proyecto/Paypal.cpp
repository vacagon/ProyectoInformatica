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
    string output, id_aux, num_aux, ba_aux;
    stringstream ss_id, ss_num, ss_ba;
    ss_id << id ;
    ss_id >> id_aux;
    ss_ba << billing_address ;
    ss_ba >> ba_aux;
    output = "\t" + id_aux;
    output += " - Paypal Account:\t" + ba_aux;
    output += "\t" + email;
    return output;
}
