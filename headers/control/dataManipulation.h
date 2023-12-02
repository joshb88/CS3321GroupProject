#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "entity/user.h"
#include "entity/inventory.h"

class dataManipulation
{
private:
    /* data */
public:

    // user stuff
    static bool userInDatabase(User& user);
    static bool userInDatabase(const std::string& user_name);
    static void addUserToFile(User& user);
    User getUserFromFile(std::string);
    void modifyUserFromFile (User);

    // Inventory stuff
    bool checkForItem(std::string);
    void wtireToInventoryFile(Inventory);
    Inventory getInventoryFromFile(std::string);
    std::vector<Inventory> createList();
    void writeUpdatedItemToFile (std::vector<Inventory>);

};

