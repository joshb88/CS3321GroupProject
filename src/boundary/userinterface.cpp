#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <cctype>
#include <ctime>
#include "entity/staff.h"
#include "entity/patient.h"
#include "boundary/userinterface.h"
#include "boundary/patientUI.h"
#include "control/LoginVerification.h"

const std::string MainMenu::SECTION_BREAK = "==================================================\n";


void MainMenu::clearScreen() 
{
    for (int i = 0; i < 40; ++i) { std::cout << std::endl; }
}
void MainMenu::StartMenu()
{
    clearScreen();
    short user_choice;

    std::cout << 
    SECTION_BREAK << std::setw(45) << 
    "Welcome to the Hospital Management System" << std::endl <<
    SECTION_BREAK;

    std::cout << std::left << std::setw(38) <<
    "Please, select an option." << std::endl;
    std::cout << std::left << std::setw(38) <<
    "1.\tCreate an Account" << std::endl;
    std::cout << std::left << std::setw(38) <<
    "2.\tLogin to an Existing Account" << std::endl;
    std::cout << std::left << std::setw(38) <<
    "0.\tExit" << std::endl;
    std::cout << SECTION_BREAK;

    std::cin >> user_choice;

    if (std::cin.fail())
    {
        std::cin.clear();                // Clear the error state
        std::cin.ignore(INT_MAX, '\n');  // Discard invalid input
        StartMenu();                     // Recursively call accountCreation
        return;                          // Ensure the function exits after recursion
    }

    switch (user_choice)
    {
    case 1:
        // Sign up
        std::cout << "You've opted to create an account." << std::endl;
        MainMenu::accountCreation();
        break;
    case 2:
        // Login
        std::cout << "You've opted to login." << std::endl;
        loginMenu();
        break;
    case 0:
        // Exit
        std::cout << "Exiting." << std::endl;
        return;
    default:
        std::cout << "You've entered an incorrect choice." << std::endl;
        StartMenu();
    }
}
void MainMenu::loginMenu()
{
    std::string login_input;
    std::string password_input;

    clearScreen();
    std::cout << 
    SECTION_BREAK << std::setw(30) << std::right << 
    "Login Menu" << std::endl <<
    SECTION_BREAK;
    
    std::cout << std::left << std::setw(35) <<
    "Enter User Login:";
    std::cin >> login_input;
    std::cout << SECTION_BREAK << std::endl;

    if (LoginVerification::userInDatabase(login_input)) 
    {
        do
        {
            std::cout << std::left << std::setw(35) <<
            "Enter User Password:";
            std::cin >> password_input;
        } 
        while (!LoginVerification::checkPassword(login_input, password_input));
        std::cout << SECTION_BREAK << std::endl;

        std::cout << "LOGIN PASSED" << std::endl; 
        return;
    }
    // User not found, offer to make a new account.
    else 
    {
        unsigned char make_account;
        std::cout << 
        "User Not Found." << std::endl <<
        "Would you like to create a new account?" << std::endl << std::endl <<
        "Type y for yes." << std::endl <<
        "Type n for try again." << std::endl << std::endl <<
        SECTION_BREAK;
        
        std::cin >> make_account;

        switch (tolower(make_account))
        {
        case 'y':
            accountCreation();
            break;
        case 'n':
            loginMenu();
            break;
        default:
            StartMenu();
            break;
        }
    }
    
    

}

void MainMenu::accountCreation()
{
    short user_type;

    clearScreen();
    std::cout << 
    SECTION_BREAK << std::setw(34) << std::right <<
    "Account Creation" << std::endl <<
    SECTION_BREAK;

    std::cout <<
    "Select your account type." << std::endl <<
    "1.\tPatient" << std::endl <<
    "2.\tStaff" << std::endl <<
    "9.\tGo Back" << std::endl <<
    "0.\tGo to Main Menu" << std::endl <<
    SECTION_BREAK;
    
    std::cin >> user_type;

    if (std::cin.fail()) 
    {
        std::cin.clear();                // Clear the error state
        std::cin.ignore(INT_MAX, '\n');  // Discard invalid input
        accountCreation();               // Recursively call accountCreation
        return;                          // Ensure the function exits after recursion
    }


    switch (user_type)
    {
    case 1:
        // Patient class used
        PatientUI::accountCreation();
        break;
    case 2:
        // Staff class used
        std::cout << "Staff class to be used" << std::endl;
        break;
    case 9:
        loginMenu();
        break;
    case 0:
        StartMenu();
        break; 
    default:
        accountCreation();
        break;
    } 
}