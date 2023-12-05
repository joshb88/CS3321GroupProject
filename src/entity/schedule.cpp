#include <chrono>
#include <ctime>
#include <iostream>
#include <iomanip>
#include "entity/schedule.h"
#include "entity/staff.h"
#include "entity/patient.h"
#include "entity/procedure.h"

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
void Schedule::setProcedure(Procedure& pro)
{
    procedure = pro;
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