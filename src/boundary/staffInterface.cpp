#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "boundary/staffInterface.h"
#include "boundary/MainMenu.h"

void StaffInterface::displayMainMenu() 
{
    int choice = 0;
    bool isRunning = true;
    std::string header_content = "Staff Main Menu";

    while (isRunning) 
    {
        MainMenu::clearScreen();
        MainMenu::header(header_content);
        std::cout << 
        "Select an option:" << 
        "1.\tView Schedule" << std::endl <<
        "2.\tManage Patient Records" << std::endl <<
        "3.\tAccess Inventory" << std::endl <<
        "4.\tProcess Billing Information" << std::endl <<
        "0.\tLog Out" << std::endl <<
        MainMenu::SECTION_BREAK;
        std::cin >> choice;

        switch (choice) {
            case 1:
                int response;
                while (int running = true){
                std::cout << "viewSchedule() ran\n";
                viewSchedule();

                std::cout << "1. add to schedule\n";
                std::cout << "2. remove from schedule\n";
                std::cout << "3. exit\n";
                std::cin >> response;
                if (response == 1){ addSchedule();}
                if (response == 2) {removeSchedule();}
                if (response == 3) {break;}
                }
                break;
            case 2:
                std::cout << "managePatientRecords() ran\n";
                break;
            case 3:
                std::cout << "accessInventory() ran \n";
                break;
            case 4:
                std::cout << "processBillingInformation() ran\n";
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

void StaffInterface::viewSchedule() {
    std::ifstream file("./database/schedules.csv");
    std::string line;
    std::vector<std::string> scheduleEntries;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            scheduleEntries.push_back(line);
        }
        file.close();

        std::cout << "Staff Schedule:\n";
        if (scheduleEntries.empty()) {
            std::cout << "No scheduled appointments.\n";
        } else {
            for (const auto& entry : scheduleEntries) {
                std::cout << "- " << entry << "\n";
            }
        }
    } else {
        std::cout << "Error: Unable to open the schedules file.\n";
    }
}

void StaffInterface::addSchedule() {
    std::string newEntry;
    std::cout << "Enter schedule details (Format: Room - Date & Time - Patient - Procedure): ";
    std::getline(std::cin >> std::ws, newEntry); // Read the full line including spaces

    std::ofstream file("./database/schedules.csv", std::ios::app); // Open in append mode
    if (file.is_open()) {
        file << newEntry << "\n";
        file.close();
        std::cout << "Schedule added successfully.\n";
    } else {
        std::cout << "Error: Unable to open file.\n";
    }
}
    //myFile.open("./database/schedules.csv");

void StaffInterface::removeSchedule() {
    std::string lineToRemove;
    std::cout << "Enter the exact schedule details to remove: ";
    std::getline(std::cin >> std::ws, lineToRemove);

    std::string line;
    std::vector<std::string> lines;
    std::ifstream file("./database/schedules.csv");
    bool found = false;

    if (file.is_open()) {
        while (getline(file, line)) {
            if (line != lineToRemove) {
                lines.push_back(line);
            } else {
                found = true;
            }
        }
        file.close();

        if (found) {
            std::ofstream outFile("./database/schedules.csv");
            for (const auto& l : lines) {
                outFile << l << "\n";
            }
            outFile.close();
            std::cout << "Schedule removed successfully.\n";
        } else {
            std::cout << "Schedule not found.\n";
        }
    } else {
        std::cout << "Error: Unable to open file.\n";
    }
}
// void StaffInterface::managePatientRecords() {
//     std::cout << "Managing patient records...\n";
//     // Implementation for managing patient records
// }

// void StaffInterface::accessInventory() {
//     std::cout << "Accessing inventory...\n";
//     // Implementation for accessing inventory
// }

// void StaffInterface::processBillingInformation() {
//     std::cout << "Processing billing information...\n";
//     // Implementation for processing billing information
// }
