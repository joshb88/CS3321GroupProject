#include <sstream>
#include <memory>
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
            if (patientPtr) 
            {
                user_file << "," << 
                patientPtr->getHasInsurance()<< "," << 
                patientPtr->getInsuranceProvider()<< "," << 
                patientPtr->getHasRoom();

                // check that room as been assigned or fatal error
                if (!(patientPtr->getHasRoom())) { std::cout << "Room not assigned; set to placeholder." << std::endl; }
                user_file << "," <<
                patientPtr->getRoom().getRoomAvailability() << "," <<
                patientPtr->getRoom().getRoomFloorNumber() << "," <<
                patientPtr->getRoom().getRoomNumber();
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

std::unique_ptr<User> dataManipulation::getUserFromFile(const std::string& username) 
{
    std::fstream file;
    file.open("./database/users.txt", std::ios::in);
    
    std::string line, token;

    while (std::getline(file, line, '\n'))
    {
        User read_user;
        std::string account_type;
        std::istringstream iss(line);
        
        std::getline(iss, account_type, ','); // store first token as account_type
        std::getline(iss, token, ','); // store second token as token

        if (token == username) 
        {   

            read_user.setUserLogin(username);

            std::string password;
            std::getline(iss, password, ',');
            read_user.setUserPassword(password);

            std::string lastName;
            std::getline(iss, lastName, ',');
            read_user.setLastName(lastName);

            std::string firstName;
            std::getline(iss, firstName, ',');
            read_user.setFirstName(firstName);

            std::string birthdayStr;
            std::getline(iss, birthdayStr, ',');
            read_user.setDateOfBirth(std::stoi(birthdayStr));

            std::string genderStr;
            std::getline(iss, genderStr, ',');
            read_user.setGender(genderStr[0]);

            if (account_type == "1") // Assuming account_type 1 corresponds to "patient"
            {
                Patient read_patient(read_user);

                std::string hasInsuranceStr;
                std::getline(iss, hasInsuranceStr, ',');
                bool hasInsurance = (hasInsuranceStr == "1");
                read_patient.setHasInsurance(hasInsurance);

                std::string provider;
                std::getline(iss, provider, ',');
                read_patient.setInsuranceProvider(provider);
                

                std::string hasRoomStr;
                std::getline(iss, hasRoomStr, ',');
                read_patient.setHasRoom(hasInsuranceStr == "1");
                
        
                std::string roomAvailStr;
                std::getline(iss, roomAvailStr, ',');
                read_patient.getRoom().setRoomAvailability(!(read_patient.getHasRoom()));
                

                std::string roomFloorStr;
                std::getline(iss, roomFloorStr, ',');
                read_patient.getRoom().setRoomFloorNumber(std::stoi(roomFloorStr));

                std::string roomNumberStr;
                std::getline(iss, roomNumberStr, ',');
                read_patient.getRoom().setRoomNumber(std::stoi(roomNumberStr));

                return std::make_unique<Patient>(read_patient);
            }
            else if (account_type == "2") // Assuming account_type 1 corresponds to "staff"
            {
                Staff read_staff(read_user);
                
                std::string idNumberStr;
                std::getline(iss, idNumberStr, ',');
                read_staff.setIdNumber(std::stoi(idNumberStr));

                std::string clearanceStr;
                std::getline(iss, clearanceStr, ',');
                read_staff.setClearanceLevel(std::stoi(clearanceStr));

                std::string jobTitleStr;
                std::getline(iss, jobTitleStr, ',');
                read_staff.setJobTitle(jobTitleStr);

                std::string hireDateStr;
                std::getline(iss, hireDateStr, ',');
                read_staff.setClearanceLevel(std::stoi(hireDateStr));

                return std::make_unique<Staff>(read_staff);
                
            }
        }
    }

    file.close(); // Close the file before returning a default-constructed User object
    return nullptr;
}

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