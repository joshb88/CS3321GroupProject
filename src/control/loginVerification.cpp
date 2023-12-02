#include "control/LoginVerification.h"

bool LoginVerification::checkPassword(User& user) {
    std::fstream user_file;
    user_file.open("./database/users.txt", std::ios::in);
    std::string userToCheck = user.getUserLogin();
    std::string passToCheck = user.getUserPassword();
    std::string line;

    if (user_file.is_open()) // as long as the database file is open,
    {
        while (std::getline(user_file, line)) // loop through each line in the file
        {
            std::istringstream iss(line); // create a string stream to iterate through each token (word)
            std::string token;

            // Split the line using commas as delimiters
            if (std::getline(iss, token, ',') && token == userToCheck)
            {
                // Now, check the password (second token)
                if (std::getline(iss, token, ',') && token == passToCheck)
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

bool LoginVerification::checkPassword(const std::string& user_login, const std::string& user_password) {
    std::fstream user_file;
    user_file.open("./database/users.txt", std::ios::in);
    std::string line;

    if (user_file.is_open()) {
        while (std::getline(user_file, line)) {
            std::istringstream iss(line);
            std::string token;

            // Split the line using commas as delimiters
            if (std::getline(iss, token, ',') && std::getline(iss, token, ',') && token == user_login) {
                // Now, check the password (third token)
                if (std::getline(iss, token, ',') && token == user_password) {
                    user_file.close();
                    return true;
                }
            }
        }
    }
    user_file.close();
    return false;
}