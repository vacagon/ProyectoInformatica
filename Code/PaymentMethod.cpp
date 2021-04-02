#include "PaymentMethod.hpp"

PaymentMethod::PaymentMethod(int i, Address* baddress) {
    id = i;
    billing_address = baddress;
}

PaymentMethod::~PaymentMethod() {};

int PaymentMethod::getId() const {
    return 0;
}

void PaymentMethod::setId(int i) {
    id = i;
}

Address* PaymentMethod::getBillingAddress() const {
    return nullptr;
}

void PaymentMethod::setBillingAddress(const Address* a) {}
