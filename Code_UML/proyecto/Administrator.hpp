
#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include string


/**
  * class Administrator
  * Users which are also employees of the compan. They get a 7.5% discount as
  * costumers. They are identified by an employee code which has to be uniquee.
  */

class Administrator
{
public:
	// Constructors/Destructors
	//  


	/**
	 * Empty Constructor
	 */
	Administrator();

	/**
	 * Empty Destructor
	 */
	virtual ~Administrator();

	// Static Public attributes
	//  

	// Public attributes
	//  

	User User;

	// Public attribute accessor methods
	//  


	// Public attribute accessor methods
	//  


	/**
	 * Set the value of User
	 * @param value the new value of User
	 */
	void setUser(User value)
	{
		User = value;
	}

	/**
	 * Get the value of User
	 * @return the value of User
	 */
	User getUser()
	{
		return User;
	}


	/**
	 * @return unsigned long
	 */
	unsigned long getEmployeeCode() const
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

	unsigned long employee_code;

	// Private attribute accessor methods
	//  


	// Private attribute accessor methods
	//  


	/**
	 * Set the value of employee_code
	 * @param value the new value of employee_code
	 */
	void setEmployee_code(unsigned long value)
	{
		employee_code = value;
	}

	/**
	 * Get the value of employee_code
	 * @return the value of employee_code
	 */
	unsigned long getEmployee_code()
	{
		return employee_code;
	}

	void initAttributes();

};

#endif // ADMINISTRATOR_H
