
#ifndef PAYPAL_H
#define PAYPAL_H

#include string


/**
  * class PayPal
  * Payment method through a Paypal account
  */

class PayPal
{
public:
	// Constructors/Destructors
	//  


	/**
	 * Empty Constructor
	 */
	PayPal();

	/**
	 * Empty Destructor
	 */
	virtual ~PayPal();

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
	void setEmail()
	{
	}


	/**
	 * @return string&
	 */
	string& getEmail()
	{
	}


	/**
	 * \tid {id} -Paypal Account:
	 * \tBilling address: {billing_address}
	 * \{email}
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

	// Email associated with the Paypal account
	string email;

	// Private attribute accessor methods
	//  


	// Private attribute accessor methods
	//  


	/**
	 * Set the value of email
	 * Email associated with the Paypal account
	 * @param value the new value of email
	 */
	void setEmail(string value)
	{
		email = value;
	}

	/**
	 * Get the value of email
	 * Email associated with the Paypal account
	 * @return the value of email
	 */
	string getEmail()
	{
		return email;
	}

	void initAttributes();

};

#endif // PAYPAL_H
