#ifndef PRIVATEUSERDATA_HPP
#define PRIVATEUSERDATA_HPP

#include <string>
#include <vector>
#include "Address.hpp"
#include "Order.hpp"
#include "PaymentMethod.hpp"

using namespace std;

/** @brief Store private data of a user */
class PrivateUserData {

public:

    /**
     * @brief Parametric constructor
     */
    PrivateUserData(const string &email, const string& password);

    /** @brief Empty Destructor */
	virtual ~PrivateUserData();

    /**
     * @brief Set the value of email
     */
    void setEmail(const string& em);

    /**
     * @brief Get the value of email
     */
    const string& getEmail () const;

    /**
     * @brief Set the value of password
     */
    void setPassword(const string& pas);

    /**
     * @brief Get the value of password
     */
    const string& getPassword() const;

    /**
     * @brief Get the vector of
     * pointers to Address registered by the user
     */
    vector<Address *> getAddresses() const;

    /**
     * @brief Let the manager add a new address
     */
    void addAddress(Address* new_address);

    /**
     * @brief Get the vector of pointers
     * to PaymentMethod of the user
     */
    vector<PaymentMethod*> getPaymentMethods () const;

    /**
     * @brief Let the manager add a new payment method
     */
    void addPaymentMethod(PaymentMethod* new_paymentmethod);

    /**
     * @brief Get the vector of pointers
     * to Order made by the user
     */
    vector<Order*> getOrders() const;

    /**
     * @brief Let the manager add a new order
     */
    void addOrder(Order* new_order);

    friend PaymentMethod;

protected:

    /** @brief Empty Constructor */
    PrivateUserData();

    string email;

    string password;

    /**
     * @brief Store all the addresses registered
     * by the user
     */
    vector<Address*> addresses;

    /**
     * @brief Store all the payment methods
     * recorded by the user
     */
    vector<PaymentMethod*> payment_methods;


    /**
     * @brief Stores the orders made
     * by the user
     */
    vector<Order*> orders;

};

#endif // PRIVATEUSERDATA_HPP
