#ifndef PATIENT_SCHEDULING_H
#define PATIENT_SCHEDULING_H

#include <string>
#include <map>
#include "entity/Patient.h"
#include "entity/Room.h"
#include "control/ModifyRoomAvailability.h"
#include "control/GenerateRoomAvailabilityReport.h"

class PatientScheduling {
private:
    std::map<int, Room*> roomMap; // This map should be populated with room numbers and their corresponding Room objects

public:
    PatientScheduling();
    void checkInPatient(const std::string& patientID);
};

#endif // PATIENT_SCHEDULING_H
