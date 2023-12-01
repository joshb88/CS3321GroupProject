#include "boundary/userLogInUI.h"
#include "control/loginVerificationeddy.h"

std::string SECTION_BREAK = "==================================================\n";

void MainMenu::loginInterface()
{
    std::string login_input;
    std::string password_input;
    std::vector<std::string> inputs;
    bool login_successful = false;
    int login_count = 0;

    loginVerification login;

    std::cout << 
    SECTION_BREAK << std::setw(45) << 
    "Welcome to the Hospital Management System" << std::endl <<
    SECTION_BREAK;

    while(!login_successful)
    {
    // system("clear");
    // if(login_count > 0)
    // {
    //     std::cout << "Incorrect User Name and Password" << std::endl << std::endl;
    // }
    std::cout << std::left << std::setw(38) <<
    "Enter User Login:";
    std::cin >> login_input;

    std::cout << std::left << std::setw(38) <<
    "Enter User Password:";
    std::cin >> password_input;

    login_successful = login.verifyUser(login_input, password_input);  
    
    if (login_successful)
    {
        std::cout << "Login Successful" << std::endl;
    }  
    else
    {
        login_count++;

        std::cout <<  "\nIncorrect User Name and Password\n\n";
    }

    }

    std::cout << SECTION_BREAK << std::endl;
}