#include <chrono>
#include <ctime>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "entity/schedule.h"
#include "entity/staff.h"
#include "entity/patient.h"
#include "entity/procedure.h"

// SCHEDULE CLASS
// Schedule Class Constructors
Schedule::Schedule() : time(TimePoint::clock::now()) {}
// Schedule constructor taking a string value of the date.
// Formatted as YYYYMMDD HH:DD
Schedule::Schedule(std::string time) 
{
    std::tm tm = {};
    std::istringstream ss(time);
    ss >> std::get_time(&tm, "%Y%m%d %H:%M");

    if (ss.fail()) {
        // Handle parsing failure
        throw std::runtime_error("Failed to parse date and time from the string");
    }

    tm.tm_isdst = -1;

    this->time = std::chrono::system_clock::from_time_t(std::mktime(&tm));
}
Schedule::Schedule(const TimePoint& appointment_time, const Staff& staff, const Patient& patient, const Room& room, const Procedure& proc)
: time(appointment_time), staffer(staff), patient(patient), room(room), procedure(proc) {}

// Schedule Class Setters
void Schedule::setTime(TimePoint& apt_time)
{
    time = apt_time;
}
// Overloaded setTime function for string input
// Takes format "YYYYMMDD HH:MM"
void Schedule::setTime(const std::string& date_time_str) {
    std::tm tm = {};
    std::istringstream ss(date_time_str);
    ss >> std::get_time(&tm, "%Y/%m/%d %H:%M");

    if (ss.fail()) {
        // Handle parsing failure
        throw std::runtime_error("Failed to parse date and time from the string");
    }

    tm.tm_isdst = -1;

    time = std::chrono::system_clock::from_time_t(std::mktime(&tm));
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
    roomno.setRoomAvailability(false);
    this->room = roomno;
}
void Schedule::setProcedure(Procedure& pro)
{
    procedure = pro;
}

// Schedule Class Getters
TimePoint Schedule::getTime() const
{
    return time;    
}
Staff Schedule::getStaffer() const
{
    return staffer;
}
Patient Schedule::getPatient() const
{
    return patient;
}
Room Schedule::getRoom() const
{
    return room;
}
Procedure Schedule::getProcedure() const
{
    return procedure;
}
// Overload stream insertion operator for TimePoint
std::ostream& operator<<(std::ostream& os, const Schedule::TimePoint& tp) 
{
    std::time_t time_t = std::chrono::system_clock::to_time_t(tp);
    std::tm tm = *std::localtime(&time_t);
    os << std::put_time(&tm, "%Y/%m/%d %H:%M");
    return os;
}