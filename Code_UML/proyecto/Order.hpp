
#ifndef ORDER_H
#define ORDER_H

#include string


/**
  * class Order
  * Order made by any user.
  */

class Order
{
public:
	// Constructors/Destructors
	//  


	/**
	 * Empty Constructor
	 */
	Order();

	/**
	 * Empty Destructor
	 */
	virtual ~Order();

	// Static Public attributes
	//  

	// Public attributes
	//  


	// Public attribute accessor methods
	//  


	// Public attribute accessor methods
	//  



	/**
	 */
	void setReference()
	{
	}


	/**
	 * @return unsigned long
	 */
	unsigned long getReference() const
	{
	}


	/**
	 * @return unsigned long
	 */
	unsigned long getProduct()
	{
	}


	/**
	 * Recibe la referencia del nuevo producto y la añade al vector products
	 */
	void addProduct()
	{
	}


	/**
	 * @return time_t
	 */
	time_t getDate() const
	{
	}


	/**
	 * @return Address
	 */
	Address getDeliveryAddress()
	{
	}


	/**
	 * @param  address
	 */
	void setDeliveryAddress(Address address)
	{
	}


	/**
	 * @param  payment_method
	 */
	void setPaymentMethod(PaymentMethod payment_method)
	{
	}


	/**
	 * @return PaymentMethod
	 */
	PaymentMethod getPaymentMethod() const
	{
	}


	/**
	 */
	void setTotal()
	{
	}


	/**
	 * @return float
	 */
	float getTotal() const
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

	// Uniquee identifier for the order.
	unsigned long reference;
	// Vector of unsigned long which store all the references of the productos in one order.
	vector<unsigned long> products;
	// Unix time, stores the moment in which the order was created.
	time_t date;
	// ID of the shipping address of the order.
	int delivery_address;
	// ID of the payment method chose by user to pay the order
	int payment_method;
	// Cost of the order. Sum of the prices of the products in the order (minus the 7.5% in case de costumer is an Administrator)
	float total;

	// Private attribute accessor methods
	//  


	// Private attribute accessor methods
	//  


	/**
	 * Set the value of reference
	 * Uniquee identifier for the order.
	 * @param value the new value of reference
	 */
	void setReference(unsigned long value)
	{
		reference = value;
	}

	/**
	 * Get the value of reference
	 * Uniquee identifier for the order.
	 * @return the value of reference
	 */
	unsigned long getReference()
	{
		return reference;
	}

	/**
	 * Set the value of products
	 * Vector of unsigned long which store all the references of the productos in one
	 * order.
	 * @param value the new value of products
	 */
	void setProducts(vector<unsigned long> value)
	{
		products = value;
	}

	/**
	 * Get the value of products
	 * Vector of unsigned long which store all the references of the productos in one
	 * order.
	 * @return the value of products
	 */
	vector<unsigned long> getProducts()
	{
		return products;
	}

	/**
	 * Set the value of date
	 * Unix time, stores the moment in which the order was created.
	 * @param value the new value of date
	 */
	void setDate(time_t value)
	{
		date = value;
	}

	/**
	 * Get the value of date
	 * Unix time, stores the moment in which the order was created.
	 * @return the value of date
	 */
	time_t getDate()
	{
		return date;
	}

	/**
	 * Set the value of delivery_address
	 * ID of the shipping address of the order.
	 * @param value the new value of delivery_address
	 */
	void setDelivery_address(int value)
	{
		delivery_address = value;
	}

	/**
	 * Get the value of delivery_address
	 * ID of the shipping address of the order.
	 * @return the value of delivery_address
	 */
	int getDelivery_address()
	{
		return delivery_address;
	}

	/**
	 * Set the value of payment_method
	 * ID of the payment method chose by user to pay the order
	 * @param value the new value of payment_method
	 */
	void setPayment_method(int value)
	{
		payment_method = value;
	}

	/**
	 * Get the value of payment_method
	 * ID of the payment method chose by user to pay the order
	 * @return the value of payment_method
	 */
	int getPayment_method()
	{
		return payment_method;
	}

	/**
	 * Set the value of total
	 * Cost of the order. Sum of the prices of the products in the order (minus the
	 * 7.5% in case de costumer is an Administrator)
	 * @param value the new value of total
	 */
	void setTotal(float value)
	{
		total = value;
	}

	/**
	 * Get the value of total
	 * Cost of the order. Sum of the prices of the products in the order (minus the
	 * 7.5% in case de costumer is an Administrator)
	 * @return the value of total
	 */
	float getTotal()
	{
		return total;
	}

	void initAttributes();

};

#endif // ORDER_H
