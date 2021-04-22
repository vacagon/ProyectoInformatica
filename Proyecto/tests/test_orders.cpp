#include <gtest/gtest.h>
#include "../Manager.hpp"

class TestOrders : public ::testing::Test {
protected:
    // You can remove any or all of the following functions if their bodies would
    // be empty.

    TestOrders() {
        // You can do set-up work for each test here.
        member = nullptr;
        email1 = "email@domain.com";
        password1 = "1234";
        name1 = "illuminator42";

        member2 = nullptr;
        email2 = "otheremail@domain.com";
        password2 = "member2pass";
        name2 = "totalNoob";

        member3 = nullptr;
        email3 = "fakeemail@domain.com";
        password3 = "member3pass";
        name3 = "theThird";

        member4 = nullptr;
        email4 = "eemaill@domain.com";
        password4 = "member4pass";
        name4 = "Romualdo";

        employee_code = 100235689;
        address_line = "Fake Street, 123";
        city = "Fake City";
        province = "Madrid";
        postal_code = 25630;
        number1 = 1111222255556666;
        number2 = 2222333366665555;
        owner1 = "Homer Simpson";
        owner2 = "Marge Simpson";
        emailp = "homer@aol.com";
        credit_card1 = nullptr;
        credit_card2 = nullptr;
        paypal = nullptr;

        pname1 = "Monitor";
        pname2 = "SSD";
        description1 = "AOC 32 UHD";
        description2 = "1TB nvme";
        reference1 = 100;
        reference2 = 201;
        price1 = 120.99;
        price2 = 110.99;
        total_price = price1 + price2;
        product1 = nullptr;
        product2 = nullptr;

        rating = 5;
        text = "It's a very nice product.";
    }

    ~TestOrders() override {
        // You can do clean-up work that doesn't throw exceptions here.
    }

    bool areSame(float a, float b) {
        const float epsilon = 1e-3;
        return std::abs(a - b) < epsilon;
    }

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    void SetUp() override {
        // Code here will be called immediately after the constructor (right
        // before each test).
        member = new User(name1, email1, password1);
        member2 = new User(name2, email2, password2);
        member3 = new User(name3, email3, password3);
        member4 = new User(name4, email4, password4);

        product1 = new Product(pname1, description1, reference1, price1);
        product2 = new Product(pname2, description2, reference2, price2);
    }

    void TearDown() override {
        // Code here will be called immediately after each test (right
        // before the destructor).
        delete member;
        member = nullptr;

        delete member2;
        member2 = nullptr;

        delete member3;
        member3 = nullptr;

        delete member4;
        member4 = nullptr;

        delete product1;
        delete product2;
    }

    // Class members declared here can be used by all tests in the test suite
    // for Foo.
    std::string email1, email2, email3, email4;
    std::string password1, password2, password3, password4;
    std::string name1, name2, name3, name4;
    User* member, *member2, *member3, *member4;

    unsigned long employee_code;
    std::string address_line, city, province;
    unsigned int postal_code;
    unsigned long number1, number2;
    std::string owner1, owner2;
    std::string emailp;

    Address* address;
    CreditCard* credit_card1, *credit_card2;
    Paypal* paypal;

    std::string pname1, pname2;
    std::string description1, description2;
    unsigned long reference1, reference2;
    float price1, price2, total_price;
    Product *product1, *product2;

    int rating;
    std::string text;
};


TEST_F(TestOrders, ManagerCanAddProducts)
{
    Manager manager;
    ASSERT_TRUE(manager.addUser(name1, email1, password1));
    ASSERT_TRUE(manager.addAdministrator(name3, email3, password3, employee_code));

    // can not add products if no logged in
    ASSERT_FALSE(manager.addProduct(pname1, description1, reference1, price1));
    EXPECT_EQ(0, manager.getProducts().size());

    // user must be admin
    ASSERT_TRUE(manager.login(email1, password1));
    ASSERT_FALSE(manager.addProduct(pname1, description1, reference1, price1));
    EXPECT_EQ(0, manager.getProducts().size());
    ASSERT_TRUE(manager.logout());
    ASSERT_TRUE(manager.login(email3, password3));
    ASSERT_TRUE(manager.addProduct(pname1, description1, reference1, price1));
    EXPECT_EQ(1, manager.getProducts().size());
    EXPECT_EQ(pname1, manager.getProducts()[0]->getName());
    EXPECT_EQ(description1, manager.getProducts()[0]->getDescription());
    EXPECT_EQ(reference1, manager.getProducts()[0]->getReference());
    EXPECT_EQ(price1, manager.getProducts()[0]->getPrice());

    // reference must be unique
    ASSERT_FALSE(manager.addProduct(pname2, description2, reference1, price2));
    ASSERT_TRUE(manager.addProduct(pname2, description2, reference2, price2));
    EXPECT_EQ(2, manager.getProducts().size());
    ASSERT_TRUE(manager.logout());
}


TEST_F(TestOrders, ManagerCanSHowMembers)
{
    Manager manager;
    ASSERT_TRUE(manager.addUser(name1, email1, password1));
    ASSERT_TRUE(manager.addAdministrator(name3, email3, password3, employee_code));

    // can not add products if no logged in
    std::vector<PublicUserData*> user_data = manager.showMembers();
    EXPECT_EQ(0, user_data.size());

    // user must be admin
    ASSERT_TRUE(manager.login(email1, password1));
    user_data = manager.showMembers();
    EXPECT_EQ(0, user_data.size());
    ASSERT_TRUE(manager.logout());
    ASSERT_TRUE(manager.login(email3, password3));
    user_data = manager.showMembers();
    EXPECT_EQ(2, user_data.size());
    EXPECT_EQ(name1, manager.getUsers()[0]->getUsername());
    EXPECT_EQ(0, manager.getUsers()[0]->getReputation());
    ASSERT_TRUE(manager.logout());
}


TEST_F(TestOrders, ManagerCanCreateNewOrder)
{
    Manager manager;
    ASSERT_TRUE(manager.addUser(name1, email1, password1));
    ASSERT_TRUE(manager.addUser(name2, email2, password2));
    ASSERT_TRUE(manager.addAdministrator(name3, email3, password3, employee_code));

    ASSERT_TRUE(manager.login(email3, password3));
    ASSERT_TRUE(manager.addProduct(pname1, description1, reference1, price1));
    ASSERT_TRUE(manager.addProduct(pname2, description2, reference2, price2));
    ASSERT_TRUE(manager.logout());

    std::vector<unsigned long> products;
    products.push_back(product1->getReference());
    products.push_back(product2->getReference());

    // can not make orders if no logged in
    ASSERT_FALSE(manager.makeOrder(products, 0, 0));

    // no orders if no address or payment method
    ASSERT_TRUE(manager.login(email1, password1));
    ASSERT_FALSE(manager.makeOrder(products, 0, 0));    // no address, no payment
    ASSERT_TRUE(manager.addAddress(address_line, city, province, postal_code));
    ASSERT_FALSE(manager.makeOrder(products, 0, 0));    // no payment
    ASSERT_TRUE(manager.addCreditCard(manager.getCurrentMember()->getAddresses()[0], number1, owner1));
    ASSERT_TRUE(manager.makeOrder(products, 0, 0));
    Order* order = manager.getCurrentMember()->getOrders()[0];
    EXPECT_EQ(2, order->getProducts().size());
    EXPECT_EQ(reference1, order->getProducts()[0]);
    EXPECT_EQ(reference2, order->getProducts()[1]);
    EXPECT_EQ(0, order->getDeliveryAddress());
    EXPECT_EQ(0, order->getPaymentMethod());
    ASSERT_TRUE(areSame(total_price, order->getTotal()));
    ASSERT_TRUE(manager.logout());

    // administrator's discount
    ASSERT_TRUE(manager.login(email3, password3));
    ASSERT_TRUE(manager.addAddress(address_line, city, province, postal_code));
    ASSERT_TRUE(manager.addCreditCard(manager.getCurrentMember()->getAddresses()[0], number1, owner1));
    ASSERT_TRUE(manager.makeOrder(products, 0, 0));
    Order* order2 = manager.getCurrentMember()->getOrders()[0];
    EXPECT_EQ(2, order2->getProducts().size());
    EXPECT_EQ(reference1, order2->getProducts()[0]);
    EXPECT_EQ(reference2, order2->getProducts()[1]);
    EXPECT_EQ(0, order2->getDeliveryAddress());
    EXPECT_EQ(0, order2->getPaymentMethod());
    ASSERT_TRUE(areSame(total_price * 0.925, order2->getTotal()));
    ASSERT_TRUE(manager.logout());

    // two orders, two references
    ASSERT_TRUE(order->getReference() != order2->getReference());
}


TEST_F(TestOrders, ManagerCanCreateReviews)
{
    Manager manager;
    ASSERT_TRUE(manager.addUser(name1, email1, password1));
    ASSERT_TRUE(manager.addUser(name2, email2, password2));
    ASSERT_TRUE(manager.addAdministrator(name3, email3, password3, employee_code));

    ASSERT_TRUE(manager.login(email3, password3));
    ASSERT_TRUE(manager.addProduct(pname1, description1, reference1, price1));
    ASSERT_TRUE(manager.addProduct(pname2, description2, reference2, price2));
    ASSERT_TRUE(manager.logout());

    std::vector<unsigned long> products;
    products.push_back(product1->getReference());
    products.push_back(product2->getReference());

    // can not create reviews if no logged in
    ASSERT_FALSE(manager.createReview(reference1, rating, text));

    // cannot create a review of a product that does not exist
    ASSERT_TRUE(manager.login(email1, password1));
    ASSERT_FALSE(manager.createReview(9999, rating, text));

    // cannot create a review of a product not ordered by the user
    ASSERT_FALSE(manager.createReview(reference1, rating, text));
    EXPECT_EQ(0, manager.getProducts()[0]->getReviews().size());
    EXPECT_EQ(0, manager.getProducts()[1]->getReviews().size());
    ASSERT_FALSE(manager.createReview(reference2, rating, text));
    EXPECT_EQ(0, manager.getProducts()[0]->getReviews().size());
    EXPECT_EQ(0, manager.getProducts()[1]->getReviews().size());
    ASSERT_TRUE(manager.addAddress(address_line, city, province, postal_code));
    ASSERT_TRUE(manager.addCreditCard(manager.getCurrentMember()->getAddresses()[0], number1, owner1));
    ASSERT_TRUE(manager.makeOrder(products, 0, 0));
    ASSERT_TRUE(manager.createReview(reference2, rating, text));
    EXPECT_EQ(0, manager.getProducts()[0]->getReviews().size());
    EXPECT_EQ(1, manager.getProducts()[1]->getReviews().size());

    // check product review
    Review* review = manager.getProducts()[1]->getReviews()[0];
    EXPECT_EQ(rating, review->getRating());
    EXPECT_EQ(text, review->getText());
    EXPECT_EQ(name1, review->getAuthor()->getUsername());

    // two reviews, two ids
    ASSERT_TRUE(manager.createReview(reference1, rating, text));
    EXPECT_EQ(1, manager.getProducts()[0]->getReviews().size());
    EXPECT_EQ(1, manager.getProducts()[1]->getReviews().size());

    Review* review2 = manager.getProducts()[0]->getReviews()[0];
    ASSERT_TRUE(review->getId() != review2->getId());
    ASSERT_TRUE(manager.logout());
}


TEST_F(TestOrders, ManagerCanGetReviewsByRating)
{
    Manager manager;
    ASSERT_TRUE(manager.addUser(name1, email1, password1));
    ASSERT_TRUE(manager.addAdministrator(name3, email3, password3, employee_code));

    ASSERT_TRUE(manager.login(email3, password3));
    ASSERT_TRUE(manager.addProduct(pname1, description1, reference1, price1));
    ASSERT_TRUE(manager.addProduct(pname2, description2, reference2, price2));
    ASSERT_TRUE(manager.logout());

    std::vector<unsigned long> products;
    products.push_back(product1->getReference());
    products.push_back(product2->getReference());

    ASSERT_TRUE(manager.login(email1, password1));
    ASSERT_TRUE(manager.addAddress(address_line, city, province, postal_code));
    ASSERT_TRUE(manager.addCreditCard(manager.getCurrentMember()->getAddresses()[0], number1, owner1));
    ASSERT_TRUE(manager.makeOrder(products, 0, 0));
    ASSERT_TRUE(manager.createReview(reference1, rating, text));
    ASSERT_TRUE(manager.createReview(reference1, 2, "text"));
    ASSERT_TRUE(manager.logout());

    // cannot get reviews of a product that does not exist
    std::vector<Review*> rvs = manager.getReviewsByRating(0, 5);
    EXPECT_EQ(0, rvs.size());

    rvs = manager.getReviewsByRating(reference1, 5);
    EXPECT_EQ(1, rvs.size());
    rvs = manager.getReviewsByRating(reference1, 4);
    EXPECT_EQ(0, rvs.size());
    rvs = manager.getReviewsByRating(reference1, 3);
    EXPECT_EQ(0, rvs.size());
    rvs = manager.getReviewsByRating(reference1, 2);
    EXPECT_EQ(1, rvs.size());
    rvs = manager.getReviewsByRating(reference1, 1);
    EXPECT_EQ(0, rvs.size());
}


TEST_F(TestOrders, ManagerCanUpvoteorDownvoteReviews)
{
    Manager manager;
    ASSERT_TRUE(manager.addUser(name1, email1, password1));
    ASSERT_TRUE(manager.addUser(name2, email2, password2));
    ASSERT_TRUE(manager.addAdministrator(name3, email3, password3, employee_code));
    ASSERT_TRUE(manager.addUser(name4, email4, password4));

    ASSERT_TRUE(manager.login(email3, password3));
    ASSERT_TRUE(manager.addProduct(pname1, description1, reference1, price1));
    ASSERT_TRUE(manager.addProduct(pname2, description2, reference2, price2));
    ASSERT_TRUE(manager.logout());

    std::vector<unsigned long> products;
    products.push_back(product1->getReference());
    products.push_back(product2->getReference());

    ASSERT_TRUE(manager.login(email1, password1));
    ASSERT_TRUE(manager.addAddress(address_line, city, province, postal_code));
    ASSERT_TRUE(manager.addCreditCard(manager.getCurrentMember()->getAddresses()[0], number1, owner1));
    ASSERT_TRUE(manager.makeOrder(products, 0, 0));
    ASSERT_TRUE(manager.createReview(reference1, rating, text));
    ASSERT_EQ(0, manager.getCurrentMember()->getReputation());
    ASSERT_TRUE(manager.logout());

    unsigned long id = manager.getProducts()[0]->getReviews()[0]->getId();
    Review* review = manager.getProducts()[0]->getReviews()[0];
    ASSERT_EQ(0, review->getVotes());

    // can not vote if not logged in
    ASSERT_FALSE(manager.upvoteReview(id));
    ASSERT_FALSE(manager.downvoteReview(id));

    ASSERT_TRUE(manager.login(email2, password2));

    // can not vote if review id is not valid
    ASSERT_FALSE(manager.upvoteReview(id+1));
    ASSERT_FALSE(manager.downvoteReview(id+1));
    ASSERT_EQ(0, manager.getCurrentMember()->getReputation());
    ASSERT_TRUE(manager.upvoteReview(id));
    ASSERT_EQ(0, manager.getCurrentMember()->getReputation());
    ASSERT_EQ(1, review->getVotes());
    // can not vote twice
    ASSERT_FALSE(manager.upvoteReview(id));
    ASSERT_FALSE(manager.downvoteReview(id));
    ASSERT_TRUE(manager.logout());

    // owner can not vote his own review
    ASSERT_TRUE(manager.login(email1, password1));
    ASSERT_FALSE(manager.upvoteReview(id));
    ASSERT_FALSE(manager.downvoteReview(id));
    // review owner reputation must increase
    ASSERT_EQ(1, manager.getCurrentMember()->getReputation());
    ASSERT_TRUE(manager.logout());

    ASSERT_TRUE(manager.login(email3, password3));
    ASSERT_TRUE(manager.downvoteReview(id));
    ASSERT_EQ(0, review->getVotes());
    ASSERT_TRUE(manager.logout());

    ASSERT_TRUE(manager.login(email1, password1));
    // review owner reputation must decrease
    ASSERT_EQ(0, manager.getCurrentMember()->getReputation());
    ASSERT_TRUE(manager.logout());

    // review votes can be negative, but user reputation can not
    ASSERT_TRUE(manager.login(email4, password4));
    ASSERT_TRUE(manager.downvoteReview(id));
    ASSERT_EQ(-1, review->getVotes());
    ASSERT_TRUE(manager.logout());
    ASSERT_TRUE(manager.login(email1, password1));
    ASSERT_EQ(0, manager.getCurrentMember()->getReputation());  // never -1
    ASSERT_TRUE(manager.logout());
}


TEST_F(TestOrders, ManagerCanModifyReviews)
{
    Manager manager;
    ASSERT_TRUE(manager.addUser(name1, email1, password1));
    ASSERT_TRUE(manager.addUser(name2, email2, password2));
    ASSERT_TRUE(manager.addAdministrator(name3, email3, password3, employee_code));
    ASSERT_TRUE(manager.addUser(name4, email4, password4));

    ASSERT_TRUE(manager.login(email3, password3));
    ASSERT_TRUE(manager.addProduct(pname1, description1, reference1, price1));
    ASSERT_TRUE(manager.addProduct(pname2, description2, reference2, price2));
    ASSERT_TRUE(manager.logout());

    std::vector<unsigned long> products;
    products.push_back(product1->getReference());
    products.push_back(product2->getReference());

    ASSERT_TRUE(manager.login(email1, password1));
    ASSERT_TRUE(manager.addAddress(address_line, city, province, postal_code));
    ASSERT_TRUE(manager.addCreditCard(manager.getCurrentMember()->getAddresses()[0], number1, owner1));
    ASSERT_TRUE(manager.makeOrder(products, 0, 0));
    ASSERT_TRUE(manager.createReview(reference1, rating, text));
    ASSERT_EQ(0, manager.getCurrentMember()->getReputation());
    ASSERT_TRUE(manager.logout());

    unsigned long id = manager.getProducts()[0]->getReviews()[0]->getId();
    Review* review = manager.getProducts()[0]->getReviews()[0];

    // can not modify review if no logged in
    ASSERT_FALSE(manager.modifyReviewRating(id, 5));
    ASSERT_FALSE(manager.modifyReviewText(id, ""));

    ASSERT_TRUE(manager.login(email1, password1));
    // review id must be valid
    ASSERT_FALSE(manager.modifyReviewRating(id+1, 5));
    ASSERT_FALSE(manager.modifyReviewText(id+1, ""));

    ASSERT_TRUE(manager.modifyReviewRating(id, 0));
    ASSERT_TRUE(manager.modifyReviewText(id, "useless"));
    ASSERT_EQ(0, review->getRating());
    ASSERT_EQ("useless", review->getText());
    ASSERT_TRUE(manager.logout());

    // other than owner can not modify review
    ASSERT_TRUE(manager.login(email2, password2));
    ASSERT_FALSE(manager.modifyReviewRating(id, 0));
    ASSERT_FALSE(manager.modifyReviewText(id, "useless"));
    ASSERT_EQ(0, review->getRating());
    ASSERT_EQ("useless", review->getText());
    ASSERT_TRUE(manager.logout());
}


TEST_F(TestOrders, ManagerCanDeleteReviews)
{
    Manager manager;
    ASSERT_TRUE(manager.addUser(name1, email1, password1));
    ASSERT_TRUE(manager.addUser(name2, email2, password2));
    ASSERT_TRUE(manager.addAdministrator(name3, email3, password3, employee_code));

    ASSERT_TRUE(manager.login(email3, password3));
    ASSERT_TRUE(manager.addProduct(pname1, description1, reference1, price1));
    ASSERT_TRUE(manager.addProduct(pname2, description2, reference2, price2));
    ASSERT_TRUE(manager.logout());

    std::vector<unsigned long> products;
    products.push_back(product1->getReference());
    products.push_back(product2->getReference());

    ASSERT_TRUE(manager.login(email1, password1));
    ASSERT_TRUE(manager.addAddress(address_line, city, province, postal_code));
    ASSERT_TRUE(manager.addCreditCard(manager.getCurrentMember()->getAddresses()[0], number1, owner1));
    ASSERT_TRUE(manager.makeOrder(products, 0, 0));
    ASSERT_TRUE(manager.createReview(reference1, rating, text));
    ASSERT_EQ(0, manager.getCurrentMember()->getReputation());
    ASSERT_TRUE(manager.logout());

    unsigned long id = manager.getProducts()[0]->getReviews()[0]->getId();

    // can not delete review if not logged in
    ASSERT_FALSE(manager.deleteReview(id));

    // other users than owner can not delete reviews
    ASSERT_TRUE(manager.login(email2, password2));
    ASSERT_FALSE(manager.deleteReview(id));
    EXPECT_EQ(1, manager.getProducts()[0]->getReviews().size());
    ASSERT_TRUE(manager.logout());

    // id must be valid
    ASSERT_TRUE(manager.login(email1, password1));
    ASSERT_FALSE(manager.deleteReview(id+1));
    EXPECT_EQ(1, manager.getProducts()[0]->getReviews().size());
    ASSERT_TRUE(manager.deleteReview(id));
    EXPECT_EQ(0, manager.getProducts()[0]->getReviews().size());

    // administrators can delete any review
    ASSERT_TRUE(manager.createReview(reference1, rating, text));
    EXPECT_EQ(1, manager.getProducts()[0]->getReviews().size());
    ASSERT_TRUE(manager.logout());

    id = manager.getProducts()[0]->getReviews()[0]->getId();

    ASSERT_TRUE(manager.login(email3, password3));
    ASSERT_TRUE(manager.deleteReview(id));
    EXPECT_EQ(0, manager.getProducts()[0]->getReviews().size());
}
