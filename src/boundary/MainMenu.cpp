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
// #include "entity/staff.h"
// #include "entity/patient.h"
#include "boundary/StaffUI.h"
#include "boundary/patientUI.h"
#include "boundary/MainMenu.h"
#include "control/loginVerification.h"
#include "control/storedata.h"

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
        MainMenu::accountCreateMenu();
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
    std::string login_input;
    std::string password_input;

    clearScreen();
    header();
    
    std::cout << std::left << std::setw(35) <<
    "Enter User Login:";
    std::cin >> login_input;
    std::cout << SECTION_BREAK;

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
            MainMenu::accountCreateMenu(login_input);
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
void MainMenu::accountCreateMenu()
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
        std::cin.clear();                // Clear the error state
        std::cin.ignore(INT_MAX, '\n');  // Discard invalid input
        accountCreateMenu();               // Recursively call accountCreateMenu
        return;                          // Ensure the function exits after recursion
    }

    Patient new_patient;
    Staff new_staff;
    switch (user_type)
    {
    case 1:
        // Patient class used
        new_patient = PatientUI::accountCreation();
        StoreData::storeUser(new_patient);
        break;
    case 2:
        // Staff class used
        new_staff = StaffUI::accountCreation();
        StoreData::storeUser(new_staff);
        break;
    case 9:
        loginMenu();
        break;
    case 0:
        StartMenu();
        break; 
    default:
        accountCreateMenu();
        break;
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


    Patient new_patient;
    Staff new_staff;
    switch (user_type)
    {
    case 1:
        // Patient class used
        new_patient = PatientUI::accountCreation(entered_username);
        StoreData::storeUser(new_patient);
        break;
    case 2:
        // Staff class used
        new_staff = StaffUI::accountCreation(entered_username);
        StoreData::storeUser(new_staff);
        break;
    case 9:
        loginMenu();
        break;
    case 0:
        StartMenu();
        break; 
    default:
        accountCreateMenu(entered_username);
        break;
    } 
}
User MainMenu::genericUserCreation(short user_type)
{
    std::string desired_user_login, password, confirmation_password, first_name, last_name;
    unsigned int date_of_birth;
    unsigned char gender;
    short user_choice, patient_or_staff = user_type;
    std::tm timeStruct = {};

    clearScreen();
    header(); 
    std::cout <<
    "Enter a username:\t";
    std::cin >> desired_user_login;
    std::cout << SECTION_BREAK;

    
    while (LoginVerification::userInDatabase(desired_user_login)) // If username given is found, fix.
    {
        clearScreen();
        header();
        std::cout <<
        "Username '" << desired_user_login << "' already exists." << std::endl <<
        "1.\tEnter a different username" << std::endl <<
        //"2.\tLogin with '" << desired_user_login << "'." << std::endl <<
        "0.\tMain Menu" << std::endl << 
        SECTION_BREAK;

        std::cin >> user_choice;
        if (std::cin.fail()) // if not given an appropriate input
        {
            std::cin.clear();                // Clear the error state
            std::cin.ignore(INT_MAX, '\n');  // Discard invalid input
            // PatientUI::accountCreation(); // Recursively call accountCreation
            clearScreen();
            accountCreateMenu();
            std::cout << SECTION_BREAK <<
            "Invalid Choice" << std::endl <<
            "1.\tEnter a different username" << std::endl <<
            "0.\tMain Menu" << std::endl;
            continue;                          // Ensure the function exits after recursion
        }

        if (user_choice == 0) { StartMenu(); } // start menu
        else if(user_choice == 1 && patient_or_staff == 1) { PatientUI::accountCreation(); std::exit(EXIT_SUCCESS); } // retry as patient
        else if(user_choice == 1 && patient_or_staff == 2) { StaffUI::accountCreation(); std::exit(EXIT_SUCCESS); } // retry as staff
    };

    do // password confirmation
    {
        clearScreen();
        header();
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
    SECTION_BREAK;

    // Name
    clearScreen();
    header(); 
    std::cout <<
    "Enter your first name:\t";
    std::cin >> first_name;
    std::cout <<
    "Enter your last name:\t";
    std::cin >> last_name;
    std::cout << SECTION_BREAK;


    do // date of birth
    {
        clearScreen();
        header();
        std::cout << "Enter your date of birth (YYYYMMDD): ";
        std::cin >> std::get_time(&timeStruct, "%Y%m%d");

        if (std::cin.fail()) 
        {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "Invalid entry." << std::endl;
            continue; // Skip the rest of the loop and start over
        }

        // Check if the birthdate is within a valid range
        std::time_t currentTime = std::time(nullptr);
        std::tm* currentTM = std::localtime(&currentTime);

        if (timeStruct.tm_year < 0 ||
            timeStruct.tm_year + 1900 > currentTM->tm_year + 1900 || 
            (timeStruct.tm_year + 1900 == currentTM->tm_year + 1900 && std::mktime(&timeStruct) > currentTime)) 
        {
            std::cout << "Invalid birthdate. Please enter a date between 1900 and today." << std::endl;
        } 
        else 
        {
            std::stringstream ss;
            ss << std::put_time(&timeStruct, "%Y%m%d") << std::endl;
            ss >> date_of_birth;
            break; // Exit once valid.
        }
    } 
    while (true);
    std::cout << SECTION_BREAK;

    do // Gender
    {
        clearScreen();
        header();
        std::cout <<
        "Enter your Sex." << std::endl <<
        "Enter either:\nM for male\nF for female\nX to not answer" << std::endl <<
        SECTION_BREAK;
        std::cin >> gender;
        gender = tolower(gender);
        if (std::cin.fail() || !(gender == 'm' || gender == 'f' || gender == 'x')) // if not given an appropriate input
        {
            std::cin.clear();                // Clear the error state
            std::cin.ignore(INT_MAX, '\n');  // Discard invalid input
            std::cout << "Invalid entry." << std::endl;
            continue;
        }
    } 
    while (std::cin.fail() || !(gender == 'm' || gender == 'f' || gender == 'x') );
    std::cout << SECTION_BREAK;

    User new_user(desired_user_login,password,last_name,first_name,date_of_birth,gender);
    return new_user;
}
User MainMenu::genericUserCreation(std::string entered_name)
{
    std::string password, confirmation_password, first_name, last_name;
    unsigned int date_of_birth;
    unsigned char gender;
    short user_choice;
    std::tm timeStruct = {};

    do // password confirmation
    {
        clearScreen();
        header();
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
    SECTION_BREAK;

    // Name
    clearScreen();
    header(); 
    std::cout <<
    "Enter your first name:\t";
    std::cin >> first_name;
    std::cout <<
    "Enter your last name:\t";
    std::cin >> last_name;
    std::cout << SECTION_BREAK;


    do // date of birth
    {
        clearScreen();
        header();
        std::cout << "Enter your date of birth (YYYYMMDD): ";
        std::cin >> std::get_time(&timeStruct, "%Y%m%d");

        if (std::cin.fail()) 
        {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "Invalid entry." << std::endl;
            continue; // Skip the rest of the loop and start over
        }

        // Check if the birthdate is within a valid range
        std::time_t currentTime = std::time(nullptr);
        std::tm* currentTM = std::localtime(&currentTime);

        if (timeStruct.tm_year < 0 ||
            timeStruct.tm_year + 1900 > currentTM->tm_year + 1900 || 
            (timeStruct.tm_year + 1900 == currentTM->tm_year + 1900 && std::mktime(&timeStruct) > currentTime)) 
        {
            std::cout << "Invalid birthdate. Please enter a date between 1900 and today." << std::endl;
        } 
        else 
        {
            std::stringstream ss;
            ss << std::put_time(&timeStruct, "%Y%m%d") << std::endl;
            ss >> date_of_birth;
            break; // Exit once valid.
        }
    } 
    while (true);
    std::cout << SECTION_BREAK;

    do // Gender
    {
        clearScreen();
        header();
        std::cout <<
        "Enter your Sex." << std::endl <<
        "Enter either:\nM for male\nF for female\nX to not answer" << std::endl <<
        SECTION_BREAK;
        std::cin >> gender;
        gender = tolower(gender);
        if (std::cin.fail() || !(gender == 'm' || gender == 'f' || gender == 'x')) // if not given an appropriate input
        {
            std::cin.clear();                // Clear the error state
            std::cin.ignore(INT_MAX, '\n');  // Discard invalid input
            std::cout << "Invalid entry." << std::endl;
            continue;
        }
    } 
    while (std::cin.fail() || !(gender == 'm' || gender == 'f' || gender == 'x') );
    std::cout << SECTION_BREAK;

    User new_user(entered_name,password,last_name,first_name,date_of_birth,gender);
    return new_user;
}