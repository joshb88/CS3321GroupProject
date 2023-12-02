#pragma once
#include <string>
#include "entity/user.h"

class MainMenu
{
    protected:
        static const std::string SECTION_BREAK;
        static void pause(int sec);
        static void header();
        static void clearScreen();
        static void loginMenu();
        static void loginMenu(std::string entered_username);
        static void accountCreateMenu();
        static void accountCreateMenu(std::string entered_username);
        static User genericUserCreation(short user_type);
        static User genericUserCreation(std::string entered_username);
    public:
        static void StartMenu();
};