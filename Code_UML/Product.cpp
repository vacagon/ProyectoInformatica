#include "Product.h"

// Constructors/Destructors
//  

Product::Product()
{
	initAttributes();
}

Product::~Product()
{
}

//  
// Methods
//  


// Accessor methods
//  


/**
 * Add a Purchaser object to the m_purchaserVector List
 */
void Product::addPurchaser (User * add_object) {
	m_purchaserVector.push_back(add_object);
}

/**
 * Remove a Purchaser object from m_purchaserVector List
 */
void Product::removePurchaser (User * remove_object) {
	int i, size = m_purchaserVector.size();
	for (i = 0; i < size; ++i) {
		User * item = m_purchaserVector.at(i);
		if(item == remove_object) {
			std::vector<User *>::iterator it = m_purchaserVector.begin() + i;
			m_purchaserVector.erase(it);
			return;
		}
	 }
}

/**
 * Get the list of Purchaser objects held by m_purchaserVector
 * @return std::vector<User *> list of Purchaser objects held by m_purchaserVector
 */
std::vector<User *> Product::getPurchaserList() {
	return m_purchaserVector;
}

// Other methods
//  

void Product::initAttributes()
{
}

