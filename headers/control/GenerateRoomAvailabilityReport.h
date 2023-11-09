#pragma once
#include <string>
#include <map>
#include "entity/room.h"

class GenerateRoomAvailabilityReport{
    /*private:
        Map<int, Room*> *roomMap;
    public:
        GenerateReport(Map<int, Room*> &);
        */
    public:
        static std::string generateRoomReport(const std::map<int, Room*>&);
};