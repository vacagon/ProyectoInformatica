#ifndef CREDITCARD_HPP
#define CREDITCARD_HPP

#include <string>
#include <sstream>
#include "PaymentMethod.hpp"

using namespace std;

/**
  * @brief Payment method type through a bank card
  */
class CreditCard: public PaymentMethod {

public:

	virtual ~CreditCard();

    /**
     * @brief Parametric constructor
     */
    CreditCard(const int& i, Address* address, const unsigned long& number, const string& cardholder);

    /**
     * @brief Set the value of number
     */
    void setNumber(const unsigned long& num);

    /**
     * @brief Get the credit card number
     */
    unsigned long getNumber() const;

    /**
     * @brief Set the name of the card holder
     */
    void setCardholder(const string& carhol);

    /**
     * @brief Get the name of the card holder
     */
    const string& getCardholder() const;

    bool isCreditCard() const;

	/**
     * @brief \tid {id} - Credit Card:
	 * \tBilling address: {billing address}
	 * \t{number} - {cardholder}
	 */
    const string show() const;

    friend ostream& operator << (ostream& os, CreditCard& CC);

private:

    CreditCard();

    /**
     * @brief Credit card number (16 digits)
     */
	unsigned long number;

    /**
     * @brief Name of the card holder
     */
	string cardholder;

};

#endif // CREDITCARD_HPP
