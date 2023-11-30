#pragma once

class MainMenu
{
    protected:
        static const std::string SECTION_BREAK;
        static void clearScreen();
        static void loginMenu();
        static void accountCreation();
        //static void patientAccountCreation();
    public:
        static void StartMenu();
};