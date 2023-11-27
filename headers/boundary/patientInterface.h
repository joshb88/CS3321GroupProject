#ifndef PATIENT_INTERFACE_H
#define PATIENT_INTERFACE_H

#include <string>
#include "userInterface.h"

class PatientInterface : public UserInterface {

private:
    std::string patientName;
public:
    PatientInterface(const std::string& name) : patientName(name) {}

    void displayMainMenu() override; // Implementation specific to patients
    void viewAppointments();
};

#endif // PATIENT_INTERFACE_H
