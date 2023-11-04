#include <fstream>
#include <iostream>
#include "control/storedata.h"

void StoreData::storeUser(User& user)
{
    std::cout << user.getUserLogin() << std::endl;
}