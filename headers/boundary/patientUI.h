#pragma once
#include "entity/patient.h"


class PatientUI : public MainMenu
{
    public:
        static Patient accountCreation();
        static Patient accountCreation(std::string entered_username);
};