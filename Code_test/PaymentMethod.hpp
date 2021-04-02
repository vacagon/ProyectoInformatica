#ifndef PAYMENTMETHOD_HPP
#define PAYMENTMETHOD_HPP

#include <string>
#include "CreditCard.hpp"
#include "Paypal.hpp"
#include "PrivateUserData.hpp"
#include "Address.hpp"

using namespace std;

/**
  * @brief Platform allows two payment methods: credit card, or paypal.
  */
class PaymentMethod {

public:

    /**
     * @brief Parametric  constructor
     * @param i: id
     * @param baddress: index in the vector of
     * registered addresses
     */
    PaymentMethod(int i, Address* baddress);

    virtual ~PaymentMethod();

    /**
     * @brief Returns text with information
     * about payment method
     */
    virtual const string show() const = 0;

protected:

    PaymentMethod();

    /**
     * @brief Its value depends on the number of
     * payment methods registered by each user.
     * If it's the first one, id = 0, if it's the second one, id = 1, and so on.
     */
    int id;

    /**
     * @brief Billing direction associated with a payment method
     * Pointer to one of the previously registered addresses
     */
    Address* billing_address;

};

#endif // PAYMENTMETHOD_H
