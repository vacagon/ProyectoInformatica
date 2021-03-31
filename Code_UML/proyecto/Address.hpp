
#ifndef ADDRESS_H
#define ADDRESS_H

#include string


/**
  * class Address
  * Shipping address registered by any user
  */

class Address
{
public:
	// Constructors/Destructors
	//  


	/**
	 * Empty Constructor
	 */
	Address();

	/**
	 * Empty Destructor
	 */
	virtual ~Address();

	// Static Public attributes
	//  

	// Public attributes
	//  


	// Public attribute accessor methods
	//  


	// Public attribute accessor methods
	//  



	/**
	 * @return int
	 */
	int getId() const
	{
	}


	/**
	 */
	void setId()
	{
	}


	/**
	 * @return string&
	 */
	string& getAddress() const
	{
	}


	/**
	 */
	void setAddress()
	{
	}


	/**
	 */
	void setCity()
	{
	}


	/**
	 * @return string&
	 */
	string& getCity() const
	{
	}


	/**
	 * @return string&
	 */
	string& getProvince()
	{
	}


	/**
	 */
	void setProvince() const
	{
	}


	/**
	 */
	void setPostalCode()
	{
	}


	/**
	 */
	void getPostalCode() const
	{
	}


	/**
	 * {address}, {city}, {province}, {postal_code}
	 * @return string&
	 */
	string& show() const
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

	// Its value depends on the number of addresses registered by each user. If it's the first one, id = 0, if it's the second one, id = 1, and so on. 
	int id;
	string address;
	string city;
	string province;
	unsigned int postal_code;

	// Private attribute accessor methods
	//  


	// Private attribute accessor methods
	//  


	/**
	 * Set the value of id
	 * Its value depends on the number of addresses registered by each user. If it's
	 * the first one, id = 0, if it's the second one, id = 1, and so on.
	 * @param value the new value of id
	 */
	void setId(int value)
	{
		id = value;
	}

	/**
	 * Get the value of id
	 * Its value depends on the number of addresses registered by each user. If it's
	 * the first one, id = 0, if it's the second one, id = 1, and so on.
	 * @return the value of id
	 */
	int getId()
	{
		return id;
	}

	/**
	 * Set the value of address
	 * @param value the new value of address
	 */
	void setAddress(string value)
	{
		address = value;
	}

	/**
	 * Get the value of address
	 * @return the value of address
	 */
	string getAddress()
	{
		return address;
	}

	/**
	 * Set the value of city
	 * @param value the new value of city
	 */
	void setCity(string value)
	{
		city = value;
	}

	/**
	 * Get the value of city
	 * @return the value of city
	 */
	string getCity()
	{
		return city;
	}

	/**
	 * Set the value of province
	 * @param value the new value of province
	 */
	void setProvince(string value)
	{
		province = value;
	}

	/**
	 * Get the value of province
	 * @return the value of province
	 */
	string getProvince()
	{
		return province;
	}

	/**
	 * Set the value of postal_code
	 * @param value the new value of postal_code
	 */
	void setPostal_code(unsigned int value)
	{
		postal_code = value;
	}

	/**
	 * Get the value of postal_code
	 * @return the value of postal_code
	 */
	unsigned int getPostal_code()
	{
		return postal_code;
	}

	void initAttributes();

};

#endif // ADDRESS_H
