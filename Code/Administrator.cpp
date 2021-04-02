#include "Administrator.hpp"

Administrator::Administrator(string& us, string& em, string& pas, unsigned long emcode):
    User(us,em,pas)
{
    setEmployeeCode(emcode);
}

Administrator::~Administrator() {}

unsigned long Administrator::getEmployeeCode() const {
    return employee_code;
}

void Administrator::setEmployeeCode(unsigned long emcode){
    employee_code = emcode;
}

bool Administrator::isAdmin() {
    return true;
}
