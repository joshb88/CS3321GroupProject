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

    //std::cout << schedule.getProcedure();

    ModifySchedule::writeScheduleToDatabase(schedule);
    // std::cout <<

    //     // Get the time
    //     schedule.getTime() <<

    //     '|' << // Start with general User info
    //     schedule.getStaffer().getUserLogin() << '-' <<
    //     schedule.getStaffer().getUserPassword() << '-' <<
    //     schedule.getStaffer().getLastName() << '-' <<
    //     schedule.getStaffer().getFirstName() << '-' <<
    //     std::to_string(schedule.getStaffer().getDateOfBirth()) << '-' <<
    //     schedule.getStaffer().getGender() << '-' <<
    //     std::to_string(schedule.getStaffer().getIdNumber()) << '-' <<
    //     std::to_string(schedule.getStaffer().getClearanceLevel()) << '-' <<
    //     schedule.getStaffer().getJobTitle() << '-' <<
    //     schedule.getStaffer().getDateOfHire() <<

    //     '|' << // Store Patient Info
    //     schedule.getPatient().getUserLogin() << '-' <<
    //     schedule.getPatient().getUserPassword() << '-' <<
    //     schedule.getPatient().getLastName() << '-' <<
    //     schedule.getPatient().getFirstName() << '-' <<
    //     schedule.getPatient().getDateOfBirth() << '-' <<
    //     schedule.getPatient().getGender() << '-' <<
    //     schedule.getPatient().getHasInsurance() << '-' <<
    //     schedule.getPatient().getInsuranceProvider() << '-' <<
    //     schedule.getPatient().getHasRoom() << '-' <<
    //     schedule.getPatient().getRoom().getRoomNumber() << '-' <<
    //     schedule.getPatient().getRoom().getRoomFloorNumber() << '-' <<
    //     schedule.getPatient().getRoom().getRoomAvailability() << '-' <<

    //     '|' << // Store Room for Event
    //     schedule.getRoom().getRoomNumber() << '-' <<
    //     schedule.getRoom().getRoomFloorNumber() << '-' <<
    //     schedule.getRoom().getRoomAvailability() << '-' <<
        
    //     '|' << // Store Procedure
    //     schedule.getProcedure().getProcedureName() << '-' <<
    //     schedule.getProcedure().getCost() << '-' <<
    //     ModifyProcedure::itemsUsedVectorToString(schedule.getProcedure().getItemsUsed());

    return 0;
};