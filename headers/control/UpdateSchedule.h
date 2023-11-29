#pragma once
#include <string>
#include <vector>
#include "entity/schedule.h"
//Assuming storage of Schedule objects in a vector.
//Since schedule objects are not private attributes in other classes, there is no need for references or pointers
class UpdateSchedule{
    public:
        static void addEvent(std::vector<Schedule>&, const Schedule::TimePoint&, const Staff&, const Patient&, const Room&, const Procedure&);
};