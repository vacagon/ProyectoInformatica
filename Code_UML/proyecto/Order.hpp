#ifndef ORDER_HPP
#define ORDER_HPP

#include <string>
#include <ctime>
#include "PrivateUserData.hpp"

using namespace std;

/**
 * @brief Order made by any user.
 */
class Order {

public:

    Order(unsigned long ref, vector<unsigned long> prod, int ad, int pm, float tot);

    Order(unsigned long ref, int ad, int pm);

    ~Order();

    void setReference (unsigned long ref);

    unsigned long getReference() const;

    vector<unsigned long> getProducts() const;

    void addProduct(unsigned long ref);

    time_t getDate() const;

    int getDeliveryAddress() const;

    void setDeliveryAddress(int ad);

    int getPaymentMethod() const;

    void setPaymentMethod(int pm);

    float getTotal() const;

    void setTotal();

private:

    Order();

    /**
     * @brief Uniquee identifier
     */
    unsigned long reference;

    /**
     * @brief Stores the references of the products
     */
    vector<unsigned long> products;

    /**
     * @brief Stores the date in which the order
     * was made by the user
     */
    time_t date;

    /**
     * @brief Address in which the order
     * will be delivered. It will be one of
     * the previously registered addresses (ID)
     */
    int delivery_address;

    /**
     * @brief Payment method chose
     * to pay the order. It will be one of
     * the previously registered addresses (ID)
     */
    int payment_method;

    /**
     * @brief Price of the order
     */
    float total;

};

#endif // ORDER_HPP