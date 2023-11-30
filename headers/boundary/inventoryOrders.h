#ifndef INVENTORY_ORDERS_H
 #define INVENTORY_ORDERS_H

 #include<iostream>
 #include<vector>
 #include<cstdlib>
 #include<ctime>
 #include "control/modifyInventory.h"

 class inventoryOrders{
private:
    modifyInventory inventoryModifier;
public:
    void compileAndPlaceOrder(const std::vector<Inventory>& my_inventory);
 };

 #endif // INVENTORY_ORDERS_H