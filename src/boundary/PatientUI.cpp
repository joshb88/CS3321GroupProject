// #include <ctime>
// #include <iomanip>
// #include <cctype>
// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <string>
// #include "boundary/MainMenu.h"
// #include "boundary/patientUI.h"
// #include "entity/patient.h"
// //#include "control/LoginVerification.h"

// Patient PatientUI::accountCreation()
// {
//     short user_type = 1; //1 is the value for patient in LoginMenu()
//     User temp_user = genericUserCreation(user_type);
//     Patient new_patient(temp_user);
//     short choice;
//     bool insurance;
//     std::string provider;

//    do // Insurance or OOP
//     {
//         clearScreen();
//         header();
//         std::cout << 
//         "Do you have any insurance?" << std::endl <<
//         "1.\tYes" << std::endl <<
//         "2.\tNo" << std::endl <<
//         SECTION_BREAK;
//         std::cin >> choice;
//         if (std::cin.fail() || !(choice == 1 || choice == 2)) // if not given an appropriate input
//         {
//             std::cin.clear();                // Clear the error state
//             std::cin.ignore(INT_MAX, '\n');  // Discard invalid input
//             std::cout << "Invalid entry." << std::endl;
//             continue;
//         }
        
//     } 
//     while (std::cin.fail() || !(choice == 1 || choice == 2));
//     insurance = (choice==1);
//     new_patient.setHasInsurance(insurance);

//     if (insurance)
//     {
//         do
//         {
//             clearScreen();
//             header();
//             std::cout << 
//             "Write your insurance provider:" << std::endl <<
//             SECTION_BREAK;
//             std::getline(std::cin, provider);
//             if (provider.empty())  {std::cout << "Please enter a provider." << std::endl; }
//             std::getline(std::cin, provider);
//         }
//         while (provider.empty());
//     }
//     new_patient.setInsuranceProvider(provider);

//     new_patient.setHasRoom(false); // Rooms will be assigned differently

//     return new_patient;
// }

// Patient PatientUI::accountCreation(std::string entered_username)
// {
//     User temp_user = genericUserCreation(entered_username);
//     Patient new_patient(temp_user);
//     short choice;
//     bool insurance;
//     std::string provider;

//     do // Insurance or OOP
//     {
//         clearScreen();
//         header();
//         std::cout << 
//         "Do you have any insurance?" << std::endl <<
//         "1.\tYes" << std::endl <<
//         "2.\tNo" << std::endl <<
//         SECTION_BREAK;
//         std::cin >> choice;
//         if (std::cin.fail() || !(choice == 1 || choice == 2)) // if not given an appropriate input
//         {
//             std::cin.clear();                // Clear the error state
//             std::cin.ignore(INT_MAX, '\n');  // Discard invalid input
//             std::cout << "Invalid entry." << std::endl;
//             continue;
//         }
        
//     } 
//     while (std::cin.fail() || !(choice == 1 || choice == 2));
//     insurance = (choice==1);
//     new_patient.setHasInsurance(insurance);

//     if (insurance)
//     {
//         do
//         {
//             clearScreen();
//             header();
//             std::cout << 
//             "Write your insurance provider:" << std::endl <<
//             SECTION_BREAK;
//             std::getline(std::cin, provider);
//             if (provider.empty())  {std::cout << "Please enter a provider." << std::endl; }
//             std::getline(std::cin, provider);
//         }
//         while (provider.empty());
//     }
//     new_patient.setInsuranceProvider(provider);

//     // std::cout <<
//     // new_patient.getUserLogin() << std::endl <<
//     // new_patient.getUserPassword() << std::endl <<
//     // new_patient.getLastName() << std::endl <<
//     // new_patient.getFirstName() << std::endl <<
//     // new_patient.getDateOfBirth() << std::endl <<
//     // new_patient.getGender() << std::endl <<
//     // new_patient.getHasInsurance() << std::endl <<
//     // new_patient.getInsuranceProvider() << std::endl;

//     new_patient.setHasRoom(false); // Rooms will be assigned differently

//     return new_patient;
// }