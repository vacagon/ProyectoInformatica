#ifndef PUBLICUSERDATA_HPP
#define PUBLICUSERDATA_HPP

#include <string>
#include <vector>
#include "Address.hpp"
#include "PaymentMethod.hpp"
#include "Order.hpp"

using namespace std;

/** @brief Public data of the user */
class PublicUserData
{

public:

    void setUsername(string& us) const;

    string getUsername() const { return username; }

    int getReputation() const { return reputation; }

    void increaseReputation() { reputation++; }

    void decreaseReputation() { if (reputation > 0) reputation--; }

    PublicUserData(string& us, int rep = 0): username(us), reputation(rep) {}

    ~PublicUserData();

protected:

    string username;

    int reputation;

    PublicUserData();
};

#endif // PUBLICUSERDATA_HPP
