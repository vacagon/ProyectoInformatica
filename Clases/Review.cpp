#include "Review.hpp"

Review::Review(const unsigned long &i, const int &rating, const string& text, PublicUserData *a) {
    id = i;
    //Making sure rating is between 0 and 5
    if (rating < 0) {
        setRating(0);
    } else {
        if (rating > 5) {
            setRating(5);
        } else {
            setRating(rating);
        }
    }
    setText(text);
    author = a;
    votes = 0;
    date = time(0);
    users_vote = vector<PublicUserData*> ();
}

Review::~Review() {}

const string Review::show() const {

    //Giving format to date
    struct tm* timeinfo;
    timeinfo = localtime(&date);
    char dat[24];
    strftime(dat, 24, "%c", timeinfo);

    //Turning different data types into strings
    stringstream ss;
    ss << "\t" << rating << " stars on "
           << dat << " by " << getAuthor()->getUsername() << endl
           << "\t" << text << "\n"
           << "\t" << votes << " votes" << "\n";
    return ss.str();
}

const unsigned long& Review::getId() const {
    return id;
}

const time_t &Review::getDate() const {
    return date;
}

void Review::setRating(const int &rat) {
    rating = rat;
}

const int &Review::getRating() const {
    return rating;
}

void Review::setText(const string& t) {
    text = t;
}

const string& Review::getText() const {
    return text;
}

const int &Review::getVotes() const {
    return votes;
}

void Review::incrementVotes() {
    ++votes;
}

void Review::decremVotes() {
        --votes;
}

 PublicUserData* Review::getAuthor() const {
    return author;
}

 vector<PublicUserData*> Review::getUserVotedReview() const {
     return users_vote;
 }

void Review::setUserVotedReview(PublicUserData* user) {
     users_vote.push_back(user);
 }
