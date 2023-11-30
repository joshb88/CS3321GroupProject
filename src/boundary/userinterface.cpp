#include <cctype>
#include "entity/staff.h"
#include "entity/patient.h"
#include "boundary/userinterface.h"
#include "control/LoginVerification.h"

std::string SECTION_BREAK = "==================================================\n";

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
        accountCreation();
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
        EXIT_SUCCESS;
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
            //accountCreation(login_input);
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
        patientAccountCreation();
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

void MainMenu::patientAccountCreation()
{
    Patient new_patient();
    std::string desired_user_login, password, confirmation_password, first_name, last_name;
    short user_choice;

    clearScreen();

    std::cout << 
    SECTION_BREAK << std::setw(37) << std::right << 
    "Patient Account Creation" << std::endl <<
    SECTION_BREAK <<
    "Enter a username:\t";
    std::cin >> desired_user_login;

    
    while (LoginVerification::userInDatabase(desired_user_login)) // If username given is found
    {
        std::cout << 
        SECTION_BREAK <<
        "Username already exists." << std::endl <<
        "1.\tEnter a different username" << std::endl <<
        "0.\tMain Menu" << std::endl << 
        SECTION_BREAK;

        std::cin >> user_choice;
        if (std::cin.fail()) // if not given an appropriate input
        {
            std::cin.clear();                // Clear the error state
            std::cin.ignore(INT_MAX, '\n');  // Discard invalid input
            patientAccountCreation();               // Recursively call accountCreation
            return;                          // Ensure the function exits after recursion
        }

        if (user_choice == 0) { StartMenu(); return;} // start menu
        else if(user_choice == 1) { patientAccountCreation(); return; } // retry
        else // wrong entry
        { 
            std::cout << 
            "Invalid Choice" << std::endl <<
            "1.\tEnter a different username" << std::endl <<
            "0.\tMain Menu" << std::endl <<
            SECTION_BREAK;
        }
    };

   do
   {
    std::cout <<
    "Enter a password:\t";
    std::cin >> password;
    std::cout <<
    "Confirm your password:\t";
    std::cin >> confirmation_password;
    if (!(password == confirmation_password)) { std::cout << "Passwords don't match." << std::endl << SECTION_BREAK; }
   } 
   while (!(password == confirmation_password));
   
    std::cout << 
    "Password confirmed." << std::endl << 
    SECTION_BREAK << std::endl <<
    "Enter your first name:\t";
    std::cin >> first_name;
    std::cout << std::endl <<
    "Enter your last name:\t";
    std::cin >> last_name;