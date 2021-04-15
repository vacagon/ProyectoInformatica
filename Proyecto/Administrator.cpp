#include "Administrator.hpp"

Administrator::Administrator(const string &username, const string &email, const string &password, const unsigned long &employee_code):
    User(username,email,password) {
    setEmployeeCode(employee_code);
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
