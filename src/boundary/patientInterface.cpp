#include "boundary/patientInterface.h"
#include "boundary/MainMenu.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

void PatientInterface::displayMainMenu(Patient& current_patient) {
    //Patient current_patient = dynamic_cast<Patient*>(&user);
    int choice = 0;
    bool isRunning = true;
    std::string header_content = "Patient Menu";


    while (isRunning) {
        MainMenu::clearScreen();
        MainMenu::header(header_content);
        
        std::cout << "Currently Logged in as " + current_patient.getFirstName() + " " + current_patient.getLastName() + "." << std::endl;
    

        std::cout << "1. View My Profile\n";
        std::cout << "2. View Bills\n";
        std::cout << "0. Log Out\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                //viewPatientProfile.displayPatientProfile(); // vector of schedules
                break;
            case 2:
                //viewBill.displayBillInformation();
                break;
            case 0:
                std::cout << "Logging out...\n";
                isRunning = false;
                MainMenu::StartMenu();
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

