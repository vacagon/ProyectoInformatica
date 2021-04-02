#include "PublicUserData.hpp"

PublicUserData::PublicUserData(string &us_name, int rep) {
    setUsername(us_name);
    reputation = rep;
}

PublicUserData::~PublicUserData() {}

const string& PublicUserData::getUsername() const {
    return username;
}

void PublicUserData::setUsername(string &us) {
    username = us;
}

int PublicUserData::getReputation() const {
    return reputation;
}

void PublicUserData::increaseReputation() {
    reputation++;
}

void PublicUserData::decreaseReputation() {
    if (reputation < 0)
        reputation--;
}