#include <string>
#include "boundary/MainMenu.h"
#include "boundary/StaffUI.h"
#include "entity/staff.h"

Staff StaffUI::accountCreation()
{
    User temp_user = genericUserCreation();
    Staff new_staff(temp_user);
    short choice;
    unsigned int idnumber;
    short clearance, 
    std::string jobtitle;
    unsigned int doh;

   do // Insurance or OOP
    {
        clearScreen();
        header();
        std::cout << 
        "Do you have any insurance?" << std::endl <<
        "1.\tYes" << std::endl <<
        "2.\tNo" << std::endl <<
        SECTION_BREAK;
        std::cin >> choice;
        if (std::cin.fail() || !(choice == 1 || choice == 2)) // if not given an appropriate input
        {
            std::cin.clear();                // Clear the error state
            std::cin.ignore(INT_MAX, '\n');  // Discard invalid input
            std::cout << "Invalid entry." << std::endl;
            continue;
        }
        
    } 
    while (std::cin.fail() || !(choice == 1 || choice == 2));
    insurance = (choice==1);
    new_staff.setHasInsurance(insurance);

    if (insurance)
    {
        do
        {
            clearScreen();
            header();
            std::cout << 
            "Write your insurance provider:" << std::endl <<
            SECTION_BREAK;
            std::getline(std::cin, provider);
            if (provider.empty())  {std::cout << "Please enter a provider." << std::endl; }
            std::getline(std::cin, provider);
        }
        while (provider.empty());
    }
    new_staff.setInsuranceProvider(provider);

    return new_staff;
}

Staff PatientUI::accountCreation(std::string entered_username)
{
    User temp_user = genericUserCreation(entered_username);
    Staff new_staff(temp_user);
    short choice;
    bool insurance;
    std::string provider;

    do // Insurance or OOP
    {
        clearScreen();
        header();
        std::cout << 
        "Do you have any insurance?" << std::endl <<
        "1.\tYes" << std::endl <<
        "2.\tNo" << std::endl <<
        SECTION_BREAK;
        std::cin >> choice;
        if (std::cin.fail() || !(choice == 1 || choice == 2)) // if not given an appropriate input
        {
            std::cin.clear();                // Clear the error state
            std::cin.ignore(INT_MAX, '\n');  // Discard invalid input
            std::cout << "Invalid entry." << std::endl;
            continue;
        }
        
    } 
    while (std::cin.fail() || !(choice == 1 || choice == 2));
    insurance = (choice==1);
    new_staff.setHasInsurance(insurance);

    if (insurance)
    {
        do
        {
            clearScreen();
            header();
            std::cout << 
            "Write your insurance provider:" << std::endl <<
            SECTION_BREAK;
            std::getline(std::cin, provider);
            if (provider.empty())  {std::cout << "Please enter a provider." << std::endl; }
            std::getline(std::cin, provider);
        }
        while (provider.empty());
    }
    new_staff.setInsuranceProvider(provider);

    std::cout <<
    new_staff.getUserLogin() << std::endl <<
    new_staff.getUserPassword() << std::endl <<
    new_staff.getLastName() << std::endl <<
    new_staff.getFirstName() << std::endl <<
    new_staff.getDateOfBirth() << std::endl <<
    new_staff.getGender() << std::endl <<
    new_staff.getHasInsurance() << std::endl <<
    new_staff.getInsuranceProvider() << std::endl;

    return new_staff;
}