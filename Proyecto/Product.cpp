#include "Product.hpp"

Product::Product(const string& name, const string& description, const unsigned long &reference, const float &price) {
    setName(name);
    setDescription(description);
    setReference(reference);
    setPrice(price);
    reviews = vector<Review*> ();
}

Product::~Product() {
    for (Review* product_reviews: reviews) {
        delete product_reviews;
    }
}

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

vector<Review*> Product::getReviews() {
    return reviews;
}

void Product::addReview(Review* r) {
    reviews.push_back(r);
}

void Product::deleteReview(Review *r) {
    reviews.erase(std::remove(reviews.begin(), reviews.end(), r), reviews.end());
}

ostream& operator<<(ostream& os, const Product& p) {
    os << p.getReference() << " - "
       << p.getName() << endl
       << p.getDescription() << endl
       << p.getPrice() << " [$]" <<endl;
    if (p.reviews.size() > 0) {
        os << "\t-- User reviews --" << endl;
        for (unsigned int i = 0; i < p.reviews.size(); i++) {
            os << p.reviews[i]->show() << endl;
        }
    }
    return os;
}
