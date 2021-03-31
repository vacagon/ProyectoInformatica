
#ifndef PAYMENTMETHOD_H
#define PAYMENTMETHOD_H

#include string


/**
  * class PaymentMethod
  * Platform allows to payment methods: credit card, or paypal.
  */

/******************************* Abstract Class ****************************
PaymentMethod does not have any pure virtual methods, but its author
  defined it as an abstract class, so you should not use it directly.
  Inherit from it instead and create only objects from the derived classes
*****************************************************************************/

class PaymentMethod
{
public:
	// Constructors/Destructors
	//  


	/**
	 * Empty Constructor
	 */
	PaymentMethod();

	/**
	 * Empty Destructor
	 */
	virtual ~PaymentMethod();

	// Static Public attributes
	//  

	// Public attributes
	//  


	// Public attribute accessor methods
	//  


	// Public attribute accessor methods
	//  



	/**
	 * Returns the content of the payment method
	 * @return string&
	 */
	string& show()
	{
	}


	/**
	 * @param  i
	 */
	void setId(int i)
	{
	}


	/**
	 * @return int
	 */
	int getId() const
	{
	}


	/**
	 */
	void setBillingAddress()
	{
	}


	/**
	 * @return Address*
	 */
	Address* getBillingAddress()
	{
	}

protected:
	// Static Protected attributes
	//  

	// Protected attributes
	//  

	// Its value depends on the number of payment method registered by each user. If it's the first one, id = 0, if it's the second one, id = 1, and so on. 
	int id;
	// Represent the billing address of the payment method. Pointer to one of the previously registered addresses.
	Address billing_address;

	// Protected attribute accessor methods
	//  


	// Protected attribute accessor methods
	//  


	/**
	 * Set the value of id
	 * Its value depends on the number of payment method registered by each user. If
	 * it's the first one, id = 0, if it's the second one, id = 1, and so on.
	 * @param value the new value of id
	 */
	void setId(int value)
	{
		id = value;
	}

	/**
	 * Get the value of id
	 * Its value depends on the number of payment method registered by each user. If
	 * it's the first one, id = 0, if it's the second one, id = 1, and so on.
	 * @return the value of id
	 */
	int getId()
	{
		return id;
	}

	/**
	 * Set the value of billing_address
	 * Represent the billing address of the payment method. Pointer to one of the
	 * previously registered addresses.
	 * @param value the new value of billing_address
	 */
	void setBilling_address(Address value)
	{
		billing_address = value;
	}

	/**
	 * Get the value of billing_address
	 * Represent the billing address of the payment method. Pointer to one of the
	 * previously registered addresses.
	 * @return the value of billing_address
	 */
	Address getBilling_address()
	{
		return billing_address;
	}

private:
	// Static Private attributes
	//  

	// Private attributes
	//  


	// Private attribute accessor methods
	//  


	// Private attribute accessor methods
	//  


	void initAttributes();

};

#endif // PAYMENTMETHOD_H
