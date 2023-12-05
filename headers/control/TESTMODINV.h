#include "entity/procedure.h"
#include "entity/inventory.h"
#include <string>
#include <vector>

class ModifyInventory
{
    public:
        static bool inventoryInDatabase(Inventory& inventory);
        static bool inventoryInDatabase(std::string& inventory_name);
        static void writeInventoryToDatabase(Inventory& inventory);
        static Inventory readInventoryFromDatabase(const std::string& inventory_name);
        //static void changeinventory(inventory& inventory);
};