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

bool LoginVerification::userInDatabase(const std::string& user_login)
{
    std::fstream user_file;
    user_file.open("./database/users.txt", std::ios::in);
    std::string first_token;
    std::string second_token;
    

    if (user_file.is_open()) // as long as the database file is open,
    {
        std::string line;

        while (std::getline(user_file, line)) // loop through each line in the file
        {
            std::istringstream iss(line); // create a string stream to iterate through each token (word)
            if (iss >> first_token)
            {       // make the first token the database entry (user login) 
                if (first_token == user_login) // user found in database.
                {
                    return true;
                }
            }
        }
    }
    user_file.close();
    return false;
};

bool LoginVerification::checkPassword(User& user)
{
    std::fstream user_file;
    user_file.open("./database/users.txt", std::ios::in);
    std::string userToCheck = user.getUserLogin();
    std::string passToCheck = user.getUserPassword();
    std::string first_token;
    std::string second_token;
    
    if (user_file.is_open()) // as long as database file is open,
    {
        std::string line;
        
        while (std::getline(user_file, line))   //loop through each line in the file
        {
            std::istringstream iss(line);       // create a string stream to iterate through each token (word)
            if (iss >> first_token >> second_token)             // make the firstand second token the database entries (user login and second token)
            {
                if (first_token == userToCheck && second_token == passToCheck) // is it the same as the provided?
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

bool LoginVerification::checkPassword(const std::string& user_login, const std::string& user_password)
{
    std::fstream user_file;
    user_file.open("./database/users.txt", std::ios::in);
    std::string first_token;
    std::string second_token;
    

    if (user_file.is_open()) // as long as the database file is open,
    {
        std::string line;

        while (std::getline(user_file, line)) // loop through each line in the file
        {
            std::istringstream iss(line); // create a string stream to iterate through each token (word)
            if (iss >> first_token >> second_token)       // make the firstand second token the database entries (user login and second token)
            {
                if (first_token == user_login && second_token == user_password) // user found in database.
                {
                    return true;
                }
            }
        }
    }
    user_file.close();
    return false;
};