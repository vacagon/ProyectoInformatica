#include "User.hpp"

User::User(const string &us, const string &em, const string &pas):
    PublicUserData(us), PrivateUserData(em, pas) {}

User::~User() {}

bool User::isAdmin() {
    return false;
}

unsigned long User::getEmployeeCode() const {
    return 0;
}

ostream& operator << (ostream& os, User& U) {
    os << "User:" << endl
       << "-----------" << endl
       << "username: " << U.username << endl
       << "email: " << U.email << endl
       << "password: " << U.password << endl;
    if (U.isAdmin()) {
        os << "employee code: " << U.getEmployeeCode() << endl;
    }
    os << "reputation: " << U.getReputation() << endl;
    if (U.getAddresses().size() > 0) {
        os << "Registered addresses:" << endl
           << "--------------" << endl;
        for (Address* address: U.getAddresses()) {
            os << *address << endl;
        }
    }
    if (U.getCreditCards().size() > 0) {
        os << "Registered credit cards:" << endl
           << "--------------" << endl;
        for (CreditCard* credit_cards: U.getCreditCards()) {
            os << *credit_cards << endl;
        }
    }
    if (U.getPaypals().size() > 0) {
        os << "Registered Paypal accounts:" << endl
            << "--------------" << endl;
        for (Paypal* paypals: U.getPaypals()) {
            os << *paypals << endl;
        }
    }
    if (U.getOrders().size() > 0) {
        os << "Orders:" << endl
           << "--------------" << endl;
        for (Order* orders: U.getOrders()) {
            os << *orders << endl;
        }
    }
    return os;
}
