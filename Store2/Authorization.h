#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <string>
#include <stdio.h>

class Authorization {
    std::string userName;
    std::string password;

public:
    Authorization(std::string p, std::string u);
    std::string getPassword();
    std::string getUserName();
    bool checkLogIn(std::string username, std::string password);


};
#endif