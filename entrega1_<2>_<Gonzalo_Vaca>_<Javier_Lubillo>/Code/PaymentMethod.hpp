#ifndef PAYMENTMETHOD_HPP
#define PAYMENTMETHOD_HPP

#include <string>
#include "Address.hpp"

using namespace std;

/**
  * @brief Platform allows two payment methods: credit card, or paypal.
  */
class PaymentMethod {

public:

    /**
     * @brief Parametric  constructor
     */
    PaymentMethod(const Address *billing_address, const int& id = -1);

    virtual ~PaymentMethod();

    /**
     * @brief Returns text with information
     * about payment method
     */
    virtual const string show() const = 0;

    int getId() const;

    void setId(const int& i);

    const Address *getBillingAddress() const;

    void setBillingAddress(const Address *badress);

protected:

    PaymentMethod();

    /**
     * @brief Its value depends on the number of
     * payment methods registered by each user.
     * If it's the first one, id = 0, if it's
     * the second one, id = 1, and so on. If there
     * is no registered payment method, id = -1
     */
    int id;

    /**
     * @brief Billing direction associated with a payment method
     * Pointer to one of the previously registered addresses
     */
    const Address* billing_address;

};

#endif // PAYMENTMETHOD_H
