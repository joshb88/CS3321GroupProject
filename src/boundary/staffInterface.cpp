#include "boundary/staffInterface.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

void StaffInterface::displayMainMenu() {
    int choice = 0;
    bool isRunning = true;

    while (isRunning) {
        std::cout << "\nStaff Menu:\n";
        std::cout << "1. View Schedule\n";
        std::cout << "2. Manage Patient Records\n";
        std::cout << "3. Access Inventory\n";
        std::cout << "4. Process Billing Information\n";
        std::cout << "5. Log Out\n";
        std::cout << "Enter your choice: ";
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



//myFile.open("./database/schedules.csv");


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
