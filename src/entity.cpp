//#include "..\headers\entity.h"    //windows
#include "../headers/entity.h"      //mac
#include <cstdlib>
#include <string>

using TimePoint = std::chrono::system_clock::time_point;

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

// ROOM CLASS
// Room Class Default Constructor
Room::Room() : room_number(0), room_floor_number(0), room_available(false) {}

// Room Class Parameterized Constructor
// Room number, floor number, room availability
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

// PATIENT CLASS
// Patient Class Default Constructor
Patient::Patient() : User()
{
    has_insurance = false;
    insurance_provider = "N/A";
}
// Patient Class Parameterized Constructor
Patient::Patient(std::string name, std::string pass, std::string last, std::string first, unsigned int dob, unsigned char gender, bool insurance, std::string provider)
{
    user_login = name;
    user_password = pass;
    last_name = last;
    first_name = first;
    date_of_birth = dob;
    this->gender = gender;
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
Room Patient::getRoom() const
{
    return room;
}

// STAFF CLASS
// Staff Class Default Constructor
Staff::Staff() : User()
{
    id_number = 0;
    clearance_level = entry;
    job_title = "";
    date_of_hire = 19000101;
}

// Staff Class Parameterized Constructor
Staff::Staff(std::string name, std::string pass, std::string last, std::string first, unsigned int dob, unsigned char gender, unsigned int idnumber, short clearance, std::string jobtitle, unsigned int doh)
{
    user_login = name;
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

// INVENTORY CLASS
// Inventory Class Constructors
Inventory::Inventory() : item_name(""), item_count(0), item_threshold(0) {}
Inventory::Inventory(std::string name, unsigned int count, unsigned int threshold)
{
    item_name = name;
    item_count = count;
    item_threshold = threshold;
}

// Inventory Class Setters
void Inventory::setItemName(std::string name)
{
    item_name = name;
}
void Inventory::setItemCount(unsigned int count)
{
    item_count = count;
}
void Inventory::setItemThreshold(unsigned int threshold)
{
    item_threshold = threshold;
}

// Inventory Class Getters
std::string Inventory::getItemName() const { return item_name; }
unsigned int Inventory::getItemCount() const { return item_count; }
unsigned int Inventory::getItemThreshold() const { return item_threshold; }

// PROCEDURE CLASS
// Procedure Class Constructors
Procedure::Procedure() : procedure_name(""), cost(0.0), items_used() {}
Procedure::Procedure(std::string name, float cost, std::vector<Inventory>& items_used) : 
procedure_name(name), cost(cost), items_used(items_used) {}

// Procedure Class Setters
void Procedure::setProcedureName(std::string proc_name)
{
    procedure_name = proc_name;
}
void Procedure::setCost(float cost)
{
    this->cost = cost;
}
void Procedure::setItemsUsed(std::vector<Inventory>& items_used)
{
    this->items_used = items_used;
}

// Procedure Class Getters
std::string Procedure::getProcedureName() const
{
    return procedure_name;
}
float Procedure::getCost() const
{
    return cost;
}
const std::vector<Inventory>& Procedure::getItemsUsed() const
{
    return items_used;
}

// SCHEDULE CLASS
// Schedule Class Constructors
Schedule::Schedule() : time(TimePoint::clock::now()) {}
Schedule::Schedule(const TimePoint& appointment_time, const Staff& staff, const Patient& patient, const Room& room, const Procedure& proc)
: time(appointment_time), staffer(staff), patient(patient), room(room), procedure(proc) {}

// Schedule Class Setters
void Schedule::setTime(TimePoint& apt_time)
{
    time = apt_time;
}
void Schedule::setStaffer(Staff& staffer)
{
    this->staffer = staffer;
}
void Schedule::setPatient(Patient& patient)
{
    this->patient = patient;
}
void Schedule::setRoom(Room& roomno)
{
    this->room = roomno;
}

// Schedule Class Getters
const TimePoint Schedule::getTime() const
{
    return time;    
}
const Staff Schedule::getStaffer() const
{
    return staffer;
}
const Patient Schedule::getPatient() const
{
    return patient;
}
const Room Schedule::getRoom() const
{
    return room;
}
const Procedure Schedule::getProcedure() const
{
    return procedure;
}