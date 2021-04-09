#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <vector>
#include "PublicUserData.hpp"
#include "PrivateUserData.hpp"

using namespace std;

/**
  * @brief Can order products. Have one or more shipping address, and one or more payment
  * methods
  */
class User: public PublicUserData, public PrivateUserData {

public:

    User(const string& us, const string& em, const string& pas);

	virtual ~User();

	/**
     * @brief Tells if the user is an administrator
     * @return True if it's, false if it's not
	 */
    virtual bool isAdmin();

    /**
     * @brief Virtual method to get employee code, in case
     * it is not an employee, return 0
     */
    virtual unsigned long getEmployeeCode() const;

protected:

    User();

};

#endif // USER_HPP
