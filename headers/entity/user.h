#pragma once
#include <string>

class User
{
    protected:
        std::string user_login;
        std::string user_password;
        std::string last_name;
        std::string first_name;
        unsigned int date_of_birth;
        unsigned char gender;

    public:
        //Constructors
        User();
        //login, password, last name, first name, dob, gender
        User(std::string login, std::string password, 
        std::string last, std::string first, 
        unsigned int dob, unsigned char gender);
        // Deconstructor
        virtual ~User() = default;

        // Setters
        void setUserLogin(std::string);
        void setUserPassword(std::string);
        void setLastName(std::string);
        void setFirstName(std::string);
        void setDateOfBirth(unsigned int);
        void setGender(unsigned char);

        // Getters
        std::string getUserLogin() const;
        std::string getUserPassword() const;
        std::string getLastName() const;
        std::string getFirstName() const;
        unsigned int getDateOfBirth() const;
        unsigned char getGender() const;
};
