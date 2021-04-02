#ifndef PRIVATEUSERDATA_HPP
#define PRIVATEUSERDATA_HPP

#include <string>
#include <vector>
#include "User.hpp"
#include "Address.hpp"
#include "Order.hpp"
#include "PaymentMethod.hpp"

using namespace std;

/** @brief Store private data of a user */
class PrivateUserData
{

public:

    /**
     * @brief Parametric constructor
     * @param em: Email
     * @param pas: Password
     */
    PrivateUserData(string &em, string& pas);

    /** @brief Empty Destructor */
	virtual ~PrivateUserData();

    /**
     * @brief Set the value of email
     */
    void setEmail(string& em);

    /**
     * @brief Get the value of email
     */
    const string& getEmail () const;

    /**
     * @brief Set the value of password
     */
    void setPassword(string& pas);

    /**
     * @brief Get the value of password
     */
    const string& getPassword() const;

    /**
     * @brief Get the vector of
     * pointers to Address registered by the user
     */
    vector<Address*> getAddresses() const;

    /**
     * @brief Get the vector of pointers
     * to PaymentMethod of the user
     */
    vector<PaymentMethod*> getPayment_methods () const;

    /**
     * @brief Get the vector of pointers
     * to Order made by the user
     */
    vector<Order*> getOrders() const;

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
