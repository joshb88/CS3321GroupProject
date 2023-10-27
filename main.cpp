#include <iomanip>
#include <iostream>
#include <string>
//#include ".\headers\entity.h"     // windows
#include "./headers/entity.h"      // mac

int main()
{   
    User newcomer;
    Patient testPatient;
    // Patient testPatient("josh","pass", 8884, 19880814, false, "");

    std::cout 
    << newcomer.getUserLogin() << '\n' 
    << newcomer.getUserPassword() << std::endl;

    newcomer.setUserLogin("name-test1");
    newcomer.setUserPassword("pass-test1");

    std::cout 
    << newcomer.getUserLogin() << '\n' 
    << newcomer.getUserPassword() << std::endl;
    std::cout << "Hello World. \nThis is a test." << std::endl;

    std::cout
    << testPatient.getUserLogin() << '\n' << testPatient.getUserPassword() << std::endl;

    std::cout << testPatient.getDateOfBirth() << std::endl;
    testPatient.setUserLogin("test-Patient");
    testPatient.setUserPassword("test-password");

    std::cout 
    << testPatient.getUserLogin() << '\n' 
    << testPatient.getUserPassword() << std::endl;

    std::cout << "ty for work" << std::endl;
    return 0;
};