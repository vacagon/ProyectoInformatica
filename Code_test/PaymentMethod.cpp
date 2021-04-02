#include "PaymentMethod.hpp"

PaymentMethod::PaymentMethod(int i, Address* baddress) {
    id = i;
    billing_address = baddress;
}

PaymentMethod::~PaymentMethod() {};
