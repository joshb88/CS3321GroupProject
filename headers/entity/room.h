#pragma once
#include <iostream>

class Room
{
    private:
        unsigned int room_number; // Room number
        short room_floor_number;  // Floor Number
        bool room_available;      // Room Availability
    public:
        //Constructors
        Room();
        Room(unsigned int Room_no, short Floor_no, bool Room_Available);

        // Setters
        void setRoomNumber(unsigned int);
        void setRoomFloorNumber(short);
        void setRoomAvailability(bool);

        // Getters
        unsigned int getRoomNumber() const;
        short getRoomFloorNumber() const;
        bool getRoomAvailability() const;
};

std::ostream& operator<<(std::ostream& os, const Room& room);
std::istream& operator>>(std::istream& is, Room& room);