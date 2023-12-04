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
        std::cout << "2. View Bills\n";
        std::cout << "3. Log Out\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                //viewPatientProfile.displayPatientProfile(); // vector of schedules
                break;
            case 2:
                //viewBill.displayBillInformation();
                break;
            case 4:
                std::cout << "Logging out...\n";
                isRunning = false;
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

