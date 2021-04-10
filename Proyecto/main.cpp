#include <iostream>
#include "Manager.hpp"
#include "Interface.hpp"

using namespace std;

int main()
{
    Manager* manager = new Manager;
    Interface* interface = new Interface(*manager);
    return 0;
}
