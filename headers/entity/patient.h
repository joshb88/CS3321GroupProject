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
        Patient(std::string, std::string, std::string, std::string, unsigned int, unsigned char, bool, std::string, Room*);

        // Setters
        void setHasInsurance(bool);
        void setInsuranceProvider(std::string);
        void setRoom(Room&);

        // Getters
        bool getHasInsurance() const;
        std::string getInsuranceProvider() const;
        Room& getRoom();
        int getRoomNumber();
};