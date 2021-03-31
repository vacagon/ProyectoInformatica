#ifndef PRIVATEUSERDATA_HPP
#define PRIVATEUSERDATA_HPP

#include <string>
#include <vector>
#include "Address.hpp"
#include "PaymentMethod.hpp"
#include "Order.hpp"

using namespace std;

/** @brief Private data of the user*/
class PrivateUserData
{

public:

    string getEmail() const { return email; };

    void setEmail(string& em) { email = em; }

    string getPassword() const { return password; };

    void setPassword(string& pas) { password = pas; }

    const Address& getAddress();

    const PaymentMethod& getPaymentMethod();

    const Order& getOrder();

    PrivateUserData(string& em, string& pas): email(em), password(pas){}

    ~PrivateUserData();

protected:

    string email, password;

    vector<Address*> adresses;

    vector<PaymentMethod*> payment_methods;

    vector<Order*> orders;

    PrivateUserData();
};

#endif // PRIVATEUSERDATA_HPP
