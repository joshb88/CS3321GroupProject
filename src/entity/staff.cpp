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
// Overload operator>> for Staff class
std::istream& operator>>(std::istream& is, Staff& staff) 
{
    // Call the >> operator of the base class (User) to read common properties
    is >> static_cast<User&>(staff);

    // Consume the delimiter after the user part
    char delimiter;
    is >> delimiter;

    if (delimiter != '-') {
        // Handle error: unexpected delimiter
        std::cerr << "Error: Unexpected delimiter after User part." << std::endl;
        return is;
    }

    // Read specific properties of the Staff class
    unsigned int idNumber;
    unsigned int clearanceLevel;
    std::string jobTitle;
    unsigned int dateOfHire;

    // Read data from the input stream
    is >> idNumber;
    is.ignore();
    is >> clearanceLevel;
    is.ignore();
    std::getline(is,jobTitle,'-');
    is >> dateOfHire;
    is.ignore();

    // Set the specific properties using setter methods
    staff.setIdNumber(idNumber);
    staff.setClearanceLevel(clearanceLevel);
    staff.setJobTitle(jobTitle);
    staff.setDateOfHire(dateOfHire);

    return is;
}