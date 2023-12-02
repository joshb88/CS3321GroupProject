#include <string>
#include <iomanip>
#include <ctime>
#include <limits>
#include "boundary/MainMenu.h"
#include "boundary/StaffUI.h"
#include "entity/staff.h"
#include "control/loginVerification.h"

Staff StaffUI::accountCreation()
{   
    short user_type = 2; //2 is the value for Staff in LoginMenu()
    User temp_user = genericUserCreation(user_type);
    Staff new_staff(temp_user);
    int idnumber;
    short clearance;
    std::string jobtitle;
    unsigned int doh;
    std::tm timeStruct = {};

    do // ID number
    {
        clearScreen();
        header();
        std::cout << "Assign an ID number." << std::endl << SECTION_BREAK;
        std::cin >> idnumber;

        if (std::cin.fail() || !(idnumber >= 0 || idnumber >= std::numeric_limits<unsigned int>::max()))
        {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "Invalid entry." << std::endl;
            continue;
        }

    } 
    while (std::cin.fail() || !(idnumber >= 0 || idnumber >= std::numeric_limits<unsigned int>::max()));
    new_staff.setIdNumber(idnumber);

   do // Clearance level
    {
        clearScreen();
        header();
        std::cout << 
        "Enter a clearance level" << std::endl <<
        "1.\tJanitorial" << std::endl <<
        "2.\tNursing" << std::endl <<
        "3.\tMedical" << std::endl <<
        "4.\tAdmin" << std::endl <<
        SECTION_BREAK;
        std::cin >> clearance;
        if (std::cin.fail() || !(clearance >= 1 && clearance <= 4)) // if not given an appropriate input
        {
            std::cin.clear();                // Clear the error state
            std::cin.ignore(INT_MAX, '\n');  // Discard invalid input
            std::cout << "Invalid entry." << std::endl;
            continue;
        }
        
    } 
    while (std::cin.fail() || !(clearance >= 1 && clearance <= 4));
    new_staff.setClearanceLevel(clearance);

    do //Job title
    {
        clearScreen();
        header();
        std::cout << 
        "Enter job title:" << std::endl <<
        SECTION_BREAK;
        // std::getline(std::cin, jobtitle);
        // if (jobtitle.empty())  {std::cout << "Please enter a job title." << std::endl; }
        std::getline(std::cin, jobtitle);
    }
    while (jobtitle.empty());

    new_staff.setJobTitle(jobtitle);

    do // hire date
    {
        clearScreen();
        header();
        std::cout << "Enter your hire date (YYYYMMDD): ";
        std::cin >> std::get_time(&timeStruct, "%Y%m%d");

        if (std::cin.fail()) 
        {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "Invalid entry." << std::endl;
            continue; // Skip the rest of the loop and start over
        }

        // Check if the hire data is within a valid range
        std::time_t currentTime = std::time(nullptr);
        std::tm* currentTM = std::localtime(&currentTime);
        std::tm bdayStruct = {};
        std::stringstream ss;
        ss << std::setw(8) << std::setfill('0') << new_staff.getDateOfBirth();
        ss >> std::get_time(&bdayStruct, "%Y%m%d");

        if (
            timeStruct.tm_year < 0 || 
            timeStruct.tm_year + 1900 > currentTM->tm_year + 1900 || 
            (timeStruct.tm_year + 1900 == currentTM->tm_year + 1900 && std::mktime(&timeStruct) > currentTime) ||
            std::mktime(&timeStruct) < std::mktime(&bdayStruct)) 
        {
            std::cout << "Invalid hire date. Please enter a date between your birthday and today." << std::endl;
        } 
        else 
        {
            std::stringstream ss;
            ss << std::put_time(&timeStruct, "%Y%m%d") << std::endl;
            ss >> doh;
            break; // Exit once valid.
        }
    } 
    while (true);
    std::cout << SECTION_BREAK;
    new_staff.setDateOfHire(doh);
    
    return new_staff;
}

Staff StaffUI::accountCreation(std::string entered_username)
{
    User temp_user = MainMenu::genericUserCreation(entered_username);
    Staff new_staff(temp_user);
    int idnumber;
    short clearance;
    std::string jobtitle;
    unsigned int doh;
    std::tm timeStruct = {};

    
    do // ID number
    {
        clearScreen();
        header();
        std::cout << "Assign an ID number." << std::endl << SECTION_BREAK;
        std::cin >> idnumber;

        if (std::cin.fail() || !(idnumber >= 0 || idnumber >= std::numeric_limits<unsigned int>::max()))
        {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "Invalid entry." << std::endl;
            continue;
        }

    } 
    while (std::cin.fail() || !(idnumber >= 0 || idnumber >= std::numeric_limits<unsigned int>::max()));
    new_staff.setIdNumber(idnumber);

   do // Clearance level
    {
        clearScreen();
        header();
        std::cout << 
        "Enter a clearance level" << std::endl <<
        "1.\tJanitorial" << std::endl <<
        "2.\tNursing" << std::endl <<
        "3.\tMedical" << std::endl <<
        "4.\tAdmin" << std::endl <<
        SECTION_BREAK;
        std::cin >> clearance;
        if (std::cin.fail() || !(clearance >= 1 && clearance <= 4)) // if not given an appropriate input
        {
            std::cin.clear();                // Clear the error state
            std::cin.ignore(INT_MAX, '\n');  // Discard invalid input
            std::cout << "Invalid entry." << std::endl;
            continue;
        }
        
    } 
    while (std::cin.fail() || !(clearance >= 1 && clearance <= 4));
    new_staff.setClearanceLevel(clearance);

    do //Job title
    {
        clearScreen();
        header();
        std::cout << 
        "Enter job title:" << std::endl <<
        SECTION_BREAK;
        // std::getline(std::cin, jobtitle);
        // if (jobtitle.empty())  {std::cout << "Please enter a job title." << std::endl; }
        std::getline(std::cin, jobtitle);
    }
    while (jobtitle.empty());

    new_staff.setJobTitle(jobtitle);

    do // hire date
    {
        clearScreen();
        header();
        std::cout << "Enter your hire date (YYYYMMDD): ";
        std::cin >> std::get_time(&timeStruct, "%Y%m%d");

        if (std::cin.fail()) 
        {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "Invalid entry." << std::endl;
            continue; // Skip the rest of the loop and start over
        }

        // Check if the hire data is within a valid range
        std::time_t currentTime = std::time(nullptr);
        std::tm* currentTM = std::localtime(&currentTime);
        std::tm bdayStruct = {};
        std::stringstream ss;
        ss << std::setw(8) << std::setfill('0') << new_staff.getDateOfBirth();
        ss >> std::get_time(&bdayStruct, "%Y%m%d");

        if (
            timeStruct.tm_year < 0 || 
            timeStruct.tm_year + 1900 > currentTM->tm_year + 1900 || 
            (timeStruct.tm_year + 1900 == currentTM->tm_year + 1900 && std::mktime(&timeStruct) > currentTime) ||
            std::mktime(&timeStruct) < std::mktime(&bdayStruct)) 
        {
            std::cout << "Invalid hire date. Please enter a date between your birthday and today." << std::endl;
        } 
        else 
        {
            std::stringstream ss;
            ss << std::put_time(&timeStruct, "%Y%m%d") << std::endl;
            ss >> doh;
            break; // Exit once valid.
        }
    } 
    while (true);
    std::cout << SECTION_BREAK;
    new_staff.setDateOfHire(doh);

    return new_staff;
}