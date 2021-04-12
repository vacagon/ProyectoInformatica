#ifndef ADMINISTRATOR_HPP
#define ADMINISTRATOR_HPP

#include <string>
#include "User.hpp"

using namespace std;

/**
  * @brief Users which are also employees of the compan. They get a 7.5% discount as
  * costumers. They are identified by an employee code which has to be unique.
  */
class Administrator: public User {

public:

    /**
     * @brief Parametric constructor
     * @param us: Username
     * @param em: Email
     * @param pas: Password
     * @param emcode: Employee code
     */
    Administrator(string& us, string& em, string& pas, unsigned long emcode);

	/**
     * @brief Empty Destructor
	 */
	virtual ~Administrator();

	/**
     * @brief Gets employee's uniquee code
	 */
    unsigned long getEmployeeCode() const;

    /**
     * @brief Sets employee's uniquee code
     */
    void setEmployeeCode(unsigned long emcode);

    bool isAdmin();

private:

    /**
     * @brief Empty Constructor
     */
    Administrator();

	/**
     * @brief Uniquee for each employee
	 */
    unsigned long employee_code;

};

#endif // ADMINISTRATOR_HPP
