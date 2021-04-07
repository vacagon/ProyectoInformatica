#include <iostream>
#include "Manager.hpp"

using namespace std;

int main()
{
    Manager manager;
    manager.addUser("name1", "email1", "password1");
    std::vector<User*> members = manager.getUsers();
    return 0;
}
