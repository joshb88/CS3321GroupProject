#include "../headers/entity.h"
#include <cstdlib>
#include <string>

// Default Constructor
User::User() : user_login(""), user_password(""), id_number(0)
{
    // A default constructor to set the the user name, password, and id number to nothing.
};

void User::setUserLogin(std::string login)
{
    user_login = login;
}

void User::setUserPassword(std::string password)
{
    user_password = password;
}

void User::setIdNumber(unsigned int id)
{
    id_number = id;
}