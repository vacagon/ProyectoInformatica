#include <gtest/gtest.h>
#include <string>

#include "../Manager.hpp"

// The fixture for testing class Foo.
class TestBasic : public ::testing::Test {
protected:
    // You can remove any or all of the following functions if their bodies would
    // be empty.

    TestBasic() {
        // You can do set-up work for each test here.
        member = nullptr;
        email1 = "email@domain.com";
        password1 = "1234";
        name1 = "illuminator42";
        bio1 = "Guardian of the answer to life and everything elsee";

        member2 = nullptr;
        email2 = "otheremail@domain.com";
        password2 = "member2pass";
        name2 = "totalNoob";
        bio2 = "It's my first day here";

        member3 = nullptr;
        email3 = "fakeemail@domain.com";
        password3 = "member3pass";
        name3 = "theThird";
        bio3 = "I'm here just to test stuff";

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
    }

    ~TestBasic() override {
        // You can do clean-up work that doesn't throw exceptions here.
    }

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    void SetUp() override {
        // Code here will be called immediately after the constructor (right
        // before each test).
        member = new User(name1, email1, password1);
        member2 = new User(name2, email2, password2);
        member3 = new User(name3, email3, password3);
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
    }

    // Class members declared here can be used by all tests in the test suite
    // for Foo.
    std::string email1, email2, email3;
    std::string password1, password2, password3;
    std::string name1, name2, name3;
    std::string bio1, bio2, bio3;
    User* member, *member2, *member3;

    unsigned long employee_code;
    std::string address_line, city, province;
    unsigned int postal_code;
    unsigned long number1, number2;
    std::string owner1, owner2;
    std::string emailp;

    Address* address;
    CreditCard* credit_card1, *credit_card2;
    Paypal* paypal;
};


TEST_F(TestBasic, ManagerCanCreateAndShowMembers)
{
    Manager manager;
    ASSERT_TRUE(manager.addUser(name1, email1, password1));
    std::vector<User*> members = manager.getUsers();
    ASSERT_EQ(1, members.size());
    EXPECT_EQ(name1, members[0]->getUsername());
    EXPECT_EQ(email1, members[0]->getEmail());
    EXPECT_EQ(password1, members[0]->getPassword());

    ASSERT_TRUE(manager.addUser(name2, email2, password2));
    members = manager.getUsers();
    ASSERT_EQ(2, members.size());
    EXPECT_EQ(name2, members[1]->getUsername());
    EXPECT_EQ(email2, members[1]->getEmail());
    EXPECT_EQ(password2, members[1]->getPassword());

    // Administrators
    ASSERT_TRUE(manager.addAdministrator(name3, email3, password3, employee_code));
    members = manager.getUsers();
    ASSERT_EQ(3, members.size());
    EXPECT_EQ(name3, members[2]->getUsername());
    EXPECT_EQ(email3, members[2]->getEmail());
    EXPECT_EQ(password3, members[2]->getPassword());
    Administrator *admin = dynamic_cast<Administrator*>(members[2]);
    ASSERT_TRUE(admin);
    EXPECT_EQ(employee_code, admin->getEmployeeCode());
}


TEST_F(TestBasic, ManagerCannotDuplicateMember)
{
    Manager manager;
    ASSERT_TRUE(manager.addUser(name1, email1, password1));
    std::vector<User*> members = manager.getUsers();
    ASSERT_EQ(1, members.size());
    EXPECT_EQ(name1, members[0]->getUsername());
    EXPECT_EQ(email1, members[0]->getEmail());
    EXPECT_EQ(password1, members[0]->getPassword());

    ASSERT_FALSE(manager.addUser(name1, email1, password1));
    members = manager.getUsers();
    ASSERT_EQ(1, members.size());
}

TEST_F(TestBasic, ManagerCanLoginMember)
{
    Manager manager;
    ASSERT_TRUE(manager.addUser(name1, email1, password1));
    std::vector<User*> members = manager.getUsers();
    ASSERT_EQ(1, members.size());
    EXPECT_EQ(name1, members[0]->getUsername());
    EXPECT_EQ(email1, members[0]->getEmail());
    EXPECT_EQ(password1, members[0]->getPassword());

    EXPECT_TRUE(manager.login(email1, password1));
    EXPECT_TRUE(manager.isLogged());
    User *logged_member = manager.getCurrentMember();
    ASSERT_NE(nullptr, logged_member);
    EXPECT_EQ(email1, logged_member->getEmail());
    EXPECT_EQ(password1, logged_member->getPassword());
    EXPECT_EQ(name1, logged_member->getUsername());
}

TEST_F(TestBasic, ManagerWrongMemberCannotLogin)
{
    Manager manager;
    ASSERT_TRUE(manager.addUser(name1, email1, password1));
    EXPECT_FALSE(manager.login(email1, password2));
    EXPECT_FALSE(manager.isLogged());
    EXPECT_EQ(nullptr, manager.getCurrentMember());
    EXPECT_FALSE(manager.login(email2, password2));
    EXPECT_FALSE(manager.isLogged());
    EXPECT_EQ(nullptr, manager.getCurrentMember());
}

TEST_F(TestBasic, ManagerCannotLoginMemberTwice)
{
    Manager manager;
    ASSERT_TRUE(manager.addUser(name1, email1, password1));
    ASSERT_TRUE(manager.addUser(name2, email2, password2));
    ASSERT_TRUE(manager.login(email1, password1));
    ASSERT_TRUE(manager.isLogged());
    EXPECT_FALSE(manager.login(email1, password1));
    EXPECT_FALSE(manager.login(email2, password2));
}

TEST_F(TestBasic, ManagerCanLogoutMember)
{
    Manager manager;
    ASSERT_TRUE(manager.addUser(name1, email1, password1));
    ASSERT_TRUE(manager.addUser(name2, email2, password2));
    EXPECT_FALSE(manager.logout());     //-- No member logged in yet
    ASSERT_TRUE(manager.login(email1, password1));
    EXPECT_TRUE(manager.logout());
    EXPECT_FALSE(manager.logout());
    EXPECT_EQ(nullptr, manager.getCurrentMember());
}

TEST_F(TestBasic, ManagerCanEraseLoggedMember)
{
    Manager manager;
    ASSERT_FALSE(manager.eraseCurrentMember());     //-- Error if not logged in
    ASSERT_TRUE(manager.addUser(name1, email1, password1));
    ASSERT_TRUE(manager.addUser(name2, email2, password2));
    ASSERT_TRUE(manager.login(email1, password1));
    ASSERT_TRUE(manager.eraseCurrentMember());
    EXPECT_EQ(nullptr, manager.getCurrentMember());
    std::vector<User*> members = manager.getUsers();
    ASSERT_EQ(1, members.size());
    EXPECT_EQ(name2, members[0]->getUsername());
    EXPECT_EQ(email2, members[0]->getEmail());
    EXPECT_EQ(password2, members[0]->getPassword());
}

TEST_F(TestBasic, ManagerLoggedMemberCanEditProfile)
{
    Manager manager;
    ASSERT_TRUE(manager.addUser(name1, email1, password1));
    ASSERT_TRUE(manager.addUser(name2, email2, password2));
    EXPECT_FALSE(manager.editEmail(email3));        //-- Cannot edit profile if not logged in
    EXPECT_FALSE(manager.editPassword(password3));  //-- Cannot edit profile if not logged in
    EXPECT_FALSE(manager.editUsername(name3));      //-- Cannot edit profile if not logged in
    ASSERT_TRUE(manager.login(email1, password1));
    ASSERT_EQ(email1, manager.getCurrentMember()->getEmail());
    ASSERT_EQ(password1, manager.getCurrentMember()->getPassword());
    ASSERT_EQ(name1, manager.getCurrentMember()->getUsername());

    EXPECT_TRUE(manager.editEmail(email3));
    EXPECT_EQ(email3, manager.getCurrentMember()->getEmail());
    EXPECT_EQ(password1, manager.getCurrentMember()->getPassword());
    EXPECT_EQ(name1, manager.getCurrentMember()->getUsername());

    ASSERT_TRUE(manager.editPassword(password3));
    EXPECT_EQ(email3, manager.getCurrentMember()->getEmail());
    EXPECT_EQ(password3, manager.getCurrentMember()->getPassword());
    EXPECT_EQ(name1, manager.getCurrentMember()->getUsername());

    ASSERT_TRUE(manager.editUsername(name3));
    EXPECT_EQ(email3, manager.getCurrentMember()->getEmail());
    EXPECT_EQ(password3, manager.getCurrentMember()->getPassword());
    EXPECT_EQ(name3, manager.getCurrentMember()->getUsername());

    ASSERT_FALSE(manager.editEmail(email2));        //-- cannot duplicate an existing email
    EXPECT_EQ(email3, manager.getCurrentMember()->getEmail());
    ASSERT_FALSE(manager.editUsername(name2));      //-- cannot duplicate an existing username
    EXPECT_EQ(name3, manager.getCurrentMember()->getUsername());
}

TEST_F(TestBasic, ManagerCanCreateAddress)
{
    Manager manager;
    ASSERT_TRUE(manager.addUser(name1, email1, password1));
    ASSERT_TRUE(manager.login(email1, password1));

    ASSERT_TRUE(manager.addAddress(address_line, city, province, postal_code));
    EXPECT_EQ(1, manager.getCurrentMember()->getAddresses().size());
    EXPECT_EQ(0, manager.getCurrentMember()->getAddresses()[0]->getId());
    EXPECT_EQ(address_line, manager.getCurrentMember()->getAddresses()[0]->getAddress());
    EXPECT_EQ(city, manager.getCurrentMember()->getAddresses()[0]->getCity());
    EXPECT_EQ(province, manager.getCurrentMember()->getAddresses()[0]->getProvince());
    EXPECT_EQ(postal_code, manager.getCurrentMember()->getAddresses()[0]->getPostalCode());
}

TEST_F(TestBasic, ManagerCanCreatePaymentMethods)
{
    Manager manager;
    ASSERT_TRUE(manager.addUser(name1, email1, password1));
    ASSERT_TRUE(manager.login(email1, password1));

    User* user = manager.getCurrentMember();
    ASSERT_TRUE(manager.addAddress(address_line, city, province, postal_code));
    ASSERT_TRUE(manager.addCreditCard(user->getAddresses()[0], number1, owner1));
    ASSERT_TRUE(manager.addCreditCard(user->getAddresses()[0], number2, owner2));
    ASSERT_TRUE(manager.addPaypal(user->getAddresses()[0], emailp));

    CreditCard* cc1 = dynamic_cast<CreditCard*>(user->getPaymentMethods()[0]);
    ASSERT_TRUE(cc1);
    EXPECT_EQ(0, cc1->getId());
    EXPECT_EQ(number1, cc1->getNumber());
    EXPECT_EQ(owner1, cc1->getCardholder());
    EXPECT_EQ(address_line, cc1->getBillingAddress()->getAddress());

    CreditCard* cc2 = dynamic_cast<CreditCard*>(user->getPaymentMethods()[1]);
    ASSERT_TRUE(cc2);
    EXPECT_EQ(1, cc2->getId());
    EXPECT_EQ(number2, cc2->getNumber());
    EXPECT_EQ(owner2, cc2->getCardholder());
    EXPECT_EQ(address_line, cc2->getBillingAddress()->getAddress());

    Paypal* paypal = dynamic_cast<Paypal*>(user->getPaymentMethods()[2]);
    ASSERT_TRUE(paypal);
    EXPECT_EQ(2, paypal->getId());
    EXPECT_EQ(emailp, paypal->getEmail());
    EXPECT_EQ(address_line, paypal->getBillingAddress()->getAddress());
}
