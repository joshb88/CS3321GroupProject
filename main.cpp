#include <iostream>
#include <iomanip>
#include <string>
#include "entity/schedule.h"
#include "boundary/MainMenu.h"
#include "control/MainMenuLogic.h"
#include "boundary/patientInterface.h"
#include "boundary/staffInterface.h"
// #include "boundary/userLogInUI.h"
// #include "boundary/inventoryUI.h"
// #include "boundary/staffInterface.h"
// #include "boundary/patientInterface.h"
//#include "control/GenerateRoomAvailabilityReport.h"
//#include "control/ModifyRoomAvailability.h"
#include "control/modifyProcedure.h"
#include "control/TESTMODINV.h"

/* 
There is a chain of includes that are all satisfied by calling "schedule.h".
These include the contents of the header/entity/ folder, <string>, <vector>, and
<chrono>.
*/

int main()
{

    //MainMenu::StartMenu();
    // Room testroom1(101, 5, true);
    // Patient test_patient2("patient_test2","patient_pw2", "patient_last", "patient_first",20231031,'F',false,"n/a",false,Room());
    // Staff test_staff1("staff1","staff1","test","test",19010101,'X',814,1,"RN",20220101);

    // Room testroom2(303, 2, false);
    // Patient test_patient1("ptest1","ptest1","Boehm","Josh",19880814,'X',true,"blue shield",true,testroom2);
    // std::unique_ptr<User> test = std::make_unique<Patient>(test_patient1);
    // LoginVerification::passUserToCorrectUI(std::move(test));
    
    
    // Patient test_patient2;
    // Staff test_staff2;


    Inventory imaging_fluid("imaging fluid",500,10);
    Inventory iv_bags("iv bags",1000,30);
    Inventory mri_machine("cat scan machine",3,0);
    std::vector<Inventory> mri_itesm_needed = {imaging_fluid, iv_bags,mri_machine};
    Procedure mri("mri",5000.75,mri_itesm_needed);

    ModifyInventory::writeInventoryToDatabase(imaging_fluid);
    Inventory itest = ModifyInventory::readInventoryFromDatabase("imaging fluid");

    // std::cout << 
    // itest.getItemName() << std::endl <<
    // itest.getItemCount() << std::endl <<
    // itest.getItemThreshold() << std::endl;

    ModifyProcedure::writeProcedureToDatabase(mri);
    Procedure ptest = ModifyProcedure::readProcedureFromDatabase("mri");

    std::cout <<
    "Procedure Name:\t" << ptest.getProcedureName() << std::endl <<
    "Procedure Cost:\t" << ptest.getCost() << std::endl <<
    "Inventory Required:\t" << ptest.getItemsUsed() << std::endl;
    Procedure ptest2 = ModifyProcedure::createProcedureFromUser();

    std::cout <<
    "Procedure Name:\t" << ptest2.getProcedureName() << std::endl <<
    "Procedure Cost:\t" << ptest2.getCost() << std::endl <<
    "Inventory Required:\t" << ptest2.getItemsUsed() << std::endl;

    return 0;
};