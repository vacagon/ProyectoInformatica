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

    Address(int i, string& ad, string& cit, string& prov, unsigned int pcode);

	virtual ~Address();

    int getId() const;

    void setId(int i);

    const string& getAddress() const;

    void setAddress(string& ad);

    const string& getCity() const;

    void setCity(string& cit);

    const string& getProvince() const;

    void setProvince(string& prov);

    unsigned int getPostalCode() const;

    void setPostalCode(unsigned int pcode);

    const string show() const;

private:

    Address();

    /**
     * @brief Its value depends on the number of addresses registered by each user.
     * If it's the first one, id = 0, if it's the second one, id = 1, and so on.
     */
    int id;

	string address;

    string city;

	string province;

	unsigned int postal_code;

};

#endif // ADDRESS_HPP
