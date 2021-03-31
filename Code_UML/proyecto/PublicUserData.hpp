#ifndef PUBLICUSERDATA_HPP
#define PUBLICUSERDATA_HPP

#include <string>
#include "User.hpp"
#include "Review.hpp"

/**
  * class PublicUserData
  * 
  */

class PublicUserData
{
public:
	// Constructors/Destructors
	//  


	/**
	 * Empty Constructor
	 */
	PublicUserData();

	/**
	 * Empty Destructor
	 */
	virtual ~PublicUserData();

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
	void setUsername()
	{
	}


	/**
	 * @return undef
	 */
	undef getUsername()
	{
	}


	/**
	 * @return int
	 */
	int getReputation()
	{
	}


	/**
	 */
	void increaseReputation()
	{
	}


	/**
	 */
	void decreaseReputation()
	{
	}

protected:
	// Static Protected attributes
	//  

	// Protected attributes
	//  

	string username;
	// Users can score other user´s reviews on productos, and depending on their score, each user gets a reputation (never smaller than 0)
	int reputation;

	// Protected attribute accessor methods
	//  


	// Protected attribute accessor methods
	//  


	/**
	 * Set the value of username
	 * @param value the new value of username
	 */
	void setUsername(string value)
	{
		username = value;
	}

	/**
	 * Get the value of username
	 * @return the value of username
	 */
	string getUsername()
	{
		return username;
	}

	/**
	 * Set the value of reputation
	 * Users can score other user´s reviews on productos, and depending on their score,
	 * each user gets a reputation (never smaller than 0)
	 * @param value the new value of reputation
	 */
	void setReputation(int value)
	{
		reputation = value;
	}

	/**
	 * Get the value of reputation
	 * Users can score other user´s reviews on productos, and depending on their score,
	 * each user gets a reputation (never smaller than 0)
	 * @return the value of reputation
	 */
	int getReputation()
	{
		return reputation;
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

#endif // PUBLICUSERDATA_H
