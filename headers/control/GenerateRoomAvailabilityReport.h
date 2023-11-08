#pragma once
#include "entity/room.h"
#include <string>
#include <map>

class GenerateRoomAvailabilityReport{
    /*private:
        Map<int, Room*> *roomMap;
    public:
        GenerateReport(Map<int, Room*> &);
        */
    public:
        static std::string generateRoomReport(const std::map<int, Room*>&);
};