#include "ShoppingCart.hpp"

ShoppingCart::ShoppingCart(User *logged_user) {
    _user = logged_user;
    _products = vector<Product*> ();
    _total = 0;
}

ShoppingCart::~ShoppingCart() {
    _products.clear();
}

void ShoppingCart::addProduct(Product *new_product) {
    _products.push_back(new_product);
    _total += new_product->getPrice();
}

void ShoppingCart::eraseProduct(Product *erase_product) {
    _products.erase(remove(_products.begin(), _products.end(), erase_product), _products.end());
    _total -= erase_product->getPrice();
}

vector<Product*> ShoppingCart::getProducts() const {
    return _products;
}

float ShoppingCart::getTotal() const {
    if (_user->isAdmin()) {
        return _total*(1-0.075);
    } else {
        return _total;
    }
}

void ShoppingCart::setTotal(float total) {
    _total = total;
}

ostream& operator << (ostream& os, ShoppingCart& SC) {
    int i = 0;
    os << endl << "\t***SHOPPING CART***" << endl
       << "------------------------------" << endl
       << "------------------------------" << endl
       << "\tProducts" << endl
       << "------------------------------" << endl;
    if (SC.getProducts().size() > 0) {
        for (Product* products: SC.getProducts()) {
            os << endl << i << ". " << products->getReference()
               << " - " << products->getName() << endl
               << products->getDescription() << endl
               << setprecision(2) << fixed
               << products->getPrice() << " [$]" << endl;
            i++;
        }
    } else {
        os << "No product addded to the shopping cart yet" << endl;
    }
    os << "------------------------------" << endl
       << "TOTAL: " << setprecision(2) << fixed
       << SC.getTotal() << " [$]" << endl;
    return os;
}
