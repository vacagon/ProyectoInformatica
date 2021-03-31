
#ifndef PRODUCT_H
#define PRODUCT_H

#include string
#include vector

class User;


/**
  * class Product
  * Electronic component selled in the platform.
  */

class Product
{
public:
	// Constructors/Destructors
	//  


	/**
	 * Empty Constructor
	 */
	Product();

	/**
	 * Empty Destructor
	 */
	virtual ~Product();

	// Static Public attributes
	//  

	// Public attributes
	//  


	std::vector<User*> m_purchaserVector;

	// Public attribute accessor methods
	//  


	// Public attribute accessor methods
	//  


	/**
	 * Add a Purchaser object to the m_purchaserVector List
	 */
	void addPurchaser (User * add_object);

	/**
	 * Remove a Purchaser object from m_purchaserVector List
	 */
	void removePurchaser (User * remove_object);

	/**
	 * Get the list of Purchaser objects held by m_purchaserVector
	 * @return std::vector<User *> list of Purchaser objects held by m_purchaserVector
	 */
	std::vector<User *> getPurchaserList();


	/**
	 * @return string&
	 */
	string& getName()
	{
	}


	/**
	 */
	void setName() const
	{
	}


	/**
	 */
	void setDescription()
	{
	}


	/**
	 * @return string&
	 */
	string& getDescription() const
	{
	}


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
	 */
	void setPrice()
	{
	}


	/**
	 * @return float
	 */
	float getPrice() const
	{
	}


	/**
	 * @return Review
	 */
	Review getReviews() const
	{
	}


	/**
	 * @param  new_review Pointer to the new review to be added
	 */
	void addReviews(Review new_review)
	{
	}


	/**
	 * Overload of  operator <<, so cout << <Product> prints:
	 * {reference} - {name}
	 * {description}
	 * {price}
	 * \t-- User reviews --
	 * \t {review}
	 * \t----
	 * \t {review}
	 * \t----
	 */
	void operator_()
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

	// Name or short description of the product
	string name;
	// Long description of the product
	string description;
	// Uniquee reference corresponding to each product
	unsigned long reference;
	float price;
	// Vector which stores all the reviews made by users to an specific product.
	Review reviews;

	// Private attribute accessor methods
	//  


	// Private attribute accessor methods
	//  


	/**
	 * Set the value of name
	 * Name or short description of the product
	 * @param value the new value of name
	 */
	void setName(string value)
	{
		name = value;
	}

	/**
	 * Get the value of name
	 * Name or short description of the product
	 * @return the value of name
	 */
	string getName()
	{
		return name;
	}

	/**
	 * Set the value of description
	 * Long description of the product
	 * @param value the new value of description
	 */
	void setDescription(string value)
	{
		description = value;
	}

	/**
	 * Get the value of description
	 * Long description of the product
	 * @return the value of description
	 */
	string getDescription()
	{
		return description;
	}

	/**
	 * Set the value of reference
	 * Uniquee reference corresponding to each product
	 * @param value the new value of reference
	 */
	void setReference(unsigned long value)
	{
		reference = value;
	}

	/**
	 * Get the value of reference
	 * Uniquee reference corresponding to each product
	 * @return the value of reference
	 */
	unsigned long getReference()
	{
		return reference;
	}

	/**
	 * Set the value of price
	 * @param value the new value of price
	 */
	void setPrice(float value)
	{
		price = value;
	}

	/**
	 * Get the value of price
	 * @return the value of price
	 */
	float getPrice()
	{
		return price;
	}

	/**
	 * Set the value of reviews
	 * Vector which stores all the reviews made by users to an specific product.
	 * @param value the new value of reviews
	 */
	void setReviews(Review value)
	{
		reviews = value;
	}

	/**
	 * Get the value of reviews
	 * Vector which stores all the reviews made by users to an specific product.
	 * @return the value of reviews
	 */
	Review getReviews()
	{
		return reviews;
	}

	void initAttributes();

};

#endif // PRODUCT_H
