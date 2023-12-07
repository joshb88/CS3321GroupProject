#include <iostream>
#include "entity/room.h"

// ROOM CLASS
// Room Class Default Constructor
Room::Room() : room_number(0), room_floor_number(0), room_available(true) {}

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
// Overload operator<< for Inventory class
std::ostream& operator<<(std::ostream& os, const Room& room)
{
    os << 
    room.getRoomNumber() << "-" <<
    room.getRoomFloorNumber() << "-" <<
    room.getRoomAvailability();

    return os;
}
std::istream& operator>>(std::istream& is, Room& room)
{
    // Read input values from the stream
    unsigned int roomNumber;
    short floorNumber;
    bool availability;

    char dash; // To consume the dashes between values

    is >> roomNumber >> dash >> floorNumber >> dash >> availability;

    // Set the values in the Room object
    room.setRoomNumber(roomNumber);
    room.setRoomFloorNumber(floorNumber);
    room.setRoomAvailability(availability);

    return is;
}