#include "Address.hpp"

Address::Address(int i, string& ad, string& cit, string& prov, unsigned int pcode) {
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

void Address::setAddress(string &ad) {
    address = ad;
}

const string& Address::getCity() const {
    return city;
}

void Address::setCity(string &cit){
    city = cit;
}

const string& Address::getProvince() const {
    return province;
}

void Address::setProvince(string &prov) {
    province = prov;
}

unsigned int Address::getPostalCode() const {
    return postal_code;
}

void Address::setPostalCode(unsigned int pcode) {
    postal_code = pcode;
}

const string Address::show() const {
    string output, postalcode;
    stringstream ss;
    ss << postal_code;
    ss >> postalcode;
    output = address + ", ";
    output += city + ", ";
    output += province + ", ";
    output += postalcode + "\n";
    return output;
}
