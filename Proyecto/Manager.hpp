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
#include "Interface.hpp"

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
    vector<User*> getUsers() const;

    /**
     * @brief Get a vector with every
     * product registered in the platform.
     */
    vector<Product*> getProducts() const;


	/**
     * @brief Check user's credentials when trying to log into the platform.
     * @return true, if the credentials are correct
     * and there's not any other user already logged
     * false otherwise
	 * @param  email
	 * @param  password
	 */
    bool login(const string& em, const string& pas);

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
     * @param  us: username
     * @param  em: email
     * @param  pas: password
	 */
    bool addUser(string& us, string& em, string& pas);


	/**
     * @brief Same ass "addUser" method
     * but in this case it creates an Administrator instead.
     * It also takes employee code as parameter.
     * @return True: succes; otherwise False
     * @param  us: username
     * @param  em: email
     * @param  pas: password
     * @param  emcode: employee_code
	 */
    bool addAdministrator(string& us, string& em, string& pas, unsigned long emcode);


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
     * @param  a: address
     * @param  c: city
     * @param  p: province
     * @param  pcode: postal_code
	 */
    bool addAddress(const string& a, const string& c, const string& p, unsigned int pcode);

	/**
     * @brief Allow currently logged user to
     * register a new credit card
     * @return True: success, otherwise False
     * @param  a: billing address
     * @param  n: credit card's number
     * @param  cholder: cardholder
	 */
    bool addCreditCard(Address* a, unsigned long n, string& cholder);

	/**
     * @brief Allow currently logged user to
     * register a new paypal account
     * @return True: success, otherwise False
     * @param  a: billing address
     * @param  em: email
	 */
    bool addPaypal(Address* a, string& em);

    //################# SEGUNDA ENTREGA ############################//

	/**
     * @brief Adds a new product to the platform.
     * Only logged users which are administrator con do it.
     * @return True: success, otherwise False
     * @param  n: name
     * @param  d: description
     * @param  r: reference
     * @param  p: price
     */
    bool addProduct(string n, string d, unsigned long r, float p);

	/**
     * @brief It stores a vector of pointers to PublicUserData.
     * Show the public data of all
     * the registered members.
     * It can only be called by an Administrator, otherwise it
	 * returns an empty vector.
	 */
    vector<PublicUserData*> showMembers() const;

	/**
     * @brief Calculates the price taking into account
     * if the user is an administrator or not,
     * and asignates the order a uniquee reference.
     * A new order is created, and it is
     * added to the order history of the user currently logged.
     * @return True: success, false otherwise.
     * @param  pr: products
     * @param  pm: payment_method
     * @param  ddaddress: delivery_address
	 */
    bool makeOrder(vector<unsigned long> pr, int pm, int ddaddress);

	/**
     * @brief This allow the logged user to review a product
     * but ONLY if the user has already
     * bought the product.
     * Creates the review and adds it to the rest of the reviews of
	 * the specific product, with a unique id.
     * @return True: success, false otherwise.
     * @param  ref: Reference of the product to review
     * @param  rat: rating 0-5
     * @param  t: text
	 */
    bool createReview(unsigned long ref, int rat, string t);

	/**
     * @brief Allows us to filter reviews of a product by rating.
     * @return Reviews with a given rating
     * @param  ref: Reference of the product which
     * reviews we are trying to filter
     * @param  ret: Rating by which the user
     * want to filter the ratings
	 */
    vector<Review*> getReviewsByRating(unsigned long ref, int rat);

	/**
     * @brief Increase votes of an specific review
     * and so it does to the reviewer's
     * reputation. Any user can only vote once for each review,
     * and they can not vote for their own reviews.
     * @return True: succes, false otherwise
     * @param  i: Id of the review
	 */
    bool upvoteReview(unsigned long i);

	/**
     * @brief Decrease votes of an specific review
     * and so it does to the reviewer's
     * reputation. Any user can only vote once for each review,
     * and they can not vote for their own reviews
     * @return True: succes, false otherwise
     * @param i: Id of the review voted
	 */
    bool downvoteReview(unsigned long i);

	/**
     * @brief Allows the logged user to change a review's rating.
     * @return True: success, otherwise false
     * @param  i: ID of the review
     * @param  new_rating: 0-5 stars
	 */
    bool modifyReviewRating(unsigned long i, int new_rating);

	/**
     * @brief Allows the logged user to change a review's text.
     * @return True: success, otherwise false.
     * @param  i: ID of the review
	 * @param  new_text
	 */
    bool modifyReviewText(unsigned long i, string& new_text);

	/**
     * @brief Allow the currently logged user to delete
     * a review of his own. Only administrators can delete reviews
     * which are not made by them.
     * @return True success, otherwise false
     * @param  i: ID of the review
	 */
    bool deleteReview(unsigned long i);

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
