#include "control/dataManipulation.h"
//******************************************************************************************************************
//                                          USER DATA MANIPULATION
//******************************************************************************************************************
// User dataManipulation::getUserFromFile ( std::string the_login)
// {
//     std::string user_login = the_login;
//     std::string name;

//     std::ifstream patient_file;

//     patient_file.open("./database/users.txt", std::ios::in);

//     User our_user;

//     // patient_file.read((char*)&our_user, sizeof(our_user));

//     // while (!patient_file.eof())
//     // {
//     //     if(our_user.getUserLogin() == user_login)
//     //     {
//     //         user.setUserLogin(user_login);
//     //         user.setUserPassword(our_user.getUserPassword()); 
//     //         user.setDateOfBirth(our_user.getDateOfBirth());
//     //         user.setFirstName(our_user.getFirstName());
//     //         user.setGender(our_user.getGender());
//     //         user.setLastName(our_user.getLastName());

//     //     }
//     //     patient_file.read((char*)&our_user, sizeof(our_user));
//     // }
//     patient_file.close(); 
// }


// bool dataManipulation::checkForUeser(std::string user_login)
// {
//     bool userIsFound = false;
//     std::ifstream patient_file;

//     User our_user;

//     patient_file.open("./database/users.txt", std::ios::in);
//     patient_file.read((char*)&our_user, sizeof(our_user));

//     while (!patient_file.eof()){
//         if(our_user.getUserLogin() == user_login)
//         {
//             userIsFound = true;
//             break;
//         }
//         patient_file.read((char*)&our_user, sizeof(our_user));
//     }

//     patient_file.close();
//     return userIsFound;
// }
//******************************************************************************************************************
//                                          INVENTORY DATA MANIPULATION
//******************************************************************************************************************
// checks to see if the item requested in in the file
bool dataManipulation::checkForItem(std::string item)
{
    bool itemIsFound = false;
    std::ifstream inventory_file;

    Inventory our_item;

    inventory_file.open("./database/inventory.txt", std::ios::in);

    if(inventory_file)
    {
        
     inventory_file.read((char*)&our_item, sizeof(our_item));

        while (!inventory_file.eof())
        {
            if(our_item.getItemName() == item)
            {
                itemIsFound = true;
                break;
            }
            inventory_file.read((char*)&our_item, sizeof(our_item));
        }
    }
    else {
        std::cout << "File does not exist\n\n";
    }
    inventory_file.close();
    return itemIsFound;
}
// appends an item to the existing file
void dataManipulation::wtireToInventoryFile(Inventory item)
{
    std::ofstream inventory_file;

    inventory_file.open("./database/inventory.txt", std::ios::app);

    // if there is no file, create one and add the item you want to add to the file
    if(!inventory_file.is_open())
     {
        std:: ofstream inventory_file("./database/inventory.txt");
        inventory_file.write((char*)&item, sizeof(item));
        std::cout << "file is not open\n";
     }

     else
     {
        inventory_file.write((char*)&item, sizeof(item));
        std::cout << "file is open\n";
     }

    inventory_file.close();
}

// Inventory dataManipulation::getInventoryFromFile(std::string item)
// {
//     std::ifstream inventory_file;
//     bool item_found = false;
    
//     Inventory list;
//     Inventory empty;

//     inventory_file.open("./database/inventory.txt", std::ios::in);

//     inventory_file.read((char*)&list, sizeof(list));

//     while (!inventory_file.eof())
//         {
//             if(list.getItemName() == item)
//             {
//                 item_found = true;
//                 break;
//             }
//             inventory_file.read((char*)&list, sizeof(list));
//         }
//         inventory_file.close();

//     if (item_found)
//     {
//         return list;
//     }
//     else{
//         std::cout << "\n Item not found\n";
//         return empty;
//     }

// }
// creates a vector of Inventory items from the file
std::vector<Inventory> dataManipulation::createList()
{
    std::vector<Inventory> inventory_list;
    std::ifstream inventory_file;

    Inventory list;

    inventory_file.open("./database/inventory.txt", std::ios::in);

    inventory_file.read((char*)&list, sizeof(list));

    while (!inventory_file.eof())
        {
            inventory_list.push_back(list);
            inventory_file.read((char*)&list, sizeof(list));
        }
        inventory_file.close();

        return inventory_list;

}
// Overwtires the existing file using a vector of Inventory items
void dataManipulation::writeUpdatedItemToFile(std::vector<Inventory> inventory_list)
{
    std::fstream inventory_file;

    inventory_file.open("./database/inventory.txt", std::fstream::out);

    for (int i = 0; i <inventory_list.size(); i++)
    {
        inventory_file.write((char*)&inventory_list[i], sizeof(inventory_list[i]));
    }
    
    inventory_file.close();

}