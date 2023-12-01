#include "boundary/viewRoomAvailabilityReport.h"
#include <map>

void viewRoomAvailabilityReport::displayRoomAvailabilityReport(const std::map<int, Room*>& rooms){
    
    // Assume roomAvailabilityReporter is correctly instantiated and accessible in this context.
    // Obtain report from GenerateRoomAvailability class
    std::string report = roomAvailabilityReporter.generateRoomReport(rooms);

    // Display report
    std::cout << "Room Availability Report:\n";
    std::cout << report << std::endl;
}