#pragma once
#include <string>

class User
{
    private:
        std::string user_login;
        std::string user_password;
        unsigned int id_number;

    public:
        User();
        User(std::string, std::string, unsigned int);
        void setUserLogin(std::string);
        void setUserPassword(std::string);
        std::string getUserLogin() const;
        std::string getUserPassword() const;
        void setIdNumber(unsigned int);
        unsigned int getId() const;
};

class Client : virtual public User
{
    private:
        unsigned int date_of_birth;
        bool has_insurance;
        std::string insurance_provider;
        //Room::room_number
    public:
        Client();
        Client(std::string, std::string, unsigned int, unsigned int, bool, std::string);
        void setDateOfBirth(unsigned int);
        void setHasInsurance(bool);
        void setInsuranceProvider(std::string);
        unsigned int getDateOfBirth() const;
        bool getHasInsurance() const;
        std::string getInsuranceProvider() const;
};