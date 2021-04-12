#include "CreditCard.hpp"
#include "PaymentMethod.hpp"

CreditCard::CreditCard(int i, Address* ad, unsigned long num, string& carhol): PaymentMethod(i, ad) {
    setNumber(num);
    setCardholder(carhol);
}

CreditCard::~CreditCard() {}

void CreditCard::setNumber(unsigned long num) {
    number = num;
}

unsigned long CreditCard::getNumber() const {
    return number;
}

void CreditCard::setCardholder(string carhol) {
    cardholder = carhol;
}

const string& CreditCard::getCardholder() const {
    return cardholder;
}

const string CreditCard::show() const {             // CAMBIO: añadido
    string output, id_aux, num_aux, ba_aux;
    stringstream ss_id, ss_num, ss_ba;
    ss_id << id ;
    ss_id >> id_aux;
    ss_num << number ;
    ss_num >> num_aux;
    ss_ba << billing_address ;
    ss_ba >> ba_aux;
    output = "\t" + id_aux;
    output += " - Credit Card:\t" + ba_aux;
    output += "\t" + num_aux;
    output += " - " + cardholder;
    return output;
}
