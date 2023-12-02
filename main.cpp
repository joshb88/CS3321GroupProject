#include <iostream>
#include <iomanip>
#include <string>
#include "entity/schedule.h"
#include "control/storedata.h"
#include "boundary/MainMenu.h"
#include "control/LoginVerification.h"
#include "boundary/patientUI.h"
#include "boundary/StaffUI.h"
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

    //PatientUI::accountCreation();
    // Room testroom1(101, 5, true);
    // Room testroom2(303, 2, true);
    // User testPatient1("test_login1","test_password1","test_last1","test_first1",19880814,'M');
    // User testPatient2("test_login2","test_password2","test_last2","test_first2",19880815,'F');
    // User testPatient3("test_login3","test_password3","test_last3","test_first3",19880816,'X');
    // User testPatient4("test_login4","test_password4","test_last4","test_first4",19880817,'X');
    // Patient test_patient1("patient_test1","patient_pw1", "patient_last", "patient_first",20231031,'F',false,"n/a",&testroom2);
    // Patient test_patient2;
    // Staff test_staff1("staff1","staff1","test","test",19010101,'X',814,1,"RN",20220101);
    // Staff test_staff2;

    // StoreData::storeUser(testPatient1);
    // StoreData::storeUser(testPatient2);
    // StoreData::storeUser(testPatient3);
    // StoreData::storeUser(testPatient4);
    // StoreData::storeUser(test_patient1);
    // StoreData::storeUser(test_patient2);
    // StoreData::storeUser(test_staff1);
    // StoreData::storeUser(test_staff2);

    //std::cout << testPatient.getRoom()->getRoomNumber3();
    // testPatient.setRoom(&testroom1); 
    // std::cout << testPatient.getRoom()->getRoomNumber() << std::endl;
    // testPatient.setRoom(&testroom2);
    // std::cout << testPatient.getRoom()->getRoomNumber();

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