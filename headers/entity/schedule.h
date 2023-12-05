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
        Schedule(const TimePoint&, const Staff&, const Patient&, const Room&, const Procedure&);

        // Setters
        void setTime(TimePoint&);
        void setStaffer(Staff&);
        void setPatient(Patient&);
        void setRoom(Room&);
        void setProcedure(Procedure&);
        // No need to set the procedure here, because it's instantiated from a seperate class.
        // There will also be implementation of control classes to modify these members.

        // Getters
        const TimePoint getTime() const;
        const Staff getStaffer() const;
        const Patient getPatient() const;
        const Room getRoom() const;
        const Procedure getProcedure() const;
};