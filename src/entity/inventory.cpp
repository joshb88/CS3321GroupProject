#include "..\..\headers\entity\inventory.h"

// INVENTORY CLASS
// Inventory Class Constructors
Inventory::Inventory() : item_name(""), item_count(0), item_threshold(0) {}
Inventory::Inventory(std::string name, unsigned int count, unsigned int threshold)
{
    item_name = name;
    item_count = count;
    item_threshold = threshold;
}

// Inventory Class Setters
void Inventory::setItemName(std::string name)
{
    item_name = name;
}
void Inventory::setItemCount(unsigned int count)
{
    item_count = count;
}
void Inventory::setItemThreshold(unsigned int threshold)
{
    item_threshold = threshold;
}

// Inventory Class Getters
std::string Inventory::getItemName() const { return item_name; }
unsigned int Inventory::getItemCount() const { return item_count; }
unsigned int Inventory::getItemThreshold() const { return item_threshold; }