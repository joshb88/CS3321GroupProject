#include <iostream>
#include "entity/user.h"
#include "entity/staff.h"

// Staff Class Default Constructor
Staff::Staff() : User()
{
    id_number = 0;
    clearance_level = entry;
    job_title = "";
    date_of_hire = 19000101;
}
Staff::Staff(const User& user)
    : User(user), id_number(0), clearance_level(entry), job_title(""), date_of_hire(19010101)
{

}

// Staff Class Parameterized Constructor
Staff::Staff(std::string login, std::string pass, std::string last, std::string first, unsigned int dob, unsigned char gender, unsigned int idnumber, short clearance, std::string jobtitle, unsigned int doh)
{
    user_login = login;
    user_password = pass;
    last_name = last;
    first_name = first;
    date_of_birth = dob;
    this->gender = gender;
    id_number = idnumber;
    clearance_level = clearance;
    job_title = jobtitle;
    date_of_hire = doh;
}

// Staff Class Setters
void Staff::setIdNumber(unsigned int id)
{
    id_number = id;
}
void Staff::setClearanceLevel(short clearancelevel)
{
    clearance_level = clearancelevel;
}
void Staff::setJobTitle(std::string title)
{
    job_title = title;
}
void Staff::setDateOfHire(unsigned int doh)
{
    date_of_hire = doh;
}

// Staff Class Getters
unsigned int Staff::getIdNumber() const
{
    return id_number;
}
unsigned int Staff::getDateOfHire() const
{
    return date_of_hire;
}
short Staff::getClearanceLevel() const
{
    return clearance_level;
}
std::string Staff::getJobTitle() const
{
    return job_title;
}

// Overload operator<< for Staff class
std::ostream& operator<<(std::ostream& os, const Staff& staff)
{
    os << static_cast<const User&>(staff) << "-";

    os <<
    staff.getIdNumber()<< "-" <<
    staff.getClearanceLevel()<< "-" <<
    staff.getJobTitle()<< "-" <<
    staff.getDateOfHire();

    return os;
}