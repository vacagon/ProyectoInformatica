#include <iostream>
#include "Manager.hpp"
#include "Interface.hpp"

using namespace std;

int main()
{
    Manager* manager = new Manager;
    Interface* interface = new Interface(*manager);

    interface->FrontPageMenu();

    //Delete the objects created with dynamic memory
    delete interface;
    delete manager;
    return 0;
}
