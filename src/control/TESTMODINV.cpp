#include "control/TESTMODINV.h"
#include "boundary/MainMenu.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

bool ModifyInventory::inventoryInDatabase(Inventory& inventory)
{
    std::fstream inventory_file;
    std::string line;
    inventory_file.open("./database/inventory.txt", std::ios::in);

    if(inventory_file.is_open())
    {
        while (std::getline(inventory_file, line)) // loop through each line in the file
        {
            std::istringstream iss(line); // create a string stream to iterate through each token (word)
            std::string token;

            // Read the first token and (more importantly) the second token.
            std::getline(iss, token, ',');

            // Check if the second token is equal to the provided user login
            if (token == inventory.getItemName())
            {
                inventory_file.close();
                return true;
            }
        }
    }
    inventory_file.close();
    return false;
}

bool ModifyInventory::inventoryInDatabase(std::string& inventory)
{
    std::fstream inventory_file;
    std::string line;
    inventory_file.open("./database/inventory.txt", std::ios::in);

    if(inventory_file.is_open())
    {
        while (std::getline(inventory_file, line)) // loop through each line in the file
        {
            std::istringstream iss(line); // create a string stream to iterate through each token (word)
            std::string token;

            // Read the first token and (more importantly) the second token.
            std::getline(iss, token, ',');

            // Check if the second token is equal to the provided user login
            if (token == inventory)
            {
                inventory_file.close();
                return true;
            }
        }
    }
    inventory_file.close();
    return false;
}

void ModifyInventory::writeInventoryToDatabase(Inventory& inventory)
{
    std::fstream inventory_file;
    inventory_file.open("./database/inventory.txt", std::ios::app);
    if(!(ModifyInventory::inventoryInDatabase(inventory)))
    {    
        if(inventory_file.is_open())
            {
                inventory_file << 
                inventory.getItemName() << ',' <<
                inventory.getItemCount() << ',' <<
                inventory.getItemThreshold() << std::endl;
            }
            else
            {
                std::cout << "\nItem Already Exists\n\n";
            }
    }
}
Inventory ModifyInventory::readInventoryFromDatabase(const std::string& inventory_name)
{
    std::fstream inventory_file;
    inventory_file.open("./database/inventory.txt", std::ios::in);

    if (inventory_file.is_open())
    {
        std::string line;
        while (std::getline(inventory_file, line))
        {
            std::istringstream iss(line);
            std::string token;

            // Read the first token (inventory name)
            std::getline(iss, token, ',');

            if (token == inventory_name)
            {
                unsigned int item_count, item_threshold;

                // Read the cost
                std::getline(iss, token, ',');
                item_count = std::stoi(token);

                // Read the serialized itemsUsed
                std::getline(iss, token, ',');
                item_threshold = std::stoi(token);

                // Create and return a inventory object
                return Inventory(inventory_name, item_count, item_threshold);
            }
        }

        std::cout << "\nInventory Item Not Found\n\n";
    }
    else
    {
        std::cout << "\nError opening the file\n\n";
    }

    // Return a default-constructed inventory if not found or an error occurred
    return Inventory();
}

Inventory ModifyInventory::createInventoryFromUser() 
{
    std::string inventory_item, header_content = "Inventory Creation Menu";
    unsigned int item_count, item_threshold;
    short choice;
    
    MainMenu::clearScreen();
    MainMenu::header(header_content);
    std::cout << 
    "Enter a name for the inventory item:" << std::endl;
    std::getline(std::cin, inventory_item);

    if (ModifyInventory::inventoryInDatabase(inventory_item))
    {
        MainMenu::clearScreen();
        MainMenu::header(header_content);
        std::cout << 
        "This item is already in the database." << std::endl <<
        "Is this the item you were looking for?" << std::endl <<
        "1.\tYes" << std::endl <<
        "2.\tNo" << std::endl <<
        MainMenu::SECTION_BREAK;
        std::cin >> choice;
        while (std::cin.fail()|| !(choice == 1 || choice == 2))
        {
            std::cout << "Invalid entry." << std::endl;
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cin >> choice;
        };
        if (choice == 1) { return ModifyInventory::readInventoryFromDatabase(inventory_item); } // if entered item is desired, read from file and return it
        else { ModifyInventory::createInventoryFromUser(); } //otherwise try again
    }
    
    
    while (true) // item count
    {
        MainMenu::clearScreen();
        MainMenu::header(header_content);
        std::cout <<
        "Enter the current count of the inventory item:" << std::endl;
        std::cin >> item_count;
        if (std::cin.fail() || item_count < 0) 
        {
            std::cout << "Invalid input; please, enter a non-negative number." << std::endl;
            std::cin.clear();
            std::cin.ignore(INT_MAX,'\n');
        }
        else { break; }
    }
    std::cin.ignore(INT_MAX,'\n');

    while (true) // item threshold
    {
        MainMenu::clearScreen();
        MainMenu::header(header_content);
        std::cout <<
        "Enter the fewest allowed of the inventory item:" << std::endl;
        std::cin >> item_threshold;
        if (std::cin.fail() || item_threshold < 0) 
        {
            std::cout << "Invalid input; please, enter a non-negative number." << std::endl;
            std::cin.clear();
            std::cin.ignore(INT_MAX,'\n');
        }
        else { break; }
    }
    std::cin.ignore(INT_MAX,'\n');

    Inventory new_inventory(inventory_item, item_count, item_threshold);
    ModifyInventory::writeInventoryToDatabase(new_inventory);
    return new_inventory;
}

Inventory ModifyInventory::createInventoryFromUser(std::string entered_item_name) 
{
    std::string header_content = "Inventory Creation Menu";
    unsigned int item_count, item_threshold;
    short choice;

    MainMenu::clearScreen();
    MainMenu::header(header_content);
    std::cout <<
    "The entered inventory item name is:" << std::endl <<
    entered_item_name << std::endl <<
    MainMenu::SECTION_BREAK;
    
    while (true) // item count
    {
        MainMenu::clearScreen();
        MainMenu::header(header_content);
        std::cout <<
        "Enter the current count of the inventory item:" << std::endl;
        std::cin >> item_count;
        if (std::cin.fail() || item_count < 0) 
        {
            std::cout << "Invalid input; please, enter a non-negative number." << std::endl;
            std::cin.clear();
            std::cin.ignore(INT_MAX,'\n');
        }
        else { break; }
    }
    std::cin.ignore(INT_MAX,'\n');

    while (true) // item threshold
    {
        MainMenu::clearScreen();
        MainMenu::header(header_content);
        std::cout <<
        "Enter the fewest allowed of the inventory item:" << std::endl;
        std::cin >> item_threshold;
        if (std::cin.fail() || item_threshold < 0) 
        {
            std::cout << "Invalid input; please, enter a non-negative number." << std::endl;
            std::cin.clear();
            std::cin.ignore(INT_MAX,'\n');
        }
        else if (std::cin.fail() || item_count < item_threshold) 
        {
            std::cout << "Threshold cannot be less than the current count." << std::endl;
            std::cin.clear();
            std::cin.ignore(INT_MAX,'\n');
        }
        else { break; }
    }
    std::cin.ignore(INT_MAX,'\n');

    Inventory new_inventory(entered_item_name, item_count, item_threshold);
    ModifyInventory::writeInventoryToDatabase(new_inventory);
    return new_inventory;
}