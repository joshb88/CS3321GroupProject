#ifndef PATIENT_INTERFACE_H
#define PATIENT_INTERFACE_H

#include <string>
#include "userInterface.h"
#include "patientScheduling.h"
#include "control/generateBill.h"
#include "viewSchedule.h"
#include "viewPatientProfile.h"

class PatientInterface : public UserInterface {

private:
    std::string patientName;
public:
    PatientInterface(const std::string& name) : patientName(name) {}
    PatientInterface(Patient& patient) : patientName(patient.getLastName()) {}
    void displayMainMenu(Patient& user); // Implementation specific to patients
};

#endif // PATIENT_INTERFACE_H
