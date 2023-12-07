#include <string>
#include <iostream>
#include "entity/user.h"

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
User::User(std::string login, std::string pass, std::string last, std::string first, unsigned int dob, unsigned char gend)
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
std::ostream& operator<<(std::ostream& os, const User& user) 
{
    os << 
    user.getUserLogin() << "-" <<
    user.getUserPassword() << "-" <<
    user.getLastName()<< "-" <<
    user.getFirstName()<< "-" <<
    user.getDateOfBirth()<< "-" <<
    user.getGender();

    return os;
}
std::istream& operator>>(std::istream& is, User& user) {
    // Temporary variables to store values read from the stream
    std::string login, password, last, first;
    unsigned int dob;
    char gender;

    // Read data from the input stream
    std::getline(is, login, '-');
    std::getline(is, password, '-');
    std::getline(is, last, '-');
    std::getline(is, first, '-');

    // Read date_of_birth as an integer
    is >> dob;
    is.ignore(); // Ignore the delimiter '-'

    // Read gender as a character
    is >> gender;

    // Call setter methods to update the User object
    user.setUserLogin(login);
    user.setUserPassword(password);
    user.setLastName(last);
    user.setFirstName(first);
    user.setDateOfBirth(dob);
    user.setGender(gender);

    return is;
}