#include "Authorization.h"
#include <iostream>
#include <string>

Authorization::Authorization(string p, string u) {
    userName = u;
    password = p;
};
string Authorization::getPassword() { return password; };
string Authorization::getUserName() { return userName; };
bool Authorization::checkLogIn(string username, string password) {

    if (username == "userAd" && password == "12345") {
        return true;
    }
    else
        return false;
}
