#ifndef PAYPAL_HPP
#define PAYPAL_HPP

#include <string>
#include <sstream>

#include "PaymentMethod.hpp"

using namespace std;


/**
 * @brief Payment method through a Paypal account
 */
class Paypal: public PaymentMethod {

public:

    Paypal(const int& id, const Address* address, const string& email);

    virtual ~Paypal();

    /**
     * @brief Email associated with the Paypal account
     */
    void setEmail(const string& em);

    /**
     * @brief Get the email associated with the Paypal account
     */
    const string& getEmail() const;

	/**
     * @brief \tid {id} -Paypal Account:
	 * \tBilling address: {billing_address}
	 * \{email}
	 */
     const string show() const;

private:

    Paypal();

    string email;

};

#endif // PAYPAL_HPP
