#include <iomanip>
#include <iostream>
#include <string>
// #include "./headers/entity.h"

class User
{
    private:
        std::string user_login;
        std::string user_password;
        unsigned int id_number;

    public:
        void setUserLogin(std::string log) { user_login = log; };
        void setUserPassword(std::string pw) {user_password = pw; };
        std::string getUserLogin() const { return user_login; } 
        std::string getUserPassword() const { return user_password;}
        void setIdNumber(unsigned int id) {id_number = id; };
        unsigned int getId() const { return id_number; }
};

int main()
{
    User newcomer;
    
    newcomer.setUserLogin("boehm.j");
    newcomer.setUserPassword("password");

    std::cout << newcomer.getUserLogin() << std::endl;
    std::cout << "Hello World. \nThis is a test.";
};