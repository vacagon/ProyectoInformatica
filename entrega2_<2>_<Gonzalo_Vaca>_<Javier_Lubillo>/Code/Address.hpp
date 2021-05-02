#ifndef ADDRESS_HPP
#define ADDRESS_HPP

#include <iostream>
#include <string>
#include <sstream>
#include "Order.hpp"

using namespace std;

/**
  * @brief Shipping address registered by any user
  */
class Address {

public:

    Address(const string& address, const string& city, const string& province, const unsigned int& postal_code, const int& id = -1);

	virtual ~Address();

    int getId() const;

    void setId(const int& i);

    const string& getAddress() const;

    void setAddress(const string& ad);

    const string& getCity() const;

    void setCity(const string& cit);

    const string& getProvince() const;

    void setProvince(const string& prov);

    unsigned int getPostalCode() const;

    void setPostalCode(const unsigned int& pcode);

    const string show() const;

private:

    Address();

    /**
     * @brief Its value depends on the number of addresses registered by each user.
     * If it's the first one, id = 0, if it's the second one, id = 1, and so on. If
     * there is no registered address, id = -1;
     */
    int id;

	string address;

    string city;

	string province;

	unsigned int postal_code;

};

#endif // ADDRESS_HPP
