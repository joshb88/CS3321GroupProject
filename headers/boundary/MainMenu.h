#pragma once
#include <string>
#include <memory>
#include "entity/user.h"

class MainMenu
{
    public:
        static const std::string SECTION_BREAK;
        static void pause(int sec);
        static void header(std::string header_content);
        static void header();
        static void clearScreen();
        static std::unique_ptr<User> loginMenu(std::string entered_username);
        static void accountCreateMenu(std::string entered_username);
        static void StartMenu();
};