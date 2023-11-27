#pragma once
#include <iostream>
#include <string>
#include "control/modifyInventory.h"


class inventoryMenu
{
private:
enum menu_choices
{
    add_item,
    modify_item, 
    view_inventory,
    exit_menu,
    home_menu
};

menu_choices convert(const std::string);

public:
    static void createInventoryMenu();
};