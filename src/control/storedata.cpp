#include "control/storedata.h"

void StoreData::storeUser(User& user)
// {
//     std::fstream user_file;
//     user_file.open("./database/users.txt", std::ios::in | std::ios::out | std::ios::app | std::ios::ate);

//     if (user_file.is_open()) // Checks that the file opened correctly
//     {
//         // Write user data as a single line with a newline at the end
//         user_file << 
//             user.getUserLogin() << " " << 
//             user.getUserPassword() << " " << 
//             user.getLastName() << " " << 
//             user.getFirstName() << " " <<
//             user.getDateOfBirth() << " " <<
//             user.getGender() << " " << std::endl;

//         user_file.close();
//         std::cout << "User data written to file." << std::endl;
//     } 
//     else
//     {
//         std::cerr << "Failed to open the file for writing." << std::endl;
//     }
// }


{
    if (user.getUserLogin() != "") // Assume user's info isn't still default
    {
        std::fstream user_file;
        user_file.open("./database/users.txt", std::ios::in | std::ios::out | std::ios::app | std::ios::ate);

        if (user_file.is_open()) {
            std::string userLoginToCheck = user.getUserLogin();
            std::string line;
            bool userExists = false;

            // Read the file line by line
            while (std::getline(user_file, line)) {
                // Create a stringstream to parse the line
                std::istringstream iss(line);
                std::string firstToken;

                // Extract the first token (user login)
                if (iss >> firstToken) {
                    if (firstToken == userLoginToCheck) {
                        // User login exists in the file
                        userExists = true;
                        break; // No need to continue searching
                    }
                }
            }

            if (!userExists) {
                // Write user data as a single line with a newline at the end
                user_file << 
                    user.getUserLogin() << " " << 
                    user.getUserPassword() << " " << 
                    user.getLastName() << " " << 
                    user.getFirstName() << " " <<
                    user.getDateOfBirth() << " " <<
                    user.getGender() << " " << std::endl;

                std::cout << "User data written to file." << std::endl;
            } else {
                std::cout << "User login already exists in the file." << std::endl;
            }

            user_file.close();
        } else {
            std::cerr << "Failed to open the file for writing." << std::endl;
        }
    } 
    else {
        std::cerr << "Invalid user data. Skipping the write operation." << std::endl;
    }
}