#include <iostream>
#include <iomanip>
#include <string>
#include "entity/schedule.h"
#include "boundary/MainMenu.h"
#include "boundary/patientUI.h"
#include "boundary/StaffUI.h"
#include "control/dataManipulation.h"
//#include "boundary/userLogInUI.h"
// #include "boundary/inventoryUI.h"
// #include "boundary/staffInterface.h"
// #include "boundary/patientInterface.h"
//#include "control/GenerateRoomAvailabilityReport.h"
//#include "control/ModifyRoomAvailability.h"

/* 
There is a chain of includes that are all satisfied by calling "schedule.h".
These include the contents of the header/entity/ folder, <string>, <vector>, and
<chrono>.
*/

int main()
{
    MainMenu::StartMenu();

    
   
    // Room testroom1(101, 5, true);
    // Room testroom2(303, 2, true);
    // Patient test_patient1("ptest1","test","test","test",19880814,'X',true,"blue shield",true,testroom2);
    // Patient test_patient2("patient_test2","patient_pw2", "patient_last", "patient_first",20231031,'F',false,"n/a",false,Room());
    // dataManipulation::addUserToFile(test_patient1);
    // dataManipulation::addUserToFile(test_patient2);
    // Staff test_staff1("staff1","staff1","test","test",19010101,'X',814,1,"RN",20220101);
    // dataManipulation::addUserToFile(test_staff1);
    
    
    // Patient test_patient2;
    // Staff test_staff2;


    // StoreData::storeUser(test_staff2);


    // bool isStaff = false;
    
    // std::string name;
    // std::cout << "Name: ";
    // std::cin >> name;

    // if (isStaff) {
    //     StaffInterface staffUI;
    //     staffUI.displayMainMenu();
    // } else {
    //     PatientInterface patientUI(" Jane Doe ");
    //     patientUI.displayMainMenu();
    // }

    return 0;
};