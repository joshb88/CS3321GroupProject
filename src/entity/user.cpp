#include <cstdlib>
#include <string>
#include "../../headers/entity/user.h"

// USER CLASS
// User Class Default Constructor
User::User()
{
    user_login = "";
    user_password = "";
    last_name = "";
    first_name = "";
    date_of_birth = 19000101;
    gender = 'X';
}
// User Class Parameterized Constructor
User::User(const std::string& login, std::string pass, std::string last, std::string first, unsigned int dob, unsigned char gend)
{
    user_login = login;
    user_password = pass;
    last_name = last;
    first_name = first;
    date_of_birth = dob;
    gender = gend;

}

// User Class Setters
void User::setUserLogin(std::string login)
{
    user_login = login;
}
void User::setUserPassword(std::string password)
{
    user_password = password;
}
void User::setLastName(std::string last)
{
    last_name = last;
}
void User::setFirstName(std::string first)
{
    first_name = first;
}
void User::setDateOfBirth(unsigned int dob)
{
    //YYYYMMDD
    date_of_birth = dob;
}
void User::setGender(unsigned char gend)
{
    //if (std::toupper(gend) == 'M' || std::toupper(gend) == 'F' || std::toupper(gend) == 'X')
    gender = gend;
}

// User Class Getters
std::string User::getUserLogin() const
{
    return user_login;
}
std::string User::getUserPassword() const
{
    return user_password;
}
std::string User::getLastName() const
{
    return last_name;
}
std::string User::getFirstName() const
{
    return first_name;
}
unsigned int User::getDateOfBirth() const
{
    return date_of_birth;
}
unsigned char User::getGender() const
{
    return gender;
}