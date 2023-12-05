#pragma once
#include <map>
#include "entity/room.h"
//take in room Number and reference to map, change room availability according to method called

class ModifyRoomAvailability
{
    /*private:
        Map<int, Room&> *roomMap;
    public:
        ModifyRoomAvailability(Map<int, Room&> &);
        */
    public:
        static void bookRoom(int, std::map<int, Room*>&);
        static void returnRoom(int, std::map<int, Room*>&);
};