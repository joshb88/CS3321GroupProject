#include "boundary/userinterface.h"

std::string SECTION_BREAK = "==================================================\n";

std::string MainMenu::passwordInput()
{
    std::string password;
    char ch;

    while (true) 
    {
        ch = _getch(); // Get a character from the console without echoing

        if (ch == '\r') { // Enter key pressed
            break;
        } else if (ch == 8 && !password.empty()) { // Backspace key pressed
            password.pop_back();
            std::cout << "\b \b"; // Move the cursor back and erase the last character
        } else {
            password.push_back(ch);
            std::cout << '*'; // Display '*' instead of the actual character
        }
    }

    std::cout << std::endl;  // Move to the next line after entering the password
    return password;
}

void MainMenu::loginInterface()
{
    std::string login_input;
    std::string password_input;
    std::cout << 
    SECTION_BREAK << std::setw(45) << 
    "Welcome to the Hospital Management System" << std::endl <<
    SECTION_BREAK;
    
    std::cout << std::left << std::setw(20) <<
    "Enter User Login:\t";
    std::cin >> login_input;

    std::cout << std::left << std::setw(22) <<
    "Enter User Password:\t";
    password_input = MainMenu::passwordInput();

    std::cout << SECTION_BREAK << std::endl;
}