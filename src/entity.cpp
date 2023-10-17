#include "..\headers\entity.h"
#include <cstdlib>
#include <string>

// Default Constructor
User::User()
{
    // A default constructor to set the the user name, password, and id number to nothing.
    user_login = "assign_login";
    user_password = "assign_password";
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

Client::Client() : User()
{
    date_of_birth = 19000101;
    has_insurance = false;
    insurance_provider = "enter_insurance";
}

Client::Client(std::string name, std::string pass, unsigned int idnum, unsigned int dob, bool insurance, std::string provider)
{
    setUserLogin(name);
    setUserPassword(pass);
    setIdNumber(idnum);
    date_of_birth = dob;
    has_insurance = insurance;
    insurance_provider = provider;
}

void Client::setDateOfBirth(unsigned int dob)
{
    //YYYYMMDD
    date_of_birth = dob;
}

void Client::setHasInsurance(bool ins)
{
    has_insurance = ins;
}

void Client::setInsuranceProvider(std::string prov)
{
    insurance_provider = prov;
}

unsigned int Client::getDateOfBirth() const
{
    return date_of_birth;
}

bool Client::getHasInsurance() const
{
    return has_insurance;
}

std::string Client::getInsuranceProvider() const
{
    return insurance_provider;
}