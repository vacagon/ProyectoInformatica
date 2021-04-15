#include "Address.hpp"

Address::Address(const string& address, const string& city, const string& province, const unsigned int& postal_code, const int& id) {
    setAddress(address);
    setCity(city);
    setProvince(province);
    setPostalCode(postal_code);
    setId(id);
}

Address::~Address() {}

int Address::getId() const {
    return id;
}

void Address::setId(const int& i) {
    id = i;
}

const string& Address::getAddress() const {
    return address;
}

void Address::setAddress(const string &ad) {
    address = ad;
}

const string& Address::getCity() const {
    return city;
}

void Address::setCity(const string &cit){
    city = cit;
}

const string& Address::getProvince() const {
    return province;
}

void Address::setProvince(const string &prov) {
    province = prov;
}

unsigned int Address::getPostalCode() const {
    return postal_code;
}

void Address::setPostalCode(const unsigned int &pcode) {
    postal_code = pcode;
}

const string Address::show() const {
    stringstream ss;
    ss << address << ", " << city << ", " << province << ", " << postal_code << endl;
    return ss.str();
}
