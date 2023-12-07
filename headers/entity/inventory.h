#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
class Inventory
{
    private:
        std::string item_name;
        unsigned int item_count;
        unsigned int item_threshold;
    public:
        // Constructors
        Inventory();
        Inventory(std::string item_name, unsigned int item_count, unsigned int item_threshold);
        
        // Setters
        void setItemName(std::string);
        void setItemCount(unsigned int);
        void setItemThreshold(unsigned int);
        
        // Getters
        std::string getItemName() const;
        unsigned int getItemCount() const;
        unsigned int getItemThreshold() const;

};
std::ostream& operator<<(std::ostream& os, const Inventory& inventory);
std::ostream& operator<<(std::ostream& os, const std::vector<Inventory>& items);
std::istream& operator>>(std::istream& is, Inventory& inventory);
std::istream& operator>>(std::istream& is, std::vector<Inventory>& items);