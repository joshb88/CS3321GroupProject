#include <iomanip>
#include <iostream>
#include <string>
#include ".\headers\entity.h"

int main()
{   
    User newcomer;

    std::cout 
    << newcomer.getUserLogin() << '\n' 
    << newcomer.getUserPassword() << std::endl;

    newcomer.setUserLogin("name-test1");
    newcomer.setUserPassword("pass-test1");

    std::cout 
    << newcomer.getUserLogin() << '\n' 
    << newcomer.getUserPassword() << std::endl;
    std::cout << "Hello World. \nThis is a test.";

    return 0;
};