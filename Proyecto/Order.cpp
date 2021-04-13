#include <ctime>
#include "Order.hpp"

Order::Order(unsigned long reference, vector<unsigned long> products, int address, int payment_method, float total) {
    setReference(reference);
    for (const unsigned long& product : products) {
    addProduct(product);
    }
    setDeliveryAddress(address);
    setPaymentMethod(payment_method);
    setTotal(total);
    date = time(0);
}

Order::Order(unsigned long ref, int ad, int pm) {
    reference = ref;
    delivery_address = ad;
    payment_method = pm;
    time_t t_now = getDate() ;
}

Order::Order() {
    time_t t_now = getDate() ;
}

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

time_t Order::getDate( time_t* i)  {                //CAMBIO: terminado método
    time_t now = time(i);
    return now;
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
