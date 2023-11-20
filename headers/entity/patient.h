#pragma once
#include "user.h"
#include "room.h"

class Patient : public User
{
    private:
        bool has_insurance;
        std::string insurance_provider;
        Room* room;

    public:
        // Constructors
        Patient();
        Patient(std::string patient_login, std::string patient_password, std::string last_name, std::string first_name, unsigned int date_of_birth, unsigned char gender, bool has_insurance, std::string insurance_provider, Room* room_ptr);

        // Setters
        void setHasInsurance(bool);
        void setInsuranceProvider(std::string);
        void setRoom(Room&);

        // Getters
        bool getHasInsurance() const;
        std::string getInsuranceProvider() const;
        Room& getRoom();
};