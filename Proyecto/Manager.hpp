#ifndef MANAGER_HPP
#define MANAGER_HPP

/**
 * Header files
 */
#include <string>
#include <vector>
#include <algorithm>
#include "User.hpp"
#include "Administrator.hpp"
#include "PrivateUserData.hpp"
#include "PublicUserData.hpp"
#include "Address.hpp"
#include "PaymentMethod.hpp"
#include "CreditCard.hpp"
#include "Paypal.hpp"
#include "Order.hpp"
#include "Product.hpp"
#include "Review.hpp"

using namespace std;

/**
  * @brief In charge of the application running and provides all the functionality to it.
  */
class Manager {

public:

    //################# PRIMERA ENTREGA ############################//

	/**
     * @brief Empty Constructor initialices
     * all the parameters to default values
	 */
	Manager();

	virtual ~Manager();

    /**
     * @brief Get a vector with every
     * user registered in the platform.
     */
    const vector<User*>& getUsers() const;

    /**
     * @brief Get a vector with every
     * product registered in the platform.
     */
    const vector<Product*>& getProducts() const;


	/**
     * @brief Check user's credentials when trying to log into the platform.
     * @return true, if the credentials are correct
     * and there's not any other user already logged
     * false otherwise
	 * @param  email
	 * @param  password
	 */
    bool login(const string& email, const string& password);

	/**
     * @brief Close user's session in the platform.
     * @return True: succes; false otherwise.
	 */
    bool logout();

	/**
     * @brief Know if there's any user logged in the platform.
     * @return True: there is; False otherwise.
	 */
    bool isLogged();

	/**
     * @brief Get public and private information of
     * the currently logged user
     * @return Pointer to the logged user in case there's one
     * otherwise nullptr.
	 */
    User* getCurrentMember();

	/**
     * @brief Creates a new user
     * it checks wether the mail, or username,
     * is already used.
     * @return True: succes; otherwise False
	 */
    bool addUser(const string& username, const string& email, const string& password);


	/**
     * @brief Same ass "addUser" method
     * but in this case it creates an Administrator instead.
     * It also takes employee code as parameter.
     * @return True: succes; otherwise False
	 */
    bool addAdministrator(const string& username, const string& email, const string& password, const unsigned long& employee_code);


	/**
     * @brief Allow the user logged
     * to unsuscribe of the platform.
     * @return True: succes; otherwise False
	 */
    bool eraseCurrentMember();


	/**
     * @brief Allow the logger user to edit
     * his username
     * @return True: success, otherwise False
	 * @param  new_username
	 */
    bool editUsername(const string& new_username);

	/**
     * @brief Allow the logger user to edit
     * his email
     * @return True: success, otherwise False
	 * @param  new_email
	 */
    bool editEmail(const string& new_email);


	/**
     * @brief Allow the logger user to edit
     * his password
     * @return True: success, otherwise False
	 * @param  new_password
	 */
    bool editPassword(const string& new_password);


	/**
     * @brief Allow currently logged user to
     * register a new address
     * @return True: success, otherwise False
     */
    bool addAddress(const string& address, const string& city, const string& province, const unsigned int& postal_code);

	/**
     * @brief Allow currently logged user to
     * register a new credit card
     * @return True: success, otherwise False
	 */
    bool addCreditCard(const Address* address, const unsigned long& number, const string& cardholder);

	/**
     * @brief Allow currently logged user to
     * register a new paypal account
     * @return True: success, otherwise False
	 */
    bool addPaypal(const Address* address, string& email);

    //################# SEGUNDA ENTREGA ############################//

	/**
     * @brief Adds a new product to the platform.
     * Only logged users which are administrators con do it.
     * @return True: success, otherwise False
     */
    bool addProduct(const string& name, const string& description, const unsigned long& reference, const float& price);

	/**
     * @brief It stores a vector of pointers to PublicUserData.
     * Show the public data of all
     * the registered members.
     * It can only be called by an Administrator, otherwise it
	 * returns an empty vector.
	 */
    vector<PublicUserData*> showMembers();

	/**
     * @brief Calculates the price taking into account
     * if the user is an administrator or not,
     * and asignates the order a uniquee reference.
     * A new order is created, and it is
     * added to the order history of the user currently logged.
     * @return True: success, false otherwise.
	 */
    bool makeOrder(const vector<unsigned long> products, const int &payment_method, const int &delivery_daddress);

	/**
     * @brief This allow the logged user to review a product
     * but ONLY if the user has already
     * bought the product.
     * Creates the review and adds it to the rest of the reviews of
	 * the specific product, with a unique id.
     * @return True: success, false otherwise.
	 */
    bool createReview(const unsigned long& reference, const int& rating, const string& t);

	/**
     * @brief Allows us to filter reviews of a product by rating.
     * @return Reviews with a given rating
	 */
    vector<Review*> getReviewsByRating(const unsigned long& reference, const int& rating);

	/**
     * @brief Increase votes of an specific review
     * and so it does to the reviewer's
     * reputation. Any user can only vote once for each review,
     * and they can not vote for their own reviews.
     * @return True: succes, false otherwise
	 */
    bool upvoteReview(const unsigned long& id);

	/**
     * @brief Decrease votes of an specific review
     * and so it does to the reviewer's
     * reputation. Any user can only vote once for each review,
     * and they can not vote for their own reviews
     * @return True: succes, false otherwise
	 */
    bool downvoteReview(const unsigned long& id);

	/**
     * @brief Allows the logged user to change a review's rating.
     * @return True: success, otherwise false
	 */
    bool modifyReviewRating(const unsigned long& id, const int& new_rating);

	/**
     * @brief Allows the logged user to change a review's text.
     * @return True: success, otherwise false.
	 */
    bool modifyReviewText(const unsigned long& id, const string &new_text);

	/**
     * @brief Allow the currently logged user to delete
     * a review of his own. Only administrators can delete reviews
     * which are not made by them.
     * @return True success, otherwise false
	 */
    bool deleteReview(const unsigned long& id);

    //################# TERCERA ENTREGA ############################//

	/**
     * @brief Writes all the information of the system
     * to a given file: users and their information;
     * products and their reviews.
     * @param route: Route to the file where
     * the information is gonna be stored
	 */
    void saveToFile(string& route);

	/**
     * @brief Restores all the system's information
     * stored in a given file
     * @param route: Route to the file where the information is stored
	 */
    void loadFromFile(string route);

private:

    /**
     * @brief Vector which store pointers to every user registered in the platform.
     */
    vector<User*> users;

    /**
     * @brief Vector which stores pointers to every product selled in the platform.
     */
    vector<Product*> products;

    /**
     * @brief Tells the corresponding position in the vector
     * of users of the user currently logged in the system
     * Value of -1 when there is no user logged.
     */
	int current_member;

};

#endif // MANAGER_HPP
