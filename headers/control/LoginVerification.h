#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include "entity/user.h"
#include "entity/patient.h"
#include "entity/staff.h"


class LoginVerification
{
    public:
        static bool userInDatabase(User&);
        static bool userInDatabase(const std::string& first_name, const std::string& last_name);
        // static void checkPassword(User&);
};