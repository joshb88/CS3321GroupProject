#pragma once
#include <string>
#include "entity/user.h"

class MainMenu
{
    public:
        static const std::string SECTION_BREAK;
        static void pause(int sec);
        static void header(std::string header_content);
        static void clearScreen();
        static void loginMenu(std::string entered_username);
        static void accountCreateMenu(std::string entered_username);
        static void StartMenu();
};