#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>

class MainMenu
{
    public:
        static void clearScreen();
        static void StartMenu();
        static void loginMenu();
        static void accountCreation();
        static void patientAccountCreation();
};