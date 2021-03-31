#include "User.h"

// Constructors/Destructors
//  

User::User()
{
	initAttributes();
}

User::~User()
{
}

//  
// Methods
//  


// Accessor methods
//  


/**
 * Add a Purchased object to the m_purchasedVector List
 */
void User::addPurchased (Product * add_object) {
	m_purchasedVector.push_back(add_object);
}

/**
 * Remove a Purchased object from m_purchasedVector List
 */
void User::removePurchased (Product * remove_object) {
	int i, size = m_purchasedVector.size();
	for (i = 0; i < size; ++i) {
		Product * item = m_purchasedVector.at(i);
		if(item == remove_object) {
			std::vector<Product *>::iterator it = m_purchasedVector.begin() + i;
			m_purchasedVector.erase(it);
			return;
		}
	 }
}

/**
 * Get the list of Purchased objects held by m_purchasedVector
 * @return std::vector<Product *> list of Purchased objects held by
 * m_purchasedVector
 */
std::vector<Product *> User::getPurchasedList() {
	return m_purchasedVector;
}

// Other methods
//  

void User::initAttributes()
{
}

