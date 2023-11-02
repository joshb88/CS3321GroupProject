#pragma once
#include <string>
#include "user.h"

class Staff : public User
{
    public:
        enum Clearance { entry, janitorial, nursing, medical, admin };
    private:
        unsigned int id_number;
        short clearance_level;
        std::string job_title;
        unsigned int date_of_hire;
    public:
        //Constructors
        Staff();
        Staff(std::string login, std::string pass, std::string last, std::string first, unsigned int dob, unsigned char gender, unsigned int idnumber, short clearance, std::string jobtitle, unsigned int doh);

        // Setters
        void setIdNumber(unsigned int);
        void setClearanceLevel(short);
        void setJobTitle(std::string);
        void setDateOfHire(unsigned int);

        // Getters
        unsigned int getIdNumber() const;
        unsigned int getDateOfHire() const;
        short getClearanceLevel() const;
        std::string getJobTitle() const;
};