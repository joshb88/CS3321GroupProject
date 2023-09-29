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
        void setUserLogin(std::string);
        void setUserPassword(std::string);
        std::string getUserLogin() const { return user_login; } 
        std::string getUserPassword() const { return user_password;}
        void setIdNumber(unsigned int);
        unsigned int getId() const { return id_number; }
};

// class Client : public User
// {
//     int date_of_birth;
// };