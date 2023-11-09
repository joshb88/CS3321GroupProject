#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include "entity/user.h"

class StoreData
{
    public:
        static void storeUser(User&);
};