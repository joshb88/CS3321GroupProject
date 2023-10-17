#include <iomanip>
#include <iostream>
#include <string>
#include ".\headers\entity.h"

int main()
{   
    User newcomer;
    Client testClient;
    // Client testClient("josh","pass", 8884, 19880814, false, "");

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
    << testClient.getUserLogin() << '\n' << testClient.getUserPassword() << std::endl;

    std::cout << testClient.getDateOfBirth() << std::endl;
    testClient.setUserLogin("test-client");
    testClient.setUserPassword("test-password");

    std::cout 
    << testClient.getUserLogin() << '\n' 
    << testClient.getUserPassword() << std::endl;
    return 0;
};