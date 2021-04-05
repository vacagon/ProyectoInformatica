#ifndef PAYPAL_HPP
#define PAYPAL_HPP

#include <string>
#include "PaymentMethod.hpp"

using namespace std;


/**
 * @brief Payment method through a Paypal account
 */
class Paypal: public PaymentMethod {

public:

    Paypal(int i, Address* ad, string& em);

    virtual ~Paypal();

    /**
     * @brief Email associated with the Paypal account
     */
    void setEmail(string& em);

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
