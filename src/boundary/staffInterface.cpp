#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "boundary/staffInterface.h"
#include "boundary/MainMenu.h"

void StaffInterface::displayMainMenu(Staff& staff) 
{
     int choice = 0;
     bool isRunning = true;
     std::string header_content = "Staff Main Menu";

     while (isRunning) 
     {
         MainMenu::clearScreen();
         MainMenu::header(header_content);
         std::cout << 
         "Select an option:\n" << 
         "1.\tView Schedule" << std::endl <<
         "2.\tAdd To Schedule" << std::endl <<
         "3.\tAccess Inventory" << std::endl <<
         "4.\tOpen Inventory" << std::endl <<
         "0.\tLog Out" << std::endl <<
         MainMenu::SECTION_BREAK;
         std::cin >> choice;
         switch (choice) {
             case 1:
                 std::cout << "You've opted to View Schedule\n";
                 StaffInterface::viewSchedule();
                 break;
             case 2:
                 std::cout << "You've opted to Add To Schedule\n";
                 StaffInterface::addSchedule();
                 break;
             case 3:
                std::cout << "You've opted to Remove From Schedule \n";
                StaffInterface::removeSchedule();
                 break;
             case 4:
                 std::cout << "You've opted to Open Inventory\n";
                 break;
             case 0:
                 std::cout << "Logging out...\n";
                 isRunning = false;
                 break;
             default:
                 std::cout << "Invalid choice. Please try again.\n";
         }
     }
}

//myFile.open("./database/schedules.csv");

void StaffInterface::viewSchedule() {
    std::cout << "Viewing schedule...\n";
    //viewSchedule
}

void StaffInterface::addSchedule() {
    std::cout << "Accessing schedule...\n";
    //updateSchedule
}
void StaffInterface::removeSchedule() {
    std::cout << "Removing from schedule...\n";
    //updateSchedule
}

void StaffInterface::openInventory() {
    std::cout << "Opening inventory...\n";
    //open inventoryUi
}
