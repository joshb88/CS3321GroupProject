#include "entity/schedule.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <chrono>
#include "boundary/MainMenu.h"
#include "control/MainMenuLogic.h"
#include "boundary/patientInterface.h"
#include "boundary/staffInterface.h"
#include "control/modifyProcedure.h"
#include "control/TESTMODINV.h"
#include "control/ModifySchedule.h"
// #include "control/ModifyUser.h"

int main()
{

    //MainMenu::StartMenu();
    Procedure mri = ModifyProcedure::readProcedureFromDatabase("mri");
    // Staff staff = *DatabaseManagement::getUserFromFile("stest1");
    // Room room(101,5,true);

    std::cout << mri << std::endl;

    // Schedule schedule("19880814 15:30");
    // schedule.setPatient(patient);
    // schedule.setStaffer(staff);
    // schedule.setProcedure(mri);
    // schedule.setRoom(room);
    // Patient patient = *DatabaseManagement::getUserFromFile("ptest1");
    // std::cout << patient;

    // Room room(123, 5, false);
    // Room room_copy;
    // std::cout << room << std::endl;
    // std::cout << room_copy << std::endl;
    // std::ostringstream room_stream;
    // room_stream << room;
    // std::string room_string = room_stream.str();
    // std::istringstream iss(room_string);
    // iss >> room_copy;
    // std::cout << room_copy << std::endl;
    

    // Patient patient = *DatabaseManagement::getUserFromFile("ptest1");
    // Patient patient_copy;
    // std::cout << patient << std::endl;
    // std::ostringstream patient_stream;
    // patient_stream << patient;
    // std::string patient_string = patient_stream.str();
    // std::istringstream iss(patient_string);
    // iss >> patient_copy;
    // std::cout << patient_copy << std::endl;
    


    // Schedule schedule = ModifySchedule::readFromDatabase("19880814")
    // std::cout << schedule;

    return 0;
};