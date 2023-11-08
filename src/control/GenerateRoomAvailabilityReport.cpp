#include "control/GenerateRoomAvailabilityReport.h"

std::string GenerateRoomAvailabilityReport::generateRoomReport(const std::map<int, Room*> &rooms)
{
    std::string formattedReport="";
    for (auto it = rooms.begin(); it != rooms.end(); ++it)
    {
        Room *room = it->second;
        formattedReport+="Room: "+ std::to_string(room->getRoomNumber()) + " Floor: "+std::to_string(room->getRoomFloorNumber()) + " Availability: ";
        if(room->getRoomAvailability())
            formattedReport+="Available\n";
        else
            formattedReport+="Unavailable\n";
    }
    return formattedReport;
}