#include <ctime>
#include <iomanip>
// #include <cctype>
// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <string>
#include "boundary/MainMenu.h"
#include "boundary/patientUI.h"
#include "entity/patient.h"
#include "control/LoginVerification.h"

Patient PatientUI::accountCreation()
{
    User temp_user = genericUserCreation();
    Patient new_patient(temp_user);
    short choice;
    bool insurance;

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
    new_patient.setHasInsurance(insurance);

    if (insurance)
    {
        std::string provider;
        clearScreen();
        header();
        std::cout << 
        "Write your insurance provider:" << std::endl <<
        SECTION_BREAK;
        std::cin >> provider;
        new_patient.setInsuranceProvider(provider);
    }

    return new_patient;
}