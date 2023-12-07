#include "entity/inventory.h"
#include "entity/procedure.h"
#include <iostream>
#include <sstream>

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
std::ostream& operator<<(std::ostream& os, const Procedure& procedure) 
{
    os << 
    procedure.getProcedureName() << ',' <<
    procedure.getCost() << ',' <<
    procedure.getItemsUsed();
    return os;
}
std::istream& operator>>(std::istream& is, Procedure& procedure)
{
    std::string name, cost;
    std::vector<Inventory> tempItems;

    // Read procedure name and cost
    std::getline(is, name, ',');
    std::getline(is, cost, ',');
    is >> tempItems;
    

    // Set values using setter functions
    procedure.setProcedureName(name);
    procedure.setCost(std::stof(cost));
    procedure.setItemsUsed(tempItems);

    return is;
}