#include <sstream>
#include "control/dataManipulation.h"
#include "entity/patient.h"
#include "entity/staff.h"
//******************************************************************************************************************
//                                          USER DATA MANIPULATION
//******************************************************************************************************************

bool dataManipulation::userInDatabase(User& user) 
{
    std::fstream user_file;
    user_file.open("./database/users.txt", std::ios::in);
    std::string userToCheck = user.getUserLogin();
    
    if (user_file.is_open()) {
        std::string line;

        while (std::getline(user_file, line)) {
            std::istringstream iss(line);
            std::string token;

            while (std::getline(iss, token, ',')) {
                if (token == userToCheck) {
                    std::cout << userToCheck << " already exists in database." << std::endl;
                    user_file.close();
                    return true;
                }
            }
        }
    }

    user_file.close();
    return false;
}

bool dataManipulation::userInDatabase(const std::string& user_login)
{
    std::fstream user_file;
    user_file.open("./database/users.txt", std::ios::in);
    std::string line;

    if (user_file.is_open()) // as long as the database file is open,
    {
        while (std::getline(user_file, line)) // loop through each line in the file
        {
            std::istringstream iss(line); // create a string stream to iterate through each token (word)
            std::string token;

            // Split the line using commas as delimiters
            while (std::getline(iss, token, ','))
            {
                // Check if the current token is equal to the provided user login
                if (token == user_login)
                {
                    user_file.close();
                    return true;
                }
            }
        }
    }
    user_file.close();
    return false;
}

void dataManipulation::addUserToFile(User& user) 
{
   
    std::fstream user_file;
    user_file.open("./database/users.txt", std::ios::out | std::ios::app);
    if (!userInDatabase(user)) {
        if (user_file.is_open()) {
            
            Patient* patientPtr = dynamic_cast<Patient*>(&user);
            Staff* staffPtr = dynamic_cast<Staff*>(&user);
            if (patientPtr) // signify the stored user as a patient
            {
                user_file << 1 << ",";
            }
            else if(staffPtr) // signify the stored user as a patient
            {
                user_file << 2 << ",";
            }
            else
            {
                user_file << 0 << ",";
            }
            
            
            // Write common user data
            user_file << 
                user.getUserLogin() << "," << 
                user.getUserPassword() << "," << 
                user.getLastName() << "," << 
                user.getFirstName() << "," <<
                user.getDateOfBirth() << "," <<
                user.getGender();

            // Check if the user is a Patient and append additional data
            if (patientPtr) {
                user_file << "," << 
                patientPtr->getHasInsurance();
                if (patientPtr->getHasInsurance()) 
                {
                    user_file << "," << patientPtr->getInsuranceProvider();
                }

                // check that room as been assigned or fatal error
                if (patientPtr->getRoom() != nullptr)
                {
                    user_file << "," <<
                    patientPtr->getRoom()->getRoomAvailability() << "," <<
                    patientPtr->getRoom()->getRoomFloorNumber() << "," <<
                    patientPtr->getRoom()->getRoomNumber();
                }
                else { std::cout << "Room isn't set; will not store." << std::endl; }
            }

            // Check if the user is a Staff and append additional data
            if (staffPtr) {
                user_file << "," << 
                staffPtr->getIdNumber() << "," <<
                staffPtr->getClearanceLevel() << "," <<
                staffPtr->getJobTitle() << "," <<
                staffPtr->getDateOfHire();
            }

            user_file << std::endl;  // Add a newline at the end
            user_file.close();
            std::cout << "User data written to file." << std::endl;
        }
    }
}




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