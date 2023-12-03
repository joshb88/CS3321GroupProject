#pragma once
#include <memory>
#include <string>
#include <ctime>
#include "control/MainMenuLogic.h"
#include "boundary/MainMenu.h"
#include "entity/staff.h"
#include "entity/patient.h"

class AccountCreation
{
    public:
        
        static std::unique_ptr<User> CreateAccount(const std::string& entered_username, const short& account_type);
        static std::string getUsername();
};

class LoginVerification
{
    public:
        static bool checkPassword(User&);
        static bool checkPassword(const std::string& user_login, const std::string& user_password);
};

class DatabaseManagement
{
    public:
        static bool userInDatabase(User& user);
        static bool userInDatabase(const std::string& user_name);
        static void addUserToFile(User& user);
        static std::unique_ptr<User> readUserFromDatabase(const std::string& user_name);
        void modifyUserFromFile (User);
};