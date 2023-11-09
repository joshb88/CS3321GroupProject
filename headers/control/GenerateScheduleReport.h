#pragma once
#include <string>
#include <vector>
#include "entity/schedule.h"
//Assuming storage of Schedule objects in a vector.
//Since schedule objects are not private attributes in other classes, there is no need for references or pointers
class GenerateScheduleReport{
    public:
        static std::string generateScheduleReport(const std::vector<Schedule>&);
};