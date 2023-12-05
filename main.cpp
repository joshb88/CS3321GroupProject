#include <iostream>
#include <iomanip>
#include <string>
#include "entity/schedule.h"
#include "boundary/MainMenu.h"
#include "control/MainMenuLogic.h"
#include "boundary/patientInterface.h"
#include "boundary/staffInterface.h"
#include "control/modifyProcedure.h"
#include "control/TESTMODINV.h"
#include "control/ModifySchedule.h"

int main()
{

    //MainMenu::StartMenu();
    Procedure mri = ModifyProcedure::readProcedureFromDatabase("mri");
    Patient patient = *DatabaseManagement::getUserFromFile("ptest1");
    Staff staff = *DatabaseManagement::getUserFromFile("stest1");
    Room room(101,5,true);

    Schedule schedule("19880814 15:30");
    schedule.setPatient(patient);
    schedule.setStaffer(staff);
    schedule.setProcedure(mri);
    schedule.setRoom(room);

    // std::cout << schedule.getTime();

    ModifySchedule::writeScheduleToDatabase(schedule);

    return 0;
};