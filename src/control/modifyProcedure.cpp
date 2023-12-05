#include "boundary/MainMenu.h"
#include "control/modifyProcedure.h"
#include "control/TESTMODINV.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

bool ModifyProcedure::procedureInDatabase(Procedure& procedure)
{
    std::fstream procedure_file;
    std::string line;
    procedure_file.open("./database/procedures.txt", std::ios::in);

    if(procedure_file.is_open())
    {
        while (std::getline(procedure_file, line)) // loop through each line in the file
        {
            std::istringstream iss(line); // create a string stream to iterate through each token (word)
            std::string token;

            // Read the first token and (more importantly) the second token.
            std::getline(iss, token, ',');

            // Check if the second token is equal to the provided user login
            if (token == procedure.getProcedureName())
            {
                procedure_file.close();
                return true;
            }
        }
    }
    procedure_file.close();
    return false;
}

bool ModifyProcedure::procedureInDatabase(std::string& procedure)
{
    std::fstream procedure_file;
    std::string line;
    procedure_file.open("./database/procedures.txt", std::ios::in);

    if(procedure_file.is_open())
    {
        while (std::getline(procedure_file, line)) // loop through each line in the file
        {
            std::istringstream iss(line); // create a string stream to iterate through each token (word)
            std::string token;

            // Read the first token and (more importantly) the second token.
            std::getline(iss, token, ',');

            // Check if the second token is equal to the provided user login
            if (token == procedure)
            {
                procedure_file.close();
                return true;
            }
        }
    }
    procedure_file.close();
    return false;
}

void ModifyProcedure::writeProcedureToDatabase(Procedure& procedure)
{
    std::fstream procedure_file;
    procedure_file.open("./database/procedures.txt", std::ios::app);
    if(procedure_file.is_open())
    {
        if(!(ModifyProcedure::procedureInDatabase(procedure)))
        {
            procedure_file << 
            procedure.getProcedureName() << ',' <<
            procedure.getCost() << ',' <<
            serializeItemsUsed(procedure.getItemsUsed()) << std::endl;
        }
        else
        {
            std::cout << "\nItem Already Exists\n\n";
        }
    }
}
Procedure ModifyProcedure::readProcedureFromDatabase(const std::string& procedure_name)
{
    std::fstream procedure_file;
    procedure_file.open("./database/procedures.txt", std::ios::in);

    if (procedure_file.is_open())
    {
        std::string line;
        while (std::getline(procedure_file, line))
        {
            std::istringstream iss(line);
            std::string token;

            // Read the first token (procedure name)
            std::getline(iss, token, ',');

            if (token == procedure_name)
            {
                // If the procedure name matches, extract other information
                float cost;
                std::vector<Inventory> itemsUsed;

                // Read the cost
                std::getline(iss, token, ',');
                cost = std::stof(token);

                // Read the serialized itemsUsed
                std::getline(iss, token, ',');
                itemsUsed = deserializeItemsUsed(token);

                // Create and return a Procedure object
                return Procedure(procedure_name, cost, itemsUsed);
            }
        }

        std::cout << "\nProcedure Not Found\n\n";
    }
    else
    {
        std::cout << "\nError opening the file\n\n";
    }

    // Return a default-constructed Procedure if not found or an error occurred
    return Procedure();
}
std::string ModifyProcedure::serializeItemsUsed(const std::vector<Inventory>& itemsUsed)
{
    std::string serializedList;

    for (const Inventory& item : itemsUsed)
    {
        serializedList += item.getItemName() + "-" +
                          std::to_string(item.getItemCount()) + "-" +
                          std::to_string(item.getItemThreshold()) + ";";
    }

    // Remove the trailing semicolon if the list is not empty
    if (!serializedList.empty())
    {
        serializedList.pop_back();
    }

    return serializedList;
}
std::vector<Inventory> ModifyProcedure::deserializeItemsUsed(const std::string& serializedList)
{
    std::vector<Inventory> itemsUsed;

    std::istringstream iss(serializedList);
    std::string itemString;

    while (std::getline(iss, itemString, ';'))
    {
        std::istringstream itemIss(itemString);
        std::string itemName, itemCount, itemThreshold;

        // Read item information from hyphenated list
        std::getline(itemIss, itemName, '-');
        std::getline(itemIss, itemCount, '-');
        std::getline(itemIss, itemThreshold, '-');

        // Convert string values to appropriate types
        unsigned int count = std::stoi(itemCount);
        unsigned int threshold = std::stoi(itemThreshold);

        // Create Inventory object and add to the vector
        itemsUsed.push_back(Inventory(itemName, count, threshold));
    }

    return itemsUsed;
}
Procedure ModifyProcedure::createProcedureFromUser() 
{
    std::string proc_name, inventory_item, header_content = "Procedure Creation Menu";
    float proc_cost;
    std::vector<Inventory> item_list;
    short choice;
    
    MainMenu::clearScreen();
    MainMenu::header(header_content);
    std::cout << 
    "Enter a name for the procedure:" << std::endl;
    std::getline(std::cin, proc_name);

    if (ModifyProcedure::procedureInDatabase(inventory_item))
    {
        MainMenu::clearScreen();
        MainMenu::header(header_content);
        std::cout << 
        "This procedure is already in the database." << std::endl <<
        "Is this the procedure you were looking for?" << std::endl <<
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
        if (choice == 1) { return ModifyProcedure::readProcedureFromDatabase(inventory_item); } // if entered item is desired, read from file and return it
        else { ModifyProcedure::createProcedureFromUser(); } //otherwise try again
    }

    while (true)
    {
        MainMenu::clearScreen();
        MainMenu::header(header_content);
        std::cout <<
        "Enter the cost for the procedure:" << std::endl;
        std::cin >> proc_cost;
        if (std::cin.fail() || proc_cost < 0) 
        {
            std::cout << "Invalid input; please, enter a non-negative number." << std::endl;
            std::cin.clear();
            std::cin.ignore(INT_MAX,'\n');
        }
        else { break; }
    }
    std::cin.ignore(INT_MAX,'\n');  //getline comes next, have to clear '\n'

    do
    {
        MainMenu::clearScreen();
        MainMenu::header(header_content);
        std::cout <<
        "Enter the an inventory item for the procedure:" << std::endl;
        std::getline(std::cin, inventory_item);

        if (ModifyInventory::inventoryInDatabase(inventory_item))
        {
            Inventory added_inventory = ModifyInventory::readInventoryFromDatabase(inventory_item);
            item_list.push_back(added_inventory);
            std::cout << "Added " << added_inventory.getItemName() << " to item list." << std::endl;
        }
        else
        {
            std::cout << "Item was not found in database; creating a new item to store." << std::endl;
            // Item entered not found
            Inventory created_inventory = ModifyInventory::createInventoryFromUser(inventory_item);
            item_list.push_back(created_inventory);
            std::cout << "Added " << created_inventory.getItemName() << " to item list." << std::endl;
        }
        std::cout << MainMenu::SECTION_BREAK <<
        "Are there more items?" << std::endl <<
        "1.\tYes" << std::endl <<
        "2.\tNo" << std::endl <<
        MainMenu::SECTION_BREAK; 
        std::cin >> choice;
        while (!(choice == 1 || choice == 2))
        {
            std::cout << "Invalid Entry; Enter Again:" << std::endl; 
            std::cin.clear();
            std::cin.ignore(INT_MAX,'\n');
        };
    } 
    while (choice != 2);

    Procedure new_procedure(proc_name, proc_cost, item_list);
    return new_procedure;
}