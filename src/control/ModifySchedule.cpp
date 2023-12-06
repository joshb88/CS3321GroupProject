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

        '|' << // Start with general User info
        schedule.getStaffer().getUserLogin() << '-' <<
        schedule.getStaffer().getUserPassword() << '-' <<
        schedule.getStaffer().getLastName() << '-' <<
        schedule.getStaffer().getFirstName() << '-' <<
        std::to_string(schedule.getStaffer().getDateOfBirth()) << '-' <<
        schedule.getStaffer().getGender() << '-' <<
        std::to_string(schedule.getStaffer().getIdNumber()) << '-' <<
        std::to_string(schedule.getStaffer().getClearanceLevel()) << '-' <<
        schedule.getStaffer().getJobTitle() << '-' <<
        schedule.getStaffer().getDateOfHire() <<

        '|' << // Store Patient Info
        schedule.getPatient().getUserLogin() << '-' <<
        schedule.getPatient().getUserPassword() << '-' <<
        schedule.getPatient().getLastName() << '-' <<
        schedule.getPatient().getFirstName() << '-' <<
        schedule.getPatient().getDateOfBirth() << '-' <<
        schedule.getPatient().getGender() << '-' <<
        schedule.getPatient().getHasInsurance() << '-' <<
        schedule.getPatient().getInsuranceProvider() << '-' <<
        schedule.getPatient().getHasRoom() << '-' <<
        schedule.getPatient().getRoom().getRoomNumber() << '-' <<
        schedule.getPatient().getRoom().getRoomFloorNumber() << '-' <<
        schedule.getPatient().getRoom().getRoomAvailability() << '-' <<

        '|' << // Store Room for Event
        schedule.getRoom().getRoomNumber() << '-' <<
        schedule.getRoom().getRoomFloorNumber() << '-' <<
        schedule.getRoom().getRoomAvailability() << '-' <<
        
        '|' << // Store Procedure
        schedule.getProcedure().getProcedureName() << '-' <<
        schedule.getProcedure().getCost() << '-' <<
        ModifyProcedure::itemsUsedVectorToString(schedule.getProcedure().getItemsUsed());
    }
    else {std::cout << "file not open";};
    schedule_file.close();
}