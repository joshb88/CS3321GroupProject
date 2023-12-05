#include "entity/inventory.h"
#include <iostream>
#include <vector>

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

// Overload operator<< for Inventory class
std::ostream& operator<<(std::ostream& os, const Inventory& inventory)
{
    os << inventory.getItemName() << "-" << inventory.getItemCount() << "-" << inventory.getItemThreshold();
    return os;
}

// Overload operator<< for vector of Inventory objects
std::ostream& operator<<(std::ostream& os, const std::vector<Inventory>& items) {
    for (auto it = items.begin(); it != items.end(); ++it) 
    {
        os << *it;
        if (it != items.end() - 1) 
        {
            os << ";";
        }
    }
    return os;
}