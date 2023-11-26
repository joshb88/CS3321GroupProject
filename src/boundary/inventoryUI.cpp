#include "boundary/inventoryUI.h"


void inventoryMenu::createInventoryMenu()
{
    char user_input = 'H';
    bool quit = false;
    menu_choices choices;
    modifyInventory item;

while(!quit)
{
    switch (user_input)
    {
        case 'H': // home menu
        {
            std::cout << "Please select the number option from the following" << std::endl <<std::endl;
            std::cout <<
            "1. Add Item\n" <<
            "2. Modify Item Count\n" <<
            "3. View Inventory List\n" <<
            "4. Exit\n";
            std::cin >> user_input;
        }
        break;
        case '1': // add and item
        {
            std::string item_name;
            std::string counts;
            std::string thresh;
            int item_count;
            int item_thresh;

            std::cout << "Enter item info\n";
            std::cout << "Item name : \t";
            std::cin >> item_name;
            std::cout << "\nItem quantity : \t";
            std::cin >> counts;
            std::cout << "\nItem threshold : \t";
            std::cin >> thresh;

            item_count = stoi(counts);
            item_thresh = stoi(thresh);
            item.addItem(item_name, item_count, item_thresh);

            user_input = 'H';
        }
        break;

        case '2': // modify and item
        {
            std::cout << "What item would you like to modify" << std::endl;
            user_input = 'H';
        }
        break;

        case '3': // view inventory list
        {
            std::cout << "This is the current inventory list" << std::endl;
            user_input = 'H';
        }
        break;

        case '4': // Exit
        {
            std::cout << "You are now exiting the menu" << std::endl;
            quit = true;

        }
        break;

        default: // invalid input
        {
            std::cout << "Invalid selection, please try agian" << std::endl << std::endl;
            user_input = 'H';
        }
    }
}
}
