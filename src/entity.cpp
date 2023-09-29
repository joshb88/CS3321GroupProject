#include "..\headers\entity.h"
#include <cstdlib>
#include <string>

// Default Constructor
User::User()
{
    // A default constructor to set the the user name, password, and id number to nothing.
    user_login = "assign_login";
    user_password = "password";
    id_number = 0;
}

User::User(std::string name, std::string pass, unsigned int idnum)
{
    user_login = name;
    user_password = pass;
    id_number = idnum;
}

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

std::string User::getUserLogin() const
{
    return user_login;
}
std::string User::getUserPassword() const
{
    return user_password;
}
unsigned int User::getId() const
{
    return id_number;
}