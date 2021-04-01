#include "Order.hpp"

Order::Order(unsigned long ref, vector<unsigned long> prod, int ad, int pm, float tot) {}

Order::Order(unsigned long ref, int ad, int pm) {}

Order::~Order() {}

void Order::setReference (unsigned long ref) {
    reference = ref;
}

unsigned long Order::getReference() const {
    return reference;
}

vector<unsigned long> Order::getProducts() const {
    return products;
}

void Order::addProduct(unsigned long ref) {
    reference = ref;
}

time_t Order::getDate() const {
    return date;
}

int Order::getDeliveryAddress() const {
    return delivery_address;
}

void Order::setDeliveryAddress(int ad) {
    delivery_address = ad;
}

int Order::getPaymentMethod() const {
    return payment_method;
}

void Order::setPaymentMethod(int pm) {
    payment_method = pm;
}

float Order::getTotal() const {
    return total;
}

void Order::setTotal() {
    total = 0;
}
