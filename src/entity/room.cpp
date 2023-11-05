#include "entity/room.h"

// ROOM CLASS
// Room Class Default Constructor
Room::Room() : room_number(0), room_floor_number(0), room_available(false) {}

// Room Class Parameterized Constructor
// Room number, floor number, room availability
Room::Room(unsigned int roomnum, short floorno, bool roomavail)
{
    room_number = roomnum;
    room_floor_number = floorno;
    room_available = roomavail;
}

// Room Setters
void Room::setRoomNumber(unsigned int roomno)
{
    room_number = roomno;
}
void Room::setRoomFloorNumber(short floorno)
{
    room_floor_number = floorno;
}
void Room::setRoomAvailability(bool availability)
{
    room_available = availability;
}

// Room Getters
unsigned int Room::getRoomNumber() const
{
    return room_number;
}
short Room::getRoomFloorNumber() const
{
    return room_floor_number;
}
bool Room::getRoomAvailability() const
{
    return room_available;
}