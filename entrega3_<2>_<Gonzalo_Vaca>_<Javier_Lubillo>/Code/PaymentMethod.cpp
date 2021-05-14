#include "PaymentMethod.hpp"
#include "PrivateUserData.hpp"

PaymentMethod::PaymentMethod(Address *billing_address, const int &id) {
    setBillingAddress(billing_address);
    setId(id);
}

PaymentMethod::~PaymentMethod() {};

int PaymentMethod::getId() const {
    return id;
}

void PaymentMethod::setId(const int& i) {
    id = i;
}

Address* PaymentMethod::getBillingAddress() const {
    return billing_address;
}

void PaymentMethod::setBillingAddress(Address* baddress) {
    billing_address = baddress;
}
