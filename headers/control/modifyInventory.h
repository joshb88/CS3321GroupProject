#pragma once
#include <string>
#include "entity/inventory.h"
#include "control/dataManipulation.h"

class modifyInventory
{
private:
    /* data */
public:
    void addItem(std::string, int, int);
    void printInventory();
    void modifyItemCount(std::string, int);
    void modifyItemThresh(std::string, int);
    void modifyBoth(std::string, int, int);

};
