#pragma once
#include "entity/patient.h"


class StaffUI : public MainMenu
{
    public:
        static StaffUI accountCreation();
        static StaffUI accountCreation(std::string entered_username);
};