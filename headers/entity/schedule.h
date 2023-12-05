#pragma once
#include <chrono>
#include <ctime>
#include <iostream>
#include <iomanip>
#include "entity/staff.h"
#include "entity/patient.h"
#include "entity/procedure.h"

using TimePoint = std::chrono::system_clock::time_point;


class Schedule
{
    public:
        using TimePoint = std::chrono::system_clock::time_point;

    private:
        TimePoint time;
        Staff staffer;
        Patient patient;
        Room room;
        Procedure procedure;
    public:
        // Constructors
        Schedule();
        Schedule(std::string time) ;
        Schedule(const TimePoint&, const Staff&, const Patient&, const Room&, const Procedure&);

        // Setters
        void setTime(TimePoint&);
        void setTime(const std::string& date_time_str);
        void setStaffer(Staff&);
        void setPatient(Patient&);
        void setRoom(Room&);
        void setProcedure(Procedure&);
        // No need to set the procedure here, because it's instantiated from a seperate class.
        // There will also be implementation of control classes to modify these members.

        // Getters
        TimePoint getTime() const;
        Staff getStaffer() const;
        Patient getPatient() const;
        Room getRoom() const;
        Procedure getProcedure() const;
};

std::ostream& operator<<(std::ostream& os, const Schedule::TimePoint& tp);