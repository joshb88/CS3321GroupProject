//#include "..\headers\entity.h"
#include "../headers/entity.h"
#include <cstdlib>
#include <string>

// Default Constructor
User::User()
{
    // A default constructor to set the the user login, password, names, and id number to nothing
    user_login = "";
    user_password = "";
    last_name = "";
    first_name = "";
    date_of_birth = 19000101;
}
// Parameterized Constructor used to initialize the class
User::User(std::string login, std::string pass, std::string last, std::string first, unsigned int dob)
{
    user_login = login;
    user_password = pass;
    last_name = last;
    first_name = first;
    date_of_birth = dob;
}
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

Patient::Patient() : User()
{
    date_of_birth = 19000101;
    has_insurance = false;
    insurance_provider = "N/A";
}

Patient::Patient(std::string name, std::string pass, std::string last, std::string first, unsigned int dob, bool insurance, std::string provider)
{
    setUserLogin(name);
    setUserPassword(pass);
    setLastName(last);
    setFirstName(first);
    date_of_birth = dob;
    has_insurance = insurance;
    insurance_provider = provider;
}

void Patient::setHasInsurance(bool ins)
{
    has_insurance = ins;
}

void Patient::setInsuranceProvider(std::string prov)
{
    insurance_provider = prov;
}

bool Patient::getHasInsurance() const
{
    return has_insurance;
}

std::string Patient::getInsuranceProvider() const
{
    return insurance_provider;
}

Staff::Staff() : User()
{
    id_number = 0;
    clearance_level = entry;
    job_title = "";
    date_of_hire = 19000101;
}

Staff::Staff(std::string name, std::string pass, std::string last, std::string first, unsigned int dob, unsigned int idnumber, short clearance, std::string jobtitle, unsigned int doh)
{
    setUserLogin(name);
    setUserPassword(pass);
    setLastName(last);
    setFirstName(first);
    setDateOfBirth(dob);
    setClearanceLevel(clearance);
    setJobTitle(jobtitle);
    setDateOfHire(doh);
}
void Staff::setIdNumber(unsigned int id)
{
    id_number = id;
}
unsigned int Staff::getIdNumber() const
{
    return id_number;
}
// class Staff : virtual User
// {
//     public:
//         enum Clearance { entry, janitorial, nursing, medical, admin };
//     private:
//         unsigned int id_number;
//         short clearance_level;
//         std::string job_title;
//         unsigned int date_of_hire;
//     public:
//         void setClearanceLevel(short);
//         void setJobTitle(std::string);
//         void setHireDate(unsigned int);
//         unsigned int getHireDate() const;
//         short getClearanceLevel() const;
//         std::string getJobTitle() const;
// };