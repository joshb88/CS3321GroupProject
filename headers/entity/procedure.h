#pragma once
#include <string>
#include <vector>
#include "inventory.h"

class Procedure
{
    private:
        std::string procedure_name;
        float cost;
        std::vector<Inventory> items_used;
    public:
        Procedure();
        Procedure(std::string, float, std::vector<Inventory>&);
        void setProcedureName(std::string);
        void setCost(float);
        void setItemsUsed(std::vector<Inventory>&);
        // void addItemUsed(Inventory&);        // these operations will be
        // void removeItemUsed(Inventory&);     // done by the control class
        std::string getProcedureName() const;
        float getCost() const;
        const std::vector<Inventory>& getItemsUsed() const;
};
