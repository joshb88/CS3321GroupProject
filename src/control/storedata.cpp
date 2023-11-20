#include "control/storedata.h"

bool StoreData::userInDatabase(User& user)
{
    std::fstream user_file;
    user_file.open("./database/users.txt", std::ios::in);
    std::string userToCheck = user.getUserLogin();
    std::string first_token;
    
    if (user_file.is_open()) // as long as database file is open,
    {
        std::string line;
        
        while (std::getline(user_file, line))   //loop through each line in the file
        {
            std::istringstream iss(line);       // create a string stream to iterate through each token (word)
            if (iss >> first_token)             // make the first token the database entry (user login)
            {
                if (first_token == userToCheck) // is it the same as the provided?
                {
                    std::cout << userToCheck << " already exists in database." << std::endl;
                    return true;
                }
            }
        }
    }
    user_file.close();
    return false;    
}

// void StoreData::storeUser(User& user)
// {
//     std::fstream user_file;
//     user_file.open("./database/users.txt", std::ios::out | std::ios::app);
//     if (!userInDatabase(user))
//     {
//         if (user_file.is_open()) // Checks that the file opened correctly
//         {
//             // Write user data as a single line with a newline at the end
//             user_file << 
//                 user.getUserLogin() << " " << 
//                 user.getUserPassword() << " " << 
//                 user.getLastName() << " " << 
//                 user.getFirstName() << " " <<
//                 user.getDateOfBirth() << " " <<
//                 user.getGender() << " " << std::endl;
//             user_file.close();
//             std::cout << "User data written to file." << std::endl;
//         } 
//     }
// }

void StoreData::storeUser(User& user)
{
    std::fstream user_file;
    user_file.open("./database/users.txt", std::ios::out | std::ios::app);
    if (!userInDatabase(user)) {
        if (user_file.is_open()) {
            // Write common user data
            user_file << 
                user.getUserLogin() << " " << 
                user.getUserPassword() << " " << 
                user.getLastName() << " " << 
                user.getFirstName() << " " <<
                user.getDateOfBirth() << " " <<
                user.getGender();

            // Check if the user is a Patient and append additional data
            Patient* patientPtr = dynamic_cast<Patient*>(&user);
            if (patientPtr) {
                user_file << " " << 
                patientPtr->getHasInsurance() << " " <<
                patientPtr->getInsuranceProvider() << " ";

                if (patientPtr->getRoom().getRoomNumber() > 0)
                {
                    user_file << 
                    patientPtr->getRoom().getRoomAvailability() <<
                    patientPtr->getRoom().getRoomFloorNumber() <<
                    patientPtr->getRoom().getRoomNumber();
                }
            }

            user_file << " " << std::endl;  // Add a newline at the end
            user_file.close();
            std::cout << "User data written to file." << std::endl;
        }
    }
};