#include "control/ModifyRoomAvailability.h"

void ModifyRoomAvailability::bookRoom(int roomNumber, std::map<int, Room*> &roomMap)
{
    roomMap[roomNumber]->setRoomAvailability(false);
}

void ModifyRoomAvailability::returnRoom(int roomNumber, std::map<int, Room*> &roomMap)
{
    roomMap[roomNumber]->setRoomAvailability(true);
}