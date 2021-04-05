#include "Review.hpp"

Review::Review(unsigned long i, int r, const string& t, PublicUserData* a) {
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

    //Giving format to date
    struct tm* timeinfo;
    timeinfo = localtime(&date);
    char dat[24];
    strftime(dat, 24, "%c", timeinfo);

    //Turning different data types into strings
    stringstream rat, d, v;
    string rating, date, votes;
    rat << getRating();
    rat >> rating;
    d << getDate();
    d >> date;
    v << getVotes();
    v >> votes;
    string output;
    output = "\t" + rating + " stars on " + dat + " by " + getAuthor()->getUsername() + "\n";
    output += "\t" + text + "\n";
    output += "\t" + votes +" votes"+ "\n";
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

void Review::setText(const string& t) {
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
    if (votes>0) {
        --votes;
    }
}

const PublicUserData* Review::getAuthor() const {
    return author;
}

