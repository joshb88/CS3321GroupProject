#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "boundary/staffInterface.h"
#include "boundary/MainMenu.h"

void StaffInterface::displayMainMenu(Staff& staff) 
{
//     int choice = 0;
//     bool isRunning = true;
//     std::string header_content = "Staff Main Menu";

//     while (isRunning) 
//     {
//         MainMenu::clearScreen();
//         MainMenu::header(header_content);
//         std::cout << 
//         "Select an option:" << 
//         "1.\tView Schedule" << std::endl <<
//         "2.\tManage Patient Records" << std::endl <<
//         "3.\tAccess Inventory" << std::endl <<
//         "4.\tProcess Billing Information" << std::endl <<
//         "0.\tLog Out" << std::endl <<
//         MainMenu::SECTION_BREAK;
//         std::cin >> choice;

//         switch (choice) {
//             case 1:
//                 int response;
//                 while (int running = true){
//                 std::cout << "viewSchedule() ran\n";
//                 viewSchedule();

//                 std::cout << "1. add to schedule\n";
//                 std::cout << "2. remove from schedule\n";
//                 std::cout << "3. exit\n";
//                 std::cin >> response;
//                 if (response == 1){ addSchedule();}
//                 if (response == 2) {removeSchedule();}
//                 if (response == 3) {break;}
//                 }
//                 break;
//             case 2:
//                 std::cout << "managePatientRecords() ran\n";
//                 break;
//             case 3:
//                 std::cout << "accessInventory() ran \n";
//                 break;
//             case 4:
//                 std::cout << "processBillingInformation() ran\n";
//                 break;
//             case 5:
//                 std::cout << "Logging out...\n";
//                 isRunning = false;
//                 break;
//             default:
//                 std::cout << "Invalid choice. Please try again.\n";
//         }
//     }
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
