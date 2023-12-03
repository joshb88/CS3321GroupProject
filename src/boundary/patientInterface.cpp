#include "boundary/patientInterface.h"
#include "boundary/MainMenu.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

void PatientInterface::displayMainMenu() {
    int choice = 0;
    bool isRunning = true;

    while (isRunning) {
        MainMenu::clearScreen();
        MainMenu::header();
        std::cout << "\nPatient Menu:\n";
        std::cout << "1. View My Profile\n";
        std::cout << "2. View My Schedule\n";
        std::cout << "3. View Bills\n";
        std::cout << "4. Log Out\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                viewPatientProfile.displayPatientProfile() // vector of schedules
                break;
            case 2:
                viewPatientProfile
                break;
            case 3:
                std::cout << "3. view patient profile\n";
                break;
            case 4:
                std::cout << "5. Logging out...\n";
                isRunning = false;
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
