
#ifndef CREDITCARD_H
#define CREDITCARD_H

#include string


/**
  * class CreditCard
  * Payment method type through a bank card
  */

class CreditCard
{
public:
	// Constructors/Destructors
	//  


	/**
	 * Empty Constructor
	 */
	CreditCard();

	/**
	 * Empty Destructor
	 */
	virtual ~CreditCard();

	// Static Public attributes
	//  

	// Public attributes
	//  

	PaymentMethod PaymentMethod;

	// Public attribute accessor methods
	//  


	// Public attribute accessor methods
	//  


	/**
	 * Set the value of PaymentMethod
	 * @param value the new value of PaymentMethod
	 */
	void setPaymentMethod(PaymentMethod value)
	{
		PaymentMethod = value;
	}

	/**
	 * Get the value of PaymentMethod
	 * @return the value of PaymentMethod
	 */
	PaymentMethod getPaymentMethod()
	{
		return PaymentMethod;
	}


	/**
	 */
	void setNumber()
	{
	}


	/**
	 * @return unsigned long
	 */
	unsigned long getNumber() const
	{
	}


	/**
	 */
	void setCardholder()
	{
	}


	/**
	 * @return string&
	 */
	string& getCardholder() const
	{
	}


	/**
	 * \tid {id} - Credit Card:
	 * \tBilling address: {billing address}
	 * \t{number} - {cardholder}
	 * @return string&
	 */
	string& show()
	{
	}

protected:
	// Static Protected attributes
	//  

	// Protected attributes
	//  


	// Protected attribute accessor methods
	//  


	// Protected attribute accessor methods
	//

private:
	// Static Private attributes
	//  

	// Private attributes
	//  

	// Credit card number
	unsigned long number;
	string cardholder;

	// Private attribute accessor methods
	//  


	// Private attribute accessor methods
	//  


	/**
	 * Set the value of number
	 * Credit card number
	 * @param value the new value of number
	 */
	void setNumber(unsigned long value)
	{
		number = value;
	}

	/**
	 * Get the value of number
	 * Credit card number
	 * @return the value of number
	 */
	unsigned long getNumber()
	{
		return number;
	}

	/**
	 * Set the value of cardholder
	 * @param value the new value of cardholder
	 */
	void setCardholder(string value)
	{
		cardholder = value;
	}

	/**
	 * Get the value of cardholder
	 * @return the value of cardholder
	 */
	string getCardholder()
	{
		return cardholder;
	}

	void initAttributes();

};

#endif // CREDITCARD_H
