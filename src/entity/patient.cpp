#include "../../headers/entity/user.h"
#include "../../headers/entity/patient.h"

// PATIENT CLASS
// Patient Class Default Constructor
Patient::Patient() : User()
{
    has_insurance = false;
    insurance_provider = "N/A";
    room = nullptr;
}
// Patient Class Parameterized Constructor
Patient::Patient(std::string name, std::string pass, std::string last, std::string first, unsigned int dob, unsigned char gender, bool insurance, std::string provider, Room* roomptr)
{
    user_login = name;
    user_password = pass;
    last_name = last;
    first_name = first;
    date_of_birth = dob;
    this->gender = gender;
    has_insurance = insurance;
    insurance_provider = provider;
    room = roomptr;
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
void Patient::setRoom(Room& room)
{
    this->room = &room;
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
Room* Patient::getRoom()
{
    return room;
}