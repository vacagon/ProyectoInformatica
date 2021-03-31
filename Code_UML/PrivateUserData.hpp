
#ifndef PRIVATEUSERDATA_H
#define PRIVATEUSERDATA_H

#include string


/**
  * class PrivateUserData
  * 
  */

class PrivateUserData
{
public:
	// Constructors/Destructors
	//  


	/**
	 * Empty Constructor
	 */
	PrivateUserData();

	/**
	 * Empty Destructor
	 */
	virtual ~PrivateUserData();

	// Static Public attributes
	//  

	// Public attributes
	//  

	// Vector of pointers to Address
	Address addresses;

	// Public attribute accessor methods
	//  


	// Public attribute accessor methods
	//  


	/**
	 * Set the value of addresses
	 * Vector of pointers to Address
	 * @param value the new value of addresses
	 */
	void setAddresses(Address value)
	{
		addresses = value;
	}

	/**
	 * Get the value of addresses
	 * Vector of pointers to Address
	 * @return the value of addresses
	 */
	Address getAddresses()
	{
		return addresses;
	}


	/**
	 */
	void setEmail()
	{
	}


	/**
	 * @return string
	 */
	string getEmail() const
	{
	}


	/**
	 */
	void setPassword()
	{
	}


	/**
	 * @return string
	 */
	string getPassword() const
	{
	}


	/**
	 * @param  id
	 */
	void getAddress(int id)
	{
	}


	/**
	 * @param  id
	 */
	void getPaymentMethod(int id)
	{
	}


	/**
	 * @param  id
	 */
	void getOrder(int id)
	{
	}

protected:
	// Static Protected attributes
	//  

	// Protected attributes
	//  

	string email;
	string password;
	// Vector of pointers to PaymentMethod
	PaymentMethod payment_methods;
	// Vector of pointers to Order
	Order orders;

	// Protected attribute accessor methods
	//  


	// Protected attribute accessor methods
	//  


	/**
	 * Set the value of email
	 * @param value the new value of email
	 */
	void setEmail(string value)
	{
		email = value;
	}

	/**
	 * Get the value of email
	 * @return the value of email
	 */
	string getEmail()
	{
		return email;
	}

	/**
	 * Set the value of password
	 * @param value the new value of password
	 */
	void setPassword(string value)
	{
		password = value;
	}

	/**
	 * Get the value of password
	 * @return the value of password
	 */
	string getPassword()
	{
		return password;
	}

	/**
	 * Set the value of payment_methods
	 * Vector of pointers to PaymentMethod
	 * @param value the new value of payment_methods
	 */
	void setPayment_methods(PaymentMethod value)
	{
		payment_methods = value;
	}

	/**
	 * Get the value of payment_methods
	 * Vector of pointers to PaymentMethod
	 * @return the value of payment_methods
	 */
	PaymentMethod getPayment_methods()
	{
		return payment_methods;
	}

	/**
	 * Set the value of orders
	 * Vector of pointers to Order
	 * @param value the new value of orders
	 */
	void setOrders(Order value)
	{
		orders = value;
	}

	/**
	 * Get the value of orders
	 * Vector of pointers to Order
	 * @return the value of orders
	 */
	Order getOrders()
	{
		return orders;
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

#endif // PRIVATEUSERDATA_H
