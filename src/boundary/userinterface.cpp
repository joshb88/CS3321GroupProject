#include "boundary/userinterface.h"
#include "control/LoginVerification.h"

std::string SECTION_BREAK = "==================================================\n";

void MainMenu::clearScreen() 
{
    for (int i = 0; i < 25; ++i) { std::cout << std::endl; }
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
    std::cout << SECTION_BREAK << std::endl;

    std::cin >> user_choice;


    switch (user_choice)
    {
    case 1:
        // Sign up
        std::cout << "You've opted to create an account." << std::endl;
        accountCreation();
        break;
    case 2:
        // Login
        std::cout << "You've opted to login." << std::endl;
        loginMenu();
    case 0:
        // Exit
        std::cout << "Exiting." << std::endl;
        break;
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
    SECTION_BREAK << std::setw(45) << 
    "Login Menu" << std::endl <<
    SECTION_BREAK;
    
    std::cout << std::left << std::setw(38) <<
    "Enter User Login:";
    std::cin >> login_input;

    std::cout << std::left << std::setw(38) <<
    "Enter User Password:";
    std::cin >> password_input;

    std::cout << SECTION_BREAK << std::endl;

    //login verify
    if (LoginVerification::userInDatabase(login_input, password_input)) {std::cout << "yes" << std::endl; }
    else {std::cout << "no" << std::endl; }
}

void MainMenu::accountCreation()
{
    clearScreen();
    std::cout << 
    SECTION_BREAK << std::setw(45) << 
    "Account Creation" << std::endl <<
    SECTION_BREAK;

}