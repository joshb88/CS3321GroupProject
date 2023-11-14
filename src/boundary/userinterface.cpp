#include "boundary/userinterface.h"

std::string SECTION_BREAK = "==================================================\n";

void MainMenu::loginInterface()
{
    std::string login_input;
    std::string password_input;

    std::cout << 
    SECTION_BREAK << std::setw(45) << 
    "Welcome to the Hospital Management System" << std::endl <<
    SECTION_BREAK;
    
    std::cout << std::left << std::setw(38) <<
    "Enter User Login:";
    std::cin >> login_input;

    std::cout << std::left << std::setw(38) <<
    "Enter User Password:";
    std::cin >> password_input;

    std::cout << SECTION_BREAK << std::endl;
}