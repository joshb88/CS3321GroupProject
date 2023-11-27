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

void modifyInventory::printInventory()
{
    dataManipulation data;
    std::string item_name;
    int item_count;
    int item_thresh;
    std::vector<Inventory> inventory_list = data.createList();

    for(int i = 0;i < inventory_list.size(); i++)
    {
        item_name = inventory_list[i].getItemName();
        item_count = inventory_list[i].getItemCount();
        item_thresh = inventory_list[i].getItemThreshold();

        std::cout << item_name 
        << "\t\t" << item_count
        << "\t\t" << item_thresh << "\n\n"; 

    }
}

void modifyInventory::modifyItemCount(std::string item, int count)
{
    dataManipulation data;
    std::string counts;
    std::vector<Inventory> my_inventory;

    my_inventory = data.createList();

    for (int i = 0; i < my_inventory.size(); i++)
    {
        if(my_inventory[i].getItemName() == item)
        {
            my_inventory[i].setItemCount(count);
        }
    }

    data.writeUpdatedItemToFile(my_inventory);
}
void modifyInventory::modifyItemThresh(std::string item, int thresh)
{
    dataManipulation data;
    std::string counts;
    std::vector<Inventory> my_inventory;

    my_inventory = data.createList();

    for (int i = 0; i < my_inventory.size(); i++)
    {
        if(my_inventory[i].getItemName() == item)
        {
            my_inventory[i].setItemThreshold(thresh);
        }
    }

    data.writeUpdatedItemToFile(my_inventory);
}
void modifyInventory::modifyBoth(std::string item, int count, int thresh)
{
    dataManipulation data;
    std::string counts;
    std::vector<Inventory> my_inventory;

    my_inventory = data.createList();

    for (int i = 0; i < my_inventory.size(); i++)
    {
        if(my_inventory[i].getItemName() == item)
        {
            my_inventory[i].setItemCount(count);
            my_inventory[i].setItemThreshold(thresh);
        }
    }

    data.writeUpdatedItemToFile(my_inventory);
}