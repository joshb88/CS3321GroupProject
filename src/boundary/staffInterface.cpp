#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include "boundary/staffInterface.h"
#include "boundary/MainMenu.h"
#include "control/TESTMODINV.h"
#include "control/MainMenuLogic.h"

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
         "3.\tRemove From Schedule" << std::endl <<
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
                 StaffInterface::openInventory(staff);
                 break;
             case 0:
                 std::cout << "Logging out...\n";
                 isRunning = false;
                 MainMenu::StartMenu();
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

void StaffInterface::openInventory(Staff& staff) {
    std::cout << "Opening inventory...\n";
    std::string line, header_content = "Inventory List";
    std::fstream inventory_file;

    inventory_file.open("./database/inventory.txt", std::ios::in);

    if (inventory_file.is_open())
    {
        MainMenu::clearScreen();
        MainMenu::header("Inventory List");
        std::cout << std::left << std::setw(17) << "Item Name" << std::left << std::setw(17) << "Current Count" << std::left << std::setw(17) << "Least Allowed" << std::endl << MainMenu::SECTION_BREAK;
        while (std::getline(inventory_file, line))
        {
            std::istringstream iss(line);
            std::string token;
            std::getline(iss, token, ',');
            Inventory displayed_inventory = ModifyInventory::readInventoryFromDatabase(token);
            std::cout << std::left << std::setw(21) << 
            displayed_inventory.getItemName() << std::left << std::setw(18) << 
            displayed_inventory.getItemCount() << std::left << 
            displayed_inventory.getItemThreshold() << std::endl;
        }
        MainMenu::SECTION_BREAK;
    }
    inventory_file.close();
    std::cout << "Press any key to return to Staff Menu" << std::endl;
    std::cin >> std::ws;
    std::cin.ignore();
     std::unique_ptr<User> staffptr = std::make_unique<Staff>(staff);
    LoginVerification::passUserToCorrectUI(std::move(staffptr));
}