#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include "entity/schedule.h"
#include <iomanip>
#include <ctime>
#include <chrono>
#include "control/ModifySchedule.h"
#include "boundary/MainMenu.h"
#include "control/modifyProcedure.h"
#include "control/TESTMODINV.h"

void ModifySchedule::writeScheduleToDatabase(Schedule& schedule)
{
    std::ofstream schedule_file;
    schedule_file.open("./database/schedules.txt", std::ios::app | std::ios::out);

    if (schedule_file.is_open())
    {
        schedule_file << 
        // std::cout <<

        // Get the time
        schedule.getTime() <<

        '|' << // Store  Staff  info
        schedule.getStaffer() <<

        '|' << // Store Patient Info
        schedule.getPatient() <<

        '|' << // Store Room for Event
        schedule.getRoom() <<
        
        '|' << // Store Procedure
        schedule.getProcedure().getProcedureName() << '-' <<
        schedule.getProcedure().getCost() << '-' <<
        ModifyProcedure::itemsUsedVectorToString(schedule.getProcedure().getItemsUsed()) <<
        std::endl;
    }
    else {std::cout << "file not open";};
    schedule_file.close();
}
