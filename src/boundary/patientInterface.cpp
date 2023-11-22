#include "boundary/patientInterface.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

void PatientInterface::displayMainMenu() {
    int choice = 0;
    bool isRunning = true;

    while (isRunning) {
        std::cout << "\nPatient Menu:\n";
        std::cout << "1. View My Appointments\n";
        std::cout << "2. Update My Profile\n";
        std::cout << "3. View My Medical Records\n";
        std::cout << "4. Pay Bills\n";
        std::cout << "5. Log Out\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "viewAppointments() ran\n";
                viewAppointments();
                break;
            case 2:
                std::cout << "updateProfile() ran\n";
                break;
            case 3:
                std::cout << "viewMedicalRecords() ran\n";
                break;
            case 4:
                std::cout << "payBills() ran\n";
                break;
            case 5:
                std::cout << "Logging out...\n";
                isRunning = false;
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

void PatientInterface::viewAppointments() {
    std::ifstream file("./database/schedules.csv");
    std::string line;
    std::vector<std::string> patientAppointments;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string room, dateTime, patientName, procedure;
            getline(iss, room, '-');
            getline(iss, dateTime, '-');
            getline(iss, patientName, '-');
            getline(iss, procedure);

            if (this->patientName == patientName) {
                patientAppointments.push_back(dateTime + " - " + procedure);
            }
        }
        file.close();

        std::cout << "Your Appointments:\n";
        if (patientAppointments.empty()) {
            std::cout << "No scheduled appointments.\n";
        } else {
            for (const auto& appointment : patientAppointments) {
                std::cout << "- " << appointment << "\n";
            }
        }
    } else {
        std::cout << "Error: Unable to open the schedules file.\n";
    }
}

// void PatientInterface::updateProfile() {
//     std::cout << "Updating profile...\n";
//     // Implementation for updating profile
// }

// void PatientInterface::viewMedicalRecords() {
//     std::cout << "Viewing medical records...\n";
//     // Implementation for viewing medical records
// }

// void PatientInterface::payBills() {
//     std::cout << "Paying bills...\n";
//     // Implementation for paying bills
// }
