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
        user_file.open("./database/users.txt", std::ios::in | std::ios::out | std::ios::app); // Open database file

        if (user_file.is_open() && user_file.good()) { // If the file opened correctly,
                              
            std::string userLoginToCheck = user.getUserLogin();
            std::string line;
            bool userExists = false;

                                                                    
            while (std::getline(user_file, line)) {                 // Read the file line by line
                user_file.seekg(0,std::ios::beg);
                std::istringstream iss(line);                       // Create a stringstream to parse the line
                std::string firstToken;                             // and a string variable for the first word in each line (user login).
    
                if (iss >> firstToken) {                            // If the line has a first token (not an empty line) and
                    std::cout << firstToken;
                    if (firstToken == userLoginToCheck) {           // the User login provided is the same as the line,
                        userExists = true;                          // Signify that the User does exist and
                        break;                                      // stop searching.
                    }
                }
            }

            if (!userExists && user_file.is_open()) {               // If the User login does not exist in the file,
                user_file.seekp(0,std::ios::end);
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