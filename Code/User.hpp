#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <vector>
#include "Product.hpp"
#include "PublicUserData.hpp"
#include "PrivateUserData.hpp"
#include "Manager.hpp"
#include "Administrator.hpp"

using namespace std;

/**
  * @brief Can order products. Have one or more shipping address, and one or more payment
  * methods
  */
class User: public PublicUserData, public PrivateUserData {

public:

    User(string& us, string& em, string& pas);

	virtual ~User();

	/**
     * @brief Tells if the user is an administrator
     * @return True if it's, false if it's not
	 */
    virtual bool isAdmin();

protected:

    User();

};

#endif // USER_HPP
