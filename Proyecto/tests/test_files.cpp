#include <gtest/gtest.h>
#include <time.h>
#include "../Manager.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <sstream>

class TestFiles : public ::testing::Test {
protected:
    // You can remove any or all of the following functions if their bodies would
    // be empty.

    TestFiles() {
        // You can do set-up work for each test here.
        email1 = "email@domain.com";
        password1 = "1234";
        name1 = "illuminator42";

        email2 = "otheremail@domain.com";
        password2 = "member2pass";
        name2 = "totalNoob";

        email3 = "fakeemail@domain.com";
        password3 = "member3pass";
        name3 = "theThird";

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

    ~TestFiles() override {
        // You can do clean-up work that doesn't throw exceptions here.
    }

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    void SetUp() override {
        // Code here will be called immediately after the constructor (right
        // before each test)
        product1 = new Product(pname1, description1, reference1, price1);
        product2 = new Product(pname2, description2, reference2, price2);
    }

    void TearDown() override {
        // Code here will be called immediately after each test (right
        // before the destructor).
        if (product1) delete product1;
        if (product2) delete product2;
    }

    // Class members declared here can be used by all tests in the test suite
    // for Foo.
    std::string email1, email2, email3, email4;
    std::string password1, password2, password3, password4;
    std::string name1, name2, name3, name4;

    unsigned long employee_code;
    std::string address_line, city, province;
    unsigned int postal_code;
    unsigned long number1, number2;
    std::string owner1, owner2;
    std::string emailp;

    std::string pname1, pname2;
    std::string description1, description2;
    unsigned long reference1, reference2;
    float price1, price2, total_price;
    Product *product1, *product2;

    int rating;
    std::string text;

    static Manager* dumped_manager;

public:
    static std::stringstream errors;

    static bool areSame(float a, float b) {
        const float epsilon = 0.1;
        return std::abs(a - b) < epsilon;
    }
};

// static variable implementation
Manager* TestFiles::dumped_manager = nullptr;
std::stringstream TestFiles::errors;

void logError(const std::string& error) {
    std::cerr << error << std::endl;
    TestFiles::errors << error << std::endl;
}

// ============================================================================ //
// CHECKS
// ============================================================================ //

bool checkAddresses(User* manual, User* read) {
    // first check same number of addresses
    if (manual->getAddresses().size() != read->getAddresses().size()) {
        logError("Incorrect number of addresses read from file");
        return false;
    }

    for (Address* m_address : manual->getAddresses()) {
        bool found = false;

        // address must be in read
        for (Address* r_address : read->getAddresses()) {
            if (m_address->getId() == r_address->getId() &&
                m_address->getAddress() == r_address->getAddress() &&
                m_address->getCity() == r_address->getCity() &&
                m_address->getProvince() == r_address->getProvince() &&
                m_address->getPostalCode() == r_address->getPostalCode())
            {
                found = true;
                break;
            }
        }

        if (!found) {
            std::stringstream ss;
            ss << "Address " << m_address->getAddress() << " from user " << manual->getUsername() << " not correctly read from file";
            logError(ss.str());
            return false;
        }
    }

    return true;
}

bool checkAddress(Address* ad1, Address* ad2) {
    if (ad1->getId() == ad2->getId() &&
        ad1->getAddress() == ad2->getAddress() &&
        ad1->getCity() == ad2->getCity() &&
        ad1->getProvince() == ad2->getProvince() &&
        ad1->getPostalCode() == ad2->getPostalCode())
    {
        return true;
    }
    else {
        return false;
    }
}

bool checkPaymentMethods(User* manual, User* read) {
    // first check same number of payment methods
    if (manual->getPaymentMethods().size() != read->getPaymentMethods().size()) {
        logError("Incorrect number of payment methods read from file");
        return false;
    }

    for (PaymentMethod* m_pm : manual->getPaymentMethods()) {
        bool found = false;

        // address must be in read
        for (PaymentMethod* r_pm : read->getPaymentMethods()) {
            CreditCard* m_cc = dynamic_cast<CreditCard*>(m_pm);
            Paypal* m_p = dynamic_cast<Paypal*>(m_pm);

            // CreditCard
            if (m_cc) {
                CreditCard* r_cc = dynamic_cast<CreditCard*>(r_pm);
                if (!r_cc) {
                    logError("Payment Methods types do not match");
                    return false;
                }

                // check creditcard
                if (m_cc->getId() == r_cc->getId() &&
                    checkAddress(m_cc->getBillingAddress(), r_cc->getBillingAddress()) &&
                    m_cc->getNumber() == r_cc->getNumber() &&
                    m_cc->getCardholder() == r_cc->getCardholder())
                {
                    found = true;
                    break;
                }
            }
            // Paypal
            else if (m_p) {
                Paypal* r_p = dynamic_cast<Paypal*>(r_pm);
                if (!r_p) {
                    logError("Payment Methods types do not match");
                    return false;
                }

                // check Paypal account
                if (m_p->getId() == r_p->getId() &&
                    checkAddress(m_p->getBillingAddress(), r_p->getBillingAddress()) &&
                    m_p->getEmail() == r_p->getEmail())
                {
                    found = true;
                    break;
                }
            }
            // Not possible, program is ill-formed
            else {
                logError("Fatal error, the payment method is neither a credit card nor a paypal account.");
                return false;
            }
        }

        if (!found) {
            std::stringstream ss;
            ss << "Payment Method " << m_pm->getId() << " from user " << manual->getUsername() << " not correctly read";
            logError(ss.str());
            return false;
        }
    }

    return true;
}

bool checkOrderProducts(Order* m_order, Order* r_order) {
    auto r_products = r_order->getProducts();
    for (unsigned long m_reference : m_order->getProducts()) {
        if (std::find(r_products.begin(), r_products.end(), m_reference) == r_products.end() ) {
            // Product reference not found in Order
            std::stringstream ss;
            ss << "Product reference " << m_reference << " from Order " << m_order->getReference() << " not read from file";
            logError(ss.str());
            return false;
        }
    }

    return true;
}

bool checkOrders(User* manual, User* read) {
    // first check same number of orders
    if (manual->getOrders().size() != read->getOrders().size()) {
        logError("Incorrect number of orders read from file");
        return false;
    }

    for (Order* m_order : manual->getOrders()) {
        bool found = false;

        for (Order* r_order : read->getOrders()) {
            if (m_order->getReference() == r_order->getReference() &&
                checkOrderProducts(m_order, r_order) &&
                m_order->getDate() == r_order->getDate() &&
                m_order->getDeliveryAddress() == r_order->getDeliveryAddress() &&
                m_order->getPaymentMethod() == r_order->getPaymentMethod() &&
                TestFiles::areSame(m_order->getTotal(), r_order->getTotal()))
            {
                found = true;
                break;
            }
        }

        if (!found) {
            std::stringstream ss;
            ss << "Order " << m_order->getReference() << " from user " << manual->getUsername() << " not correctly read";
            logError(ss.str());
            return false;
        }
    }

    return true;
}

bool checkReviews(Product* manual, Product* read) {
    // first check same number of reviews
    if (manual->getReviews().size() != read->getReviews().size()) {
        std::cerr << "Incorrect number of reviews read from file" << std::endl;
        return false;
    }

    for (Review* m_review : manual->getReviews()) {
        bool found = false;

        for (Review* r_review : read->getReviews()) {
            if (m_review->getId() == r_review->getId() &&
                m_review->getDate() == r_review->getDate() &&
                m_review->getRating() == r_review->getRating() &&
                m_review->getText() == r_review->getText() &&
                m_review->getVotes() == r_review->getVotes() &&
                m_review->getAuthor()->getUsername() == r_review->getAuthor()->getUsername())
            {
                found = true;
                break;
            }
        }

        if (!found) {
            std::cerr << "Review " << m_review->getId() << " from product " << manual->getName() << " not correctly read from file" << std::endl;
            return false;
        }
    }

    return true;
}

// ========================================================================================= //
// TESTS ASSERTION FUNCTIONS
// ========================================================================================= //

testing::AssertionResult IsUserLoadedFromFile(User* manual, const Manager& read_manager) {
    bool flag = false;

    for (User* read : read_manager.getUsers()) {
        // check basic information
        bool basicInformationRead =
                manual->getUsername() == read->getUsername() &&
                manual->getEmail() == read->getEmail() &&
                manual->getPassword() == read->getPassword() &&
                manual->getReputation() == read->getReputation();

        if (!basicInformationRead) continue;            // basic user information not found

        // check addresses
        if (!checkAddresses(manual, read)) break;       // addresses information not correctly read

        // check payment methods
        if (!checkPaymentMethods(manual, read)) break;  // payment method information not correctly read

        // check orders
        if (!checkOrders(manual, read)) break;          // orders information not correctly read

        flag = true;
        break;
    }

    if (flag) {
        return testing::AssertionSuccess();
    }
    else {
        return testing::AssertionFailure() << "User " << manual->getUsername() << " not correctly read from file." << std::endl << TestFiles::errors.str();
    }
}

testing::AssertionResult IsProductLoadedFromFile(Product* manual, const Manager& read_manager) {
    bool flag = false;

    for (Product* read : read_manager.getProducts()) {
        // check basic information
        bool basicInformationRead =
                manual->getName() == read->getName() &&
                manual->getDescription() == read->getDescription() &&
                manual->getReference() == read->getReference() &&
                TestFiles::areSame(manual->getPrice(), read->getPrice());

        if (!basicInformationRead) continue;        // basic product information not found

        // check reviews
        if (!checkReviews(manual, read)) break;     // reviews information not corecty read

        flag = true;
        break;
    }

    if (flag) {
        return testing::AssertionSuccess();
    }
    else {
        return testing::AssertionFailure() << "Product " << manual->getName() << " not correctly read from file." << std::endl << TestFiles::errors.str();
    }
}

testing::AssertionResult IsUserInFile(User* user, const std::string& path) {
    std::ifstream ifs(path);
    std::string line;
    bool flag = false;

    while (ifs) {
        std::getline(ifs, line);
        std::string username, email, password, reputation, is_admin;

        if (line == "User:") {
            // read user information
            std::getline(ifs, username);
            std::getline(ifs, email);
            std::getline(ifs, password);
            std::getline(ifs, reputation);
            std::getline(ifs, is_admin);

            // check user information
            if (username == user->getUsername() &&
                email == user->getEmail() &&
                password == user->getPassword() &&
                std::stoi(reputation) == user->getReputation() &&
                ((user->isAdmin() && is_admin != "-1") || (!user->isAdmin() && is_admin == "-1")))
            {
                flag = true;
                break;
            }
        }
    }

    ifs.close();

    if (flag) {
        return testing::AssertionSuccess();
    }
    else {
        return testing::AssertionFailure() << "User " << user->getUsername() << " not found on file.";
    }
}

testing::AssertionResult IsProductInFile(Product* product, const std::string& path) {
    std::ifstream ifs(path);
    std::string line;
    bool flag = false;

    while (ifs) {
        std::getline(ifs, line);
        std::string name, description, reference, price;

        if (line == "Product:") {
            // read product information
            std::getline(ifs, name);
            std::getline(ifs, description);
            std::getline(ifs, reference);
            std::getline(ifs, price);

            // check product information
            if (name == product->getName() &&
                description == product->getDescription() &&
                std::stoul(reference) == product->getReference() &&
                TestFiles::areSame(std::stof(price), product->getPrice()))
            {
                flag = true;
                break;
            }
        }
    }

    ifs.close();

    if (flag) {
        return testing::AssertionSuccess();
    }
    else {
        return testing::AssertionFailure() << "Product " << product->getName() << " not found on file.";
    }
}

// ========================================================================================= //
// TESTS ASSERTION FUNCTIONS
// ========================================================================================= //


TEST_F(TestFiles, ManagerCanSaveState)
{
    // ================================================================ //
    // ORIGINAL DATA
    // ================================================================ //

    if (dumped_manager) delete dumped_manager;
    dumped_manager = new Manager();
    ASSERT_TRUE(dumped_manager->addUser(name1, email1, password1));     // one user
    ASSERT_TRUE(dumped_manager->addUser(name2, email2, password2));     // two users
    ASSERT_TRUE(dumped_manager->addAdministrator(name3, email3, password3, employee_code));     // one administrator

    ASSERT_TRUE(dumped_manager->login(email3, password3));
    ASSERT_TRUE(dumped_manager->addProduct(pname1, description1, reference1, price1));          // one product
    ASSERT_TRUE(dumped_manager->addProduct(pname2, description2, reference2, price2));          // two products
    ASSERT_TRUE(dumped_manager->logout());

    std::vector<unsigned long> products;
    products.push_back(product1->getReference());
    products.push_back(product2->getReference());

    // can not create reviews if no logged in
    ASSERT_FALSE(dumped_manager->createReview(reference1, rating, text));

    // cannot create a review of a product that does not exist
    ASSERT_TRUE(dumped_manager->login(email1, password1));
    ASSERT_FALSE(dumped_manager->createReview(9999, rating, text));

    // cannot create a review of a product not ordered by the user
    ASSERT_FALSE(dumped_manager->createReview(reference1, rating, text));
    EXPECT_EQ(0, dumped_manager->getProducts()[0]->getReviews().size());
    EXPECT_EQ(0, dumped_manager->getProducts()[1]->getReviews().size());
    ASSERT_FALSE(dumped_manager->createReview(reference2, rating, text));
    EXPECT_EQ(0, dumped_manager->getProducts()[0]->getReviews().size());
    EXPECT_EQ(0, dumped_manager->getProducts()[1]->getReviews().size());
    // user needs at least one address and payment method
    ASSERT_TRUE(dumped_manager->addAddress(address_line, city, province, postal_code));
    ASSERT_TRUE(dumped_manager->addCreditCard(dumped_manager->getCurrentMember()->getAddresses()[0], number1, owner1));
    // user makes one order of two products
    ASSERT_TRUE(dumped_manager->makeOrder(products, 0, 0));
    ASSERT_TRUE(dumped_manager->createReview(reference2, rating, text));
    EXPECT_EQ(0, dumped_manager->getProducts()[0]->getReviews().size());
    EXPECT_EQ(1, dumped_manager->getProducts()[1]->getReviews().size());

    // save manager state to disk
    dumped_manager->saveToFile("manager_data.dat");

    // check saved data
    for (User* user : dumped_manager->getUsers())
        ASSERT_TRUE(IsUserInFile(user, "manager_data.dat"));

    for (Product* product : dumped_manager->getProducts())
        ASSERT_TRUE(IsProductInFile(product, "manager_data.dat"));
}


TEST_F(TestFiles, ManagerCanLoadState)
{
    // ================================================================ //
    // DATA READ FROM FILE
    // ================================================================ //

    Manager file_manager;
    file_manager.loadFromFile("manager_data.dat");

    // check users
    for (User* user : dumped_manager->getUsers()) {
        ASSERT_TRUE(IsUserLoadedFromFile(user, file_manager));
    }

    // check products
    for (Product* product : dumped_manager->getProducts()) {
        ASSERT_TRUE(IsProductLoadedFromFile(product, file_manager));
    }

    if (dumped_manager) delete dumped_manager;
}
