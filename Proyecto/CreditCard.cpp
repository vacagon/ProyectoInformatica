#include "CreditCard.hpp"
#include "PaymentMethod.hpp"

CreditCard::CreditCard(const int &i, Address* address, const unsigned long &number, const string &cardholder): PaymentMethod(address, i) {
    setNumber(number);
    setCardholder(cardholder);
}

CreditCard::~CreditCard() {}

void CreditCard::setNumber(const unsigned long &num) {
    number = num;
}

unsigned long CreditCard::getNumber() const {
    return number;
}

void CreditCard::setCardholder(const string &carhol) {
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
