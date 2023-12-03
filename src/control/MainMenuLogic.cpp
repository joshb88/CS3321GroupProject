#include <memory>
#include <string>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "control/MainMenuLogic.h"
#include "boundary/MainMenu.h"
#include "entity/staff.h"
#include "entity/patient.h"

//Take username, pass to check if its in the database.
//ALREADY IN DATABASE: control into login

//NOT IN DATABASE: pass username here
//OR
//LOGIN WITH UNUSED NAME: create account with that name


std::unique_ptr<User> AccountCreation::CreateAccount(const std::string& entered_username, const short& account_type) 
{
    std::string password, confirmation_password, first_name, last_name;
    unsigned int date_of_birth;
    unsigned char gender;
    short user_choice;
    std::tm timeStruct = {};

    std::string header_content = "Account Creation Menu";

    while (DatabaseManagement::userInDatabase(entered_username)) // If username given is found, fix.
    {
        MainMenu::clearScreen();
        MainMenu::header(header_content);
        std::cout <<
        "Username '" << entered_username << "' already exists." << std::endl <<
        "1.\tEnter a different username" << std::endl <<
        "2.\tLogin with '" << entered_username << "'." << std::endl <<
        "0.\tMain Menu" << std::endl << 
        MainMenu::SECTION_BREAK;

        std::cin >> user_choice;
        if (std::cin.fail()) // if not given an appropriate input
        {
            std::cin.clear();                // Clear the error state
            std::cin.ignore(INT_MAX, '\n');  // Discard invalid input
            MainMenu::clearScreen();
            AccountCreation::getUsername();
            std::cout << MainMenu::SECTION_BREAK;
            continue;                          // Ensure the function exits after recursion
        }
        if (user_choice == 1) { MainMenu::accountCreateMenu(AccountCreation::getUsername()); continue; } // Retry
        else if(user_choice == 2) { MainMenu::loginMenu(entered_username); std::exit(EXIT_SUCCESS); } //Login with name
        else if (user_choice == 0) { MainMenu::StartMenu(); std::exit(EXIT_SUCCESS); } // Start over
    }

    do // password confirmation
    {
        MainMenu::clearScreen();
        MainMenu::header(header_content);
        std::cout <<
        "Enter a password:\t";
        std::cin >> password;
        std::cout <<
        "Confirm your password:\t";
        std::cin >> confirmation_password;
        if (!(password == confirmation_password)) 
        { 
            std::cout << "Passwords don't match." << std::endl << MainMenu::SECTION_BREAK; 
        }
    } 
    while (!(password == confirmation_password));
    
    std::cout << 
    "Password confirmed." << std::endl <<
    MainMenu::SECTION_BREAK;

    // Name
    MainMenu::clearScreen();
    MainMenu::header(header_content); 
    std::cout <<
    "Enter your first name:\t";
    std::cin >> first_name;
    std::cout <<
    "Enter your last name:\t";
    std::cin >> last_name;
    std::cout << MainMenu::SECTION_BREAK;


    do // date of birth
    {
        MainMenu::clearScreen();
        MainMenu::header(header_content);
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
    std::cout << MainMenu::SECTION_BREAK;

    do // Gender
    {
        MainMenu::clearScreen();
        MainMenu::header(header_content);
        std::cout <<
        "Enter your Sex." << std::endl <<
        "Enter either:\nM for male\nF for female\nX to not answer" << std::endl <<
        MainMenu::SECTION_BREAK;
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
    std::cout << MainMenu::SECTION_BREAK;

    User new_user(entered_username,password,last_name,first_name,date_of_birth,gender);
    
    if (account_type == 1) // Assuming account_type 1 corresponds to "patient"
    {
        Patient new_patient(new_user);
        short choice;
        bool insurance;
        std::string provider;

        do // Insurance or OOP
        {
            MainMenu::clearScreen();
            MainMenu::header(header_content);
            std::cout << 
            "Do you have any insurance?" << std::endl <<
            "1.\tYes" << std::endl <<
            "2.\tNo" << std::endl <<
            MainMenu::SECTION_BREAK;
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
            do
            {
                MainMenu::clearScreen();
                MainMenu::header(header_content);
                std::cout << 
                "Write your insurance provider:" << std::endl <<
                MainMenu::SECTION_BREAK;
                std::getline(std::cin, provider);
                if (provider.empty())  {std::cout << "Please enter a provider." << std::endl; }
                std::getline(std::cin, provider);
            }
            while (provider.empty());
        }
        new_patient.setInsuranceProvider(provider);

        // std::cout <<
        // new_patient.getUserLogin() << std::endl <<
        // new_patient.getUserPassword() << std::endl <<
        // new_patient.getLastName() << std::endl <<
        // new_patient.getFirstName() << std::endl <<
        // new_patient.getDateOfBirth() << std::endl <<
        // new_patient.getGender() << std::endl <<
        // new_patient.getHasInsurance() << std::endl <<
        // new_patient.getInsuranceProvider() << std::endl;

        new_patient.setHasRoom(false);

        return std::make_unique<Patient>(new_patient);
    }
    else if (account_type == 2) // Assuming account_type 1 corresponds to "staff"
    {
        Staff new_staff(new_user);
        int idnumber;
        short clearance;
        std::string jobtitle;
        unsigned int doh;
        std::tm timeStruct = {};

        
        do // ID number
        {
            MainMenu::clearScreen();
            MainMenu::header(header_content);
            std::cout << "Assign an ID number." << std::endl << MainMenu::SECTION_BREAK;
            std::cin >> idnumber;

            if (std::cin.fail() || !(idnumber >= 0 || idnumber >= INT_MAX))
            {
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
                std::cout << "Invalid entry." << std::endl;
                continue;
            }

        } 
        while (std::cin.fail() || !(idnumber >= 0 || idnumber >= INT_MAX));
        new_staff.setIdNumber(idnumber);

    do // Clearance level
        {
            MainMenu::clearScreen();
            MainMenu::header(header_content);
            std::cout << 
            "Enter a clearance level" << std::endl <<
            "1.\tJanitorial" << std::endl <<
            "2.\tNursing" << std::endl <<
            "3.\tMedical" << std::endl <<
            "4.\tAdmin" << std::endl <<
            MainMenu::SECTION_BREAK;
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
            MainMenu::clearScreen();
            MainMenu::header(header_content);
            std::cout << 
            "Enter job title:" << std::endl <<
            MainMenu::SECTION_BREAK;
            // std::getline(std::cin, jobtitle);
            // if (jobtitle.empty())  {std::cout << "Please enter a job title." << std::endl; }
            std::getline(std::cin, jobtitle);
        }
        while (jobtitle.empty());

        new_staff.setJobTitle(jobtitle);

        do // hire date
        {
            MainMenu::clearScreen();
            MainMenu::header(header_content);
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
        std::cout << MainMenu::SECTION_BREAK;
        new_staff.setDateOfHire(doh);

        return std::make_unique<Staff>(new_staff);
        
    }
    return nullptr;
}

std::string AccountCreation::getUsername()
{
    short user_choice;
    std::string entered_username;
    //std::string header_content = "Account Creation Menu";

    MainMenu::clearScreen();
    MainMenu::header(); 
    std::cout <<
    "Enter a username:\t";
    std::cin >> entered_username;
    std::cout << MainMenu::SECTION_BREAK;

    return entered_username;
}
//******************************************************************************************************************
//                                          LOGIN VERIFICATION
//******************************************************************************************************************

bool LoginVerification::checkPassword(User& user) {
    std::fstream user_file;
    user_file.open("./database/users.txt", std::ios::in);
    std::string userToCheck = user.getUserLogin();
    std::string passToCheck = user.getUserPassword();
    std::string line;

    if (user_file.is_open()) // as long as the database file is open,
    {
        while (std::getline(user_file, line)) // loop through each line in the file
        {
            std::istringstream iss(line); // create a string stream to iterate through each token (word)
            std::string token;

            // Split the line using commas as delimiters
            if (std::getline(iss, token, ',') && token == userToCheck)
            {
                // Now, check the password (second token)
                if (std::getline(iss, token, ',') && token == passToCheck)
                {
                    user_file.close();
                    return true;
                }
            }
        }
    }
    user_file.close();
    return false;
}

bool LoginVerification::checkPassword(const std::string& user_login, const std::string& user_password) {
    std::fstream user_file;
    user_file.open("./database/users.txt", std::ios::in);
    std::string line;

    if (user_file.is_open()) {
        while (std::getline(user_file, line)) {
            std::istringstream iss(line);
            std::string token;

            // Split the line using commas as delimiters
            if (std::getline(iss, token, ',') && std::getline(iss, token, ',') && token == user_login) {
                // Now, check the password (third token)
                if (std::getline(iss, token, ',') && token == user_password) {
                    user_file.close();
                    return true;
                }
            }
        }
    }
    user_file.close();
    return false;
}

bool DatabaseManagement::userInDatabase(User& user) 
{
    std::fstream user_file;
    user_file.open("./database/users.txt", std::ios::in);
    std::string userToCheck = user.getUserLogin();
    
    if (user_file.is_open()) {
        std::string line;

        while (std::getline(user_file, line)) {
            std::istringstream iss(line);
            std::string token;

            while (std::getline(iss, token, ',')) {
                if (token == userToCheck) 
                {
                    user_file.close();
                    return true;
                }
            }
        }
    }

    user_file.close();
    return false;
}

bool DatabaseManagement::userInDatabase(const std::string& user_login)
{
    std::fstream user_file;
    user_file.open("./database/users.txt", std::ios::in);
    std::string line;

    if (user_file.is_open()) // as long as the database file is open,
    {
        while (std::getline(user_file, line)) // loop through each line in the file
        {
            std::istringstream iss(line); // create a string stream to iterate through each token (word)
            std::string token;

            // Split the line using commas as delimiters
            while (std::getline(iss, token, ','))
            {
                // Check if the current token is equal to the provided user login
                if (token == user_login)
                {
                    user_file.close();
                    return true;
                }
            }
        }
    }
    user_file.close();
    return false;
}

void DatabaseManagement::addUserToFile(User& user) 
{
   
    std::fstream user_file;
    user_file.open("./database/users.txt", std::ios::out | std::ios::app);
    if (!userInDatabase(user)) {
        if (user_file.is_open()) {
            
            Patient* patientPtr = dynamic_cast<Patient*>(&user);
            Staff* staffPtr = dynamic_cast<Staff*>(&user);
            if (patientPtr) // signify the stored user as a patient
            {
                user_file << 1 << ",";
            }
            else if(staffPtr) // signify the stored user as a patient
            {
                user_file << 2 << ",";
            }
            else
            {
                user_file << 0 << ",";
            }
            
            
            // Write common user data
            user_file << 
                user.getUserLogin() << "," << 
                user.getUserPassword() << "," << 
                user.getLastName() << "," << 
                user.getFirstName() << "," <<
                user.getDateOfBirth() << "," <<
                user.getGender();

            // Check if the user is a Patient and append additional data
            if (patientPtr) 
            {
                user_file << "," << 
                patientPtr->getHasInsurance()<< "," << 
                patientPtr->getInsuranceProvider()<< "," << 
                patientPtr->getHasRoom();

                // check that room as been assigned or fatal error
                if (!(patientPtr->getHasRoom())) { std::cout << "Room not assigned; set to placeholder." << std::endl; }
                user_file << "," <<
                patientPtr->getRoom().getRoomAvailability() << "," <<
                patientPtr->getRoom().getRoomFloorNumber() << "," <<
                patientPtr->getRoom().getRoomNumber();
            }

            // Check if the user is a Staff and append additional data
            if (staffPtr) {
                user_file << "," << 
                staffPtr->getIdNumber() << "," <<
                staffPtr->getClearanceLevel() << "," <<
                staffPtr->getJobTitle() << "," <<
                staffPtr->getDateOfHire();
            }

            user_file << std::endl;  // Add a newline at the end
            user_file.close();
            std::cout << "User data written to file." << std::endl;
        }
    }
}




std::unique_ptr<User> DatabaseManagement::getUserFromFile(const std::string& username) 
{
    std::fstream file;
    file.open("./database/users.txt", std::ios::in);
    
    std::string line, token;

    while (std::getline(file, line, '\n'))
    {
        User read_user;
        std::string account_type;
        std::istringstream iss(line);
        
        std::getline(iss, account_type, ','); // store first token as account_type
        std::getline(iss, token, ','); // store second token as token

        if (token == username) 
        {   

            read_user.setUserLogin(username);

            std::string password;
            std::getline(iss, password, ',');
            read_user.setUserPassword(password);

            std::string lastName;
            std::getline(iss, lastName, ',');
            read_user.setLastName(lastName);

            std::string firstName;
            std::getline(iss, firstName, ',');
            read_user.setFirstName(firstName);

            std::string birthdayStr;
            std::getline(iss, birthdayStr, ',');
            read_user.setDateOfBirth(std::stoi(birthdayStr));

            std::string genderStr;
            std::getline(iss, genderStr, ',');
            read_user.setGender(genderStr[0]);

            if (account_type == "1") // Assuming account_type 1 corresponds to "patient"
            {
                Patient read_patient(read_user);

                std::string hasInsuranceStr;
                std::getline(iss, hasInsuranceStr, ',');
                bool hasInsurance = (hasInsuranceStr == "1");
                read_patient.setHasInsurance(hasInsurance);

                std::string provider;
                std::getline(iss, provider, ',');
                read_patient.setInsuranceProvider(provider);
                

                std::string hasRoomStr;
                std::getline(iss, hasRoomStr, ',');
                read_patient.setHasRoom(hasInsuranceStr == "1");
                
        
                std::string roomAvailStr;
                std::getline(iss, roomAvailStr, ',');
                read_patient.getRoom().setRoomAvailability(!(read_patient.getHasRoom()));
                

                std::string roomFloorStr;
                std::getline(iss, roomFloorStr, ',');
                read_patient.getRoom().setRoomFloorNumber(std::stoi(roomFloorStr));

                std::string roomNumberStr;
                std::getline(iss, roomNumberStr, ',');
                read_patient.getRoom().setRoomNumber(std::stoi(roomNumberStr));

                return std::make_unique<Patient>(read_patient);
            }
            else if (account_type == "2") // Assuming account_type 1 corresponds to "staff"
            {
                Staff read_staff(read_user);
                
                std::string idNumberStr;
                std::getline(iss, idNumberStr, ',');
                read_staff.setIdNumber(std::stoi(idNumberStr));

                std::string clearanceStr;
                std::getline(iss, clearanceStr, ',');
                read_staff.setClearanceLevel(std::stoi(clearanceStr));

                std::string jobTitleStr;
                std::getline(iss, jobTitleStr, ',');
                read_staff.setJobTitle(jobTitleStr);

                std::string hireDateStr;
                std::getline(iss, hireDateStr, ',');
                read_staff.setClearanceLevel(std::stoi(hireDateStr));

                return std::make_unique<Staff>(read_staff);
                
            }
        }
    }

    file.close(); // Close the file before returning a default-constructed User object
    return nullptr;
}