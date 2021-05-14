#ifndef SHOPPINGCART_HPP
#define SHOPPINGCART_HPP

#include "Product.hpp"
#include "algorithm"
#include "iomanip"

class ShoppingCart {

public:

    ShoppingCart(User* logged_user);

    ~ShoppingCart();

    void addProduct(Product* new_product);

    void eraseProduct(Product* erase_product);

    vector<Product*> getProducts() const;

    float getTotal() const;

    void setTotal(float total);

    friend ostream& operator << (ostream& os, ShoppingCart& SC);

protected:

    float _total;

    vector<Product*> _products;

    User* _user;

};

#endif // SHOPPINGCART_HPP
