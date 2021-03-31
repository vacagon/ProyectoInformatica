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
    /** @brief Empty Destructor */
	virtual ~PrivateUserData();

    /**
     * @brief Set the value of email
     */
    void setEmail(string& em) { email = em; }

    /**
     * @brief Get the value of email
     */
    string getEmail () const { return email; }

    /**
     * @brief Set the value of password
     */
    void setPassword(string& pas) { password = pas; }

    /**
     * @brief Get the value of password
     */
    string getPassword() { return password; }

    /**
     * @brief Get the vector of
     * pointers to Address registered by the user
     */
    vector<Address*> getAddresses() const { return addresses; }

    /**
     * @brief Get the vector of pointers
     * to PaymentMethod of the user
     */
    vector<PaymentMethod*> getPayment_methods () const { return payment_methods; }

    /**
     * @brief Get the vector of pointers
     * to Order made by the user
     */
    vector<Order*> getOrders() const { return orders; }

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
