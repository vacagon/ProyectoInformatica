#ifndef ORDER_HPP
#define ORDER_HPP

#include <string>
#include <sstream>
#include <vector>
#include <ctime>
#include <time.h>
#include <iomanip>

using namespace std;

/**
 * @brief Order made by any user.
 */
class Order {

public:

    Order(const unsigned long& reference, const vector<unsigned long>& prods, const int& address, const int& payment_method, const float& total);

    Order(const unsigned long& ref, const int& adress, const int& payment_method);

    ~Order();

    void setReference (const unsigned long& ref);

    const unsigned long& getReference() const;

    const vector<unsigned long>& getProducts() const;

    void addProduct(const unsigned long& ref);

    time_t &getDate();

    void setDate(time_t& d);

    const int& getDeliveryAddress() const;

    void setDeliveryAddress(const int& ad);

    const int& getPaymentMethod() const;

    void setPaymentMethod(const int& pm);

    const float& getTotal() const;

    void setTotal(const float& t);

    friend ostream& operator << (ostream &os, Order &O);

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
