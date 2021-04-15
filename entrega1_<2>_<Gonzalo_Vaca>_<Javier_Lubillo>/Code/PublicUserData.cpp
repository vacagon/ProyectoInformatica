#include "PublicUserData.hpp"

PublicUserData::PublicUserData(const string &usename, int rep) {
    setUsername(usename);
    reputation = rep;
}

PublicUserData::~PublicUserData() {}

const string& PublicUserData::getUsername() const {
    return username;
}

void PublicUserData::setUsername(const string &us) {
    username = us;
}

int PublicUserData::getReputation() const {
    return reputation;
}

void PublicUserData::increaseReputation() {
    reputation++;
}

void PublicUserData::decreaseReputation() {
    if (reputation > 0)
        reputation--;
}
