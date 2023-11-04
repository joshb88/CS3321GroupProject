#include <fstream>
#include <iostream>
#include "control/storedata.h"

void StoreData::storeUser(User& user)
{
    std::cout << 
    user.getUserLogin() << '\n' << 
    user.getUserPassword() << '\n' <<
    user.getFirstName() << '\n' <<
    user.getLastName() << '\n' <<
    user.getDateOfBirth() << '\n' <<
    user.getGender() << '\n' <<
    std::endl;
}