#include <cctype>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include "boundary/patientUI.h"
#include "control/LoginVerification.h"

void PatientUI::accountCreation()
{
    //Patient new_patient;
    std::string desired_user_login, password, confirmation_password, first_name, last_name;
    unsigned int date_of_birth;
    unsigned char gender;
    short user_choice;
    std::tm timeStruct = {};

    clearScreen();

    std::cout << 
    SECTION_BREAK << std::setw(37) << std::right << 
    "Patient Account Creation" << std::endl <<
    SECTION_BREAK <<
    "Enter a username:\t";
    std::cin >> desired_user_login;
    std::cout << SECTION_BREAK;

    
    while (LoginVerification::userInDatabase(desired_user_login)) // If username given is found, fix.
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
            PatientUI::accountCreation();    // Recursively call accountCreation
            return;                          // Ensure the function exits after recursion
        }

        if (user_choice == 0) { StartMenu(); return;} // start menu
        else if(user_choice == 1) { PatientUI::accountCreation(); return; } // retry
        else // wrong entry
        { 
            std::cout << 
            "Invalid Choice" << std::endl <<
            "1.\tEnter a different username" << std::endl <<
            "0.\tMain Menu" << std::endl <<
            SECTION_BREAK;
        }
    };

    do // password confirmation
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
    SECTION_BREAK <<
    "Enter your first name:\t";
    std::cin >> first_name;
    std::cout <<
    "Enter your last name:\t";
    std::cin >> last_name;
    std::cout << SECTION_BREAK;

    do // date of birth
    {
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

    std::cout << 
    SECTION_BREAK <<
    "Enter your Sex." << std::endl <<
    "Enter either:\nM for male\nF for female\nX for other" << std::endl;
    std::cin >> gender;
    gender = tolower(gender);
    std::cout << SECTION_BREAK;
        if (std::cin.fail()) // if not given an appropriate input
        {
            std::cin.clear();                // Clear the error state
            std::cin.ignore(INT_MAX, '\n');  // Discard invalid input
        }


//     Patient new_patient(desired_user_login,password, last_name, first_name, date_of_birth, gender, has_insurance, provider, nullptr);
//     new_patient.setUserLogin(desired_user_login);
//     new_patient.setUserPassword(password);
//     new_patient.setFirstName(first_name);
//     new_patient.setLastName(last_name);
}