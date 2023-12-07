#include <iostream>
#include "entity/user.h"
#include "entity/patient.h"

// PATIENT CLASS
// Patient Class Default Constructor
Patient::Patient() : User(), room()
{
    has_insurance = false;
    insurance_provider = "N/A";
    has_room = false;
}
Patient::Patient(const User& user)
    : User(user), has_insurance(false), insurance_provider("N/A"), has_room(false), room()
{

}
// Patient Class Parameterized Constructor
Patient::Patient(std::string name, std::string pass, std::string last, std::string first, unsigned int dob, unsigned char gender, bool insurance, std::string provider, bool has_room,const Room& room)
{
    user_login = name;
    user_password = pass;
    last_name = last;
    first_name = first;
    date_of_birth = dob;
    this->gender = gender;
    has_insurance = insurance;
    insurance_provider = provider;
    this->has_room = has_room;
    this->room = room;
    //room = roomptr;
}

// Patient Class Setters
void Patient::setHasInsurance(bool ins)
{
    has_insurance = ins;
}
void Patient::setInsuranceProvider(std::string prov)
{
    insurance_provider = prov;
}
void Patient::setHasRoom(bool room)
{
    has_room = room;
}
void Patient::setRoom(const Room& newroom)
{
    room = newroom;
}

// Patient Class Getters
bool Patient::getHasInsurance() const
{
    return has_insurance;
}
std::string Patient::getInsuranceProvider() const
{
    return insurance_provider;
}
bool Patient::getHasRoom() const
{
    return has_room;
}
Room& Patient::getRoom()
{
    return room;
}
// Overload operator<< for Patient class
std::ostream& operator<<(std::ostream& os, Patient& patient)
{
   os << static_cast<const User&>(patient) << "-";

    // Output the specific members of the Patient class
    os << patient.getHasInsurance() << "-"
       << patient.getInsuranceProvider() << "-"
       << patient.getHasRoom() << "-"
       << patient.getRoom();
       
    return os;
}