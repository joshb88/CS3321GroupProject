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
        static bool checkPassword(User&);
        static bool checkPassword(const std::string& user_login, const std::string& user_password);
};