#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include "entity/user.h"
#include "entity/patient.h"
#include "entity/staff.h"

class StoreData
{
    public:
        static bool userInDatabase(User&);
        static void storeUser(User&);
};