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

    MainMenu::StartMenu();
    // Procedure mri = ModifyProcedure::readProcedureFromDatabase("mri");
    // Staff staff = *DatabaseManagement::getUserFromFile("stest1");
    // Room room(101,5,true);

    // std::cout << mri << std::endl;
    // Procedure mri_copy;
    // std::ostringstream proc_stream;
    // proc_stream << mri;
    // std::string proc_string = proc_stream.str();
    // std::istringstream iss(proc_string);
    // iss >> mri_copy;
    // std::cout << mri_copy << std::endl;
    // std::cout << mri_copy.getItemsUsed();

    // const std::vector<Inventory>& itemsUsed = mri_copy.getItemsUsed();
    // for (const auto& item : itemsUsed) {
    //     std::cout << item << ";";
    // }
    // std::cout << std::endl;


    // Schedule schedule("19880814 15:30");
    // schedule.setPatient(patient);
    // schedule.setStaffer(staff);
    // schedule.setProcedure(mri);
    // schedule.setRoom(room);
    // Patient patient = *DatabaseManagement::getUserFromFile("ptest1");
    // std::cout << patient;

    // Inventory imaging_fluid("imaging fluid",500,10);
    // Inventory iv_bags("iv bags",1000,30);
    // Inventory cat_scan("cat scan machine",3,0);
    // std::vector<Inventory> vec_of_inv = {imaging_fluid,iv_bags,cat_scan};
    // std::cout << vec_of_inv << std::endl;
    // std::vector<Inventory> vec_of_inv_copy;
    // std::ostringstream inv_list_stream;
    // inv_list_stream << vec_of_inv;
    // std::string inv_list_string = inv_list_stream.str();
    // std::istringstream iss(inv_list_string);
    // iss >> vec_of_inv_copy;
    // std::cout << vec_of_inv_copy << std::endl;


    return 0;
};