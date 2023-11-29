#include "boundary/viewRoomAvailabilityReport.h"

void viewRoomAvailabilityReport::displayRoomAvailabilityReport(const std::map<int, Room*)& rooms){
    
    //obtain report from GenerateRoomAvailability class
    std::string report = roomAvailabilityReporter.generateRoomReport(rooms);

    //Display report
    std::cout << "Room Availability Report:\n";
    std::cout << report << std::endl;
}