#include "Address.hpp"

Address::Address(int i, const string &ad, const string &cit, const string &prov, unsigned int pcode) {
    setId(i);
    setAddress(ad);
    setCity(cit);
    setProvince(prov);
    setPostalCode(pcode);
}

Address::~Address() {}

int Address::getId() const {
    return id;
}

void Address::setId(int i) {
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

void Address::setPostalCode(unsigned int pcode) {
    postal_code = pcode;
}

const string Address::show() const {
    stringstream ss;
    ss << address << ", " << city << ", " << province << ", " << postal_code << endl;
    return ss.str();
}
