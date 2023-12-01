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
            std::cout << "Please select the number option from the following. Type your number choice.\n\n";
            std::cout <<
            "1. Add Item\n" <<
            "2. Modify Inventory Item\n" <<
            "3. View Inventory List\n" <<
            "4. Exit\n";
            std::cin >> user_input;
        }
        break;
        case '1': // add and inventory item
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

        case '2': // modify and inventory item
        {
            std::string item_name;
            char selection = ' ';
            std::string counts;
            std::string thresh;
            dataManipulation data;


            std::cout << "\n\nWhat would you like to modify? Type your number choice.\n"
            << "1. Item Count\n" <<
            "2. Item Threshold\n" << 
            "3. Both Item Count and Item Threshold\n" << 
            "4. Exit\n";

            std::cin >> selection;

            switch(selection)
            {
                case '1': // Modify item count
                {
                    std::cout << "Type the name of the item you would like to change\n\n";
                    item.printInventory();
                    std::cin >> item_name;

                    if(data.checkForItem(item_name))
                    {
                        std::cout << "\nNew Item Counts : \t";
                        std::cin >> counts;
                        item.modifyItemCount(item_name, stoi(counts));
                        user_input = '2';
                    }
                    else{
                        std::cout << "\nItem invalid. Please try again.";
                        selection = '1';
                    }
                }
                break;
                case '2': // Modify item threshold
                {
                    std::cout << "Type the name of the item you would like to change\n\n";
                    item.printInventory();
                    std::cin >> item_name;

                    if (data.checkForItem(item_name))
                    {
                        std::cout << "\nNew Item Threshold : \t";
                        std::cin >> thresh;
                        item.modifyItemThresh(item_name, stoi(thresh));
                        user_input = '2';
                    }
                    else{
                        std::cout << "\nItem invalid. Please try again.";
                        selection = '2';
                    }
                }
                break;
                case '3': // Modify both item count and item threshold
                {
                    std::cout << "Type the name of the item you would like to change\n\n";
                    item.printInventory();
                    std::cin >> item_name;

                    if (data.checkForItem(item_name))
                    {
                         std::cout << "\nNew Item Counts : \t";
                        std::cin >> counts;
                        std::cout << "\nNew Item Threshold : \t";
                        std::cin >> thresh;
                        item.modifyBoth(item_name, stoi(counts), stoi(thresh));
                        user_input = '2';
                    }
                    else
                    {
                        std::cout << "\nItem invalid. Please try again.";
                        selection = '3';
                    }
                }
                break;
                case '4': // Exit
                {
                    user_input = 'H';
                }
                break;
                default:
                {
                    std::cin.cler(); // clear input error flag
                    std::cin.ignore(100, '\n'); // clear cin buffer
                    std::cout << "\nOption not valid. Please try again\n";
                    user_input = '2';
                }
            }
            
        }
        break;

        case '3': // view inventory list
        {
            item.printInventory();

            user_input = 'H';
        }
        break;

        case '4': // Exit
        {
            std::cout << "You are now exiting the menu\n";
            quit = true;

        }
        break;

        default: // invalid input
        {
            std::cin.clear(); // clear error input flag
            std::cin.ignore(100,'n'); // clear cin buffer
            std::cout << "Invalid selection, please try agian\n\n";
            user_input = 'H';
        }
    }
}
}
