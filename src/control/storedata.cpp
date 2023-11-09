#include <fstream>
#include <iostream>
#include "control/storedata.h"

void StoreData::storeUser(User& user)
{
    std::fstream user_file;
    user_file.open("./database/users.txt", std::ios::in | std::ios::out | std::ios::app | std::ios::ate);

    if (user_file.is_open()) 
    {
        // Write user data as a single line with a newline at the end
        user_file << 
            user.getUserLogin() << " " << 
            user.getUserPassword() << " " << 
            user.getLastName() << " " << 
            user.getFirstName() << " " <<
            user.getDateOfBirth() << " " <<
            user.getGender() << std::endl;

        user_file.close();
        std::cout << "User data written to file." << std::endl;
    } 
    else
    {
        std::cerr << "Failed to open the file for writing." << std::endl;
    }
}