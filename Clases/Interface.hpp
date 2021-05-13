#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "Manager.hpp"

using namespace std;

class Interface {

public:

    Interface(Manager& m);

    ~Interface();

    //*************MENÚS********************

    /**
     * @brief Let the user chose if the
     * wants to sign in (1) or sign up (2)
     * or close the app (0)
     */
    void FrontPageMenu();

    /**
     * @brief Allow the logged user
     * do all the actions allowed by
     * the class manager
     */
    void HomeMenu();

    /**
     * @brief Allow the logged admin
     * do all the actions allowed by
     * the class manager to a normal
     * user plus those only allowed
     * for admins
     */
    void HomeMenuAdministrator();

    /**
     * @brief Allow the logged user to
     * edit its account (change username,
     * email, password and addresses)
     */
    void editAccountMenu();

    /**
     * @brief Menu in which the user
     * can add and erase products to shopping
     * cart, and make the order
     */
    void makeOrderMenu();

    /**
     * @brief Allow administrator
     * to edit a registered product
     */
    void editProductMenu();

    /**
     * @brief Allow registered user
     * to see and filter reviews, create
     * a new one, and vote other user's
     * reviews
     */
    void reviewsMenu();

    /**
     * @brief Allow registered user
     * to modify one review of his own
     */
    void modifyReviewMenu();

    //*************FUNCIONES*****************

    /**
     * @brief Add an administrator to the platform
     */
    bool addAdministrator();

    /**
     * @brief Add a normal user to the platform
     */
    bool addUser();

    /**
     * @brief Log a user if the correct email
     * and password is entered
     */
    bool login();

    /**
     * @brief Allow register user to edit
     * its username
     */
    bool editUsername();

    /**
     * @brief Allow register user to edit
     * its email
     */
    bool editEmail();

    /**
     * @brief Allow register user to edit
     * its password
     */
    bool editPassword();

    /**
     * @brief Allow register user to edit
     * one of its addresses
     */
    void editAddress();

    /**
     * @brief Allow the user to delete its
     * profile of the platform
     */
    void eraseCurrentMember();

    /**
     * @brief Allow the user to add a new
     * address
     */
    void addAddress();

    /**
     * @brief Allow the user to add a new
     * payment method
     */
    void addPaymentMethod();

    /**
     * @brief Allow the user to add a new
     * credit card
     */
    void addCreditCard(const int &id, Address *billing_address);

    /**
     * @brief Allow the user to add a new
     * paypal account
     */
    void addPaypal(const int& id, Address *billing_address);

    /**
     * @brief Show logged user profile
     */
    const string showProfile();

    /**
     * @brief Show logged user addresses
     */
    const string showAddresses() const;

    /**
     * @brief Show logged user payment methods
     */
    const string showPaymentMethods() const;

    /**
     * @brief Show every registered users public data
     */
    const string showMembers() const;

    /**
     * @brief Show logged user previous orders
     */
    const string showOrders();

    /**
     * @brief Allow logged administrator to
     * add a product to the platform
     */
    void addProduct();

    /**
     * @brief Show every product in
     * the platform
     */
    const string showProducts() const;

    /**
     * @brief Show every product in
     * the shopping cart
     */
    const string showCart() const;

    /**
     * @brief Allow logged user to add
     * a product to shopping cart
     */
    bool addProductToCart();

    /**
     * @brief Allow logged user to delete
     * a product to shopping cart
     */
    bool eraseProductFromCart();

    /**
     * @brief Allow logged user to buy
     * the product in the shopping cart
     */
    bool makeOrder();

    /**
     * @brief Allow the user to review
     * product he has already bought
     */
    void createReview();

    /**
     * @brief Show all the reviews made
     * in the platform
     */
    const string showReviews() const;

    /**
     * @brief Show all the reviews of
     * a specific product with an specific
     * rating
     */
    const string showReviewsByRating() const;

    /**
     * @brief Allow logged user to vote
     * other user's review, only once
     */
    void voteReview();

    /**
     * @brief Allow owners to delete their own
     * reviews. Administrator can also delete
     * other user's reviews
     */
    void deleteReview();

    /**
     * @brief Makes sure that the option
     * introduce by user is a number and
     * it is between allowable limits
     * @param lower_bound: lower limit
     * @param upperbound: upper limit
     * @return Valid option
     */
    int ValidOption(int lower_bound, int upperbound);

    /**
     * @brief Format the number of a
     * credit card. Delete characters
     * other than numbers and substitute
     * them to 0, or 1 in case it is the
     * first digit. Fill the number with 0
     * until it has 16 digits
     * @return 16 digits unsigned long
     */
    unsigned long ValidFormatCreditCard();

    /**
     * @brief Format the number of a
     * postal code. Delete characters
     * other than numbers and substitute
     * them to 0, or 1 in case it is the
     * first digit. Fill the number with 0
     * until it has 5 digits
     * @return 5 digits unsigned int
     */
    unsigned int ValidFormatPostalCode();

private:

    Manager* manager;

    /**
     * @brief Store the products selected
     * by user to buy, but not already bought
     */
    vector<Product*> shopping_cart;

};

#endif // INTERFACE_HPP
