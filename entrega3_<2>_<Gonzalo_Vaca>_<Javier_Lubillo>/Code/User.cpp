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
    os << "reputation: " << U.getReputation() << endl
       << "-----------" << endl
       << "-----------" << endl;
    os << "Registered addresses:" << endl
       << "--------------" << endl;
    for (Address* address: U.getAddresses()) {
        os << *address << endl;
    }
    os << "-----------" << endl
       << "-----------" << endl;
    os << "Registered credit cards:" << endl
       << "--------------" << endl;
    for (CreditCard* credit_cards: U.getCreditCards()) {
        os << *credit_cards << endl;
    }
    os << "-----------" << endl
       << "-----------" << endl;
    os << "Registered Paypal accounts:" << endl
       << "--------------" << endl;
    for (Paypal* paypals: U.getPaypals()) {
        os << *paypals << endl;
    }
    os << "-----------" << endl
       << "-----------" << endl;
    os << "Orders:" << endl
       << "--------------" << endl;
    for (Order* orders: U.getOrders()) {
        os << *orders << endl;
    }
    os << "-----------" << endl
       << "-----------" << endl;
    return os;
}
