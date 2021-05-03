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

    void editAccountMenu();

    void makeOrderMenu();

    void editProductMenu();

    void reviewsMenu();

    //*************FUNCIONES*****************

    bool addAdministrator();

    bool addUser();

    bool login();

    bool editUsername();

    bool editEmail();

    bool editPassword();

    void editAddress();

    void editPaymentMethod();

    void eraseCurrentMember();

    void addAddress();

    void addPaymentMethod();

    void addCreditCard(const int &id, const Address *billing_address);

    void addPaypal(const int& id, const Address* billing_address);

    const string showProfile() const;

    const string showUserData() const;

    const string showAddresses() const;

    const string showPaymentMethods() const;

    const string showMembers() const;

    const string showOrders() const;

    void addProduct();

    const string showProducts() const;

    const string showCart() const;

    bool addProductToCart();

    bool eraseProductFromCart();

    bool makeOrder();

    void createReview();

    const string showReviews() const;

    const string showReviewsByRating() const;

    void voteReview();

    void deleteReview();

private:

    Manager* manager;

    vector<Product*> shopping_cart;

};

#endif // INTERFACE_HPP
