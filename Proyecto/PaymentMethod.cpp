#include "PaymentMethod.hpp"
#include "PrivateUserData.hpp"

PaymentMethod::PaymentMethod(int i, Address* baddress) {
    setId(i);
    setBillingAddress(baddress);
}

PaymentMethod::~PaymentMethod() {};

int PaymentMethod::getId() const {
    return id;
}

void PaymentMethod::setId(int i) {
    id = i;
}

Address* PaymentMethod::getBillingAddress() const {
    return billing_address;
}

void PaymentMethod::setBillingAddress(Address* baddress) {
    billing_address = baddress;
}
