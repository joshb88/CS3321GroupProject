#include "control/modifyInventory.h"

void modifyInventory::addItem(std::string name, int count, int thresh)
{
    dataManipulation data;

    if(!data.checkForItem(name))
    {
        Inventory item;
        item.setItemName(name);
        item.setItemCount(count);
        item.setItemThreshold(thresh);

        data.wtireToInventoryFile(item);
        std::cout << "\nItem Added Succesfully\n\n";
    }
    else
    {
        std::cout << "\nItem Already Exists\n\n";
    }
}
