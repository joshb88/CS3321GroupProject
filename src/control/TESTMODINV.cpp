#include "control/TESTMODINV.h"
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