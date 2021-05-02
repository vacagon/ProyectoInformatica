#ifndef REVIEW_HPP
#define REVIEW_HPP

#include <string>
#include <sstream>
#include <ctime>
#include <vector>
#include <time.h>
#include "PublicUserData.hpp"

using namespace std;

/**
  * @brief Review left by users corresponding to a product
  */
class Review {

public:

    /**
     * @brief Parametric constructor
     */
    Review(const unsigned long& i, const int& rating, const string& text, const PublicUserData* a);

	virtual ~Review();

    /**
     * @brief \t{rating} starts on {date} by {username}
     * \t{text}
     * {votes} votes
     */
    const string show() const;

    const unsigned long& getId() const;

    /**
     * @brief Get the value of date in which the review
     * was created
     */
    const time_t& getDate() const;

    void setRating(const int &rat);

    const int& getRating() const;

    void setText(const string& t);

    const string& getText() const;

    const int& getVotes() const;

	/**
     * @brief Adds one unit to votes
	 */
    void incrementVotes();

	/**
     * @brief Decrease votes in one unit
	 */
    void decremVotes();

    PublicUserData* getAuthor() ;

private:

    Review();

    /**
     * @ brief Uniquee ID for each review made in the platform
     */
	unsigned long id;

    /**
     * @brief Date in which the review was created
     */
	time_t date;

    /**
     * @brief Rating from 0 to 5 (stars)
     */
	int rating;

    /**
     * @brief Content of the review
     */
	string text;

    /**
     * @brief Represent the votes of other users to the review
     */
	int votes;

    /**
     * @brief Pointer to the public information of the user making the review
     */
    PublicUserData* author;

};

#endif // REVIEW_HPP
