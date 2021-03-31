
#ifndef USER_H
#define USER_H

#include string
#include vector

#include "Product.h"


/**
  * class User
  * Can order products. Have one or more shipping address, and one or more payment
  * methods
  */

class User
{
public:
	// Constructors/Destructors
	//  


	/**
	 * Empty Constructor
	 */
	User();

	/**
	 * Empty Destructor
	 */
	virtual ~User();

	// Static Public attributes
	//  

	// Public attributes
	//  

	// Public information of the user
	PublicUserData PublicUserData;

	std::vector<Product*> m_purchasedVector;

	// Public attribute accessor methods
	//  


	// Public attribute accessor methods
	//  


	/**
	 * Set the value of PublicUserData
	 * Public information of the user
	 * @param value the new value of PublicUserData
	 */
	void setPublicUserData(PublicUserData value)
	{
		PublicUserData = value;
	}

	/**
	 * Get the value of PublicUserData
	 * Public information of the user
	 * @return the value of PublicUserData
	 */
	PublicUserData getPublicUserData()
	{
		return PublicUserData;
	}

	/**
	 * Add a Purchased object to the m_purchasedVector List
	 */
	void addPurchased (Product * add_object);

	/**
	 * Remove a Purchased object from m_purchasedVector List
	 */
	void removePurchased (Product * remove_object);

	/**
	 * Get the list of Purchased objects held by m_purchasedVector
	 * @return std::vector<Product *> list of Purchased objects held by
	 * m_purchasedVector
	 */
	std::vector<Product *> getPurchasedList();


	/**
	 * True if the user is an administrator, false if it is not.
	 * @return bool
	 */
	bool isAdmin()
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

	// Private information of the user
	PrivateUserData PrivateUserData;

	// Private attribute accessor methods
	//  


	// Private attribute accessor methods
	//  


	/**
	 * Set the value of PrivateUserData
	 * Private information of the user
	 * @param value the new value of PrivateUserData
	 */
	void setPrivateUserData(PrivateUserData value)
	{
		PrivateUserData = value;
	}

	/**
	 * Get the value of PrivateUserData
	 * Private information of the user
	 * @return the value of PrivateUserData
	 */
	PrivateUserData getPrivateUserData()
	{
		return PrivateUserData;
	}

	void initAttributes();

};

#endif // USER_H
