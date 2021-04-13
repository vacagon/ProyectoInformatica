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

const string CreditCard::show() const {
    stringstream ss;
    ss << "\tid " << id << " - Credit Card:" << endl
         << "\tBilling address: " << billing_address->show() << endl
         << "\t" << number << " - "
         << cardholder << endl;
    return ss.str();
}
