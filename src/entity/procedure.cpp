#include "../../headers/entity/procedure.h"

// PROCEDURE CLASS
// Procedure Class Constructors
Procedure::Procedure() : procedure_name(""), cost(0.0), items_used() {}
Procedure::Procedure(std::string name, float cost, std::vector<Inventory>& items_used) : 
procedure_name(name), cost(cost), items_used(items_used) {}

// Procedure Class Setters
void Procedure::setProcedureName(std::string proc_name)
{
    procedure_name = proc_name;
}
void Procedure::setCost(float cost)
{
    this->cost = cost;
}
void Procedure::setItemsUsed(std::vector<Inventory>& items_used)
{
    this->items_used = items_used;
}

// Procedure Class Getters
std::string Procedure::getProcedureName() const
{
    return procedure_name;
}
float Procedure::getCost() const
{
    return cost;
}
const std::vector<Inventory>& Procedure::getItemsUsed() const
{
    return items_used;
}