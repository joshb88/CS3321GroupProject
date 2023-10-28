//#include "..\headers\entity.h"    //windows
#include "../headers/entity.h"      //mac
#include <cstdlib>
#include <string>

// User Class Default Constructor
User::User()
{
    user_login = "";
    user_password = "";
    last_name = "";
    first_name = "";
    date_of_birth = 19000101;
}
// User Class Parameterized Constructor
User::User(std::string login, std::string pass, std::string last, std::string first, unsigned int dob)
{
    user_login = login;
    user_password = pass;
    last_name = last;
    first_name = first;
    date_of_birth = dob;
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

// Room Class Default Constructor
Room::Room() : room_number(0), room_floor_number(0), room_available(false) {}

// Room Class Parameterized Constructor
Room::Room(unsigned int roomnum, short floorno, bool roomavail)
{
    room_number = roomnum;
    room_floor_number = floorno;
    room_available = roomavail;
}

// Room Setters
void Room::setRoomNumber(unsigned int roomno)
{
    room_number = roomno;
}
void Room::setRoomFloorNumber(short floorno)
{
    room_floor_number = floorno;
}
void Room::setRoomAvailability(bool availability)
{
    room_available = availability;
}

// Room Getters
unsigned int Room::getRoomNumber() const
{
    return room_number;
}
short Room::getRoomFloor() const
{
    return room_floor_number;
}
bool Room::getRoomAvailability() const
{
    return room_available;
}

// Patient Class Default Constructor
Patient::Patient() : User()
{
    has_insurance = false;
    insurance_provider = "N/A";
}
// Patient Class Parameterized Constructor
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

// Patient Class Setters
void Patient::setHasInsurance(bool ins)
{
    has_insurance = ins;
}
void Patient::setInsuranceProvider(std::string prov)
{
    insurance_provider = prov;
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

// Staff Class Default Constructor
Staff::Staff() : User()
{
    id_number = 0;
    clearance_level = entry;
    job_title = "";
    date_of_hire = 19000101;
}

// Staff Class Parameterized Constructor
Staff::Staff(std::string name, std::string pass, std::string last, std::string first, unsigned int dob, unsigned int idnumber, short clearance, std::string jobtitle, unsigned int doh)
{
    setUserLogin(name);
    setUserPassword(pass);
    setLastName(last);
    setFirstName(first);
    setDateOfBirth(dob);
    setIdNumber(idnumber);
    setClearanceLevel(clearance);
    setJobTitle(jobtitle);
    setDateOfHire(doh);
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