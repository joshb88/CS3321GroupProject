#ifndef PATIENT_SCHEDULING_H
#define PATIENT_SCHEDULING_H

#include <string>
#include <vector>
#include "entity/Patient.h"
#include "entity/Schedule.h"

// This class handles the scheduling interactions for patients within the system.
class PatientScheduling {
private:
    std::vector<Schedule> dailySchedule;

public:
    PatientScheduling();
    void createDailySchedule(const std::vector<Patient>& patients);
    bool findPatientInSchedule(const std::string& patientID) const;
    void checkInPatient(const std::string& patientID);
};

#endif 
