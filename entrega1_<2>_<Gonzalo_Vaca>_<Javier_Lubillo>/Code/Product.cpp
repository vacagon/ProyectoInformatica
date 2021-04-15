#include "Product.hpp"

Product::Product(const string& name, const string& description, const unsigned long &reference, const float &price) {
    setName(name);
    setDescription(description);
    setReference(reference);
    setPrice(price);
}

Product::~Product() {}

void Product::setName(const string& n) {
    name = n;
}

const string& Product::getName() const {
    return name;
}

void Product::setDescription(const string &d) {
    description = d;
}

const string& Product::getDescription() const {
    return description;
}

void Product::setReference(const unsigned long& ref) {
    reference = ref;
}

const unsigned long& Product::getReference() const {
    return reference;
}

void Product::setPrice(float p) {
    price = p;
}

const float& Product::getPrice() const {
    return price;
}

const vector<Review*>& Product::getReviews() const {
    return reviews;
}

void Product::addReview(Review* r) {
    reviews.push_back(r);
}

ostream& operator<<(ostream& os, const Product& p) {
    os << p.getReference() << " - "
       << p.getName() << endl
       << p.getDescription() << endl
       << p.getPrice() << endl;
    if (p.reviews.size() > 0) {
        os << "\t-- User reviews --" << endl;
        for (unsigned int i = 0; i < p.reviews.size(); i++) {
            os << "\t" << p.reviews[i]->show()
               << "\t----" << endl;
        }
    }
    return os;
}
