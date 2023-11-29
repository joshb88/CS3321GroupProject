#include "control/LoginVerification.h"

bool LoginVerification::userInDatabase(User& user)
{
    std::fstream user_file;
    user_file.open("./database/users.txt", std::ios::in);
    std::string userToCheck = user.getUserLogin();
    std::string passToCheck = user.getUserPassword();
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
                    //std::cout << userToCheck << " already exists in database." << std::endl;
                    return true;
                }
            }
        }
    }
    user_file.close();
    return false;    
};

bool LoginVerification::userInDatabase(const std::string& first_name, const std::string& last_name)
{
    std::fstream user_file;
    user_file.open("./database/users.txt", std::ios::in);
    std::string first_token;
    

    if (user_file.is_open()) // as long as the database file is open,
    {
        std::string line;

        while (std::getline(user_file, line)) // loop through each line in the file
        {
            std::istringstream iss(line); // create a string stream to iterate through each token (word)
            if (iss >> first_token)       // make the first token the database entry (user login)
            {
                // Assuming the user data in the file is organized like "userLogin userPassword firstName lastName ..."
                std::string userLogin, userPassword, firstName, lastName;
                iss >> userLogin >> userPassword >> firstName >> lastName;

                if (firstName == first_name && lastName == last_name)
                {
                    // User with matching credentials found in the database
                    return true;
                }
            }
        }
    }
    user_file.close();
    return false;
}