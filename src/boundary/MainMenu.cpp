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
#include "control/MainMenuLogic.h"


const std::string MainMenu::SECTION_BREAK = "==================================================\n";

// void MainMenu::pause(int second_delay)
// {
//     std::this_thread::sleep_for(std::chrono::seconds(second_delay));
// }

void MainMenu::header(std::string header_content)
{
    int center = MainMenu::SECTION_BREAK.length() / 2 + header_content.length() / 2;
    std::cout << 
    MainMenu::SECTION_BREAK << std::setw(center) << std::right <<
    header_content << std::endl << 
    MainMenu::SECTION_BREAK;
};
void MainMenu::header()
{   
    std::string header_content = "UHD Hospital Management System";
    int center = MainMenu::SECTION_BREAK.length() / 2 + header_content.length() / 2;
    std::cout << 
    MainMenu::SECTION_BREAK << std::setw(center) << std::right <<
    header_content << std::endl << 
    MainMenu::SECTION_BREAK;
};
void MainMenu::clearScreen() 
{
    //std::this_thread::sleep_for(std::chrono::seconds(1));
    for (int i = 0; i < 40; ++i) { std::cout << std::endl; }
}
void MainMenu::StartMenu()
{
    short user_choice;
    std::string header_content = "UHD Hospital Management System";

    clearScreen();
    MainMenu::header(header_content);

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
        MainMenu::accountCreateMenu("");
        break;
    case 2:
        // Login
        std::cout << "You've opted to login." << std::endl;
        MainMenu::loginMenu(AccountCreation::getUsername());
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
std::unique_ptr<User> MainMenu::loginMenu(std::string entered_username)
{
    std::string password_input;
    std::string header_content = "Login Menu";
    std::unique_ptr<User> user_logged_in;


    if (DatabaseManagement::userInDatabase(entered_username)) 
    {
        for(short login_attempts = 0; login_attempts < 3; login_attempts++)
        {
            clearScreen();
            MainMenu::header(header_content);
            std::cout << std::left << std::setw(35) <<
            "Enter User Password:";
            std::cin >> password_input;
            std::cout << SECTION_BREAK;
            if(LoginVerification::checkPassword(entered_username, password_input)) 
            {
                std::cout << "LOGIN PASSED" << std::endl;
                user_logged_in = DatabaseManagement::getUserFromFile(entered_username);
                return user_logged_in;
            }
        }
        std::cout << "Too many attempts; Going to Main Menu."; 
        MainMenu::StartMenu();
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
            MainMenu::loginMenu(AccountCreation::getUsername());
            break;
        default:
            MainMenu::StartMenu();
            break;
        }
    }
    return nullptr;
}
void MainMenu::accountCreateMenu(std::string entered_username)
{
    short user_type;
    std::string header_content = "Account Creation Menu";

    MainMenu::clearScreen();
    MainMenu::header(header_content);

    std::cout <<
    "Select your account type." << std::endl <<
    "1.\tPatient" << std::endl <<
    "2.\tStaff" << std::endl <<
    "9.\tGo Back" << std::endl <<
    "0.\tGo to Main Menu" << std::endl <<
    SECTION_BREAK;
    
    std::cin >> user_type;

    if (entered_username.empty()) { entered_username = AccountCreation::getUsername(); }

    if (std::cin.fail()) 
    {
        std::cin.clear();                           // Clear the error state
        std::cin.ignore(INT_MAX, '\n');             // Discard invalid input
        accountCreateMenu(entered_username);        // Recursively call accountCreateMenu
        return;                                     // Ensure the function exits after recursion
    }

    std::unique_ptr<User> new_account = AccountCreation::CreateAccount(entered_username, user_type);
    DatabaseManagement::addUserToFile(std::move(new_account));
}