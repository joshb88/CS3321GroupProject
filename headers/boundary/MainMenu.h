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
        static void accountCreateMenu();
        static User genericUserCreation();
    public:
        static void StartMenu();
};