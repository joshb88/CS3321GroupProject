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
        user_file.open("./database/users.txt", std::ios::in | std::ios::out | std::ios::app | std::ios::ate); // Open database file

        if (user_file.is_open()) {                                  // If the file opened correctly,
            std::string userLoginToCheck = user.getUserLogin();
            std::string line;
            bool userExists = false;

                                                                    
            while (std::getline(user_file, line)) {                 // Read the file line by line
                std::istringstream iss(line);                       // Create a stringstream to parse the line
                std::string firstToken;                             // and a string variable for the first word (user login)

                if (iss >> firstToken) {
                    if (firstToken == userLoginToCheck) {           // If the User login exists in the file,
                        userExists = true;                          // Signify that it does exists and
                        break;                                      // stop searching.
                    }
                }
            }

            if (!userExists) {                                      // If the User login does not exist in the file,
                user_file <<                                        // write user data as a single line with a newline at the end
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
            user_file.flush();
            user_file.close();
        } else {
            std::cerr << "Failed to open the file for writing." << std::endl;
        }
    } 
    else {
        std::cerr << "Invalid user data. Skipping the write operation." << std::endl;
    }
}