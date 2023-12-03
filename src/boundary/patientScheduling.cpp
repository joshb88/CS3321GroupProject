#include "PatientScheduling.h"
#include <iostream>

PatientScheduling::PatientScheduling() {
}

void PatientScheduling::checkInPatient(const std::string& patientID) {

    ModifyRoomAvailability roomModifier;
    GenerateRoomAvailabilityReport roomReportGenerator;


    std::string roomReport = roomReportGenerator.generateRoomReport(roomMap);


    int roomNumberToBook = -1; // Placeholder for room number logic
    for (const auto& roomPair : roomMap) {
        if (roomPair.second->getRoomAvailability()) {
            roomNumberToBook = roomPair.first;
            break;
        }
    }

    // If an available room is found, book it
    if (roomNumberToBook != -1) {
        roomModifier.bookRoom(roomNumberToBook, roomMap);
        std::cout << "Patient " << patientID << " has been checked into room " << roomNumberToBook << std::endl;
    } else {
        std::cout << "No available rooms to book for patient " << patientID << std::endl;

    }
}
