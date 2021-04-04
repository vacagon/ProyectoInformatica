#include "Review.hpp"

Review::Review(unsigned long i, int r, string& t, PublicUserData* a) {
    id = i;
    //Making sure rating is between 0 and 5
    if (r < 0) {
        setRating(0);
    } else {
        if (r > 5) {
            setRating(5);
        } else {
            setRating(r);
        }
    }
    setText(t);
    author = a;
    votes = 0;
    date = time(0);
}

Review::~Review() {}

const string Review::show() const {
    string output = nullptr;
    return output;
}

unsigned long Review::getId() const {
    return id;
}

time_t Review::getDate() const {
    return date;
}

void Review::setRating(int rat) {
    rating = rat;
}

int Review::getRating() const {
    return rating;
}

void Review::setText(string& t) {
    text = t;
}

const string& Review::getText() const {
    return text;
}

int Review::getVotes() const {
    return votes;
}

void Review::incrementVotes() {
    ++votes;
}

void Review::decremVotes() {
    --votes;
}

const PublicUserData& Review::getAuthor() const {
    return *author;
}

