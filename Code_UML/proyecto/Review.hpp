
#ifndef REVIEW_H
#define REVIEW_H

#include string


/**
  * class Review
  * Review left by users corresponding to a product
  */

class Review
{
public:
	// Constructors/Destructors
	//  


	/**
	 * Empty Constructor
	 */
	Review();

	/**
	 * Empty Destructor
	 */
	virtual ~Review();

	// Static Public attributes
	//  

	// Public attributes
	//  


	// Public attribute accessor methods
	//  


	// Public attribute accessor methods
	//  



	/**
	 * @return unsigned long
	 */
	unsigned long getId() const
	{
	}


	/**
	 * @return time_t
	 */
	time_t getDate() const
	{
	}


	/**
	 */
	void setRating()
	{
	}


	/**
	 * @return int
	 */
	int getRating() const
	{
	}


	/**
	 */
	void setText()
	{
	}


	/**
	 * @return string&
	 */
	string& getText() const
	{
	}


	/**
	 * @return int
	 */
	int getVotes() const
	{
	}


	/**
	 * Adds one unit to votes
	 */
	void incrementVotes()
	{
	}


	/**
	 * Decrease votes in one unit
	 */
	void decremVotes()
	{
	}


	/**
	 * @return PublicUserData
	 */
	PublicUserData getPublicUserData() const
	{
	}


	/**
	 * \t{rating} starts on {date} by {username}
	 * \t{text}
	 * \t{votes} votes
	 * @return string&
	 */
	string& show()
	{
	}

protected:
	// Static Protected attributes
	//  

	// Protected attributes
	//  


	// Protected attribute accessor methods
	//  


	// Protected attribute accessor methods
	//

private:
	// Static Private attributes
	//  

	// Private attributes
	//  

	// Uniquee ID for each review made in the platform
	unsigned long id;
	// Date in which the review was created
	time_t date;
	// Rating from 0 to 5 (stars)
	int rating;
	// Content of the review
	string text;
	// Represent the votes of other users to the review
	int votes;
	// Pointer to the public information of the user making the review
	PublicUserData author;

	// Private attribute accessor methods
	//  


	// Private attribute accessor methods
	//  


	/**
	 * Set the value of id
	 * Uniquee ID for each review made in the platform
	 * @param value the new value of id
	 */
	void setId(unsigned long value)
	{
		id = value;
	}

	/**
	 * Get the value of id
	 * Uniquee ID for each review made in the platform
	 * @return the value of id
	 */
	unsigned long getId()
	{
		return id;
	}

	/**
	 * Set the value of date
	 * Date in which the review was created
	 * @param value the new value of date
	 */
	void setDate(time_t value)
	{
		date = value;
	}

	/**
	 * Get the value of date
	 * Date in which the review was created
	 * @return the value of date
	 */
	time_t getDate()
	{
		return date;
	}

	/**
	 * Set the value of rating
	 * Rating from 0 to 5 (stars)
	 * @param value the new value of rating
	 */
	void setRating(int value)
	{
		rating = value;
	}

	/**
	 * Get the value of rating
	 * Rating from 0 to 5 (stars)
	 * @return the value of rating
	 */
	int getRating()
	{
		return rating;
	}

	/**
	 * Set the value of text
	 * Content of the review
	 * @param value the new value of text
	 */
	void setText(string value)
	{
		text = value;
	}

	/**
	 * Get the value of text
	 * Content of the review
	 * @return the value of text
	 */
	string getText()
	{
		return text;
	}

	/**
	 * Set the value of votes
	 * Represent the votes of other users to the review
	 * @param value the new value of votes
	 */
	void setVotes(int value)
	{
		votes = value;
	}

	/**
	 * Get the value of votes
	 * Represent the votes of other users to the review
	 * @return the value of votes
	 */
	int getVotes()
	{
		return votes;
	}

	/**
	 * Set the value of author
	 * Pointer to the public information of the user making the review
	 * @param value the new value of author
	 */
	void setAuthor(PublicUserData value)
	{
		author = value;
	}

	/**
	 * Get the value of author
	 * Pointer to the public information of the user making the review
	 * @return the value of author
	 */
	PublicUserData getAuthor()
	{
		return author;
	}

	void initAttributes();

};

#endif // REVIEW_H
