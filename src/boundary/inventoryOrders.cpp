#include "boundary/inventoryOrders.h"

void inventoryOrders::compileAndPlaceOrder(){
    
    std::vector<Inventory> inventoryOrder;

    //Compile a list of items with less than 500 count
    for (const Inventory& item : my_inventory){
        if (item.getItemCount() < 500) {
            inventoryOrder.push_back(item);
        }
    }

    //Check if order can be placed, if so place it
    if (!inventoryOrder.empty()){
        std::srand(std::time(nullptr)); //Creates seed for num generator
        int orderNumber = std::rand(); //Generates random order number

        //Display order info
        std::cout << "Order #" << orderNumber << " has been placed.\n";
    }
    else{
        std::cout << "No items require ordering.\n";
    }
    }
}