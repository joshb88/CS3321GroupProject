#pragma once
#include <iostream>
#include "user.h"
#include "room.h"

class Patient : public User
{
    private:
        bool has_insurance;
        std::string insurance_provider;
        bool has_room;
        Room room;

    public:
        // Constructors
        Patient();
        Patient(const User&);
        Patient(std::string patient_login, std::string patient_password, std::string last_name, std::string first_name, unsigned int date_of_birth, unsigned char gender, bool has_insurance, std::string insurance_provider, bool has_room, const Room& room);

        // Setters
        void setHasInsurance(bool);
        void setInsuranceProvider(std::string);
        void setHasRoom(bool);
        void setRoom(const Room&);

        // Getters
        bool getHasInsurance() const;
        std::string getInsuranceProvider() const;
        bool getHasRoom() const;
        Room& getRoom();
};

std::ostream& operator<<(std::ostream& os, Patient& patient);