#include "Product.hpp"

Product::Product(string& n, string& d, unsigned long ref, float p) {
    setName(n);
    setDescription(d);
    setReference(ref);
    setPrice(p);
}

Product::~Product() {}

void Product::setName(string& n) {
    name = n;
}

const string& Product::getName() const {
    return name;
}

void Product::setDescription(string &d) {
    description = d;
}

const string& Product::getDescription() const {
    return description;
}

void Product::setReference(unsigned long ref) {
    reference = ref;
}

unsigned long Product::getReference() const {
    return reference;
}

void Product::setPrice(float p) {
    price = p;
}

float Product::getPrice() const {
    return price;
}

vector<Review*> Product::getReviews() const {
    return reviews;
}

void Product::addReview(Review* r) {}

ostream& operator<<(ostream& os, const Product& p) {
    return os;
}
