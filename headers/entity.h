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

// class Client : public User
// {
//     int date_of_birth;
// };