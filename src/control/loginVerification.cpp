#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "control/loginVerification.h"

bool loginVerification::verifyUser(std::string entered_login, std::string  entered_password)
{
//     User our_user;
//     bool found_user = false;
//     bool correct_password = false;
//     dataManipulation data;

//     found_user = data.checkForUeser(entered_login);
    
//     if(found_user)
//     {
//        // data.getUserFromFile(our_user, entered_login);

//         if(our_user.getUserPassword() == entered_password)
//         {
//             correct_password = true;
//         }
//     }

//     if(found_user && correct_password)
//     {
//         return true;
//     }
//     else{
//         return false;
//     }

    std::string first_token;
    std::string second_token;
    bool found_user = false;
    bool correct_password = false;
    
    std::ifstream myFile;
    myFile.open("./database/users.txt");
    if(myFile.is_open())
    {
        std::string line;

        while (std::getline(myFile, line))
        { 
            std::istringstream my_line(line);
            if (my_line >> first_token)
            {   
                if(first_token == entered_login)
                {
                    found_user = true;
                     my_line >> second_token;
                     if (second_token == entered_password)
                     {
                        correct_password = true;
                        break;
                     }
                }
               
                // std::cout << line << std::endl; 
                // std::cout << first_token << std::endl;
                
               // std::cout << my_line_updated << std::endl;
            }
        }
    }
    myFile.close();
    if (found_user && correct_password)
    {
        return true;
    }
    else 
    {
        return false;
    }


}
