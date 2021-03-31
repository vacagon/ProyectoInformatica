
#ifndef MANAGER_H
#define MANAGER_H

#include string


/**
  * class Manager
  * In charge of the application running and provides all the functionality to it.
  */

class Manager
{
public:
	// Constructors/Destructors
	//  


	/**
	 * Empty Constructor
	 */
	Manager();

	/**
	 * Empty Destructor
	 */
	virtual ~Manager();

	// Static Public attributes
	//  

	// Public attributes
	//  


	// Public attribute accessor methods
	//  


	// Public attribute accessor methods
	//  



	/**
	 * @return User
	 */
	User getUsers() const
	{
	}


	/**
	 * @return Product
	 */
	Product getProducts()
	{
	}


	/**
	 * Check user's credentials when trying to log into the platform. Returns: true, if
	 * the credentials are correct and there's not any other user already logged; false
	 * otherwise.
	 * @return bool
	 * @param  email
	 * @param  password
	 */
	bool login(string email, string password)
	{
	}


	/**
	 * Close user's session in the platform. True: succes; false otherwise.
	 * @return bool
	 */
	bool logout()
	{
	}


	/**
	 * Know if there's any user logged in the platform. True: there is; False
	 * otherwise.
	 * @return bool
	 */
	bool isLogged()
	{
	}


	/**
	 * Get public and private information of the currently logged user. Returns a
	 * pointer to the logged user in case there's one, otherwise nullptr.
	 * @return User
	 */
	User getCurrentMember()
	{
	}


	/**
	 * Creates a new user. It checks wether the mail, or username, is already used.
	 * True: succes; otherwise False
	 * @return bool
	 * @param  username
	 * @param  email
	 * @param  password
	 */
	bool addUser(string username, string email, string password)
	{
	}


	/**
	 * Same ass "addUser" method, but in this case it creates an Administrator instead
	 * a normal User. It also takes employee code as parameter.
	 * @return bool
	 * @param  username
	 * @param  email
	 * @param  password
	 * @param  employee_code
	 */
	bool addAdministrator(string username, string email, string password, unsigned long employee_code)
	{
	}


	/**
	 * Allow the user logged to unsuscribe of the platform.
	 * @return bool
	 */
	bool eraseCurrentMember()
	{
	}


	/**
	 * True: success, otherwise False
	 * @return bool
	 * @param  new_username
	 */
	bool editUsername(string new_username)
	{
	}


	/**
	 * True: success, otherwise False
	 * @return bool
	 * @param  new_email
	 */
	bool editEmail(string new_email)
	{
	}


	/**
	 * True: success, otherwise False
	 * @return bool
	 * @param  new_password
	 */
	bool editPassword(string new_password)
	{
	}


	/**
	 * True: success, otherwise False
	 * @return bool
	 * @param  address
	 * @param  city
	 * @param  province
	 * @param  postal_code
	 */
	bool addAddress(string address, string city, string province, usigned int postal_code)
	{
	}


	/**
	 * True: success, otherwise False
	 * @return bool
	 * @param  Address
	 * @param  number
	 * @param  cardholder
	 */
	bool addCreditcard(Address Address, unsigned long number, string cardholder)
	{
	}


	/**
	 * True: success, otherwise False
	 * @return bool
	 * @param  Address
	 * @param  email
	 */
	bool addPaypal(Address Address, string email)
	{
	}


	/**
	 * Only logged users which are administrator con do it.
	 * @return bool
	 * @param  name
	 * @param  description
	 * @param  reference
	 * @param  price
	 */
	bool addProduct(string name, string description, unsigned long reference, float price)
	{
	}


	/**
	 * It stores a vector of pointers to PublicUserData. Show the public data of all
	 * the registered members. It can only be called by an Administrator, otherwise it
	 * returns an empty vector.
	 * @return PublicUserData
	 */
	PublicUserData showMembers() const
	{
	}


	/**
	 * Calculates the price taking into account if the user is an administrator or not,
	 * and asignates the order a uniquee reference. A new order is created, and it is
	 * added to the order history of the user currently logged. True: success, false
	 * otherwise.
	 * @return bool
	 * @param  products
	 * @param  payment_method
	 * @param  delivery_address
	 */
	bool makeOrder(vector<unsigned long> products, int payment_method, int delivery_address)
	{
	}


	/**
	 * This allow the logged user to review a product, but ONLY if the user has already
	 * bought the product. Creates the review and adds it to the rest of the reviews of
	 * the specific product, with a unique id.
	 * @return bool
	 * @param  reference Reference of the product to review
	 * @param  rating 0-5
	 * @param  text
	 */
	bool createReview(unsigned long reference, int rating, string text)
	{
	}


	/**
	 * Allows us to filter reviews of a product by rating.
	 * @return Review
	 * @param  reference Reference of the product which reviews we are trying to filter
	 * @param  rating Rating by which the user want to filter the ratings
	 */
	Review getReviewsByRating(usigned long reference, int rating)
	{
	}


	/**
	 * Increase votes of an specific review, and so it does to the reviewer's
	 * reputation. Any user can only vote once for each review, and they can not vote
	 * for their own reviews. True: succes, false otherwise.
	 * @return bool
	 * @param  id Id of the review
	 */
	bool upvoteReview(unsigned long id)
	{
	}


	/**
	 * Decrease votes of an specific review, and so it does to the reviewer's
	 * reputation. Any user can only vote once for each review, and they can not vote
	 * for their own reviews. True: succes, false otherwise.
	 * @return bool
	 * @param  id Id of the review voted
	 */
	bool downvoteReview(unsigned long id)
	{
	}


	/**
	 * Allows the logged user to change a review's rating. True: success, otherwise
	 * false.
	 * @return bool
	 * @param  id
	 * @param  new_rating 0-5 stars
	 */
	bool modifyReviewRating(unsigned long id, int new_rating)
	{
	}


	/**
	 * Allows the logged user to change a review's text. True: success, otherwise
	 * false.
	 * @return bool
	 * @param  id
	 * @param  new_text
	 */
	bool modifyReviewText(unsigned long id, string new_text)
	{
	}


	/**
	 * Allow the currently logged user to delete a review of his own. Only
	 * administrators can delete reviews which are not made by them. True success,
	 * otherwise false
	 * @return bool
	 * @param  id
	 */
	bool deleteReview(unsigned long id)
	{
	}


	/**
	 * Writes all the information of the system to a given file: users and their
	 * information; products and their reviews.
	 * @param  route Route to the file where the information is gonna be stored
	 */
	void saveToFile(string route)
	{
	}


	/**
	 * Restores all the system's information stored in a given file
	 * @param  route Route to the file where the information is stored
	 */
	void loadFromFile(string route)
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

	// Vector which store pointers to every user registered in the platform.
	User users;
	// Vector which stores pointers to every product selled in the platform.
	Product products;
	// Tells the user currently logged in the system, and corresponds to the position in the vector users of the user. Value of -1 when there is no user logged.
	int current_member;

	// Private attribute accessor methods
	//  


	// Private attribute accessor methods
	//  


	/**
	 * Set the value of users
	 * Vector which store pointers to every user registered in the platform.
	 * @param value the new value of users
	 */
	void setUsers(User value)
	{
		users = value;
	}

	/**
	 * Get the value of users
	 * Vector which store pointers to every user registered in the platform.
	 * @return the value of users
	 */
	User getUsers()
	{
		return users;
	}

	/**
	 * Set the value of products
	 * Vector which stores pointers to every product selled in the platform.
	 * @param value the new value of products
	 */
	void setProducts(Product value)
	{
		products = value;
	}

	/**
	 * Get the value of products
	 * Vector which stores pointers to every product selled in the platform.
	 * @return the value of products
	 */
	Product getProducts()
	{
		return products;
	}

	/**
	 * Set the value of current_member
	 * Tells the user currently logged in the system, and corresponds to the position
	 * in the vector users of the user. Value of -1 when there is no user logged.
	 * @param value the new value of current_member
	 */
	void setCurrent_member(int value)
	{
		current_member = value;
	}

	/**
	 * Get the value of current_member
	 * Tells the user currently logged in the system, and corresponds to the position
	 * in the vector users of the user. Value of -1 when there is no user logged.
	 * @return the value of current_member
	 */
	int getCurrent_member()
	{
		return current_member;
	}

	void initAttributes();

};

#endif // MANAGER_H
