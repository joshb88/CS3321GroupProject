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
                std::cout << "1. viewAppointments() ran\n";
                viewAppointments();
                break;
            case 2:
                std::cout << "2. updateProfile() ran\n";
                break;
            case 3:
                std::cout << "3. view patient profile\n";

                break;
            case 4:
                std::cout << "4. view bill\n";
                break;
            case 5:
                std::cout << "5. Logging out...\n";
                isRunning = false;
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
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
