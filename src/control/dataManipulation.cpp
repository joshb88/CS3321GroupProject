#include "control/dataManipulation.h"


void dataManipulation::getUserFromFile (User &user, std::string the_login)
{
    std::string user_login = the_login;
    std::string name;

    std::ifstream patient_file;

    patient_file.open("./database/users.txt", std::ios::in);

    User our_user;

    patient_file.read((char*)&our_user, sizeof(our_user));

    while (!patient_file.eof())
    {
        if(our_user.getUserLogin() == user_login)
        {
            user.setUserLogin(user_login);
            user.setUserPassword(our_user.getUserPassword()); 
            user.setDateOfBirth(our_user.getDateOfBirth());
            user.setFirstName(our_user.getFirstName());
            user.setGender(our_user.getGender());
            user.setLastName(our_user.getLastName());

        }
        patient_file.read((char*)&our_user, sizeof(our_user));
    }
    patient_file.close(); 
}


bool dataManipulation::checkForUeser(std::string user_login)
{
        bool userIsFound = false;
    std::ifstream patient_file;

    User our_user;

    patient_file.open("./database/users.txt", std::ios::in);
    patient_file.read((char*)&our_user, sizeof(our_user));

    while (!patient_file.eof()){
        if(our_user.getUserLogin() == user_login)
        {
            userIsFound = true;
            break;
        }
        patient_file.read((char*)&our_user, sizeof(our_user));
    }

    patient_file.close();
    return userIsFound;
}