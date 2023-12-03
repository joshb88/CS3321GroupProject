#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <cctype>
#include <ctime>
#include <thread>
#include <cstdlib>
#include <memory>
// #include "entity/staff.h"
// #include "entity/patient.h"
#include "boundary/StaffUI.h"
#include "boundary/PatientUI.h"
#include "boundary/MainMenu.h"
#include "control/dataManipulation.h"
#include "control/MainMenuLogic.h"
//#include "control/LoginVerification.h"
// #include "control/storedata.h"

const std::string MainMenu::SECTION_BREAK = "==================================================\n";

// void MainMenu::pause(int second_delay)
// {
//     std::this_thread::sleep_for(std::chrono::seconds(second_delay));
// }

void MainMenu::header()
{
    std::cout << 
    SECTION_BREAK << std::setw(40) << std::right << 
    "UHD Hospital Management System" << std::endl <<
    SECTION_BREAK;
}
void MainMenu::clearScreen() 
{
    //std::this_thread::sleep_for(std::chrono::seconds(1));
    for (int i = 0; i < 40; ++i) { std::cout << std::endl; }
}
void MainMenu::StartMenu()
{
    clearScreen();
    short user_choice;

    header();

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
        StartMenu();                     // Recursively call StartMenu
        return;                          // Ensure the function exits after recursion
    }

    switch (user_choice)
    {
    case 1:
        // Sign up
        std::cout << "You've opted to create an account." << std::endl;
        MainMenu::accountCreateMenu(AccountCreation::getUsername());
        break;
    case 2:
        // Login
        std::cout << "You've opted to login." << std::endl;
        loginMenu();
        break;
    case 0:
        // Exit
        std::cout << "Exiting." << std::endl;
        std::exit(EXIT_SUCCESS);
    default:
        std::cout << "You've entered an incorrect choice." << std::endl;
        StartMenu();
    }
}
void MainMenu::loginMenu()
{
    std::string entered_username;
    std::string password_input;
    std::unique_ptr<User> user_logged_in;

    clearScreen();
    header();
    
    std::cout << std::left << std::setw(35) <<
    "Enter User Login:";
    std::cin >> entered_username;
    std::cout << SECTION_BREAK;

    if (dataManipulation::userInDatabase(entered_username)) 
    {
        do
        {
            std::cout << std::left << std::setw(35) <<
            "Enter User Password:";
            std::cin >> password_input;
        } 
        while (!LoginVerification::checkPassword(entered_username, password_input));
        std::cout << SECTION_BREAK << std::endl;


        std::cout << "Login Successful!" << std::endl;
        user_logged_in = dataManipulation::getUserFromFile(entered_username);
        return;
    }
    // User not found, offer to make a new account.
    else 
    {
        short make_account;
        do
        {
            std::cout << 
            "User Not Found." << std::endl <<
            "Would you like to create a new account with this?" << std::endl << std::endl <<
            "1.\tYes." << std::endl <<
            "2.\tTry again." << std::endl <<
            SECTION_BREAK;
            std::cin >> make_account;
            if (std::cin.fail()) { std::cin.clear(); std::cin.ignore(INT_MAX, '\n'); }
        } 
        while (!(make_account == 1 || make_account == 2));
        
        

        switch (make_account)
        {
        case 1:
            MainMenu::accountCreateMenu(entered_username);
            break;
        case 2:
            loginMenu();
            break;
        default:
            StartMenu();
            break;
        }
    }
}
void MainMenu::loginMenu(std::string entered_username)
{
    std::string password_input;
    std::unique_ptr<User> user_logged_in;

    clearScreen();
    header();

    if (dataManipulation::userInDatabase(entered_username)) 
    {
        do
        {
            std::cout << std::left << std::setw(35) <<
            "Enter User Password:";
            std::cin >> password_input;
        } 
        while (!LoginVerification::checkPassword(entered_username, password_input));
        std::cout << SECTION_BREAK << std::endl;


        std::cout << "LOGIN PASSED" << std::endl;
        user_logged_in = dataManipulation::getUserFromFile(entered_username);
        return;
    }
    // User not found, offer to make a new account.
    else 
    {
        short make_account;
        do
        {
            std::cout << 
            "User Not Found." << std::endl <<
            "Would you like to create a new account with this?" << std::endl << std::endl <<
            "1.\tYes." << std::endl <<
            "2.\tTry again." << std::endl <<
            SECTION_BREAK;
            std::cin >> make_account;
            if (std::cin.fail()) { std::cin.clear(); std::cin.ignore(INT_MAX, '\n'); }
        } 
        while (!(make_account == 1 || make_account == 2));
        
        

        switch (make_account)
        {
        case 1:
            MainMenu::accountCreateMenu(entered_username);
            break;
        case 2:
            loginMenu();
            break;
        default:
            StartMenu();
            break;
        }
    }
}
void MainMenu::accountCreateMenu(std::string entered_username)
{
    short user_type;

    clearScreen();
    header();

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
        std::cin.clear();                           // Clear the error state
        std::cin.ignore(INT_MAX, '\n');             // Discard invalid input
        accountCreateMenu(entered_username);        // Recursively call accountCreateMenu
        return;                                     // Ensure the function exits after recursion
    }

    AccountCreation::CreateAccount(entered_username, user_type);
}