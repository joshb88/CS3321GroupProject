#pragma once
#include <iostream>
#include <fstream>
#include <entity/user.h>
#include <string>

class dataManipulation
{
private:
    /* data */
public:

    bool checkForUeser(std::string);
    void getUserFromFile(User&,std::string);
    void modifyUserFromFile (User);
    void addUser (User);
};

