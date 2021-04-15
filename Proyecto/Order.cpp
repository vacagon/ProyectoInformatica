#include <ctime>
#include "Order.hpp"

Order::Order(const unsigned long &reference, const vector<unsigned long>& products, const int &address, const int &payment_method, const float &total) {
    setReference(reference);
    for (const unsigned long& product : products) {
        addProduct(product);
    }
    setDeliveryAddress(address);
    setPaymentMethod(payment_method);
    setTotal(total);
    date = time(0);
}

Order::Order(const unsigned long &reference, const int& address, const int& payment_method) {
    setReference(reference);
    setDeliveryAddress(address);
    setPaymentMethod(payment_method);
    date = time(0);
}

Order::Order() {
    date = time(0);
}

Order::~Order() {}

void Order::setReference (const unsigned long &ref) {
    reference = ref;
}

const unsigned long &Order::getReference() const {
    return reference;
}

const vector<unsigned long> &Order::getProducts() const {
    return products;
}

void Order::addProduct(const unsigned long &ref) {
    reference = ref;
}

const time_t &Order::getDate() const {
    return date;
}

const int &Order::getDeliveryAddress() const {
    return delivery_address;
}

void Order::setDeliveryAddress(const int &ad) {
    delivery_address = ad;
}

const int& Order::getPaymentMethod() const {
    return payment_method;
}

void Order::setPaymentMethod(const int &pm) {
    payment_method = pm;
}

const float& Order::getTotal() const {
    return total;
}

void Order::setTotal(const float &t) {
    total = t;
}
