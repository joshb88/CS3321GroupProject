#pragma once
#include "entity/schedule.h"

class ModifySchedule
{
    public:
    static void writeScheduleToDatabase(Schedule& schedule);
    static Schedule readFromDatabase(std::string schedule);
};