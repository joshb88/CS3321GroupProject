#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include "entity/user.h"
#include "entity/inventory.h"

class dataManipulation
{
    public:
        // Inventory stuff
        bool checkForItem(std::string);
        void wtireToInventoryFile(Inventory);
        Inventory getInventoryFromFile(std::string);
        std::vector<Inventory> createList();
        void writeUpdatedItemToFile (std::vector<Inventory>);
};

