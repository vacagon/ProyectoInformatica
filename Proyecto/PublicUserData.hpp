#ifndef PUBLICUSERDATA_HPP
#define PUBLICUSERDATA_HPP

#include <string>

using namespace std;

/**
  * @brief Store public data of a user
  */
class PublicUserData
{

public:

    /**
     * @brief Parametric constructor
     * @param us_name: Username
     * @param rep: Reputation, initialice to 0
     */
    PublicUserData(const string& us_name, int rep = 0);

	/**
     * @brief Empty Destructor
	 */
	virtual ~PublicUserData();

    /**
     * @brief Get the value of username
     */
    const string& getUsername() const;

    /**
     * @brief Sets the username
     */
    void setUsername(const string& us);

	/**
     * @brief Gets user's reputation
	 */
    int getReputation() const;

    /**
     * @brief Increase the value of
     * reputation in one unit
     */
    void increaseReputation();

    /**
     * @brief Decrease user's reputation in one
     * unit whenever it is bigger than 0
     */
    void decreaseReputation();

protected:

    /**
     * @brief Empty Constructor
     */
    PublicUserData();

    /**
     * @brief User's username
     */
	string username;

    /**
     * @brief Reputation according to other users
     *score on his reviws
     */
    int reputation;

};

#endif // PUBLICUSERDATA_H
