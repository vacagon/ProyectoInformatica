#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>
#include <vector>
#include "User.hpp"
#include "Review.hpp"

using namespace std;

/**
  * @brief Electronic component selled in the platform.
  */
class Product {

public:

    /**
     * @brief Parametric constructor
     * @param n: Name
     * @param d: Description
     * @param ref: Reference
     * @param p: Price
     */
    Product(const string& n, const string& d, unsigned long ref, float p);

    ~Product();

    void setName(const string& n);

    const string& getName() const;

    void setDescription(const string& d);

    const string& getDescription() const;

    void setReference(const unsigned long& ref);

    const unsigned long& getReference() const;

    void setPrice(float p);

    const float& getPrice() const;

    vector<Review*> getReviews() const;

    void addReview(Review* r);

    /**
     * @brief {reference} - {name}
     * {description}
     * {price}
     * In case it has reviews:
     * \t-- User reviews --
     * \t{review}
     * \t----
     * \t{review}
     * \t----
     */
    friend ostream& operator<<(ostream& os, const Product& p);

private:

    Product();

    /**
     * @brief Name or short description
     * of the product
     */
    string name;

    /**
     * @brief Long description of the product
     */
    string description;

    /**
     * @brief Uniquee reference of a product
     */
    unsigned long reference;

    float price;

    /**
     * @brief Stores all the reviews
     * made by users to a product
     */
    vector<Review*> reviews;

};

#endif // PRODUCT_H
