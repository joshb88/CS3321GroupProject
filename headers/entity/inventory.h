#pragma once
#include <string>

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